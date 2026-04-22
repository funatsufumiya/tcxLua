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
    // lua->set_function("clear", sol::overload( &trussc::clear ));
    // lua->set_function("clear", &trussc::clear);

    lua->set_function("clear", sol::overload(
        [](){ trussc:clear(); },
        [](float gray, float a){ trussc:clear(gray, a); },
        [](float gray){ trussc:clear(gray, 1.0f); },
        [](const Color& c){ trussc:clear(c); }
    ));

}

// } // namespace tcx::lua