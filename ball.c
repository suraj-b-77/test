#include <stdio.h>
#include <raylib.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main() {
    int a, b;
    a = 380; b = 260;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "BALL");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        ClearBackground(RAYWHITE);
        if (IsKeyPressedRepeat(KEY_RIGHT)) {
            a += 10;
        }
        if (IsKeyPressedRepeat(KEY_LEFT)) {
            a -= 10;
        }
        if (IsKeyPressedRepeat(KEY_DOWN)) {
            b += 10;
        }
        if (IsKeyPressedRepeat(KEY_UP)) {
            b -= 10;
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            a += 10;
        }
        if (IsKeyPressed(KEY_LEFT)) {
            a -= 10;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            b += 10;
        }
        if (IsKeyPressed(KEY_UP)) {
            b -= 10;
        }
        DrawCircle(a, b, 9.8, RED);
        DrawText(TextFormat("POSITION: %d, %d", a, b), 50, 20, 25, BLUE);
        EndDrawing();
    }
    return 0;
}