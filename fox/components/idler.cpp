#include "idler.h"

auto fox::components::update(idler_component& idler,
                             std::chrono::milliseconds delta,
                             float multiplier_speedup,
                             std::chrono::milliseconds flat_speedup) -> void {

    using namespace std::chrono;

    idler.progress += delta;

    const auto percent_duration = milliseconds{
        static_cast<milliseconds::rep>(idler.base_duration.count() / multiplier_speedup)};
    const auto adjusted_duration = std::max(percent_duration - flat_speedup, idler.duration_cap);

    if (idler.progress >= adjusted_duration) {
        idler.progress -= adjusted_duration;
    }
}

