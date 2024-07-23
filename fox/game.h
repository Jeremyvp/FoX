#pragma once

namespace fox {

struct settings {
    int screen_width = 1280;
    int screen_height = 720;
    int target_fps = 60;
};

class game {
  public:
    game() = default;
    game(settings);

    auto run() -> void;

  private:
    auto update() -> void;
    auto draw() -> void;

    settings m_settings;
};

} // namespace fox
