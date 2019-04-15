#include "Scene.h"

engine::Scene::Scene()
{
}

engine::Scene::~Scene()
{
}

void engine::Scene::UpdateScene()
{
	if (actors.size() > 0 )
	{
		for (Actor actor : actors)
			actor.Update();
	}
}

void engine::Scene::DrawScene()
{
	if (actors.size() > 0)
	{
		for (Actor actor : actors)
			actor.Draw();
	}
}


void engine::Scene::AddActorToScene(Actor toAdd)
{
	this->actors.push_back(toAdd);
}

std::vector<engine::Actor> engine::Scene::GetAllActors()
{
	return this->actors;
}
