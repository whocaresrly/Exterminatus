#pragma once

#include "raylib.h"
#include <iostream>

namespace Game {
    struct Sprite {
        Vector2 pos;
        Texture2D texture;
        bool visible;

        Sprite(Texture2D texture, Vector2 pos, bool visible) : texture(texture), pos(pos), visible(visible) {}

        ~Sprite() { UnloadTexture(this->texture); }
    };
}
