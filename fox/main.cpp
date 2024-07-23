#include "game.h"

int main() {
    auto game = fox::game{fox::settings{}};
    game.run();
}
