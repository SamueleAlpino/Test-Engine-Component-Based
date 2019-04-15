#include "Actor.h"

engine::Actor::Actor()
{
}

engine::Actor::~Actor()
{
	/*for (ActorComponent* component : actorComponents)
		delete component;
	
	for (RenderComponent* component : renderComponents)
		delete component;

	delete this;*/
}

void engine::Actor::Update() const
{
	for (ActorComponent* component : actorComponents)
		component->Update();
}

void engine::Actor::Draw() const
{
	for (RenderComponent* component : renderComponents)
		component->Draw();
}

void engine::Actor::AddActorComponent(ActorComponent* toAdd) 
{
	actorComponents.push_back(toAdd);
}

void engine::Actor::AddRenderComponent(RenderComponent* toAdd) 
{
	this->renderComponents.push_back(toAdd);
}

void * engine::Actor::GetRenderComponent() const
{
	return nullptr;
}

void * engine::Actor::GetActorComponent() const
{
	return nullptr;
}
