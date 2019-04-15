#include "RenderSystem.h"
#include "Private.h"

#define Renderer reinterpret_cast<SDL_Renderer*>(Handle)

//Constructor
engine::RenderSystem::RenderSystem(engine::Window& InWindow) : Window(InWindow)
{
	this->Window = InWindow;

	/*SDL_Window* WindowHandle = reinterpret_cast<SDL_Window*>(Window.GetHandle());
	if(!WindowHandle)
	{
       SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
       SDL_Quit();
    }*/


	Handle = SDL_CreateRenderer(reinterpret_cast<SDL_Window*>(this->Window.GetHandle()), -1, 
								SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(!Renderer)
	{
	    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	    SDL_Quit();
	}
}

//Destructor
engine::RenderSystem::~RenderSystem()
{
	//Destroy
	SDL_DestroyRenderer(Renderer);
}

void engine::RenderSystem::Clear() const
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
}

void engine::RenderSystem::Present() const
{
	SDL_RenderPresent(Renderer);
}

