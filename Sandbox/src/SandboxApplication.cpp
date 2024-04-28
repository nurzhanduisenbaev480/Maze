#include "Maze.h"

class ExampleLayer : public Maze::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		MZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Maze::Event& event) override
	{
		MZ_TRACE("{0}", event);
	}
};



class Sandbox : public Maze::Application 
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox() 
	{
		
	}
};


Maze::Application* Maze::CreateApplication()
{
	return new Sandbox();
}