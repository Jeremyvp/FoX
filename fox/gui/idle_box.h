#pragma once

#include <chrono>
#include <model/duration_info.h>
#include <components/idler.h>
#include <raylib.h>

class Rectangle;

namespace fox::gui {

using namespace fox;

auto draw_idle_box(const components::idler& data, const Rectangle& rectangle) -> void;

} // namespace fox::gui
