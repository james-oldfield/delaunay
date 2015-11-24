//
//  helper.cpp
//  delaunay
//
//  Created by James Oldfield on 24/11/2015.
//
//

#include "helper.hpp"

Helper::Helper(bool _colour, vector<string> _messages, int _fontSize): messages(_messages), colour(_colour), pos(ofGetWidth()-75, ofGetHeight()-75), fontSize(_fontSize) {
  // Load the helper icon depending on what colour we want
  (colour) ? icon.loadImage("helpBlack.png") : icon.loadImage("helpWhite.png");
  helvetica.load("hLight.ttf", fontSize);
}

void Helper::drawIcon() {
  // cache the mouse loactions from main app instance to prevent having to call method every time
  auto xLoc = ofGetAppPtr()->mouseX;
  auto yLoc = ofGetAppPtr()->mouseY;
  
  ofPushStyle();
  (colour) ? ofSetColor(ofColor(0)) : ofSetColor(ofColor(255));
  icon.draw(pos, 50, 50);
  ofPopStyle();
  
  if(xLoc < pos.x + 75
     && xLoc > pos.x
     && yLoc < pos.y + 75
     && yLoc > pos.y)
    drawHelper();
}

void Helper::drawHelper() {
  int lcl = 0; // Largest character length
  string longestString;
  
  /*
   * Lambda to compare string to
   * current longest sting length
   */
  auto pred = [&lcl, &longestString] (string s) {
    if (s.length() > lcl) {
      lcl = s.length();
      longestString = s;
    }
  };
  
  // For each message, pass its length into pred lambda.
  for_each(messages.begin(), messages.end(), pred);
  
  int   padding   = 5;
  float leading   = 1.7;
  int   height    = messages.size() * fontSize * leading - 1;
  
  auto bb = helvetica.getStringBoundingBox(longestString, 0, 0);
  
  // Draw the background
  ofPushStyle();
    glDepthMask(false);
    (colour) ? ofSetColor(ofColor(0)) : ofSetColor(ofColor(255)); // Set colour depending on what's passed into constructor
    ofFill();
    ofDrawRectangle(20, 20, bb.width+(padding*10), height+(padding*7.5));
  
  for(int i=0; i<messages.size(); i++) {
      (colour) ? ofSetColor(ofColor(255)) : ofSetColor(ofColor(0));
      ofNoFill();
      helvetica.drawString(messages[i], 20+padding*5, 20*(i+2)+padding*5);
      glDepthMask(true);
    ofPopStyle();
  }
}

/*
 * Public getter for the font
*/
ofTrueTypeFont * Helper::getFont() {
  return &helvetica;
}