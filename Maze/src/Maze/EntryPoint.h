#pragma once


#ifdef MZ_PLATFORM_WINDOWS

extern Maze::Application* Maze::CreateApplication();

int main(int argc, char** argv) 
{
	Maze::Log::Init();
	MZ_CORE_WARN("Initialized log 2");
	MZ_INFO("Hello Moto");
	auto application = Maze::CreateApplication();
	application->Run();
	delete application;
}

#endif // MZ_PLATFORM_WINDOWS