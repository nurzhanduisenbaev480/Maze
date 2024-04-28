#include "mzpch.h"
#include "Application.h"

#include "Maze/Events/ApplicationEvent.h"
#include "Maze/Log.h"
#include <GLFW/glfw3.h>


namespace Maze {
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run() 
	{
		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}