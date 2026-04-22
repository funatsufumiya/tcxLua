#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"

// namespace tcx::lua {

sol::state tcxLua::getLuaState(){
    sol::state lua;

    // lua.open_libraries(sol::lib::base, sol::lib::jit);
    lua.open_libraries(sol::lib::base);

    return lua;
}

// } // namespace tcx::lua