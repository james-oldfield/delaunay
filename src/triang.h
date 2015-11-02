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
#include "del.h"
#include "ofEvents.h"


class Triang {
  private:
    bool delImagePopulated; // Keep track of whether the ofImage has been loaded
    Delaunay triangulation; // Triangulation object
  public:
    Triang();
    bool state; // State - show this module?
  
    // Bind the keypress event
    void _mousePressed(ofMouseEventArgs & e);
  
    ImageInput * image; // Pointer to the image loader
    void bindInput(ImageInput * _image); // Binds the image loader pointer to the obj
    ofImage delImage; // Image with which to perform triangulation on
    bool loadImage(); // loads the image into delImage from image loader. returns false if failed.
    vector<ofPoint> triVec; // Contains the points to draw the triangles
    void mount();
};

#endif /* defined(____triang__) */
