#include "gui/idle_box.h"
#include "model/duration_info.h"

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include <gui/idle_box.h>

using namespace std::chrono_literals;
using namespace fox;

int main() {
    InitWindow(400, 200, "raygui - controls test suite");
    SetTargetFPS(60);

    auto progress = 0ms;
    const auto max_progress = 10000ms;

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(
            GetColor(static_cast<unsigned int>(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))));

        progress += std::chrono::milliseconds{static_cast<long long>(GetFrameTime() * 1000)};
        progress %= max_progress;
        const auto info = model::duration_info{};

        gui::draw_idle_box(gui::idle_box_data{
            .name = "Bronze",
            .duration_info = std::cref(info),
            .progress = progress,
            .duration = max_progress,
        }, {});

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
