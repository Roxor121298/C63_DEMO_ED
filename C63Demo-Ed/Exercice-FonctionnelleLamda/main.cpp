#include "raylib.h"
#include "Bouton.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib - Classe Button");

    srand(time(nullptr));
    Color backgroundColor = RAYWHITE;

    // Création du bouton
    Bouton changeColorButton(300, 250, 200, 50, "Changer couleur", [&]() {
        backgroundColor = { (unsigned char)(rand() % 256), (unsigned char)(rand() % 256), (unsigned char)(rand() % 256), 255 };
        });

    Bouton bonjourButton(300, 150, 200, 50, "Dire Bonjour", []() {
        std::cout << "Hello, world !" << std::endl;
        });


    Bouton byebyeButton(300, 350, 200, 50, "Dire Byebye", []() {
        CloseWindow();
        });



    // Personnalisation des couleurs du bouton
    changeColorButton.SetColors(DARKBLUE, BLUE, SKYBLUE);

    bonjourButton.SetColors(DARKGREEN, GREEN, BLACK);

    byebyeButton.SetColors(RED, ORANGE, BLACK);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(backgroundColor);

        // Affichage et mise à jour du bouton
        changeColorButton.DrawAndUpdate();
        bonjourButton.DrawAndUpdate();
        byebyeButton.DrawAndUpdate();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
