//
//  imageInput.h
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#ifndef ____imageInput__
#define ____imageInput__

#include "ofMain.h"
#include "ofEvents.h"

class ImageInput {
  private:
    string url;
    string placeholder;
    int posX;
    int posY;
    int textSize;
    ofRectangle boundingBox;
    ofRectangle tempBox;

    int cursor;
    ofTrueTypeFont helvetica;
  
  public:
    ImageInput();
    void draw();
    void dismount();
    void mount();
    void clearUrl();

    // Bind the keypress event
    void _keyPressed(ofKeyEventArgs & e);
};

#endif /* defined(____imageInput__) */
