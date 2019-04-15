#pragma once
//#include <stdlib.h>
#include <vector>
#include <memory>
#include "RenderSystem.h"
#include <vector>
#include "Actor.h"
#include "RenderSystem.h"
#include "Scene.h"
namespace engine
{
	class Engine
	{ 
		private:
			Scene* currentScene;

			Engine() {};
			
			RenderSystem* renderSystem;
			static Engine* instance;

		public:
			static Engine& Get();

			RenderSystem* GetRenderSystem();
			//Before Update, call these methods:
			void InitRenderSystem(Window& window);
			void SetCurrentScene(Scene* current);
	
			//-----------------------------------
			void UpdateEngine();
			~Engine();
	};

	

}

