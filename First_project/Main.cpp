#include "Engine.h"
#include "Window.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "RenderComponent.h"
int main(int argc, char**argv)
{
	engine::Window* myWindow  = new engine::Window("Hello", 1024, 768);
	engine::Engine engine = engine::Engine::Get();
	engine.InitRenderSystem(*myWindow);
	
	//create scene and set current level
	engine::Scene* firstLevel = new engine::Scene();
	engine.SetCurrentScene(firstLevel);
	
	//create actor
	engine::Actor* testActor = new engine::Actor();
	
	//create component and add to actor
	engine::SpriteComponent* sprite = new engine::SpriteComponent(30,30,255,255, "D:/Sam/Nuova cartella/Engine_c++_components_based/First_project/Assets/test.jpg");
	testActor->AddRenderComponent(reinterpret_cast<engine::RenderComponent*>(sprite));
	
	//add actor to scene
	firstLevel->AddActorToScene(*testActor);

	engine.UpdateEngine();

	return 0;
}