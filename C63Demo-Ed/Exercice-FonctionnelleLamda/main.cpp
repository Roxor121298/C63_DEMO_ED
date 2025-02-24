
#include "raylib.h"


Color HexToColor(int hexValue)
{
    Color color;
    color.r = (hexValue >> 16) & 0xFF; 
    color.g = (hexValue >> 8) & 0xFF;  
    color.b = (hexValue) & 0xFF;        
    color.a = 255;                      
    return color;
}


int main()
{

    const int mode = 2;
    const int largeur = 800;
    const int hauteur = 800;

    InitWindow(largeur, hauteur, "Exercise dessin");
    SetTargetFPS(60);

    float outerRadius = 180.0f;
    float startAngle = 0.0f;
    float endAngle = 180.0f;
    float segments = 10.0f;
    float minSegments = 4;

    while (!WindowShouldClose())
    {
        BeginDrawing();


        // Pacman
        if(mode == 1){

        ClearBackground(BLACK); // Nettoie l'écran avec un fond blanc


        // void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
        // a besoin d'un vector pour la position x, y
        Vector2 center = { 200, 400 };
        DrawCircleSector(center, 100, 30, 330, 50, YELLOW);

        DrawCircle(390, 400, 30, RAYWHITE);
        DrawCircle(480, 400, 30, RAYWHITE);
        DrawCircle(570, 400, 30, RAYWHITE);

        // void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
        const char* text = "yippie";
        DrawText(text, 150, 550, 48, WHITE);

        
        }
        else {


            Color BackGroundPurple = HexToColor(0x8745ba);
            Color LoadingYellow = HexToColor(0xffc932);
            Color Dots = HexToColor(0xb78bd4);
            Color redTop = HexToColor(0xc76365);

            ClearBackground(BackGroundPurple);


            //un boucle for seulement ish ??
            int difference; //opérateur difference
            //for (int index = 0; index < 9 * 11; index++) {
            //    int j = (index / 11);  // Convertir index en ligne
            //    int i = (index % 11);  // Convertir index en colonne
            //    int difference = (j % 2 == 0) ? -5 : 5;  // Alterner -5 et +5
            //    int shapeType = j % 3;  // Choisir entre Rectangle, Cercle et "!"
            //    int x = (i * 80) + difference;
            //    int y = (j * 120) + difference;
            //    if (shapeType == 0) {
            //        DrawRectangle(x, y, 10, 10, Dots);
            //    }
            //    else if (shapeType == 1) {
            //        DrawCircle(x, y, 10, Dots);
            //    }
            //    else {
            //        DrawText("!", x, y, 20, Dots);
            //    }
            //}

            

            // plus deux for loop 
            for (int j = 0; j < 8; j++) {
                int difference = (j % 2 == 0) ? -5 : 5;  
                int shapeType = j % 3;  // modulo + opérateur ternaires yay
                for (int i = 0; i < 15; i++) {
                    int x = (i * 80) + difference;
                    int y = (j * 125) + difference;
                    if (shapeType == 0) {
                        DrawRectangle(x, y, 10, 10, Dots);
                    }
                    else if (shapeType == 1) {
                        DrawCircle(x, y, 10, Dots);
                    }
                    else {
                        DrawText("!", x, y, 20, Dots);
                    }
                }
            }
            DrawText("Loading", largeur / 3.2, hauteur / 2.4, 80, LoadingYellow);

        }



        EndDrawing();
    }

    CloseWindow();
    return 0;
}