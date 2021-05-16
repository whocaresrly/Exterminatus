#pragma once

#include "Screen.h"

namespace Game {
    class StoryScreen : public Screen {
    private:
        StoryScreen();
        Texture2D backgroundTexture;
        Texture2D text;
    public:
        static Screen* getInstance() {
            static StoryScreen instance;
            return &instance;
        }
       
        StoryScreen(StoryScreen const&) = delete;

        void operator=(StoryScreen const&) = delete;

        ~StoryScreen();

        void ProcessInput() override;

        void Update() override;

        void Draw() override;
    };
}
