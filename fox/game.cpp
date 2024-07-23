#include "game.h"

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include <gui/idle_box.h>

using namespace std::chrono_literals;
using namespace fox;

fox::game::game(settings settings) : m_settings(std::move(settings)) {}

auto fox::game::run() -> void {

    InitWindow(m_settings.screen_width, m_settings.screen_height, "Fragments of Xyn");
    SetTargetFPS(m_settings.target_fps);

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
}


auto fox::game::update() -> void {}


auto fox::game::draw() -> void {

    auto progress = 0ms;
    const auto max_progress = 10000ms;

    BeginDrawing();
    ClearBackground(GetColor(static_cast<unsigned int>(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))));

    progress += std::chrono::milliseconds{static_cast<long long>(GetFrameTime() * 1000)};
    progress %= max_progress;
    const auto info = model::duration_info{};

    gui::draw_idle_box(
        gui::idle_box_data{
            .name = "Bronze",
            .duration_info = std::cref(info),
            .progress = progress,
            .duration = max_progress,
        },
        {});

    EndDrawing();
}
