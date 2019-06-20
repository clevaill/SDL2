#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void                SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void                SDL_LimitFPS(unsigned int limit)
{
    unsigned int    ticks = SDL_GetTicks();

    if (limit < ticks)
        return ;
    else if (limit > ticks + 16)
        SDL_Delay(16);
    else
        SDL_Delay(limit - ticks);
}

int                 main(int argc, char **argv)
{
    SDL_Window      *window = NULL;
    SDL_Renderer    *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
    
    SDL_bool        program_launched = SDL_TRUE;
    unsigned int    frame_limit = 0;

    frame_limit = SDL_GetTicks() + 16;
    SDL_LimitFPS(frame_limit);
    frame_limit = SDL_GetTicks() + 16;

    while (program_launched)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}