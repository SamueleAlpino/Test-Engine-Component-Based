#pragma once
#include <vector>
#include "Actor.h"

namespace engine
{
	class Scene
	{
	private:
		std::vector<Actor> actors;
	
	public:
		Scene();
		~Scene();

		void UpdateScene();
		void DrawScene();
		void AddActorToScene(Actor toAdd);
		std::vector<Actor> GetAllActors();
	};

}