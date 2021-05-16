#include "raylib.h"

#include "MenuScreen.h"
#include "GameScreen.h"
#include "StoryScreen.h"
#include "game.h"

Game::StoryScreen::StoryScreen() {
    backgroundTexture = LoadTexture("assets/graphics/Background_Space_Test_1.2.png");
    text = LoadTexture("assets/graphics/story_text.png");
}

Game::StoryScreen::~StoryScreen() {
    // Your screen cleanup code here...
}


void Game::StoryScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_ENTER)) currentScreen = Game::GameScreen::getInstance();
}

void Game::StoryScreen::Update() {
    // Your update game code here...
}

void Game::StoryScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawTexture(text, 0, 0, WHITE);
    DrawText("Press Enter to Proceed", 110, 900, 30, RAYWHITE);
}
