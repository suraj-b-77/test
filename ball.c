#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define PLAYER_RADIUS 9.8f
#define TARGET_RADIUS 12.0f

int main() {
    srand(time(NULL));
    int a, b, result;

    int targetX = rand() % (WINDOW_WIDTH - 40) + 20;
    int targetY = rand() % (WINDOW_HEIGHT - 40) + 20;    

    result = 0;
    a = 380; b = 260;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "BALL");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        ClearBackground(RAYWHITE);

        if (IsKeyPressed(KEY_RIGHT)) a += 10;
        if (IsKeyPressed(KEY_LEFT))   a -= 10;
        if (IsKeyPressed(KEY_DOWN))   b += 10;
        if (IsKeyPressed(KEY_UP))   b -= 10;

        Vector2 playerpos = {(float)a, (float)b};
        Vector2 targetpos = {(float)targetX, (float)targetY};

        if (CheckCollisionCircles(playerpos, PLAYER_RADIUS, targetpos, TARGET_RADIUS)) {
            targetX = rand() % (WINDOW_HEIGHT - 40) + 20; 
            targetY = rand() % (WINDOW_WIDTH - 40) + 20;
            result +=1;
        }

        DrawCircle(a, b, PLAYER_RADIUS, RED);
        DrawCircle(targetX, targetY, TARGET_RADIUS, BLACK);
        DrawText(TextFormat("POINTS: %d", result), 580, 40, 15, BLACK);
        DrawText(TextFormat("POSITION: %d, %d", a, b), 50, 20, 25, BLUE);
        EndDrawing();
    }
    return 0;
}