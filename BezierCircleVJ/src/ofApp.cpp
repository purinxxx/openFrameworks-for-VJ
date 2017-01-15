#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLineWidth(4);
    ofSetCircleResolution(128);
    
    for (int i = 0; i < 10; i++) {
        rannsuu[i] = ofRandom(s, t);
        noise[i] = 0;
        hugou[i] = 1;
    }
    
    //exp.setup(1280, 720, 30);
    //exp.setOutputDir("out");
    //exp.setOverwriteSequence(true);
    //exp.setAutoExit(true);
    //exp.startExport();
    
    mainOutputSyphonServer.setName("oF Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    w = ofGetWidth()*0.5f;
    xcenter = ofGetWidth() / 2;
    ycenter = ofGetHeight() / 2;
    
    //exp.begin();
    
    ofSetColor(0, 0, 0, 20);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    hue = hue + 0.1;
    if (hue >= 255) hue = 0;
    ofColor strokecolor = ofColor::fromHsb(hue, saturation, 100);
    ofSetColor(strokecolor);
    
    float sx = rannsuu[8] * cos(s*PI / 180) + xcenter;
    float sy = rannsuu[8] * sin(s*PI / 180) + ycenter;
    float s1_x = sx + cos((s + rannsuu[0])*PI / 180)*w;
    float s1_y = sy + sin((s + rannsuu[1])*PI / 180)*w;
    float s2_x = sx + cos((s + rannsuu[2])*PI / 180)*w;
    float s2_y = sy + sin((s + rannsuu[3])*PI / 180)*w;
    float tx = rannsuu[9] * cos(t*PI / 180) + xcenter;
    float ty = rannsuu[9] * sin(t*PI / 180) + ycenter;
    float t1_x = tx + cos((t + rannsuu[4])*PI / 180)*w;
    float t1_y = ty + sin((t + rannsuu[5])*PI / 180)*w;
    float t2_x = tx + cos((t + rannsuu[6])*PI / 180)*w;
    float t2_y = ty + sin((t + rannsuu[7])*PI / 180)*w;
    
    ofPoint s1 = ofVec2f(s1_x, s1_y);
    ofPoint s2 = ofVec2f(s2_x, s2_y);
    ofPoint t1 = ofVec2f(t1_x, t1_y);
    ofPoint t2 = ofVec2f(t2_x, t2_y);
    
    
    ofPolyline line;
    line.addVertex(s1);
    line.bezierTo(s2, t1, t2, 200);
    
    
    sx = rannsuu[9] *cos(t*PI / 180) + xcenter;
    sy = rannsuu[9] *sin(t*PI / 180) + ycenter;
    s1_x = sx + cos((t + rannsuu[0])*PI / 180)*w;
    s1_y = sy + sin((t + rannsuu[1])*PI / 180)*w;
    s2_x = sx + cos((t + rannsuu[2])*PI / 180)*w;
    s2_y = sy + sin((t + rannsuu[3])*PI / 180)*w;
    tx = rannsuu[8] *cos(s*PI / 180) + xcenter;
    ty = rannsuu[8] *sin(s*PI / 180) + ycenter;
    t1_x = tx + cos((s + rannsuu[4])*PI / 180)*w;
    t1_y = ty + sin((s + rannsuu[5])*PI / 180)*w;
    t2_x = tx + cos((s + rannsuu[6])*PI / 180)*w;
    t2_y = ty + sin((s + rannsuu[7])*PI / 180)*w;
    
    s1 = ofVec2f(s1_x, s1_y);
    s2 = ofVec2f(s2_x, s2_y);
    t1 = ofVec2f(t1_x, t1_y);
    t2 = ofVec2f(t2_x, t2_y);
    
    ofPolyline line2;
    line2.addVertex(s1);
    line2.bezierTo(s2, t1, t2, 200);
    
    //float x = 300*cos(s*PI / 180) + xcenter;
    //float y = 300*sin(s*PI / 180) + ycenter;
    //t1_x = x + cos((s + 90)*PI / 180) * w;
    //t1_y = y + sin((s + 90)*PI / 180) * w;
    //t2_x = x + cos((s + 270)*PI / 180) * w;
    //t2_y = y + sin((s + 270)*PI / 180) * w;
    //ofPolyline line3;
    //t1 = ofVec2f(t1_x, t1_y);
    //t2 = ofVec2f(t2_x, t2_y);
    //line3.addVertex(t1);
    //line3.lineTo(t2);
    
    
    line.draw();
    line2.draw();
    //line3.draw();
    
    //exp.end();
    //exp.draw(0, 0);
    
    s = s + 1;
    t = t - 1;
    
    
    for (int i = 0; i < 10; i++) {
        rannsuu[i] += noise[i]*ofNoise(1)*hugou[i];
        noise[i] += ofRandom(0,1);
        if(rannsuu[i]>360) hugou[i]=-1;
        if(rannsuu[i]<0) hugou[i]=1;
        if(noise[i]>1) noise[i]=0;
    }
    
    if (s>=360) {
        s = 0;
        t = 360;
        //for (int i = 0; i < 10; i++) {
            //rannsuu[i] = ofRandom(s, t);
        //}
    }
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
