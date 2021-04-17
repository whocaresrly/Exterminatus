#include "raylib.h"

#include "game.h"
#include "GameScreen.h"

void Game::GameScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = &menuScreen;
}

void Game::GameScreen::Update() {
    // Your update game code here...
}

void Game::GameScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawText("Game - press ENTER for menu", 10, 10, 30, LIGHTGRAY);
}
