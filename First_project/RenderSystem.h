#pragma once
#include "Window.h"

namespace engine
{
	class RenderSystem
	{
	public:
		RenderSystem(Window& InWindow);
		~RenderSystem();

		//Copy constructor non considerato dal compilatore
		RenderSystem(const RenderSystem& InWindow) = delete;

		void Clear() const;
		void Present() const;
		//Window's reference 
		Window& Window;
		void* Handle;
	};
}