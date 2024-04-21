#include "Application.h"

#include "Maze/Events/ApplicationEvent.h"
#include "Maze/Log.h"


namespace Maze {
	
	Application::Application(){
	}
	Application::~Application() {
	}
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		MZ_TRACE(e);

		while (true);
	}
}