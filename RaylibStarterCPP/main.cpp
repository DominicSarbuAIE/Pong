/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Player.h"
#include "Ball.h"


int main(int argc, char* argv[])
{
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Pong Game");

    SetTargetFPS(60);

    // Create ball and players
    Ball ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 2.0f, 2.0f }, 10.0f);
    Player player1({ 0, screenHeight / 2.0f }, { 10, 80 }, BLUE, 2.0f, KEY_W, KEY_S);
    Player player2({ screenWidth - 10.0f, screenHeight / 2.0f }, { 10, 80 }, RED, 2.0f, KEY_UP, KEY_DOWN);

    // Main game loop
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            ball.isActive = true;  // Set the ball to active when space is pressed
        }
        // Update
        ball.Update();
        player1.Update();
        player2.Update();

        // Collision detection and scoring logic
        if (player1.CheckCollision(ball) || player2.CheckCollision(ball)) {
            ball.velocity.x *= -1; // Reverse ball direction
        }
        if (ball.position.y <= 0 || ball.position.y + ball.radius >= GetScreenHeight()) {
            ball.velocity.y *= -1; // Reverse ball direction
        }

        
        if (ball.position.x <= 0) {
            player2.score++; // Player 2 scores
            ball = Ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 2.0f, 2.0f }, 10.0f); // Reset ball
        }
        
        else if (ball.position.x + ball.radius >= screenWidth) {
            player1.score++; // Player 1 scores
            ball = Ball({ screenWidth / 2.0f, screenHeight / 2.0f }, { 2.0f, 2.0f }, 10.0f); // Reset ball
        }
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        ball.Draw();
        player1.Draw();
        player2.Draw();
        DrawText(TextFormat("Player 1 Score: %i", player1.score), 10, 10, 20, LIGHTGRAY);
        DrawText(TextFormat("Player 2 Score: %i", player2.score), screenWidth - 200, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
};