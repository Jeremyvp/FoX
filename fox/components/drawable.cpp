#include "drawable.h"

void fox::components::draw(const drawable& drawable) {
    DrawTextureEx(drawable.texture,
                  drawable.transform->position,
                  drawable.transform->rotation,
                  drawable.transform->scale.x,
                  WHITE);
}

