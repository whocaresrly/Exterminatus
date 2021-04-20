#include "raylib.h"

#include "GameScreen.h"
#include "MenuScreen.h"
#include "game.h"

Game::GameScreen::GameScreen() {
    // Your screen initialization code here...
    this->textures.push_back(LoadTexture("assets/graphics/testimage.png"));
}

Game::GameScreen::~GameScreen() {
    // Your screen cleanup code here...
    for (Texture2D texture : this->textures)
        UnloadTexture(texture);
}

void Game::GameScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = Game::MenuScreen::getInstance();
}

void Game::GameScreen::Update() {
    // Your update game code here...
}

void Game::GameScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawText("Game - press ENTER for menu", 10, 10, 30, LIGHTGRAY);

    for (Texture2D texture : this->textures)
        DrawTexture(texture, 100, 100, RAYWHITE);
}
