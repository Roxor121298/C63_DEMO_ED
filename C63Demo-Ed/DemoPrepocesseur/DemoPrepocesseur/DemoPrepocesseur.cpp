// DemoPrepocesseur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "patate.h"
// on évite une erreur de compilation grace au #pragma once
#include "patate.h"

using namespace std;


// #include : copie-colle le contenue entier d'un fichier
// En pratique, sert a importer la déclaration de symboles
int main()
{
    Patate p;
    #include "NeFaitPasCa.h"
    std::cout << "Hello World!\n" << endl;
    std::cout << "PI: " << PI << endl;
    std::cout << "Circonference de 4.0f : " << FORMULE_CIRCONFERENCE(4.0f) << endl;
    std::cout << "Circonference de 4 sans f : " << FORMULE_CIRCONFERENCE(4) << endl;

    std::cout << "Fichier : " << __FILE__ << "liGNE: " << __LINE__ << std::endl;


#undef GAME_RELEASE

#ifdef GAME_RELEASE
    std::cout << "GAMER !" << std::endl;
#else
    std::cout << "Not Gamer !" << std::endl;
#endif


#ifndef STEAM_VERSION
    std::cout << "No stew !" << std::endl;
#endif
}

