//
//  imageInput.h
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#ifndef ____imageInput__
#define ____imageInput__

#include "ofApp.h"
#include "ofEvents.h"

class ImageInput {
  private:
    string url;
    int posX;
    int posY;
  
    void draw();
  
    int cursor;
    ofTrueTypeFont helvetica;
  
  public:
    ImageInput();
  
    /*
     * Getters and setters
     */
    void appendUrl(string s);
    void clearUrl();
    string getUrl();
  
    void init();

    // Bind the keypress event
    void _keyPressed(ofKeyEventArgs & e);
};

#endif /* defined(____imageInput__) */
