#include "idle_box.h"

#include <raygui.h>
#include <raylib.h>

auto fox::gui::draw_idle_box(const components::idler& data,
                             const Rectangle& rectangle) -> void {
    auto value = static_cast<float>(data.progress.count());
    const auto max = static_cast<float>(data.base_duration.count());

    GuiGroupBox(rectangle, "Bronze!");
    GuiProgressBar(Rectangle{.x = 125, .y = 160, .width = 150, .height = 20}, "", "", &value, 0,
                   max);

}

