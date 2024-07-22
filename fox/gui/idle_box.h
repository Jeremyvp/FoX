#pragma once

#include <chrono>
#include <model/duration_info.h>
#include <raylib.h>

class Rectangle;

namespace fox::gui {

using namespace fox;

struct idle_box_data {
    std::string name;
    std::reference_wrapper<const model::duration_info> duration_info;
    std::chrono::milliseconds progress;
    std::chrono::milliseconds duration;
    float multiplier{};
    bool is_active{};
};

auto draw_idle_box(const idle_box_data& data, const Rectangle& rectangle) -> void;

} // namespace fox::gui
