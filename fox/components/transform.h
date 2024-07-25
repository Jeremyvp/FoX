#pragma once

#include <raylib.h>

namespace fox::components {

using radians = float;

struct transform {
    Vector2 position{};
    Vector2 scale{};
    radians rotation = 0.f;
};

}

