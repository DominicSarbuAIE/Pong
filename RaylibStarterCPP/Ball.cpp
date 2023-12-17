#include "Ball.h"

Ball::Ball(Vector2 pos, Vector2 vel, float rad) : position(pos), velocity(vel), radius(rad), isActive(false) {}

void Ball::Draw() {
    DrawCircleV(position, radius, BLACK);
}

void Ball::Update() {
    if (isActive) {
        position.x += velocity.x;
        position.y += velocity.y;
    }
}