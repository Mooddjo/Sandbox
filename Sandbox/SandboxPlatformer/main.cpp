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

	}
};

int
main(int argc, char* argv[])
{
	MyApplication a;
	Window win(100,100,1024,768, "Sandbox Platformer");
	a.setApplicationWindow(&win);
	a.run();
	return EXIT_SUCCESS;
}