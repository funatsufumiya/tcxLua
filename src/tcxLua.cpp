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

    lua->set_function("getElapsedTimef", &trussc::getElapsedTimef);
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
        sol::constructors<Quaternion(), Quaternion(float, float, float, float), Quaternion(const Quaternion&)>()
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
            Mat4(const Mat4&)>()
    );
    mat4_type["at"] = [](Mat4& m, int raw, int col) -> float { return (float)(m.at(raw, col)); }; // WORKAROUND
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
    
}

// } // namespace tcx::lua