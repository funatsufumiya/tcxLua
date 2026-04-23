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
        sol::constructors<Vec2(), Vec2(float, float), Vec2(const Vec2&)>()
    );
    vec2_type["x"] = &Vec2::x;
    vec2_type["y"] = &Vec2::y;

    sol::usertype<Vec3> vec3_type = lua->new_usertype<Vec3>("Vec3",
        sol::constructors<Vec3(), Vec3(float, float, float), Vec3(const Vec2&), Vec3(const Vec3&)>()
    );
    vec3_type["x"] = &Vec3::x;
    vec3_type["y"] = &Vec3::y;
    vec3_type["z"] = &Vec3::z;

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
}

// } // namespace tcx::lua