#include "raylib.h"

#include "GameScreen.h"
#include "MenuScreen.h"
#include "GameoverScreen.h"
#include "GamefinishedScreen.h"
#include "game.h"


Game::GameScreen::GameScreen() {
    
    // Load textures
    playerTexture = LoadTexture("assets/graphics/Ship_Player_Final_64x64_1.6.png");
    backgroundTexture = LoadTexture("assets/graphics/Background_Space_Test_1.2.png");
    alienTexture = LoadTexture("assets/graphics/Ship_NPC_Final_63x52.png");
    marsTexture = LoadTexture("assets/graphics/Background_Mars_Final__LowerHalf_1.9.2.png");
    earthTexture = LoadTexture("assets/graphics/Background_Mars_Final__Upperhalf_2.1.1.png");
    enemyBigTexture = LoadTexture("assets/graphics/Ship_NPC_Final_118x105.png");

    // Spieler (Viereck) initialisieren
    player.rect.x = 600 / 2.0f;
    player.rect.y = 1000 - 250;
    player.rect.width = 35;
    player.rect.height = 35;
    player.speed.x = 7;
    player.speed.y = 5;
    player.color = WHITE;
    player.lives = 3;

    // Bullets initialisieren

    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        bullet[i].rect.x = player.rect.x + 29;                  //Bullet zentrieren
        bullet[i].rect.y = player.rect.y + player.rect.height / 4;
        bullet[i].rect.width = 5;
        bullet[i].rect.height = 10;
        bullet[i].speed.y = -10;
        bullet[i].active = false;
        bullet[i].color = MAROON;
    }


    //variables 
    activeEnemies = 3;
    activeEnemiesBig = 1;
    people = 0;
    score = 0;
    // Gegner initialisieren

    //Welle 1
  
    //klein
    for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].rect.width = 63;
        enemy[i].rect.height = 52;
        enemy[i].rect.x = GetRandomValue(0, 600- 64);
        enemy[i].rect.y = GetRandomValue(-1000, -20);
        enemy[i].speed.y = 5; //Geschwindigkeit Gegner
        enemy[i].active = true;
    }
    //groß
    for (int i = 0; i < activeEnemiesBig; i++)
    {
        enemyBig[i].rect.width = 118;
        enemyBig[i].rect.height = 105;
        enemyBig[i].rect.x = GetRandomValue(0, 600 - 118);
        enemyBig[i].rect.y = GetRandomValue(-200, -20);
        enemyBig[i].speed.y = 2.5; //Geschwindigkeit Gegner
        enemyBig[i].active = true;
        enemyBig[i].hit = false;
    }
    //Home planet init
    hplanet.center.x = 600 / 2;
    hplanet.center.y = 1190;
  

  }


Game::GameScreen::~GameScreen() {
    // Your screen cleanup code here...
    UnloadTexture(alienTexture);
    

}


void Game::GameScreen::ProcessInput() {
    // Your process input code here...
    if (IsKeyPressed(KEY_M)) currentScreen = Game::MenuScreen::getInstance();

    // Spieler bewegen (links-rechts)
    if (IsKeyDown(KEY_RIGHT))
        player.rect.x += player.speed.x;
    if (IsKeyDown(KEY_LEFT))
        player.rect.x -= player.speed.x;

    
   


}

void Game::GameScreen::Update() {
    // Your update game code here...
    if ((player.rect.x + 58) >= 600) player.rect.x = 600 - 58;           //Spieler an Wänden einschränken
    else if (player.rect.x <= -6) player.rect.x = -6;

    //Bullets
    if (IsKeyPressed(KEY_SPACE)) {

        for (int i = 0; i < NUM_SHOOTS; i++)
        {
            if (!bullet[i].active)
            {
                // Movement
                bullet[i].rect.y += bullet[i].speed.y;

                bullet[i].rect.x = player.rect.x + 29;                 //Bullet zentrieren
                bullet[i].rect.y = player.rect.y + player.rect.height / 4;
                bullet[i].active = true;
                break;
            }
            if (bullet[i].rect.y <= 0)
            {
                bullet[i].active = false;

            }
        }
    }



    // Shoot logic
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        if (bullet[i].active)
        {
            // Movement
            bullet[i].rect.y += bullet[i].speed.y;

            // Collision with enemy
            for (int j = 0; j < activeEnemies || j < activeEnemiesBig; j++)
            {
                if (enemy[j].active || enemyBig[i].active)
                {
                    if (CheckCollisionRecs(bullet[i].rect, enemy[j].rect))
                    {

                        bullet[i].active = false;
                        enemy[j].rect.x = GetRandomValue(0, 530);
                        enemy[j].rect.y = GetRandomValue(-1000, 0 - enemy[j].rect.height);
                        score++;
                    }

                    if (enemyBig[j].hit == true)
                    {
                        if (CheckCollisionRecs(bullet[i].rect, enemyBig[j].rect))
                        {
                            bullet[i].active = false;
                            enemyBig[j].rect.x = GetRandomValue(0, 480);
                            enemyBig[j].rect.y = GetRandomValue(-1000, 0 - enemyBig[j].rect.height);
                            enemyBig[j].hit = false;
                            score++;
                        }

                    }
                    if (CheckCollisionRecs(bullet[i].rect, enemyBig[j].rect))
                    {

                        bullet[i].active = false;
                        enemyBig[j].hit = true;

                    }

                   
                }


            }
        }
    }
    
    //Collision Player and Enemy
    for (int j = 0; j < activeEnemies || j < activeEnemiesBig; j++)
    {
        if (enemy[j].active || enemyBig[j].active)
        {
            if (CheckCollisionRecs(player.rect, enemy[j].rect))
            {
                enemy[j].rect.x = GetRandomValue(0, 536);      //Spawnbereich neuer Gegner x
                enemy[j].rect.y = GetRandomValue(0, -400);     //Spawnbereich neuer Gegner y
                player.lives--;
            }
            if (CheckCollisionRecs(player.rect, enemyBig[j].rect))
            {
                enemyBig[j].rect.x = GetRandomValue(0, 536);      //Spawnbereich neuer Gegner x
                enemyBig[j].rect.y = GetRandomValue(-200, -20);     //Spawnbereich neuer Gegner y
                player.lives--;
            }

        }
    }








    // Enemy Verhalten
    for (int i = 0; i < activeEnemies || i < activeEnemiesBig; i++)
    {
        if (enemy[i].active)
        {
            enemy[i].rect.y += enemy[i].speed.y;

            if (CheckCollisionCircleRec(hplanet.center, 350, enemy[i].rect))
            {
                enemy[i].rect.x = GetRandomValue(0, 600 - 100);
                enemy[i].rect.y = GetRandomValue(-1000, -20);
                people += 500;
            }
        }
        if (enemyBig[i].active)
        {
            enemyBig[i].rect.y += enemyBig[i].speed.y;

            if (CheckCollisionCircleRec(hplanet.center, 350, enemyBig[i].rect))
            {
                enemyBig[i].rect.x = GetRandomValue(0, 600 - 100);
                enemyBig[i].rect.y = GetRandomValue(-1000, -20);
                people += 1000;
            }
        } 
    }
    //active enemy change
    if (score == 50) {
        activeEnemies = 5;
    }
    
    if (score == 100) {
        activeEnemies = 6;
    }
    //Screen Change und variable reset
    if (player.lives == 0 || people == 10000) {
        currentScreen = Game::GameoverScreen::getInstance();
        score = 0;
        player.lives = 3;
        people = 0;
        activeEnemies = 4;
    }
    if (score == 200) {
        currentScreen = Game::GamefinishedScreen::getInstance();
        score = 0;
        player.lives = 3;
        people = 0;
        activeEnemies = 4;
    }
}



void Game::GameScreen::Draw() {
    // Your drawing code here...
    ClearBackground(LIGHTGRAY);
    //Background
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawTexture(marsTexture, 20, 800, WHITE);
    DrawTexture(earthTexture, 20, -50, WHITE);


    DrawText( TextFormat("People: %i /10.000", people), 10, 945, 20, RAYWHITE);
    DrawText(TextFormat("Lives: %i", player.lives), 10, 960, 20, RAYWHITE);
    DrawText(TextFormat("Score: %i", score), 10, 975, 20, RAYWHITE);
    // Draw Player
    DrawTexture(playerTexture, player.rect.x, player.rect.y, WHITE);
    // Draw Enemy
    for (int i = 0; i < activeEnemiesBig; i++)
    {
        if (enemyBig[i].active)
            DrawTexture(enemyBigTexture, enemyBig[i].rect.x, enemyBig[i].rect.y, WHITE);
    }

     for (int i = 0; i < activeEnemies; i++)
     {
         if (enemy[i].active)
             DrawTexture(alienTexture, enemy[i].rect.x, enemy[i].rect.y, WHITE);       
     }

     //DrawCircle(GetScreenWidth() / 2, 1190, 350, RED);

     //Draw Bullet
     for (int i = 0; i < NUM_SHOOTS; i++)
     {
         if (bullet[i].active)
             DrawRectangleRec(bullet[i].rect, bullet[i].color);
     }

    
     


}

