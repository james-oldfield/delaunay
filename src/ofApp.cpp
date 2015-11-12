#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableSmoothing();
  ofBackground(0);
  
  tri.bindInput(&imageLoader); // Binds the image loader to the triangulate class
  tri.bindGUI(&gui);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  run();
}

void ofApp::run() {
  /*
   * Start of main program, draw the different states.
   */
  if(imageLoader.state) {
    imageLoader.mount();
  }
  else if(tri.state) {
    tri.mount();
  }
  
  if(!imageLoader.state) {
    // No pointer to tri in state so it needs to be altered through a middleman class, here
    tri.state = true;
  }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // Switch state to image loader on 'f10' key
  if(key == OF_KEY_F10) {
    imageLoader.state =! imageLoader.state;
    imageLoader.mount();
    
    tri.state =! tri.state;
  }
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
