#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Maze/Events/ApplicationEvent.h"

#include "Window.h"

namespace Maze {
	class MAZE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}

