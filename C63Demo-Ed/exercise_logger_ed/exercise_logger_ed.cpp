// exercise_logger_ed.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cassert>
#include "Logger.h"
#include <windows.h>
using namespace LoopEngine;

int main()
{

    SetConsoleOutputCP(1252);

    //Écriture dans la console et le fichier "C63Demo/Exercice-Logger/LoopEngine.log"
    Logger* log = new Logger(Logger::TLevel::eINFO, true, true);
    assert(log != nullptr);

    log->Log("De l'information seulement.", Logger::TLevel::eINFO);
    log->Log("Un avertissement, peut causer des problèmes mineurs.", Logger::TLevel::eWARNING);
    log->Log("Pour débogger", Logger::TLevel::eDEBUG);
    //log->Log("Une erreur, c'est grave et va casser l'application. Va suspendre avec la configuration par défaut!", Logger::TLevel::eERROR);
    //log->SetFileTraceName("JeVaisInterrompre!");
    log->ActivateFileTrace(false);
    log->SetFileTraceName("NouveauLog.log");
    log->ActivateFileTrace(true);
    log->Log("Va écrire dans la console et NouveauLog.log.", Logger::TLevel::eINFO);

    log->SetLoggingLevel(Logger::TLevel::eWARNING);
    log->Log("Cette entrée sera ignorée.", Logger::TLevel::eINFO);

    //Ne va jamais interrompre
    log->SetAbortLevel(Logger::eNONE);
    //Cause une erreur
    log->SetFileTraceName("");

    //Toujours libérer sa mémoire
    delete log;
    log = nullptr;
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
