#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    //Init SDL_ttf

    if(TTF_Init() == -1 ) {
        std::cerr << "erreure SDL_ttf:" << TTF_GetError() << std::endl;
        SDL_Quit();
        return -1 ;
    }

    // cree une windows

    SDL_Window* window = SDL_CreateWindow(
        "Floppy Bird",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
        );

    if (!window) {
        std::cerr << "Erreur création fenêtre : " << SDL_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // cree rendere
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur création renderer : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Background
    SDL_Surface* bgSurface = SDL_LoadBMP("/home/alex/Documents/MyVideoGame/MyFirtsGames/img/Sky1.bmp");
    if (!bgSurface) {
        std::cerr << "Erreur chargement background : " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);


    // Sprite

    SDL_Surface* spriteSurface = SDL_LoadBMP("/home/alex/Documents/MyVideoGame/MyFirtsGames/img/Sprite1.bmp");
    if (!spriteSurface) {
        std::cerr << "Erreur chargement sprite : " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Uint32 colorKey = SDL_MapRGB(spriteSurface->format, 0, 0, 255);
    SDL_SetColorKey(spriteSurface, SDL_TRUE, colorKey);

    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);

    if (!spriteTexture) {
        std::cerr << "Erreur création texture sprite : " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Rect spriteRect = {
        (WINDOW_WIDTH - 50) / 2,
        (WINDOW_HEIGHT - 50) / 2,
        50,
        50
    };

    // texte

    TTF_Font* font = TTF_OpenFont("/home/alex/Documents/MyVideoGame/MyFirtsGames/Police/Arial.ttf", 48);
    if(!font) {
        std::cerr << "Erreur chargement police : " << TTF_GetError() << std::endl;
        SDL_DestroyTexture(spriteTexture);
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Color color = {255, 165, 0, 255};


    SDL_Surface* texteSurface = TTF_RenderText_Solid(font, "Floppy Bird", color);
    if(!texteSurface) {
        std::cerr << "Erreur génération surface texte : " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyTexture(spriteTexture);
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, texteSurface);
    SDL_FreeSurface(texteSurface);

    if(!textTexture) {
        std::cerr << "Erreur création texture texte : " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyTexture(spriteTexture);
        SDL_DestroyTexture(bgTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }else {
        std::cout << "Texture texte créée avec succès !" << std::endl;
    }

    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
    SDL_Rect textRect = {
        (WINDOW_WIDTH - textWidth) / 2,
        50,
        textWidth,
        textHeight
    };


    // Boucle principale
    bool quit = false;
    SDL_Event event;
    while (!quit) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderCopy(renderer, spriteTexture, NULL, &spriteRect);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyTexture(bgTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return 0;
}
