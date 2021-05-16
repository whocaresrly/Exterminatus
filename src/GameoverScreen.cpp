#include "raylib.h"

#include "MenuScreen.h"
#include "GameScreen.h"
#include "game.h"

Game::GameoverScreen::GameoverScreen() {
    backgroundTexture = LoadTexture("assets/graphics/Background_Space_Test_1.2.png");
}

Game::GameoverScreen::~GameoverScreen() {
    
}


void Game::GameoverScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = Game::MenuScreen::getInstance();
}

void Game::GameoverScreen::Update() {
    // Your update game code here...
}

void Game::GameoverScreen::Draw() {
    extern int score;
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawText("Game Over!", 160, 470, 50, RAYWHITE);
    DrawText("Press Enter to proceed...", 145, 550, 25, RAYWHITE);
}
