#include <iostream>
#include <string>
#include "gl/glew.h"
#include "Sandbox.h"

using namespace sandbox;
using namespace std;

class MyApplication : public sandbox::Application
{
public:
	void engineReady()
	{
		EQuad* quad = new EQuad(4.0);
		Scene* s = new Scene();
		s->addObject(quad);
		SceneService::getInstance()->loadScene(s);
	}
};

int
main(int argc, char* argv[])
{
	MyApplication a;
	Window win(100,100,1280,720, "Sandbox Platformer");
	a.setApplicationWindow(&win);
	a.run();
	return EXIT_SUCCESS;
}