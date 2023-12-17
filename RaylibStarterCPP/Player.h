#pragma once
#include "raylib.h"

class Ball;

class Player
{
public:
    Vector2 position;
    Vector2 dimensions;
    Color color;
    int score;
    float speed;
    int upKey;
    int downKey;

    Player(Vector2 pos, Vector2 dim, Color col, float spd, int upKey, int downKey);

    void Draw();
    void Update();
    bool CheckCollision(Ball ball);
};

