# Floppy Bird

Floppy Bird est un projet de jeu 2D inspiré de Flappy Bird, développé en C++ en utilisant la bibliothèque SDL2. Ce projet a pour but de me familiariser avec la programmation de jeux et de poser les bases d'un moteur de jeu 2D.

## Table des matières
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Compilation et Exécution](#compilation-et-exécution)
- [Fonctionnalités](#fonctionnalités)
- [Améliorations futures](#améliorations-futures)
- [Crédits](#crédits)
- [Licence](#licence)

## Prérequis
Avant d'exécuter le projet, assurez-vous d'avoir installé les dépendances suivantes :

- **C++17 ou supérieur**
- **SDL2**
- **SDL2_image**
- **SDL2_ttf**
- **Make**
- **Vim** (optionnel, utilisé pour le développement)

Sur Arch Linux, installez-les avec :
```sh
sudo pacman -Syu base-devel gcc sdl2 sdl2_image sdl2_ttf
```

## Installation
Clonez ce dépôt sur votre machine :
```sh
git clone https://github.com/lebosslex/FloppyBird.git
cd FloppyBird
```

## Compilation et Exécution
Utilisez `g++` pour compiler le projet :
```sh
g++ -o floppybird main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
```

Puis exécutez le jeu :
```sh
./floppybird
```

## Fonctionnalités
- Affichage d'une fenêtre SDL avec un background et un sprite
- Gestion des événements (fermeture de la fenêtre)
- Affichage d'un texte en SDL_ttf
- Rendu optimisé avec SDL_Renderer

## Améliorations futures
- Ajout de la physique du jeu (gravité et collision)
- Gestion des entrées clavier pour le saut
- Système de score
- Ajout de sons et musiques
- Création d'un moteur de jeu 2D générique

## Crédits
Développé par **Lex**


## Capture D'écran 

![MyPlay](https://github.com/user-attachments/assets/36f13f90-0f61-4ea3-81b1-cf8f18474090)


## Licence
Ce projet est sous licence MIT. Voir [LICENSE](LICENSE) pour plus de détails.

