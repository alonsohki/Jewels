#include "targetver.h"

#include "Config.h"
#include <cstdio>
#include <cstdlib>
#include "engine/FrameCounter.h"
#include "engine/Scene.h"
#include "JewelsGame.h"
#include "SDL/SDL.h"
#include "SDL/SDL_Image.h"
#include <sstream>
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
    using namespace Engine;
    using namespace Game;

    FrameCounter fpsCounter;
    Scene scene;
    SDL_Event event;
    JewelsGame game;

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
    vec2i lastClick ( 0, 0 );
    game.initialize(&scene);
    do
    {
        game.update();
        scene.update();
        scene.draw(surf);

        SDL_PollEvent(&event);
        switch ( event.type )
        {
            // Handle mouse clicks
            case SDL_MOUSEBUTTONDOWN:
            {
                lastClick = vec2i(0,0);
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                vec2i click;
                SDL_GetMouseState(&click[0], &click[1]);

                // Avoid multiple events for the same mouse up event.
                if ( click != lastClick )
                {
                    game.handleClick(click[0], click[1]);
                    lastClick = click;
                }
                break;
            }

            default: break;
        }

        // FPS counter
        fpsCounter.addFrame();
        std::ostringstream caption;
        caption << APP_NAME << " - FPS: " << fpsCounter.getFPS();
        SDL_WM_SetCaption(caption.str().c_str(), NULL);
    }
    while ( event.type != SDL_QUIT );

    SDL_Quit();

    return EXIT_SUCCESS;
}

