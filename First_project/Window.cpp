#include "Window.h"
#include "Private.h"
#include <iostream>

using namespace engine;

Window::Window(const char* Title,const int Width,const int Height)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	Handle = SDL_CreateWindow(Title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Width, Height, 0);

	if (!Handle)
	{
		printf("Window wasn't initialized : %s", SDL_GetError());
		//Generate exception
	}
}

Window::~Window()
{
	/*std::shared_ptr<SDL_Window> window = std::reinterpret_pointer_cast<SDL_Window>(Handle);
	SDL_DestroyWindow(window.get());*/
	//SDL_DestroyWindow(reinterpret_cast<SDL_Window*>(Handle));
	printf("fuck");
}

void* Window::GetHandle() const
{
	return this->Handle;
}

int Window::DequeueEvents() const
{
	SDL_Event Event;

	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_QUIT)
			return -1;

		if (Event.type == SDL_KEYDOWN)
		{
			std::cout << "pressed" << std::endl;

			if (Event.key.keysym.sym == SDLK_ESCAPE)
				return -1;
		}
	}

	return 0;
}
