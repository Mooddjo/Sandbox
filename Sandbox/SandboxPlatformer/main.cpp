#include <iostream>
#include <string>
#include "gl/glew.h"
#include "Sandbox.h"


using namespace sandbox;
using namespace std;



class RotationScript : public FUpdatable
{
	DECLARE_FEATURE(RotationScript)
public:
	RotationScript(EEntity* owner) :FUpdatable(owner) {}
	virtual void update(double deltaMs) override
	{
		Transform* t = getOwner()->getTransform();
		t->rotateAboutY(0.005f * deltaMs);
	}

	virtual void init() override{}
};


class MyApplication : public sandbox::Application
{
public:
	void engineReady()
	{
		sceneTwo();
	}

private:

	float computeStep(float min, float max, int count)
	{
		float length = max - min;
		

		float step = length / (count * 1.0f);

		return step;
	}

	void sceneTwo()
	{
		unsigned int maxEntity = 100;
		float minX = -1.0;
		float maxX = 1.0;
		Scene* s = new Scene();

		float step = computeStep(minX, maxX, maxEntity);
		for (float i = minX; i < maxX; i += step)
		{
			for (float j = maxX; j > minX; j -= step)
			{
				EQuad* quad = new EQuad(step, vec3(i + (0.5*step), j - (0.5f*step), 0.0f));
				FRenderable* f = quad->getFeature<FRenderable2d>();
				MaterialInstance* mat = f->getMaterialInstance();
				
				float randRed = std::rand() / (RAND_MAX * 1.0f);
				float randGreen = std::rand() / (RAND_MAX * 1.0f);
				float randBlue = std::rand() / (RAND_MAX * 1.0f);
				mat->setProperty("uColor", vec4(randRed, randGreen, randBlue, 1.0f));
				s->addObject(quad);
			}
		}


		SceneService::getInstance()->loadScene(s);
	}


	void sceneOne()
	{
// 		unsigned int maxEntity = 1000;
// 		Scene* s = new Scene();
// 		EQuad* quad = new EQuad(4.0f, vec3(-0.5f, 0.0f, 0.0f));
// 		RotationScript* scriptFeature = new RotationScript(quad);
// 		//quad->addFeature(scriptFeature);
// 		s->addObject(quad);
// 		FRenderable* f = quad->getFeature<FRenderable2d>();
// 		Material* mat = f->getMaterial();
// 		//quad->getTransform()->setPosition(vec3(0.0f, 0.0f, 0.0f));
// 		mat->setProperty("uColor", vec4(0.8f, 0.9f, 0.4f, 1.0f));
// 		SceneService::getInstance()->loadScene(s);
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