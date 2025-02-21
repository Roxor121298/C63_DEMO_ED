#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "SimpleSquare.hpp"

//À inclure pour l'utilisation des pointeurs automatiques

int main(void)
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 800;
    constexpr float buffer = 80.f;
    constexpr float delta = 100.f;

    InitWindow(screenWidth, screenHeight, "Demo pointeurs automatiques");

    Vector2 currentDrawPosition = Vector2{ buffer,buffer };
    Vector2 drawPositionDelta = Vector2{ delta,delta };

    //Objet automatique
    SimpleSquare hautGauche(currentDrawPosition, "Objet automatique", GREEN);

    //Pointeur normal - ne pas oublier de supprimer!
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);

    //Pointeur partagé
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);

    //Pointeur faible
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(VIOLET);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}