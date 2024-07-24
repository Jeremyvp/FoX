#pragma once

#include <chrono>

namespace fox::components {

struct idler_component {
    std::chrono::milliseconds progress{};
    std::chrono::milliseconds base_duration{};
    std::chrono::milliseconds duration_cap{};
    bool is_active{};
};

auto update(idler_component& idler,
            std::chrono::milliseconds delta,
            float percent_speedup,
            std::chrono::milliseconds flat_speedup) -> void;

} // namespace fox::components
