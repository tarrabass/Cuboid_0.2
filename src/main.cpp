#include "testApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
    
    
    //ofSetupOpenGL(3072,768, OF_WINDOW);
    //ofAppBaseWindow window;
     //ofAppGlutWindow window; // create a window
	// window.setGlutDisplayString("rgba double samples>=4");
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	//ofSetupOpenGL(&window,3072,768, OF_WINDOW);
    ofSetupOpenGL(3072,768, OF_WINDOW);
	ofRunApp(new testApp()); // start the app

}
