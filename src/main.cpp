#include "targetver.h"

#include "Config.h"
#include <cstdio>
#include <cstdlib>
#include <SDL/SDL.h>
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption(APP_NAME, NULL);
    SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    do
    {
        SDL_WaitEvent(&event);
    }
    while ( event.type != SDL_QUIT );
    SDL_Quit();

    return EXIT_SUCCESS;
}

