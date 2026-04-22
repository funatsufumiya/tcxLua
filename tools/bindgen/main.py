import argparse
import json
import os

from clang.cindex import CursorKind, Index, TokenKind

genfile = "trussc_generated.cpp"

prev = """
// WARNING: This file is auto-generated!

#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"
using namespace tc;

void tcxLua::setTrussCGeneratedBindings(const std::shared_ptr<sol::state>& lua){
"""

after = """
}
"""

target_filenames = [
    "TrussC.h"
]

ignore_functions = {
    "TrussC.h": [
        "trussc#setup",
        "trussc#cleanup",
        "trussc#operator|",
        "trussc#operator&",

        # makes errors:
        "trussc#intersectRect",
        "trussc#getBitmapStringBounds"
    ]
}

ignore_namespaces = {
    "TrussC.h": [
        "trussc::internal"
    ]
}

ignore_classes = {
    "TrussC.h": []
}

functions_map = {}

def visitNode(node, ns="", clazz=""):
    if node.kind.name == 'FUNCTION_DECL':
        is_ignore = False

        filepath = node.location.file.name
        filename = os.path.basename(filepath)
        if not (filename in target_filenames):
            return
        function_name = node.spelling
        return_type = node.result_type.spelling

        line_number = node.location.line

        params = []
        for param in node.get_arguments():
            param_name = param.spelling
            param_type = param.type.spelling

            params.append({
                "name": param_name,
                "type": param_type
            })

        if filename in ignore_namespaces:
            if ns in ignore_namespaces[filename]:
                is_ignore = True

        clazz_id = clazz if ns == "" else ns + "::" + clazz
        if clazz == "":
            clazz_id = ns

        if filename in ignore_classes:
            if clazz_id in ignore_classes[filename]:
                is_ignore = True

        id = clazz_id + "#" + function_name

        if filename in ignore_functions:
            if id in ignore_functions[filename]:
                is_ignore = True

        if not is_ignore:
            obj = {
                "id": id,
                # "type": "function",
                "filename": filename,
                "line_number": line_number,
                "function_name": function_name,
                "params": params,
                "return_type": return_type,
                "namespace": ns,
                "class": clazz
            }

            # print("FUNCTION_DECL", obj)
            # outfile.write(f"// {filename}, LINE {line_number}\n")

            # # write("" + obj)
            # outfile.write(str(obj) + "\n")

            detail_id = id + "@" + str(line_number)

            if not (id in functions_map):
                functions_map[id] = {}
            
            if detail_id in functions_map[id]:
                pass
            else:
                functions_map[id][line_number] = obj

    elif node.kind.name == 'NAMESPACE':
        if ns == "":
            ns = node.spelling
        else:
            ns = ns + "::" + node.spelling
    elif node.kind.name == 'CALL_EXPR':
        # print(declared_function_name, node.location.line)
        pass
    elif node.kind.name == 'CLASS_TEMPLATE':
        pass
    elif node.kind.name == 'CLASS_DECL':
        if clazz == "":
            clazz = node.spelling
        else:
            clazz = clazz + "." + node.spelling
    else:
        # print("kind_name:", node.kind.name)
        pass

    for c in node.get_children():
        visitNode(c, ns, clazz)


lp = "{"
rp = "}"

def bindFunctions(outfile, fn_map):
    for fns in fn_map.values():
        overloads_count = len(fns)
        for fn in fns.values():
            is_generated = False

            ns = fn["namespace"]
            name = fn["function_name"]
            arg_names = []
            arg_pairs = []
            for param in fn["params"]:
                arg_names.append(param["name"])
                arg_pairs.append(param["type"] + " " + param["name"])

            # print("FUNCTION_DECL", obj)
            outfile.write(f"// {fn["filename"]}, LINE {fn["line_number"]}\n")

            if overloads_count > 1:
                outfile.write(f"// overloads: {overloads_count}\n")
            else:
                id = name if ns == "" else ns + "::" + name
                if len(arg_names) == 0:
                    outfile.write(f"lua->set_function(\"{name}\", [](){lp} {id}(); {rp});\n")
                else:
                    # outfile.write(f"// args: {arg_names}\n")
                    # outfile.write(f"// args: {", ".join(arg_pairs)}\n")
                    sarg = ", ".join(arg_pairs) 
                    narg = ", ".join(arg_names) 
                    outfile.write(f"lua->set_function(\"{name}\", []({sarg}){lp} {id}({narg}); {rp});\n")

                is_generated = True

            # # write("" + obj)
            if not is_generated:
                outfile.write("// " + str(fn) + "\n")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", help="Input file")
    args = parser.parse_args()

    input_filename = os.path.basename(args.filename)

    index = Index.create()
    tree = index.parse(args.filename, args=["-x", "c++"])

    visitNode(tree.cursor)

    with open(genfile, mode='w') as f:
        f.write(prev)
        f.write("\n")

        bindFunctions(f, functions_map)

        f.write("\n")
        f.write(after)

    print(f"Generated {genfile}")

if __name__ == "__main__":
    main()