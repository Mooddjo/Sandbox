#include <iostream>
#include <string>



#include <GL/glew.h>
#include <OpenGL/OpenGL.h>
#include <glfw3.h>

#include "Sandbox.h"

using namespace sandbox;
using namespace std;



class MyScript : public FUpdatable
{
	DECLARE_FEATURE(MyScript)

public:
	MyScript(EEntity* owner) :FUpdatable(owner) {}

	virtual void update(double deltaMs) override
	{
		//SMARTLOG("coucou", kInfo);
		Transform* t = getOwner()->getTransform();
		t->rotateAboutY(0.005f * deltaMs);
	}

	virtual void init() override
	{
		
	}



};

class MyApplication : public sandbox::Application
{
public:
	void engineReady()
	{
		//unsigned int maxEntity = 1000;
		Scene* s = new Scene();
// 		for (int i = 0; i < 1000; ++i)
// 		{
// 			EQuad* quad = new EQuad(4.0);
// 			s->addObject(quad);
// 		}

		EQuad* quad = new EQuad(4.0);
		MyScript* scriptFeature = new MyScript(quad);
		quad->addFeature(scriptFeature);
		s->addObject(quad);
		FRenderable* f = quad->getFeature<FRenderable2d>();
		Material* mat = f->getMaterial();
		quad->getTransform()->setPosition(vec3(0.0f, 0.0f, 0.0f));
		mat->setProperty("uColor", vec4(0.8f, 0.9f, 0.4f, 1.0f));
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