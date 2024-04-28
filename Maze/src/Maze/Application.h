#pragma once

#include "Core.h"

#include "Window.h"
#include "Maze/LayerStack.h"
#include "Maze/Events/Event.h"
#include "Maze/Events/ApplicationEvent.h"

namespace Maze {
	class MAZE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	// To be defined in CLIENT
	Application* CreateApplication();
}

