#pragma once

#include <vector>
#include <memory>

#include "raylib.h"

#include "Screen.h"
#include "Sprite.h"
#include "math.h"
#include "Entity.h"


#define NUM_SHOOTS 10
#define NUM_MAX_ENEMIES 10


namespace Game {
    class GameScreen : public Screen {
    private:
        std::vector<std::unique_ptr<Sprite>> sprites;

        GameScreen();

    private:
        Texture2D playerTexture;
        Texture2D alienTexture;
        Texture2D backgroundTexture;
        Texture2D marsTexture;
        Texture2D earthTexture;
        Texture2D enemyBigTexture;

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
    static hPlanet hplanet;
    static Player player;
    static Bullet bullet[NUM_SHOOTS];
    static Enemy enemy[NUM_MAX_ENEMIES];
    static Enemy enemyBig[NUM_MAX_ENEMIES];
    static int activeEnemies;
    static int activeEnemiesBig;
    static int people;
    static int score;
}
