@echo off
setlocal

:: Définir le chemin du répertoire Templates de Visual Studio
set "TEMPLATE_PATH=%USERPROFILE%\Documents\Visual Studio 2022\Templates\ProjectTemplates"

:: Vérifier si le répertoire existe, sinon le créer
if not exist "%TEMPLATE_PATH%" mkdir "%TEMPLATE_PATH%"

:: Copier le fichier ZIP dans le dossier des templates
copy /Y "RaylibTemplate.zip" "%TEMPLATE_PATH%"

echo Installation du template Raylib terminée !
pause
