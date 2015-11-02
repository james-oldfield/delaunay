//
//  imageInput.cpp
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#include "imageInput.h"

ImageInput::ImageInput() {
  newImage = false;
  state = true;
  placeholder = "type in absolute image url";
  cursor = url.size(); // Set the cursor positon end of default text
  posX = 50;
  posY = ofGetWindowHeight()/2;
  textSize = 20;
  tempBox = helvetica.getStringBoundingBox(placeholder, 0 ,0);
  
  helvetica.load("Helvetica.ttf", textSize);
  helper.load("Helvetica.ttf", textSize/1.6);
}

/*
 * Handle the keypress event depending on the type of keyboard input
 */
void ImageInput::_keyPressed(ofKeyEventArgs &e) {
  // If the key is a character, append it to the string
  if (e.key >=32 && e.key <=126) {
    url.insert(url.begin()+cursor, e.key);
    cursor++;
    return;
  }
  
  // Handlers to move cursor and remove from string
  switch (e.key) {
    case OF_KEY_BACKSPACE:
      if(cursor > 0) {
        url.erase(url.begin() + cursor-1);
        cursor--;
      }
      break;
    case OF_KEY_DEL:
      if(url.size() > cursor)
        url.erase(url.begin() + cursor);
      break;
    case OF_KEY_RIGHT:
      if(cursor<url.size())
        cursor++;
      break;
    case OF_KEY_LEFT:
      if(cursor>0)
        cursor--;
      break;
    case OF_KEY_RETURN:
      newImage = true;
      state = false;
      break;
    default:
      cout << "unhandled key, sorry!" << endl;
      break;
  }
}

/*
 * Entry function to mount the loader.
 * Adds/removes the keyboard event listeners.
 */
void ImageInput::mount() {
  if(state) {
    newImage = false;
    ofAddListener(ofEvents().keyPressed, this, &ImageInput::_keyPressed);
    ImageInput::draw();
  } else {
    ofRemoveListener(ofEvents().keyPressed, this, &ImageInput::_keyPressed);
  }
  return;
}

/*
 * Public getter for url field
 */
string ImageInput::getUrl() {
  return url;
}
int ImageInput::getX() {
  return posX;
}
int ImageInput::getY() {
  return posY;
}
ofTrueTypeFont * ImageInput::getFont() {
  return &helper;
}

/*
 * Draw the text input on the screen
 */
void ImageInput::draw() {

  // Draw the bounding box
  boundingBox = helvetica.getStringBoundingBox(url, 0, 0);
  
  ofSetHexColor(0xffffff);
  ofFill();
  
  // Draw the temporary string if there is no text entered
  if(url.size() < 1) {
    ofRect(posX+tempBox.x-20, posY+tempBox.y-20, tempBox.width+40, tempBox.height+40);
    ofSetHexColor(0xd3d3d3);
    helvetica.drawString(placeholder, posX, posY);
  } else {
    ofRect(posX+boundingBox.x-20, posY+boundingBox.y-20, boundingBox.width+40, boundingBox.height+40);
    ofSetHexColor(0x000000);
    helvetica.drawString(url, posX, posY);
    
    // Draw the cursor
    ofSetHexColor(0x000000);
    if(ofGetElapsedTimeMillis()%1000 > 500) {
      helvetica.drawString("|", (posX+boundingBox.width), posY);
    }
  }
  
  // Draw helper text
  ofSetHexColor(0xd3d3d3);
  helper.drawString("Switch modes with f10 key. Type the url then press enter to load the image.", 50, posY+50);
  
}