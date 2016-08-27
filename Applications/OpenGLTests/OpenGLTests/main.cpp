//
//  main.cpp
//  OpenGLTests
//
//  Created by Jonathan on 12/08/16.
//  Copyright © 2016 Jonathan. All rights reserved.
//

#include <iostream>


#include <GL/glew.h>
#include <OpenGL/OpenGL.h>
#include <glfw3.h>

#include "Application.h"
#include "Window.h"

using namespace sandbox;

class MyApp: public sandbox::Application
{
public:
    virtual void engineReady() override;
    
};


void
MyApp::engineReady()
{
    std::cout << "Hello!\n";
}

int main(int argc, const char * argv[]) {
    
    MyApp app;
    Window win(100,100,1280,720, "Sandbox Platformer");
    app.setApplicationWindow(&win);
    
    app.run();
    
    return 0;
}




//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    
//    return 0;
//}
