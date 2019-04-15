#pragma once
#include <memory>
namespace engine
{
	class Window
	{
	public:
		Window(const char* Title,const int Width,const int Height);
		~Window();
		
		//Dico al compitalore di togliere qualcosa e non lo considererà
		//In questo caso copy constractor-> const ref e nome
		Window(const Window& rhs) = delete;
		
		void* GetHandle() const;

		int DequeueEvents() const;

	protected:
		void* Handle;
	};
}