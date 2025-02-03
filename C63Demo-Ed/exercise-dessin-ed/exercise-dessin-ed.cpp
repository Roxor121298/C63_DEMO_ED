#include <iostream>
#include "raylib.h"

int main()
{
    const int largeur = 800;
    const int hauteur = 800;

    InitWindow(largeur, hauteur, "ui");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); // Nettoie l'écran avec un fond blanc

        EndDrawing();
    }

    CloseWindow();
    return 0;
}