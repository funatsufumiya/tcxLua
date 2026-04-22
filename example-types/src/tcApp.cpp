#include "tcApp.h"

void tcApp::setup() {
    lua = tcx_lua.getLuaState();

    std::string setupLuaSource = R"LUA(
        local v = Vec2.new(1.0, 2.0)
        print("v.x = " .. v.x)
        print("v.y = " .. v.y)
    )LUA";

    sol::optional<sol::error> result = lua->safe_script(setupLuaSource);
	if (result.has_value()) {
		std::cerr << "Lua execution failed: "
		          << result.value().what() << std::endl;
	}
}

void tcApp::update() {

}

void tcApp::draw() {
    if(isFirstDraw){
        std::string drawLuaSource = R"LUA(
            function draw()
                clear(0.12, 1.0)

                -- Rotating box
                noFill()
                p = Vec3.new(getWindowWidth() / 2, getWindowHeight() / 2, 0)
                translate(p)
                rotate(getElapsedTimef() * 0.1, getElapsedTimef() * 0.15, 0);
                drawBox(200.0)
            end
        )LUA";

        lua->script(drawLuaSource);

        isFirstDraw = false;
    }

    lua->script("draw()");
}

void tcApp::keyPressed(int key) {}
void tcApp::keyReleased(int key) {}

void tcApp::mousePressed(Vec2 pos, int button) {}
void tcApp::mouseReleased(Vec2 pos, int button) {}
void tcApp::mouseMoved(Vec2 pos) {}
void tcApp::mouseDragged(Vec2 pos, int button) {}
void tcApp::mouseScrolled(Vec2 delta) {}

void tcApp::windowResized(int width, int height) {}
void tcApp::filesDropped(const vector<string>& files) {}
void tcApp::exit() {}
