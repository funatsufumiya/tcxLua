# tcxLua

- Using Lua 5.4.8 sources now (NOTE: Lua 5.5 is currently not supported by Sol2)
- Using [sol2](https://github.com/ThePhD/sol2) (v3.3.0).
- Currently LuaJIT support is not implemented yet.

## Binding coverage

### Dones

- trussc (TrussC.h directly defined functions)
- cmath (common use ones only)
- tcMath
- Vec2, Vec3, Vec4, Mat4, Quaternion
- Color
- colors (constants)
- TAU, PI
- Fbo
- Texture, Image, Pixels
- Mesh
- Shader

## Development

### Bindgen

Please read [tools/bindgen/README.md](tools/bindgen/README.md) in detail.

```bash
$ cd tools/bingen
# $ pip install uv # only at first time
# $ uv sync # only at first time
$ uv run main.py ../../../../core/include/TrussC.h
$ cp trussc_generated.cpp ../../src/generated
```
