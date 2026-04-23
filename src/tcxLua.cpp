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

    vec2_type["length"] = &Vec2::length;
    vec2_type["lengthSquared"] = &Vec2::lengthSquared;
    vec2_type["normalized"] = &Vec2::normalized;
    vec2_type["normalize"] = &Vec2::normalize;
    vec2_type["limit"] = &Vec2::limit;
    vec2_type["dot"] = &Vec2::dot;
    vec2_type["cross"] = &Vec2::cross;
    vec2_type["distance"] = &Vec2::distance;
    vec2_type["distanceSquared"] = &Vec2::distanceSquared;
    // TODO: implement
    // vec2_type["angle"] = sol::overload(
    //     [](){ return Vec2::angle(); },
    //     [](const Vec2& v){ return Vec2::angle(v); }
    // );
    vec2_type["rotated"] = &Vec2::rotated;
    vec2_type["rotate"] = &Vec2::rotate;
    vec2_type["lerp"] = &Vec2::lerp;
    vec2_type["perpendicular"] = &Vec2::perpendicular;
    vec2_type["reflected"] = &Vec2::reflected;
    vec2_type["fromAngle"] = &Vec2::fromAngle;

    sol::usertype<Vec3> vec3_type = lua->new_usertype<Vec3>("Vec3",
        sol::constructors<Vec3(), Vec3(float, float, float), Vec3(const Vec2&), Vec3(const Vec3&)>()
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