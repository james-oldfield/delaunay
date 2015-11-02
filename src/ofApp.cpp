#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableSmoothing();
  ofBackground(0);
  
  delImagePopulated = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  imageLoader.mount();
  loadImage();
}

void ofApp::loadImage() {
  if(imageLoader.newImage) {
    delImage.loadImage(imageLoader.getUrl());
    delImagePopulated = true;
    
    imageLoader.newImage = false;
  }
  
  if(delImagePopulated) {
    delImage.draw(0, 0);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // Switch state to image loader on 'f10' key
  if(key == OF_KEY_F10) {
    imageLoader.state =! imageLoader.state;
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
  triangulation.addPoint(ofPoint(x,y));
  triangulation.triangulate();
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
