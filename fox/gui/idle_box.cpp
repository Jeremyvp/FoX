#include "idle_box.h"

#include <raygui.h>
#include <raylib.h>

auto fox::gui::draw_idle_box(const idle_box_data& data, const Rectangle& rectangle) -> void {
    auto value = static_cast<float>(data.progress.count());
    const auto max = static_cast<float>(data.duration.count());

    GuiGroupBox(rectangle, data.name.c_str());
    GuiProgressBar(Rectangle{.x = 125, .y = 160, .width = 150, .height = 20}, "", "", &value, 0,
                   max);
}
