#pragma once

#include "sol/sol.hpp"

// namespace tcx::lua {

class tcxLua {
public:
    std::shared_ptr<sol::state> getLuaState();

protected:
    void setBindings(const std::shared_ptr<sol::state>& lua);
    void setTrussCGeneratedBindings(const std::shared_ptr<sol::state>& lua);
};

// } // namespace tcx::lua