#pragma once

#include "Screen.h"

namespace Game {
    class GameoverScreen : public Screen {
    private:
        GameoverScreen();
        Texture2D backgroundTexture;
    public:
        static Screen* getInstance() {
            static GameoverScreen instance;
            return &instance;
        }

        GameoverScreen(GameoverScreen const&) = delete;

        void operator=(GameoverScreen const&) = delete;

        ~GameoverScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
