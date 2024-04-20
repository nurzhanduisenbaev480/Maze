#pragma once


#ifdef MZ_PLATFORM_WINDOWS

extern Maze::Application* Maze::CreateApplication();

int main(int argc, char** argv) 
{
	auto application = Maze::CreateApplication();
	application->Run();
	delete application;
}

#endif // MZ_PLATFORM_WINDOWS