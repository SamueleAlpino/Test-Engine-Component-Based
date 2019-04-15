#pragma once
#include "RenderComponent.h"
#include "Private.h"

namespace engine
{
	class SpriteComponent: RenderComponent
	{
	private:
		SDL_Rect base;
		SDL_Texture* texture;
		SDL_Surface* image;

	public:
		SpriteComponent(int x, int y, int width,int height,const char* texture);
		~SpriteComponent();

		void Draw() override;
	};
}