//
//  triang.cpp
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#include "triang.h"

Triang::Triang(): state(false) {};// loader will be displayed first, so defaults to false initially

void Triang::mount() {
  if(loadImage()){
    cout << "drawing image";
    delImage.draw(0,0);
  } else {
    // Catch for when the error doesn't load successfully
    string error = "Error loading your image. Did you get the file path right?";
    image->getFont()->drawString(error, 20, image->getY());
  }
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