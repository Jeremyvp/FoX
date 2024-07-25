#pragma once

#include "transform.h"
#include <raylib.h>

namespace fox::components {

struct drawable {
    const transform* transform;
    Texture2D texture;
};

void draw(const drawable& drawable);

} // namespace fox::components
