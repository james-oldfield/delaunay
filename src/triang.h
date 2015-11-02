//
//  triang.h
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#ifndef ____triang__
#define ____triang__

#include "ofMain.h"
#include "imageInput.h"
#include "ofxDelaunay.h"

class Triang {
  private:
    bool delImagePopulated; // Keep track of whether the ofImage has been loaded
    ofxDelaunay triangulation; // Triangulation object
  public:
    bool state; // State - show this module?
    Triang();
    ImageInput * image; // Pointer to the image loader
    void bindInput(ImageInput * _image); // Binds the image loader pointer to the obj
    ofImage delImage; // Image with which to perform triangulation on
    bool loadImage(); // loads the image into delImage from image loader. returns false if failed.
    void mount();
};

#endif /* defined(____triang__) */
