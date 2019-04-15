#pragma once
namespace engine
{
	class RenderComponent
	{
	public:
		void* Owner;
	    virtual void Draw() = 0;
	};

}

