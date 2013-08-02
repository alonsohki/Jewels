#include "targetver.h"

#include "Config.h"
#include <cstdio>
#include <cstdlib>
#include "engine/FrameCounter.h"
#include "engine/Scene.h"
#include "JewelFactory.h"
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
    JewelFactory factory;
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

    // Test adding some jewels
    for ( int i = 1; i <= 2; ++i )
    {
        auto jewel = factory.createView(JewelFactory::GREEN);
        jewel->setPosition(vec2i(50*i, 50));
        jewel->setSelected(i == 1);
        scene.addEntity(jewel);
    }

    // Game loop
    do
    {
        scene.update();
        scene.draw(surf);

        SDL_PollEvent(&event);

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

