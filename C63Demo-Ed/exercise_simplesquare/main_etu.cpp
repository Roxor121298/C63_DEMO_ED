#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "SimpleSquare.hpp"

//À inclure pour l'utilisation des pointeurs automatiques

#include <memory>

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
    SimpleSquare* ptrSimple = new SimpleSquare(currentDrawPosition, "pointeur classique", BLUE);


    //Pointeur partagé
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);
    std::shared_ptr<SimpleSquare> ptrSharedSimpleSquare = std::make_shared<SimpleSquare>(currentDrawPosition, "pointeur shared", YELLOW);
    std::shared_ptr<SimpleSquare> ptrSharedSimpleSquareCopy = ptrSharedSimpleSquare; //use_count ++

    { // Ne peut plus etre utilisé apres la porté
        std::shared_ptr<SimpleSquare> ptrSharedSimpleSquareCopyCopy = ptrSharedSimpleSquare;
    } // use_count --

    //Pointeur faible
    // besoin de copier un shared un ou un autre weak pour créer un weak
    std::weak_ptr<SimpleSquare> ptrWeakSimpleSquare = ptrSharedSimpleSquare;
    currentDrawPosition = Vector2Add(currentDrawPosition, drawPositionDelta);
    // un weka pointer n'augmente pas use_count


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(VIOLET);

            hautGauche.Draw();


            if (ptrSimple != nullptr) {
                (*ptrSimple).Draw();
            }

            if (ptrSharedSimpleSquare != nullptr) {
               (ptrSharedSimpleSquare)->Draw(std::to_string(ptrSharedSimpleSquare.use_count()));
            }

            // "tour de passe passe"
            if (auto tempShared = ptrWeakSimpleSquare.lock()) 
            {
                tempShared->Draw(std::to_string(ptrSharedSimpleSquare.use_count()));

            }


        EndDrawing();
    }

    CloseWindow();

    if (ptrSimple != nullptr) {
        delete ptrSimple;
    }

    return 0;
}