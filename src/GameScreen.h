#pragma once

#include "Screen.h"

namespace Game {
    class GameScreen : public Screen {
        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
