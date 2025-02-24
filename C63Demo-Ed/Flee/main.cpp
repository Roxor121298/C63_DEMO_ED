#include "raylib.h"
#include "raymath.h"
#include "Flee.h"
#include <iostream>
#include <memory>
#include <vector>
#include <set>

using namespace std;

struct CollisionEvent
{
    weak_ptr<Flee> _LowerIndexFlee;
    weak_ptr<Flee> _HigherIndexFlee;
    Vector2 _Position;
    float _TimeOfImpact;

    CollisionEvent(weak_ptr<Flee> InLowerIndexFlee, weak_ptr<Flee> InHigherIndexFlee, float InTimeOfImpact)
        : _LowerIndexFlee(InLowerIndexFlee)
        , _HigherIndexFlee(InHigherIndexFlee)
        , _TimeOfImpact(InTimeOfImpact)
    {
        _Position = InLowerIndexFlee.lock()->GetPosition();
    }
};

int main(void)
{
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 1000;
    constexpr int borderMargin = 50;
    constexpr int nbFlee = 5;

    constexpr Vector2 borderMin = { borderMargin , borderMargin };
    constexpr Vector2 borderMax = { screenWidth - borderMargin , screenHeight - borderMargin };

    InitWindow(screenWidth, screenHeight, "Flee bonanza!");
    SetTargetFPS(60);

    // 1) Création d'une structure de donnée contenant les puces
    vector<shared_ptr<Flee>> fleeList;

    // 2) Génération de `nbFlee` puces aléatoirement dans les limites
    for (int i = 0; i < nbFlee; i++)
    {
        Vector2 randomPos = {
            static_cast<float>(GetRandomValue(borderMin.x, borderMax.x)),
            static_cast<float>(GetRandomValue(borderMin.y, borderMax.y))
        };

        float randomVelocity = static_cast<float>(1000); // Vitesse entre 5.0 et 15.0 // maintenant fixed a 1000 wtv
        fleeList.push_back(make_shared<Flee>(randomPos, randomVelocity, borderMin, borderMax));
    }

    // 4) Structure de données pour stocker les événements de collision
    vector<shared_ptr<CollisionEvent>> collisionEvents;

    while (!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();
        const float totalTime = GetTime();

        // 8) Faire avancer chaque puce et la dessiner
        for (auto& flee : fleeList)
        {
            flee->Move(deltaTime);
        }

        // 9) Détection des collisions
        for (size_t i = 0; i < fleeList.size(); i++)
        {
            for (size_t j = i + 1; j < fleeList.size(); j++) // Éviter les doublons
            {
                if (fleeList[i]->CollideWith(fleeList[j]))
                {
                    collisionEvents.push_back(make_shared<CollisionEvent>(fleeList[i], fleeList[j], totalTime));
                }
            }
        }

        BeginDrawing();
        ClearBackground(BLUE);
        // Dessin des limites de la zone
        DrawLine(borderMin.x, borderMin.y, borderMin.x, borderMax.y, PURPLE);
        DrawLine(borderMin.x, borderMin.y, borderMax.x, borderMin.y, PURPLE);
        DrawLine(borderMax.x, borderMin.y, borderMax.x, borderMax.y, PURPLE);
        DrawLine(borderMin.x, borderMax.y, borderMax.x, borderMax.y, PURPLE);

        // 5) Affichage du nombre de FPS en haut à gauche
        DrawText(TextFormat("FPS: %d", GetFPS()), 10, 10, 20, WHITE);

        // 6) Affichage du nombre total de puces en haut au milieu
        DrawText(TextFormat("Puces: %d", (int)fleeList.size()), screenWidth / 2 - 50, 10, 20, BLACK);

        // 7) Affichage du no+bre total de collisions en haut à droite
        DrawText(TextFormat("Collisions: %d", (int)collisionEvents.size()), screenWidth - 200, 10, 20, RED);



        // 8) Dessiner chaque puce
        for (auto& flee : fleeList)
        {
            flee->Draw();
        }

        // 11) Affichage des événements de collision
        for (const auto& collision : collisionEvents)
        {
            auto flee1 = collision->_LowerIndexFlee.lock();
            auto flee2 = collision->_HigherIndexFlee.lock();

            if (flee1 && flee2)
            {
                DrawRectangleV(collision->_Position, { 5, 5 }, Color{ 255, 255, 255, 25 });
                DrawLineEx(flee1->GetPosition(), flee2->GetPosition(), 2, Color{ 25, 25, 25, 25 });
            }
        }


        // 12) Suppression d'une puce à chaque appui sur ESPACE
        if (IsKeyPressed(KEY_SPACE) && !fleeList.empty())
        {
            fleeList.pop_back();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
