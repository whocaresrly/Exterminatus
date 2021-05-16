#pragma once
#include "raylib.h"
#include "math.h"

//Bullet Klasse 
typedef struct Bullet
{
    Rectangle rect;
    Vector2 speed;
    bool active;
    Color color;
    //Texture2D texture{};
} Bullet;

typedef struct hPlanet
{
    Vector2 center;

} hPlanet;

//Player Klasse
typedef struct Player
{
    Rectangle rect;
    Vector2 speed;
    Color color;
    int lives;
} Player;

//Enemy Klasse 
typedef struct Enemy
{
    Rectangle rect;
    Vector2 speed;
    bool active;
    bool hit;
    Color color;
    Texture2D texture{};
} Enemy;
