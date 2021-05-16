#pragma once

#include "Screen.h"

namespace Game {
    class GamefinishedScreen : public Screen {
    private:
        GamefinishedScreen();
    public:
        static Screen* getInstance() {
            static GamefinishedScreen instance;
            return &instance;
        }

        GamefinishedScreen(GamefinishedScreen const&) = delete;

        void operator=(GamefinishedScreen const&) = delete;

        ~GamefinishedScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
