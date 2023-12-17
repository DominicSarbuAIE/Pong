#include "Player.h"
#include "Ball.h"

Player::Player(Vector2 pos, Vector2 dim, Color col, float spd, int upKey, int downKey) : position(pos), dimensions(dim), color(col), score(0), speed(spd), upKey(upKey), downKey(downKey) {}

void Player::Draw() {
    DrawRectangleV(position, dimensions, color);
}

void Player::Update() {
    // Update player position based on input
    if (IsKeyDown(upKey) && !IsKeyDown(downKey)) {
        position.y -= speed;
    }
    else if (IsKeyDown(downKey) && !IsKeyDown(upKey)) {
        position.y += speed;
    }


    // Prevent the player from going off screen
    if (position.y < 0) position.y = 0;
    if (position.y > GetScreenHeight() - dimensions.y) position.y = GetScreenHeight() - dimensions.y;
}

bool Player::CheckCollision(Ball ball) {
    // Check if the ball collides with the player
    return CheckCollisionCircleRec(ball.position, ball.radius, { position.x, position.y, dimensions.x, dimensions.y });
}