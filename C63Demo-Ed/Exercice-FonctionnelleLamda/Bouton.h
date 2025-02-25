#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <functional>
#include <string>

class Bouton {
public:
    // Constructeur et destructeur
    Bouton(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const std::string& InText, std::function<void()> InActionToDo);
    ~Bouton() = default;

    // Définition des couleurs du bouton
    void SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral);

    // Affichage et mise à jour du bouton
    void DrawAndUpdate();

private:
    Rectangle rect;          // Rectangle du bouton
    std::string text;        // Texte du bouton
    std::function<void()> action; // Action à exécuter au clic

    // Couleurs
    Color colorNeutral;
    Color colorHover;
    Color colorPressed;

    bool isHovered = false;
    bool isPressed = false;
};

#endif // BUTTON_H
