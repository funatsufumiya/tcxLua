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

    // lua->set_function("clear", sol::overload( &trussc::clear ));
    // lua->set_function("clear", &trussc::clear);

    // lua->set_function("clear", sol::overload(
    //     [](){ trussc:clear(); },
    //     [](float gray, float a){ trussc:clear(gray, a); },
    //     [](float gray){ trussc:clear(gray, 1.0f); },
    //     [](const Color& c){ trussc:clear(c); }
    // ));

    // lua->set_function("noFill", &trussc::noFill);

    // lua->set_function("getWindowWidth", &trussc::getWindowWidth);
    // lua->set_function("getWindowHeight", &trussc::getWindowHeight);
    lua->set_function("getElapsedTimef", &trussc::getElapsedTimef);

    // lua->set_function("rotate", sol::overload(
    //     [](float radians){ trussc:rotate(radians); },
    //     [](float x, float y, float z){ trussc:rotate(x, y, z); },
    //     [](const Vec3& euler){ trussc:rotate(euler); },
    //     [](const Quaternion& quot){ trussc:rotate(quot); }
    // ));

    // lua->set_function("translate", sol::overload(
    //     [](float x, float y){ trussc:translate(x, y); },
    //     [](float x, float y, float z){ trussc:translate(x, y, z); },
    //     [](Vec3 pos){ trussc:translate(pos); }
    // ));

    // lua->set_function("drawBox", sol::overload(
    //     [](float size){ trussc:drawBox(size); },
    //     [](Vec3 pos, float w, float h, float d){
    //         trussc:drawBox(pos, w, h, d);
    //     },
    //     [](float x, float y, float z, float w, float h, float d){
    //         trussc:drawBox(x, y, z, w, h, d);
    //     },
    //     [](Vec3 pos, float size){
    //         trussc:drawBox(pos, size);
    //     },
    //     [](float x, float y, float z, float size){
    //         trussc:drawBox(x, y, z, size);
    //     },
    //     [](float x, float h, float d){
    //         trussc:drawBox(x, h, d);
    //     }
    // ));

}

// } // namespace tcx::lua