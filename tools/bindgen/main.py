import argparse
import json
import os

from clang.cindex import CursorKind, Index, TokenKind

genfile = "generated.h"

prev = """
#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"
using namespace tc;

void tcxLua::setGeneratedBindings(const std::shared_ptr<sol::state>& lua){
"""

after = """
}
"""

target_filenames = [
    "TrussC.h"
]

ignore_functions = {
    "TrussC.h": []
}

ignore_classes = {
    "TrussC.h": []
}

functions = []

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

        if filename in ignore_classes:
            if clazz in ignore_classes[filename]:
                is_ignore = True

        if filename in ignore_functions:
            if clazz + "#" + function_name in ignore_functions[filename]:
                is_ignore = True

        if not is_ignore:
            obj = {
                "type": "function",
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

            functions.append(obj)
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

def bindFunctions(outfile, fns):
    for fn in fns:
        # print("FUNCTION_DECL", obj)
        outfile.write(f"// {fn["filename"]}, LINE {fn["line_number"]}\n")

        # # write("" + obj)
        outfile.write(str(fn) + "\n")

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

        bindFunctions(f, functions)

        f.write("\n")
        f.write(after)

    print(f"Generated {genfile}")

if __name__ == "__main__":
    main()