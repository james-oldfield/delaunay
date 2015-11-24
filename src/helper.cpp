//
//  helper.cpp
//  delaunay
//
//  Created by James Oldfield on 24/11/2015.
//
//

#include "helper.hpp"

Helper::Helper(bool _colour, vector<string> _messages): messages(_messages), colour(_colour), pos(ofGetWidth()-75, ofGetHeight()-75), fontSize(20) {
  // Load the helper icon depending on what colour we want
  (colour) ? icon.loadImage("helpBlack.png") : icon.loadImage("helpWhite.png");
  helvetica.load("Helvetica.ttf", 20);
}

void Helper::drawIcon() {
  // cache the mouse loactions from main app instance to prevent having to call method every time
  auto xLoc = ofGetAppPtr()->mouseX;
  auto yLoc = ofGetAppPtr()->mouseY;
  
  icon.draw(pos, 50, 50);
  
  if(xLoc < pos.x + 75
     && xLoc > pos.x
     && yLoc < pos.y + 75
     && yLoc > pos.y)
    drawHelper();
}

void Helper::drawHelper() {
  int lcl = 0; // Largest character length
  
  /*
   * Lambda to compare string to
   * current longest sting length
   */
  auto pred = [&lcl] (string s) {
    if (s.length() > lcl)
      lcl = s.length();
  };
  
  // For each message, pass its length into pred lambda.
  for_each(messages.begin(), messages.end(), pred);
  
  int   padding   = 4;
  float leading   = 1.7;
  int   height    = messages.size() * fontSize;
  int   width     = fontSize * lcl;
  
  // Draw the background
  ofPushStyle();
    glDepthMask(false);
    (colour) ? ofSetColor(ofColor(0)) : ofSetColor(ofColor(255)); // Set colour depending on what's passed into constructor
    ofFill();
    ofDrawRectangle(20, 20, width + 2 * padding, height + 2 * padding);
  ofPushMatrix();
  
  for(int i=0; i<messages.size(); i++) {
      (colour) ? ofSetColor(ofColor(255)) : ofSetColor(ofColor(0));
      ofNoFill();
      helvetica.drawString(messages[i], 20, 20*(i+2));
      glDepthMask(true);
    ofPopStyle();
  }
}