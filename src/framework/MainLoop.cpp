#include "MainLoop.h"

MainLoop::MainLoop(BaseApplication* baseApplication):
	m_application(baseApplication)
{}

MainLoop::~MainLoop()
{}

void MainLoop::run()
{
	bool run = true;

	m_application.setup();

	while(run)
	{
		m_application.update();

		run = m_application.getKeepRunning();
	}

	m_application.shutdown();
}