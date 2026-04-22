#pragma once

#include "sol/sol.hpp"

// namespace tcx::lua {

class tcxLua {
public:
    sol::state getLuaState();
};

// } // namespace tcx::lua