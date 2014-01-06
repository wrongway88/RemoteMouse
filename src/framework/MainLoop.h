#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#define _WINSOCKAPI_
#include <Windows.h>

#include "app/Application.h"
#include "app/BaseApplication.h"

class MainLoop
{
public:
	MainLoop(BaseApplication* baseApplication);
	~MainLoop();

	void run();

private:
	Application m_application;
};

#endif