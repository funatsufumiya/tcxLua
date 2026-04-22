#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"

// namespace tcx::lua {

void tcxLua::simpleCallTest() {
    // std::cout << "hello from tcxLua" << std::endl;
    sol::state lua;
    // lua.open_libraries(sol::lib::base, sol::lib::jit);
    lua.open_libraries(sol::lib::base);
    sol::optional<sol::error> result = lua.safe_script("print(\"Hello from Lua!\")");
	if (result.has_value()) {
		std::cerr << "[tcxLua] Lua execution failed: "
		          << result.value().what() << std::endl;
	}
}

// } // namespace tcx::lua