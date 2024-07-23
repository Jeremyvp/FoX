#pragma once

#include <chrono>

namespace fox::components {

struct idler_component {
    std::chrono::milliseconds progress;
    std::chrono::milliseconds base_duration;
    std::chrono::milliseconds duration_cap;
    bool is_active{};
};

auto update(std::chrono::milliseconds delta, idler_component& idler, float percent_speedup,
            std::chrono::milliseconds flat_speedup) {

    using namespace std::chrono;

    idler.progress += delta;

    const auto percent_duration = milliseconds{
        static_cast<milliseconds::rep>(idler.base_duration.count() * percent_speedup / 100)};
    const auto adjusted_duration = std::max(percent_duration - flat_speedup, idler.duration_cap);

    if (idler.progress >= adjusted_duration) {
        idler.progress -= adjusted_duration;
        return true;
    }
    return false;
}

} // namespace fox::components
