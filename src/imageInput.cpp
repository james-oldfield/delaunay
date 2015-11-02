//
//  imageInput.cpp
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#include "imageInput.h"

ImageInput::ImageInput() {
  url = "james";
  cursor = 0; // Set the cursor positon to 0
  
  helvetica.load("Helvetica.ttf", 30);
}

void ImageInput::init() {
  ofAddListener(ofEvents().keyPressed, this, &ImageInput::_keyPressed);
}

/*
 * Draw the text input on the screen
 */
void ImageInput::draw() {
  helvetica.drawString(url, posX, posY);
}

/*
 * Handle the keypress event
 */
void ImageInput::_keyPressed(ofKeyEventArgs &e) {
  // If the key is a character, append it to the string
  if (e.key >=32 && e.key <=126) {
//    url += to_string(e.key);
    cout << url << endl;
    cout << e.key << endl;
//    cursor++;
    return;
  }
  
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
      if(cursor<url.size()+1)
        cursor--;
      break;
    case OF_KEY_LEFT:
      if(cursor>0)
        cursor++;
      break;
    default:
      cout << "unhandled key, sorry!" << endl;
      break;
  }
}