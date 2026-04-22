import argparse
import json
import os

from clang.cindex import CursorKind, Index, TokenKind

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

            print("FUNCTION_DECL", obj)

            # found_functions.append(obj)
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


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", help="Input file")
    args = parser.parse_args()

    input_filename = os.path.basename(args.filename)

    index = Index.create()
    tree = index.parse(args.filename, args=["-x", "c++"])

    visitNode(tree.cursor)

    # comments = {}
    # for token in tree.cursor.get_tokens():
    #     if token.kind == TokenKind.COMMENT:
    #         line_number = token.location.line
    #         comment = token.spelling

    #         comments[line_number] = comment

    # functions = []
    # for child in tree.cursor.get_children():
    #     if child.kind == CursorKind.FUNCTION_DECL:
    #         pass
    #     elif child.kind == CursorKind.NAMESPACE:
    #         print("namespace:", child)
    #         continue
    #     else:
    #         # print(child.kind)
    #         continue

    #     if child.location.file is None:
    #         continue

    #     filepath = child.location.file.name
    #     filename = os.path.basename(filepath)

    #     if filename != input_filename:
    #         continue

    #     function_name = child.spelling
    #     return_type = child.result_type.spelling

    #     line_number = child.location.line
    #     comment = comments.get(line_number, "")

    #     params = []
    #     for param in child.get_arguments():
    #         param_name = param.spelling
    #         param_type = param.type.spelling

    #         params.append({
    #             "name": param_name,
    #             "type": param_type
    #         })

    #     functions.append({
    #         "name": function_name,
    #         "return_type": return_type,
    #         "params": params,
    #         "filename": filename,
    #         "line_number": line_number,
    #         "comment": comment
    #     })

    print(json.dumps(functions, indent=4, ensure_ascii=False))

if __name__ == "__main__":
    main()