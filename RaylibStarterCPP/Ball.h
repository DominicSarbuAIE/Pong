#pragma once
#include "raylib.h"

class Ball {
public:
    Vector2 position;
    Vector2 velocity;
    float radius;
    bool isActive;

    Ball(Vector2 pos, Vector2 vel, float rad);

    void Draw();
    void Update();
    void ResetSpeed();
};