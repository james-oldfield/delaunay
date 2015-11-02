//
//  triang.cpp
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#include "triang.h"

Triang::Triang(): state(false) {};// loader will be displayed first, so defaults to false initially

/*
 * Entry method to exectue initial state of triangulation
 */
void Triang::mount() {
  if(state) {
    ofAddListener(ofEvents().mouseReleased, this, &Triang::_mousePressed); // Add event listener for keyboard
    // If the image is loading correctly, proceed else throw error
    if(loadImage()){
      image->getFont()->drawString("Begin the triangulation by clicking three times to create supertriangle.", 10, 10);
      ofNoFill();
      delImage.draw(0,0);
      ofFill();
      triangulation.draw();
    } else {
      // Catch for when the error doesn't load successfully
      string error = "Error loading your image. Did you get the file path right?";
      image->getFont()->drawString(error, 20, image->getY());
    }
  } else {
    // Remove the event listener once unmounted
    ofRemoveListener(ofEvents().mouseReleased, this, &Triang::_mousePressed);
  }
  return;
}

/*
 * Handle the keypress event depending on the type of keyboard input
 */
void Triang::_mousePressed(ofMouseEventArgs &e) {
  triangulation.addPoint(ofPoint(e.x, e.y));
  triangulation.triangulate();
}

void Triang::bindInput(ImageInput * _image) {
  image = _image;
}

bool Triang::loadImage() {
  // Run check to see if the image has changed from the loader
  if(image->newImage) {
    delImage.loadImage(image->getUrl());
    
    if(delImage.isAllocated()) {
      // If the image has successfully loaded
      delImagePopulated = true;
      image->newImage = false;
      
      return true;
    } else {
      // return error
      return false;
    }
  }
  return true;
}