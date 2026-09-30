#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main() {
    srand(time(NULL));
    
    // Player settings
    int a = 380; 
    int b = 260;
    float playerRadius = 9.8f;

    // Target settings (Random spawn within window boundaries)
    int targetX = rand() % (WINDOW_WIDTH - 40) + 20;
    int targetY = rand() % (WINDOW_HEIGHT - 40) + 20;
    float targetRadius = 15.0f;

    int result = 0;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "BALL");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        // --- 1. HANDLE INPUT ---
        if (IsKeyPressedRepeat(KEY_RIGHT) || IsKeyPressed(KEY_RIGHT)) a += 10;
        if (IsKeyPressedRepeat(KEY_LEFT) || IsKeyPressed(KEY_LEFT))   a -= 10;
        if (IsKeyPressedRepeat(KEY_DOWN) || IsKeyPressed(KEY_DOWN))   b += 10;
        if (IsKeyPressedRepeat(KEY_UP) || IsKeyPressed(KEY_UP))       b -= 10;

        // --- 2. CHECK COLLISION ---
        // Convert integer coordinates to Vector2 structures for the collision function
        Vector2 playerPos = { (float)a, (float)b };
        Vector2 targetPos = { (float)targetX, (float)targetY };

        if (CheckCollisionCircles(playerPos, playerRadius, targetPos, targetRadius)) {
            result += 1; // Increase score
            
            // Respawn target at a new random position
            targetX = rand() % (WINDOW_WIDTH - 40) + 20;
            targetY = rand() % (WINDOW_HEIGHT - 40) + 20;
        }

        // --- 3. RENDER ---
        BeginDrawing(); // Note: Added BeginDrawing() which was missing in the original snippet
        ClearBackground(RAYWHITE);
        
        // Draw the target circle (GREEN)
        DrawCircle(targetX, targetY, targetRadius, GREEN);
        
        // Draw the player circle (RED)
        DrawCircle(a, b, playerRadius, RED);
        
        // UI Text
        DrawText(TextFormat("POINTS: %d", result), 580, 40, 15, BLACK);
        DrawText(TextFormat("POSITION: %d, %d", a, b), 50, 20, 25, BLUE);
        
        EndDrawing();
    }
    
    CloseWindow(); // Clean up native window context safely
    return 0;
}
