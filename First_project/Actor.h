#pragma once
#include <vector>
#include "ActorComponent.h"
#include "RenderComponent.h"
namespace engine
{
	class Actor
	{
	private:
		std::vector<ActorComponent*>  actorComponents;
		std::vector<RenderComponent*> renderComponents;
	
	public:
		Actor();
		~Actor();

		void Update() const;
		void Draw() const;

		void AddActorComponent(ActorComponent* toAdd) ;
		void AddRenderComponent(RenderComponent* toAdd) ;
		void* GetRenderComponent() const;
		void* GetActorComponent() const;

	};

}
