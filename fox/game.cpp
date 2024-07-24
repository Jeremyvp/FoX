#include "game.h"
#include "components/idler.h"

#include <chrono>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include <gui/idle_box.h>

using namespace std::chrono_literals;
using namespace std::chrono;
using namespace fox;

fox::game::game(settings settings) : m_settings(std::move(settings)) {}

auto fox::game::run() -> void {

    InitWindow(m_settings.screen_width, m_settings.screen_height, "Fragments of Xyn");
    SetTargetFPS(m_settings.target_fps);

    m_component_system.add_component(components::idler_component{.base_duration = 3'000ms});

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
}

auto fox::game::update() -> void {
    const auto delta = milliseconds{static_cast<milliseconds::rep>(GetFrameTime() * 1'000)};
    m_component_system.update_components<components::idler_component>(delta, 1.f, 0ms);
}

auto fox::game::draw() -> void {

    BeginDrawing();
    ClearBackground(GetColor(static_cast<unsigned int>(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))));

    for (const auto& idler : m_component_system.get_components<components::idler_component>())
        gui::draw_idle_box(idler, {100, 100, 500, 500});

    EndDrawing();
}
