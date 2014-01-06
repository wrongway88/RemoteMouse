#ifndef REMOTE_MOUSE_H
#define REMOTE_MOUSE_H

#include "framework/app/BaseApplication.h"
//#include "framework/app/network/Server.h"
//#include "framework/app/network/Client.h"

#include "network/NetworkManager.h"
#include "mouseHandler/RemoteMouseHandler.h"

class RemoteMouse: public BaseApplication
{
public:
	RemoteMouse();
	~RemoteMouse();

	void setup();

	void update();

	virtual void keyDown();
	virtual void keyUp();
	virtual void keyReleased();

	virtual void mouseMoved();
	virtual void mouseButtonDown();
	virtual void mouseButtonUp();
	virtual void mouseButtonReleased();

	void shutdown();

private:
	RemoteMouseHandler m_mouseHandler;
	NetworkManager m_networkManager;

	int debugCounter;
};

#endif