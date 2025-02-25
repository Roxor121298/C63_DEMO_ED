#include "Bouton.h"

// Constructeur
Bouton::Bouton(int InPositionX, int InPositionY, int InLargeur, int InHauteur, const std::string& InText, std::function<void()> InActionToDo)
    : rect{ (float)InPositionX, (float)InPositionY, (float)InLargeur, (float)InHauteur }, text(InText), action(InActionToDo),
    colorNeutral(GRAY), colorHover(LIGHTGRAY), colorPressed(DARKGRAY) {
}

// Définition des couleurs personnalisées
void Bouton::SetColors(const Color& InColorNeutral, const Color& InHoverNeutral, const Color& InPressedNeutral) {
    colorNeutral = InColorNeutral;
    colorHover = InHoverNeutral;
    colorPressed = InPressedNeutral;
}

// Affichage et mise à jour du bouton
void Bouton::DrawAndUpdate() {
    Vector2 mousePos = GetMousePosition();
    isHovered = CheckCollisionPointRec(mousePos, rect);
    isPressed = isHovered && IsMouseButtonDown(MOUSE_LEFT_BUTTON);

    // Détection du clic
    if (isHovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        action();
    }

    // Dessiner le bouton avec la bonne couleur
    Color currentColor = isPressed ? colorPressed : (isHovered ? colorHover : colorNeutral);
    DrawRectangleRec(rect, currentColor);
    DrawRectangleLinesEx(rect, 2, BLACK);

    // Centrer le texte dans le bouton
    int textWidth = MeasureText(text.c_str(), 20);
    Vector2 textPos = { rect.x + (rect.width - textWidth) / 2, rect.y + (rect.height - 20) / 2 };
    DrawText(text.c_str(), textPos.x, textPos.y, 20, BLACK);
}
