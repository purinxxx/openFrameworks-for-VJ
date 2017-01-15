#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
//#include "ofxExportImageSequence.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        float w = 0;
        float xcenter = 0;
        float ycenter = 0;
    
        float hue = 140;
        float saturation = 200;
    
        float s = 0;
        float t = 360;
    
        float rannsuu[10];
        float noise[10];
        int hugou[10];
    
        //ofxExportImageSequence exp;
        ofxSyphonServer mainOutputSyphonServer;
        ofxSyphonServer individualTextureSyphonServer;
        ofxSyphonClient mClient;
        
};
