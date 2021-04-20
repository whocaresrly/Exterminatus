#pragma once

#include <vector>

#include "raylib.h"

#include "Screen.h"

namespace Game {
    class GameScreen : public Screen {
    private:
        std::vector<Texture2D> textures;

        GameScreen();

    public:
        static Screen *getInstance() {
            static GameScreen instance;
            return &instance;
        }

        GameScreen(GameScreen const &) = delete;

        void operator=(GameScreen const &) = delete;

        ~GameScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
