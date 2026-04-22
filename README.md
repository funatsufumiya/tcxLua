# tcxLua

- Using Lua 5.4.8 sources now (NOTE: Lua 5.5 is currently not supported by Sol2)
- Using [sol2](https://github.com/ThePhD/sol2) (v3.3.0).
- Currently LuaJIT is not implemented yet.
- Not fully binded (currently partially binded to TrussC functions)

## Bindgen

Please read [tools/bindgen/README.md](tools/bindgen/README.md) in detail.

```bash
$ cd tools/bingen
# $ pip install uv # only at first time
# $ uv sync # only at first time
$ uv run main.py ../../../../core/include/TrussC.h
$ cp trussc_generated.cpp ../../src/generated
```