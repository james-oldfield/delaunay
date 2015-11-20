//
//  triang.cpp
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#include "triang.h"

Triang::Triang(ImageInput * _image, GUI * _gui): state(false), image(_image), gui(_gui){
  glShadeModel(GL_FLAT);
}; // set the shader mode to flat to prevent gradient fill upon construction.

Triang::~Triang() {
  delete image;
  delete gui;
  
  delete this;
}

/*
 * Entry method to exectue initial state of triangulation
 */
void Triang::mount() {
  if(state) {
    ofAddListener(ofEvents().mouseReleased, this, &Triang::_mousePressed); // Add event listener for keyboard
    ofAddListener(ofEvents().keyPressed, this, &Triang::_keyPressed);
    
    // If the image is loading correctly, proceed else throw error
    if(loadImage( cb ) && image->getUrl().size() > 0){
      ofNoFill();
      delImage.draw(0,0);
      ofFill();
      triangulation.draw();
      ofNoFill();
      image->getFont()->drawString("Begin the triangulation by clicking three times to create supertriangle.", 10, 20);
      image->getFont()->drawString("Further clicks will add points to the triangulation", 10, 40);
      
      gui->panel.draw();
    } else {
      // Catch for when the error doesn't load successfully
      string error = "Error loading your image. Did you get the file path right?";
      image->getFont()->drawString(error, 20, image->getY());
    }
  } else {
    // Remove the event listener once unmounted
    ofRemoveListener(ofEvents().mouseReleased, this, &Triang::_mousePressed);
    ofRemoveListener(ofEvents().keyPressed, this, &Triang::_keyPressed);
  }
  return;
}

/*
 * Updates the transparency of the mesh
 */
void Triang::updateTrans(float const & newTrans) {
  for(auto col : triangulation.pointCols) {
    col.a = newTrans;
  }
}

/*
 * Handle the keypress event depending on the type of keyboard input
 */
void Triang::_mousePressed(ofMouseEventArgs &e) {
  ofColor tempCol;
  
  unsigned char * pixels=delImage.getPixels(); // Get the pixels of the image
  int ind = e.y*delImage.getWidth()*3 + e.x*3;
  
//  tempImg.grabScreen(e.x, e.y, 1, 1); // Grab the image at mouse location
//  unsigned char * pix = tempImg.getPixels();
  
  tempCol.r = (float) pixels[ind];
  tempCol.g = (float) pixels[ind+1];
  tempCol.b = (float) pixels[ind+2];
  tempCol.a = transPerc;
  
  triangulation.addPoint(ofPoint(e.x, e.y));
  triangulation.addColour(tempCol);
  triangulation.triangulate();
}

/*
 * Handle the keypress event depending on the type of keyboard input
 */
void Triang::_keyPressed(ofKeyEventArgs &e) {
  
  if(!this->state) { return; }
  
  // Handlers to move cursor and remove from string
  switch (e.key) {
    case 'r':
      this->removeLast();
      break;
    default:
      break;
      return;
  }
}

/*
 * Loads the image and then callsback the callback function pointer
 * Takes an optional callback
 */
bool Triang::loadImage(function<void()> callback) {
  // Run check to see if the image has changed from the loader
  if(image->newImage) {
    delImage.loadImage(image->getUrl());
    
    if(delImage.isAllocated()) {
      // If the image has successfully loaded
      delImagePopulated = true;
      
      // Callback the callback function pointer
      callback();
      
      return true;
    } else {
      // return error
      return false;
    }
  }
  return true;
}