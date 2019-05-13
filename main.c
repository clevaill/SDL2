#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

void                SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

int                 main(int argc, char **argv)
{
    SDL_Window      *window = NULL;
    SDL_Renderer    *renderer = NULL;
    SDL_Rect        rectangle;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    
    if (SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
    
    if (SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur pour le rendu");
    
    if (SDL_RenderDrawPoint(renderer, 100, 450) != 0)
        SDL_ExitWithError("Impossible de dessiner un point");

    if (SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        SDL_ExitWithError("Impossible de dessiner la ligne");

    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 120;

    if (SDL_SetRenderDrawColor(renderer, 255, 15, 15, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    if (SDL_RenderFillRect(renderer, &rectangle) != 0)
        SDL_ExitWithError("Impossible de dessiner le rectangle");

    SDL_RenderPresent(renderer);
    SDL_Delay(6000);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return EXIT_SUCCESS;
}