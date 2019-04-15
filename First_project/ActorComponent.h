#pragma once

namespace engine
{
	class ActorComponent
	{
	public:
		void* Owner;
		virtual void Update() = 0;

	};

}
