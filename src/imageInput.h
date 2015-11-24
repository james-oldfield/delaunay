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
#include "helper.hpp"

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
    ~ImageInput();
  
    unique_ptr<Helper> helper; // Helper object for information
    vector<string> loadHelperText();
  
    bool newImage; // Has there been a new image loaded (image pressed in this state)
    bool state;
    void draw();
    string getUrl();
    void mount();
    void dismount(); // Function pointer used to dismount the state and change the newImage to false
  
    /*
     * getters and setters
     */
    ofTrueTypeFont * getFont();
    int getX();
    int getY();

    // Bind the keypress event
    void _keyPressed(ofKeyEventArgs & e);
};

#endif /* defined(____imageInput__) */
