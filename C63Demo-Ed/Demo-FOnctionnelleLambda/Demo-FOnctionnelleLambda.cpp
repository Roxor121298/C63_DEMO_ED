// Demo-FOnctionnelleLambda.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <functional>



int ADD(int A, int B) 
{
    return A + B;
}

int SUB(int A, int B) 
{
    return A - B;
}


//fonction de seconde ordre ex


//std::function<int(int, int)> funcCreator(std::function<int(int, int)> funky) {
//
//    return 1;
//}

int operatorA(int A, int B) {
    return 1;
}

int main()
{
    std::cout << ADD(5, 4) << std::endl;
    std::function<int(int, int)> funcOperator = ADD;
    std::cout << funcOperator(5, 4) << std::endl;
    funcOperator = SUB;
    std::cout << funcOperator(5, 4) << std::endl;


    std::function<int(int,int)>wtv = [](int A, int B) {return A / B; };


    const int offSet = 5;
    funcOperator = [offSet](int A, int B) {return A * B; };



    funcOperator = [offSet](int A, int B) {return A * B; };




}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
