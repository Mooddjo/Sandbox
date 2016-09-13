//
//  main.cpp
//  Sandbox
//
//  Created by Jonathan on 09/08/16.
//  Copyright © 2016 Jonathan. All rights reserved.
//

#include <iostream>

#include "Application.h"

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
    
    app.run();
    
    return 0;
}
