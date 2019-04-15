#include "Engine.h"
#include "Private.h"
#include "Window.h"
#include <iostream>
using namespace engine;

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Engine* Engine::instance = 0;

Engine& engine::Engine::Get() 
{
	if (!instance)
		instance = new Engine();	

	return *instance;
}

RenderSystem* engine::Engine::GetRenderSystem()
{
	return instance->renderSystem;
}

void engine::Engine::InitRenderSystem(Window& window)
{
	renderSystem = new RenderSystem(window);
	instance->renderSystem = renderSystem;
}

void engine::Engine::SetCurrentScene(Scene * current)
{
	this->currentScene = current;
	instance->currentScene = current;
}

void engine::Engine::UpdateEngine()
{
	for (;;)
	{

		if (renderSystem->Window.DequeueEvents())
			break;

		renderSystem->Clear();
		currentScene->UpdateScene();
		currentScene->DrawScene();

		renderSystem->Present();
	}
}

engine::Engine::~Engine()
{
	SDL_Quit();
}
