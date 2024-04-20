#include "Maze.h"

class Sandbox : public Maze::Application 
{
public:
	Sandbox() 
	{
		
	}
	~Sandbox() 
	{
		
	}
};


Maze::Application* Maze::CreateApplication()
{
	return new Sandbox();
}