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
        sol::constructors<Vec2(), Vec2(float, float), Vec2(Vec2)>()
    );
    vec2_type["x"] = &Vec2::x;
    vec2_type["y"] = &Vec2::y;

    sol::usertype<Vec3> vec3_type = lua->new_usertype<Vec3>("Vec3",
        sol::constructors<Vec3(), Vec3(float, float, float), Vec3(Vec2), Vec3(Vec3)>()
    );
    vec3_type["x"] = &Vec3::x;
    vec3_type["y"] = &Vec3::y;
    vec3_type["z"] = &Vec3::z;
}

// } // namespace tcx::lua