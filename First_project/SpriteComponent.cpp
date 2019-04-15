#include "SpriteComponent.h"
#include "Private.h"
#include "Engine.h"
#include "SDL_image.h"

engine::SpriteComponent::SpriteComponent(int x,int y,int witdh,int height, const char* texture)
{  
	image = IMG_Load(texture);
	if (!image)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
	}

	
	//Engine instance = 
//	SDL_Renderer* renderer = reinterpret_cast<SDL_Renderer*>(instance.GetRenderSystem()->Handle);
	this->texture = SDL_CreateTextureFromSurface(reinterpret_cast<SDL_Renderer*>(Engine::Get().GetRenderSystem()->Handle), image);
	// this->texture = IMG_LoadTexture(reinterpret_cast<SDL_Renderer*>(Engine::Get().GetRenderSystem().Handle), );
	base.x = x;
	base.y = y;
	base.w = witdh;
	base.h = height;

	 if(!texture)
	 {
	     SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	 }
}

engine::SpriteComponent::~SpriteComponent()
{
	//delete(texture);
	printf("call destructor");
}

void engine::SpriteComponent::Draw()
{
	SDL_RenderCopy(reinterpret_cast<SDL_Renderer*>(Engine::Get().GetRenderSystem()->Handle), this->texture, NULL, &base);
}
