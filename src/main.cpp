#include "targetver.h"

#include "Config.h"
#include <cstdio>
#include <cstdlib>
#include "engine/Scene.h"
#include "SDL/SDL.h"
#include "SDL/SDL_Image.h"
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
    Engine::Scene scene;
    SDL_Event event;

    // Load the background
    SDL_Surface* bkg = IMG_Load("img/BackGround.jpg");
    if ( bkg == nullptr )
    {
        fprintf(stderr, "Unable to load the background image\n");
        return EXIT_FAILURE;
    }
    scene.setBackground(bkg);

    // Initialize the application window
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption(APP_NAME, NULL);
    SDL_Surface* surf = SDL_SetVideoMode(bkg->w, bkg->h, 32, SDL_HWSURFACE);

    // Game loop
    do
    {
        scene.update();
        scene.draw(surf);

        SDL_WaitEvent(&event);
    }
    while ( event.type != SDL_QUIT );

    SDL_Quit();

    return EXIT_SUCCESS;
}

