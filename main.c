#include "raylib.h"
#include <stdio.h>
#define HEIGHT 450
#define WIDTH 800

int main(void) {
    int score = 0;

    int posX = 400;
    int posY = 225;

    Color DEFAULT = { 2, 2, 2, 255 };
    int BallSpeedX = 5;
    int BallSpeedY = 5;
    const int radius = 20;

    int RecPosX = 0;
    int RecPosY = 10;
    int RecHeight = 100;

    InitWindow(WIDTH, HEIGHT, "Learn Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_DOWN)) {
            RecPosY += 10;
        } else if (IsKeyDown(KEY_UP)) {
            RecPosY -= 10;
        }

        posX += BallSpeedX;
        posY += BallSpeedY;

        // SCREEN BORDER DECLARATION
        if (posY + radius >= HEIGHT || posY - radius <= 0) {
            BallSpeedY *= -1;
        } if ( posX + radius >= WIDTH || posX - radius <= 0 ) {
            BallSpeedX *= -1;
        }

        if (RecPosY + RecHeight >= HEIGHT) {
            RecPosY = HEIGHT - RecHeight;
        } if (RecPosY <= 0) {
            RecPosY = 0;
        }

        BeginDrawing();

        if (CheckCollisionCircleRec((Vector2){ posX, posY }, radius, (Rectangle){RecPosX, RecPosY, 10, RecHeight})) {
            BallSpeedX *= -1;
            score++;
        }

        ClearBackground(DEFAULT);
        DrawRectangle(RecPosX, RecPosY, 10, RecHeight, RED);
        DrawCircle(posX, posY, radius, WHITE);
        DrawText(TextFormat("%i", score), 10, 10, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}