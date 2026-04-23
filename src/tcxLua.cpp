#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"
using namespace tc;

// namespace tcx::lua {

std::shared_ptr<sol::state> tcxLua::getLuaState(){
    std::shared_ptr<sol::state> lua = std::make_shared<sol::state>();

    // lua->open_libraries(sol::lib::base, sol::lib::jit);
    lua->open_libraries(sol::lib::base);

    setBindings(lua);

    return lua;
}

void tcxLua::setBindings(const std::shared_ptr<sol::state>& lua){
    setTrussCGeneratedBindings(lua);
    setTypeBindings(lua);
    setConstBindings(lua);
    setColorConstBindings(lua);
    setMathBindings(lua);

    lua->set_function("getElapsedTimef", &trussc::getElapsedTimef);
}

void tcxLua::setConstBindings(const std::shared_ptr<sol::state>& lua){
    auto&& l = *lua;
    l["TAU"] = TAU;
    l["PI"] = PI;
    l["HALF_TAU"] = HALF_TAU;
    l["QUARTER_TAU"] = QUARTER_TAU;
}

void tcxLua::setTypeBindings(const std::shared_ptr<sol::state>& lua){
    sol::usertype<Vec2> vec2_type = lua->new_usertype<Vec2>("Vec2",
        sol::constructors<Vec2(), Vec2(float, float), Vec2(const Vec2&)>(),
        sol::meta_function::addition,
        sol::overload(
           [](const Vec2& a, const Vec2& b){ return a + b; },
           [](const Vec2& a, float b){ return a + b; }
        ),
        sol::meta_function::subtraction,
        sol::overload(
           [](const Vec2& a, const Vec2& b){ return a - b; },
           [](const Vec2& a, float b){ return a - b; }
        ),
        sol::meta_function::multiplication,
        sol::overload(
           [](const Vec2& a, const Vec2& b){ return a * b; },
           [](const Vec2& a, float b){ return a * b; }
        ),
        sol::meta_function::division,
        sol::overload(
           [](const Vec2& a, const Vec2& b){ return a / b; },
           [](const Vec2& a, float b){ return a / b; }
        )
    );
    vec2_type["x"] = &Vec2::x;
    vec2_type["y"] = &Vec2::y;

    vec2_type["length"] = &Vec2::length;
    vec2_type["lengthSquared"] = &Vec2::lengthSquared;
    vec2_type["normalized"] = &Vec2::normalized;
    vec2_type["normalize"] = &Vec2::normalize;
    vec2_type["limit"] = &Vec2::limit;
    vec2_type["dot"] = &Vec2::dot;
    vec2_type["cross"] = &Vec2::cross;
    vec2_type["distance"] = &Vec2::distance;
    vec2_type["distanceSquared"] = &Vec2::distanceSquared;
    vec2_type["angle"] = sol::overload(
        [](Vec2& p){ return p.angle(); },
        [](Vec2& p, const Vec2& v){ return p.angle(v); }
    );
    vec2_type["rotated"] = &Vec2::rotated;
    vec2_type["rotate"] = &Vec2::rotate;
    vec2_type["lerp"] = &Vec2::lerp;
    vec2_type["perpendicular"] = &Vec2::perpendicular;
    vec2_type["reflected"] = &Vec2::reflected;
    vec2_type["fromAngle"] = &Vec2::fromAngle;

    sol::usertype<Vec3> vec3_type = lua->new_usertype<Vec3>("Vec3",
        sol::constructors<Vec3(), Vec3(float, float, float), Vec3(const Vec2&), Vec3(const Vec3&)>(),
        sol::meta_function::addition,
        sol::overload(
           [](const Vec3& a, const Vec3& b){ return a + b; },
           [](const Vec3& a, float b){ return a + b; }
        ),
        sol::meta_function::subtraction,
        sol::overload(
           [](const Vec3& a, const Vec3& b){ return a - b; },
           [](const Vec3& a, float b){ return a - b; }
        ),
        sol::meta_function::multiplication,
        sol::overload(
           [](const Vec3& a, const Vec3& b){ return a * b; },
           [](const Vec3& a, float b){ return a * b; }
        ),
        sol::meta_function::division,
        sol::overload(
           [](const Vec3& a, const Vec3& b){ return a / b; },
           [](const Vec3& a, float b){ return a / b; }
        )
    );
    vec3_type["x"] = &Vec3::x;
    vec3_type["y"] = &Vec3::y;
    vec3_type["z"] = &Vec3::z;

    vec3_type["length"] = &Vec3::length;
    vec3_type["lengthSquared"] = &Vec3::lengthSquared;
    vec3_type["normalized"] = &Vec3::normalized;
    vec3_type["normalize"] = &Vec3::normalize;
    vec3_type["limit"] = &Vec3::limit;
    vec3_type["dot"] = &Vec3::dot;
    vec3_type["cross"] = &Vec3::cross;
    vec3_type["distance"] = &Vec3::distance;
    vec3_type["distanceSquared"] = &Vec3::distanceSquared;
    vec3_type["lerp"] = &Vec3::lerp;
    vec3_type["reflected"] = &Vec3::reflected;
    vec3_type["xy"] = &Vec3::xy;

    sol::usertype<Vec4> vec4_type = lua->new_usertype<Vec4>("Vec4",
        sol::constructors<Vec4(), Vec4(float, float, float, float), Vec4(const Vec3&), Vec4(const Vec4&)>(),
        sol::meta_function::addition,
        sol::overload(
           [](const Vec4& a, const Vec4& b){ return a + b; },
           [](const Vec4& a, float b){ return a + b; }
        ),
        sol::meta_function::subtraction,
        sol::overload(
           [](const Vec4& a, const Vec4& b){ return a - b; },
           [](const Vec4& a, float b){ return a - b; }
        ),
        sol::meta_function::multiplication,
        [](const Vec4& a, float b){ return a * b; },
        sol::meta_function::division,
        [](const Vec4& a, float b){ return a / b; }
    );
    vec4_type["x"] = &Vec4::x;
    vec4_type["y"] = &Vec4::y;
    vec4_type["z"] = &Vec4::z;
    vec4_type["w"] = &Vec4::w;

    vec4_type["length"] = &Vec4::length;
    vec4_type["lengthSquared"] = &Vec4::lengthSquared;
    vec4_type["normalized"] = &Vec4::normalized;
    vec4_type["normalize"] = &Vec4::normalize;
    vec4_type["dot"] = &Vec4::dot;
    vec4_type["lerp"] = &Vec4::lerp;
    vec4_type["xy"] = &Vec4::xy;

    sol::usertype<Quaternion> quat_type = lua->new_usertype<Quaternion>("Quaternion",
        sol::constructors<Quaternion(), Quaternion(float, float, float, float), Quaternion(const Quaternion&)>(),
        sol::meta_function::multiplication,
        [](const Quaternion& a, const Quaternion& b){ return a * b; }
    );
    quat_type["w"] = &Quaternion::w;
    quat_type["x"] = &Quaternion::x;
    quat_type["y"] = &Quaternion::y;
    quat_type["z"] = &Quaternion::z;
    quat_type["identity"] = &Quaternion::identity;
    quat_type["fromAxisAngle"] = &Quaternion::fromAxisAngle;
    quat_type["fromEuler"] = sol::overload(
        [](float pitch, float yaw, float roll){ return Quaternion::fromEuler(pitch, yaw, roll); },
        [](const Vec3& euler){ return Quaternion::fromEuler(euler); }
    );
    quat_type["toEuler"] = &Quaternion::toEuler;
    quat_type["toMatrix"] = &Quaternion::toMatrix;
    quat_type["length"] = &Quaternion::length;
    quat_type["lengthSquared"] = &Quaternion::lengthSquared;
    quat_type["normalized"] = &Quaternion::normalized;
    quat_type["normalize"] = &Quaternion::normalize;
    quat_type["conjugate"] = &Quaternion::conjugate;
    quat_type["rotate"] = &Quaternion::rotate;
    quat_type["slerp"] = &Quaternion::slerp;

    sol::usertype<Mat4> mat4_type = lua->new_usertype<Mat4>("Mat4",
        sol::constructors<Mat4(),
            Mat4(float m00, float m01, float m02, float m03,
                 float m10, float m11, float m12, float m13,
                 float m20, float m21, float m22, float m23,
                 float m30, float m31, float m32, float m33),
            Mat4(const Mat4&)>(),
        sol::meta_function::multiplication,
        sol::overload(
           [](const Mat4& a, const Mat4& b){ return a * b; },
           [](const Mat4& a, const Vec3& b){ return a * b; },
           [](const Mat4& a, const Vec4& b){ return a * b; }
        )
    );
    mat4_type["at"] = [](Mat4& m, int raw, int col) { return m.at(raw, col); };
    mat4_type["set"] = [](Mat4& m, int raw, int col, int v){ m.at(raw, col) = v; }; // WORKAROUND
    mat4_type["identity"] = &Mat4::identity;
    mat4_type["fromHomography"] = &Mat4::fromHomography;
    mat4_type["translate"] = sol::overload(
        [](Mat4& m, float tx, float ty, float tz){ return m.translate(tx, ty, tz); },
        [](Mat4& m, const Vec3& t){ return m.translate(t); }
    );
    mat4_type["rotateX"] = &Mat4::rotateX;
    mat4_type["rotateY"] = &Mat4::rotateY;
    mat4_type["rotateZ"] = &Mat4::rotateZ;
    mat4_type["rotate"] = &Mat4::rotate;
    mat4_type["scale"] = sol::overload(
        [](Mat4& m, float s){ return m.scale(s); },
        [](Mat4& m, float sx, float sy, float sz){ return m.scale(sx, sy, sz); },
        [](Mat4& m, const Vec3& s){ return m.scale(s); }
    );
    mat4_type["transposed"] = &Mat4::transposed;
    mat4_type["inverted"] = &Mat4::inverted;
    mat4_type["lookAt"] = &Mat4::lookAt;
    mat4_type["ortho"] = &Mat4::ortho;
    mat4_type["perspective"] = &Mat4::perspective;
    mat4_type["frustum"] = &Mat4::frustum;
    
    sol::usertype<Color> color_type = lua->new_usertype<Color>("Color",
        sol::constructors<Color(), Color(float), Color(float, float), Color(float, float, float), Color(float, float, float, float), Color(const Color&)>(),
        sol::meta_function::addition,
        [](const Color& a, const Color& b){ return a + b; },
        sol::meta_function::subtraction,
        [](const Color& a, const Color& b){ return a - b; },
        sol::meta_function::multiplication,
        [](const Color& a, float b){ return a * b; },
        sol::meta_function::division,
        [](const Color& a, float b){ return a / b; }
    );

    color_type["r"] = &Color::r;
    color_type["g"] = &Color::g;
    color_type["b"] = &Color::b;
    color_type["a"] = &Color::a;

    color_type["fromBytes"] = &Color::fromBytes;
    color_type["fromHex"] = &Color::fromHex;
    color_type["fromHSB"] = &Color::fromHSB;
    color_type["fromOKLCH"] = &Color::fromOKLCH;
    color_type["fromOKLab"] = &Color::fromOKLab;
    color_type["fromLinear"] = &Color::fromLinear;
    color_type["toHex"] = &Color::toHex;
    color_type["toLinear"] = &Color::toLinear;
    color_type["toHSB"] = &Color::toHSB;
    color_type["toOKLab"] = &Color::toOKLab;
    color_type["toOKLCH"] = &Color::toOKLCH;
    color_type["clamped"] = &Color::clamped;
    color_type["lerpRGB"] = &Color::lerpRGB;
    color_type["lerpLinear"] = &Color::lerpLinear;
    color_type["lerpHSB"] = &Color::lerpHSB;
    color_type["lerpOKLab"] = &Color::lerpOKLab;
    color_type["lerpOKLCH"] = &Color::lerpOKLCH;
    color_type["lerp"] = &Color::lerp;

    sol::usertype<Mesh> mesh_type = lua->new_usertype<Mesh>("Mesh",
        sol::constructors<Mesh(), Mesh(const Mesh&), Mesh(Mesh&&)>()
    );

    mesh_type["setMode"] = &Mesh::setMode;
    mesh_type["getMode"] = &Mesh::getMode;
    mesh_type["addVertex"] = sol::overload(
        [](Mesh& m, float x, float y){ return m.addVertex(x, y); },
        [](Mesh& m, float x, float y, float z){ return m.addVertex(x, y, z); },
        [](Mesh& m, const Vec2& v){ return m.addVertex(v); },
        [](Mesh& m, const Vec3& v){ return m.addVertex(v); }
    );
    mesh_type["addVertices"] = &Mesh::addVertices;
    mesh_type["getVertices"] = [](Mesh& m){ return m.getVertices(); };
    mesh_type["getNumVertices"] = &Mesh::getNumVertices;
    mesh_type["addColor"] = sol::overload(
        [](Mesh& m, float x, float y, float z){ return m.addColor(x, y, z); },
        [](Mesh& m, float x, float y, float z, float w){ return m.addColor(x, y, z, w); },
        [](Mesh& m, const Color& v){ return m.addColor(v); }
    );
    mesh_type["addColors"] = &Mesh::addColors;
    mesh_type["getColors"] = [](Mesh& m){ return m.getColors(); };
    mesh_type["getNumColors"] = &Mesh::getNumColors;
    mesh_type["hasColors"] = &Mesh::hasColors;
    mesh_type["addIndex"] = &Mesh::addIndex;
    mesh_type["addIndices"] = &Mesh::addIndices;
    mesh_type["addTriangle"] = &Mesh::addTriangle;
    mesh_type["getIndices"] = [](Mesh& m){ return m.getIndices(); };
    mesh_type["hasIndices"] = &Mesh::hasIndices;
    mesh_type["addNormal"] = sol::overload(
        [](Mesh& m, float x, float y, float z){ return m.addNormal(x, y, z); },
        [](Mesh& m, const Vec3& v){ return m.addNormal(v); }
    );
    mesh_type["addNormals"] = &Mesh::addNormals;
    mesh_type["setNormal"] = &Mesh::setNormal;
    mesh_type["getNormal"] = &Mesh::getNormal;
    mesh_type["getNormals"] = [](Mesh& m){ return m.getNormals(); };
    mesh_type["getNumNormals"] = &Mesh::getNumNormals;
    mesh_type["hasNormals"] = &Mesh::hasNormals;
    mesh_type["addTexCoord"] = sol::overload(
        [](Mesh& m, float x, float y){ return m.addTexCoord(x, y); },
        [](Mesh& m, const Vec2& v){ return m.addTexCoord(v); }
    );
    mesh_type["getTexCoords"] = [](Mesh& m){ return m.getTexCoords(); };
    mesh_type["hasTexCoords"] = &Mesh::hasTexCoords;
    mesh_type["hasValidTexCoords"] = &Mesh::hasValidTexCoords;
    mesh_type["addTangent"] = sol::overload(
        [](Mesh& m, float x, float y, float z){ return m.addTangent(x, y, z); },
        [](Mesh& m, float x, float y, float z, float w){ return m.addTangent(x, y, z, w); },
        [](Mesh& m, const Vec4& v){ return m.addTangent(v); }
    );
    mesh_type["getTangents"] = [](Mesh& m){ return m.getTangents(); };
    mesh_type["getNumTangents"] = &Mesh::getNumTangents;
    mesh_type["hasTangents"] = &Mesh::hasTangents;
    mesh_type["clear"] = &Mesh::clear;
    mesh_type["clearVertices"] = &Mesh::clearVertices;
    mesh_type["clearNormals"] = &Mesh::clearNormals;
    mesh_type["clearColors"] = &Mesh::clearColors;
    mesh_type["clearIndices"] = &Mesh::clearIndices;
    mesh_type["clearTexCoords"] = &Mesh::clearTexCoords;
    mesh_type["clearTangents"] = &Mesh::clearTangents;
    mesh_type["translate"] = sol::overload(
        [](Mesh& m, float x, float y, float z){ return m.translate(x, y, z); },
        [](Mesh& m, const Vec3& v){ return m.translate(v); }
    );
    mesh_type["rotateX"] = &Mesh::rotateX;
    mesh_type["rotateY"] = &Mesh::rotateY;
    mesh_type["rotateZ"] = &Mesh::rotateZ;
    mesh_type["scale"] = sol::overload(
        [](Mesh& m, float x, float y, float z){ return m.scale(x, y, z); },
        [](Mesh& m, float s){ return m.scale(s); }
    );
    mesh_type["transform"] = &Mesh::transform;
    mesh_type["append"] = &Mesh::append;
    mesh_type["draw"] = sol::overload(
        [](Mesh& m){ return m.draw(); },
        [](Mesh& m, const Image& image){ return m.draw(image); },
        [](Mesh& m, const Texture& tex){ return m.draw(tex); }
    );
    mesh_type["drawNoLighting"] = &Mesh::drawNoLighting;
    mesh_type["drawWithLighting"] = &Mesh::drawWithLighting;
    mesh_type["drawNoLightingWithTexture"] = &Mesh::drawNoLightingWithTexture;
    mesh_type["drawWireframe"] = &Mesh::drawWireframe;

    sol::usertype<Fbo> fbo_type = lua->new_usertype<Fbo>("Fbo",
        sol::constructors<Fbo()>() // TODO: move constructor?
    );

    fbo_type["allocate"] = sol::overload(
        [](Fbo& f, int w, int h){ return f.allocate(w, h); },
        [](Fbo& f, int w, int h, int sampleCount){ return f.allocate(w, h, sampleCount); },
        [](Fbo& f, int w, int h, int sampleCount, TextureFormat t){ return f.allocate(w, h, sampleCount, t); }
    );
    fbo_type["clear"] = &Fbo::clear;
    fbo_type["begin"] = sol::overload(
        [](Fbo& f){ return f.begin(); },
        [](Fbo& f, float r, float g, float b){ return f.begin(r, g, b); },
        [](Fbo& f, float r, float g, float b, float a){ return f.begin(r, g, b, a); }
    );
    fbo_type["clearColor"] = &Fbo::clearColor;
    fbo_type["end"] = &Fbo::end;
    fbo_type["readPixels"] = &Fbo::readPixels;
    fbo_type["readPixelsFloat"] = &Fbo::readPixelsFloat;
    fbo_type["copyTo"] = &Fbo::copyTo;
    fbo_type["getWidth"] = &Fbo::getWidth;
    fbo_type["getHeight"] = &Fbo::getHeight;
    fbo_type["getSampleCount"] = &Fbo::getSampleCount;
    fbo_type["getTextureFormat"] = &Fbo::getTextureFormat;
    fbo_type["isAllocated"] = &Fbo::isAllocated;
    fbo_type["isActive"] = &Fbo::isActive;
    fbo_type["getTexture"] = [](Fbo& f) -> Texture& { return f.getTexture(); };
    fbo_type["save"] = &Fbo::save;
    fbo_type["getColorImage"] = &Fbo::getColorImage;
    fbo_type["getTextureView"] = &Fbo::getTextureView;
    fbo_type["getSampler"] = &Fbo::getSampler;
}

struct Colors{};

void tcxLua::setColorConstBindings(const std::shared_ptr<sol::state>& lua){
    auto&& l = *lua;
    sol::usertype<Colors> colors_type = lua->new_usertype<Colors>("colors");
    colors_type["white"] = sol::var(colors::white);
    colors_type["black"] = sol::var(colors::black);
    colors_type["red"] = sol::var(colors::red);
    colors_type["green"] = sol::var(colors::green);
    colors_type["blue"] = sol::var(colors::blue);
    colors_type["yellow"] = sol::var(colors::yellow);
    colors_type["cyan"] = sol::var(colors::cyan);
    colors_type["magenta"] = sol::var(colors::magenta);
    colors_type["transparent"] = sol::var(colors::transparent);
    colors_type["gray"] = sol::var(colors::gray);
    colors_type["darkGray"] = sol::var(colors::darkGray);
    colors_type["dimGray"] = sol::var(colors::dimGray);
    colors_type["lightGray"] = sol::var(colors::lightGray);
    colors_type["silver"] = sol::var(colors::silver);
    colors_type["gainsboro"] = sol::var(colors::gainsboro);
    colors_type["whiteSmoke"] = sol::var(colors::whiteSmoke);
    colors_type["darkRed"] = sol::var(colors::darkRed);
    colors_type["fireBrick"] = sol::var(colors::fireBrick);
    colors_type["crimson"] = sol::var(colors::crimson);
    colors_type["indianRed"] = sol::var(colors::indianRed);
    colors_type["lightCoral"] = sol::var(colors::lightCoral);
    colors_type["salmon"] = sol::var(colors::salmon);
    colors_type["darkSalmon"] = sol::var(colors::darkSalmon);
    colors_type["lightSalmon"] = sol::var(colors::lightSalmon);
    colors_type["orange"] = sol::var(colors::orange);
    colors_type["darkOrange"] = sol::var(colors::darkOrange);
    colors_type["orangeRed"] = sol::var(colors::orangeRed);
    colors_type["tomato"] = sol::var(colors::tomato);
    colors_type["coral"] = sol::var(colors::coral);
    colors_type["gold"] = sol::var(colors::gold);
    colors_type["goldenRod"] = sol::var(colors::goldenRod);
    colors_type["darkGoldenRod"] = sol::var(colors::darkGoldenRod);
    colors_type["paleGoldenRod"] = sol::var(colors::paleGoldenRod);
    colors_type["lightGoldenRodYellow"] = sol::var(colors::lightGoldenRodYellow);
    colors_type["khaki"] = sol::var(colors::khaki);
    colors_type["darkKhaki"] = sol::var(colors::darkKhaki);
    colors_type["lime"] = sol::var(colors::lime);
    colors_type["limeGreen"] = sol::var(colors::limeGreen);
    colors_type["lightGreen"] = sol::var(colors::lightGreen);
    colors_type["paleGreen"] = sol::var(colors::paleGreen);
    colors_type["darkGreen"] = sol::var(colors::darkGreen);
    colors_type["forestGreen"] = sol::var(colors::forestGreen);
    colors_type["seaGreen"] = sol::var(colors::seaGreen);
    colors_type["mediumSeaGreen"] = sol::var(colors::mediumSeaGreen);
    colors_type["darkSeaGreen"] = sol::var(colors::darkSeaGreen);
    colors_type["lightSeaGreen"] = sol::var(colors::lightSeaGreen);
    colors_type["springGreen"] = sol::var(colors::springGreen);
    colors_type["mediumSpringGreen"] = sol::var(colors::mediumSpringGreen);
    colors_type["greenYellow"] = sol::var(colors::greenYellow);
    colors_type["yellowGreen"] = sol::var(colors::yellowGreen);
    colors_type["chartreuse"] = sol::var(colors::chartreuse);
    colors_type["lawnGreen"] = sol::var(colors::lawnGreen);
    colors_type["olive"] = sol::var(colors::olive);
    colors_type["oliveDrab"] = sol::var(colors::oliveDrab);
    colors_type["darkOliveGreen"] = sol::var(colors::darkOliveGreen);
    colors_type["aqua"] = sol::var(colors::aqua);
    colors_type["aquamarine"] = sol::var(colors::aquamarine);
    colors_type["mediumAquaMarine"] = sol::var(colors::mediumAquaMarine);
    colors_type["darkCyan"] = sol::var(colors::darkCyan);
    colors_type["teal"] = sol::var(colors::teal);
    colors_type["lightCyan"] = sol::var(colors::lightCyan);
    colors_type["turquoise"] = sol::var(colors::turquoise);
    colors_type["mediumTurquoise"] = sol::var(colors::mediumTurquoise);
    colors_type["darkTurquoise"] = sol::var(colors::darkTurquoise);
    colors_type["paleTurquoise"] = sol::var(colors::paleTurquoise);
    colors_type["navy"] = sol::var(colors::navy);
    colors_type["darkBlue"] = sol::var(colors::darkBlue);
    colors_type["mediumBlue"] = sol::var(colors::mediumBlue);
    colors_type["royalBlue"] = sol::var(colors::royalBlue);
    colors_type["steelBlue"] = sol::var(colors::steelBlue);
    colors_type["blueSteel"] = sol::var(colors::blueSteel);
    colors_type["lightSteelBlue"] = sol::var(colors::lightSteelBlue);
    colors_type["dodgerBlue"] = sol::var(colors::dodgerBlue);
    colors_type["deepSkyBlue"] = sol::var(colors::deepSkyBlue);
    colors_type["skyBlue"] = sol::var(colors::skyBlue);
    colors_type["lightSkyBlue"] = sol::var(colors::lightSkyBlue);
    colors_type["lightBlue"] = sol::var(colors::lightBlue);
    colors_type["powderBlue"] = sol::var(colors::powderBlue);
    colors_type["cornflowerBlue"] = sol::var(colors::cornflowerBlue);
    colors_type["cadetBlue"] = sol::var(colors::cadetBlue);
    colors_type["midnightBlue"] = sol::var(colors::midnightBlue);
    colors_type["aliceBlue"] = sol::var(colors::aliceBlue);
    colors_type["purple"] = sol::var(colors::purple);
    colors_type["darkMagenta"] = sol::var(colors::darkMagenta);
    colors_type["darkViolet"] = sol::var(colors::darkViolet);
    colors_type["blueViolet"] = sol::var(colors::blueViolet);
    colors_type["indigo"] = sol::var(colors::indigo);
    colors_type["slateBlue"] = sol::var(colors::slateBlue);
    colors_type["darkSlateBlue"] = sol::var(colors::darkSlateBlue);
    colors_type["mediumSlateBlue"] = sol::var(colors::mediumSlateBlue);
    colors_type["mediumPurple"] = sol::var(colors::mediumPurple);
    colors_type["darkOrchid"] = sol::var(colors::darkOrchid);
    colors_type["mediumOrchid"] = sol::var(colors::mediumOrchid);
    colors_type["orchid"] = sol::var(colors::orchid);
    colors_type["violet"] = sol::var(colors::violet);
    colors_type["plum"] = sol::var(colors::plum);
    colors_type["thistle"] = sol::var(colors::thistle);
    colors_type["lavender"] = sol::var(colors::lavender);
    colors_type["fuchsia"] = sol::var(colors::fuchsia);
    colors_type["pink"] = sol::var(colors::pink);
    colors_type["lightPink"] = sol::var(colors::lightPink);
    colors_type["hotPink"] = sol::var(colors::hotPink);
    colors_type["deepPink"] = sol::var(colors::deepPink);
    colors_type["mediumVioletRed"] = sol::var(colors::mediumVioletRed);
    colors_type["paleVioletRed"] = sol::var(colors::paleVioletRed);
    colors_type["brown"] = sol::var(colors::brown);
    colors_type["maroon"] = sol::var(colors::maroon);
    colors_type["saddleBrown"] = sol::var(colors::saddleBrown);
    colors_type["sienna"] = sol::var(colors::sienna);
    colors_type["chocolate"] = sol::var(colors::chocolate);
    colors_type["peru"] = sol::var(colors::peru);
    colors_type["sandyBrown"] = sol::var(colors::sandyBrown);
    colors_type["burlyWood"] = sol::var(colors::burlyWood);
    colors_type["tan"] = sol::var(colors::tan);
    colors_type["rosyBrown"] = sol::var(colors::rosyBrown);
    colors_type["snow"] = sol::var(colors::snow);
    colors_type["honeyDew"] = sol::var(colors::honeyDew);
    colors_type["mintCream"] = sol::var(colors::mintCream);
    colors_type["azure"] = sol::var(colors::azure);
    colors_type["ghostWhite"] = sol::var(colors::ghostWhite);
    colors_type["floralWhite"] = sol::var(colors::floralWhite);
    colors_type["ivory"] = sol::var(colors::ivory);
    colors_type["antiqueWhite"] = sol::var(colors::antiqueWhite);
    colors_type["linen"] = sol::var(colors::linen);
    colors_type["lavenderBlush"] = sol::var(colors::lavenderBlush);
    colors_type["mistyRose"] = sol::var(colors::mistyRose);
    colors_type["oldLace"] = sol::var(colors::oldLace);
    colors_type["seaShell"] = sol::var(colors::seaShell);
    colors_type["beige"] = sol::var(colors::beige);
    colors_type["cornsilk"] = sol::var(colors::cornsilk);
    colors_type["lemonChiffon"] = sol::var(colors::lemonChiffon);
    colors_type["lightYellow"] = sol::var(colors::lightYellow);
    colors_type["wheat"] = sol::var(colors::wheat);
    colors_type["moccasin"] = sol::var(colors::moccasin);
    colors_type["peachPuff"] = sol::var(colors::peachPuff);
    colors_type["papayaWhip"] = sol::var(colors::papayaWhip);
    colors_type["blanchedAlmond"] = sol::var(colors::blanchedAlmond);
    colors_type["bisque"] = sol::var(colors::bisque);
    colors_type["navajoWhite"] = sol::var(colors::navajoWhite);
    colors_type["slateGray"] = sol::var(colors::slateGray);
    colors_type["lightSlateGray"] = sol::var(colors::lightSlateGray);
    colors_type["darkSlateGray"] = sol::var(colors::darkSlateGray);
}

void tcxLua::setMathBindings(const std::shared_ptr<sol::state>& lua){
    auto&& l = *lua;
    lua->set_function("sin", [](float v){ return sin(v); });
    lua->set_function("cos", [](float v){ return cos(v); });
    lua->set_function("tan", [](float v){ return tan(v); });
    lua->set_function("atan", [](float v){ return atan(v); });
    lua->set_function("atan2", [](float a, float b){ return atan2(a, b); });
    lua->set_function("atanh", [](float v){ return atanh(v); });
    lua->set_function("sqrt", [](float v){ return sqrt(v); });
    lua->set_function("tanh", [](float v){ return tanh(v); });
    lua->set_function("acos", [](float v){ return acos(v); });
    lua->set_function("asin", [](float v){ return asin(v); });

    lua->set_function("exp", [](float v){ return exp(v); });
    lua->set_function("exp2", [](float v){ return exp2(v); });
    lua->set_function("abs", [](float v){ return fabs(v); });

    lua->set_function("log", [](float v){ return log(v); });
    lua->set_function("log2", [](float v){ return log2(v); });
    lua->set_function("log10", [](float v){ return log10(v); });

    lua->set_function("ceil", [](float v){ return ceil(v); });
    lua->set_function("floor", [](float v){ return floor(v); });
    lua->set_function("round", [](float v){ return round(v); });
    lua->set_function("trunc", [](float v){ return trunc(v); });

    lua->set_function("pow", [](float a, float b){ return pow(a, b); });
    lua->set_function("remainder", [](float a, float b){ return remainder(a, b); });

    lua->set_function("fmod", [](float a, float b){ return fmod(a, b); });
    lua->set_function("max", [](float a, float b){ return std::max(a, b); });
    lua->set_function("min", [](float a, float b){ return std::min(a, b); });
}

// } // namespace tcx::lua
