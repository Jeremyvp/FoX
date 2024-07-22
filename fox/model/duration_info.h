#pragma once

#include <string>
#include <vector>

namespace fox::model {

struct duration_reduction {
    float percent;
    std::string description;
};

using duration_info = std::vector<duration_reduction>;

} // namespace fox::model
