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
#include "gui.hpp"


class Triang {
  private:
    bool delImagePopulated; // Keep track of whether the ofImage has been loaded
    Delaunay triangulation; // Triangulation object
  public:
    Triang();
    bool state; // State - show this module?
  
    function<void()> cb = [&] { image->dismount(); }; // Lambda to Capture function callback to dismount image
    function<void()> reset = [&] { triangulation.reset(); }; // Alias to the reset method in triangulation
  
    // Bind the keypress event
    void _mousePressed(ofMouseEventArgs & e);
  
    ImageInput * image; // Pointer to the image loader
    GUI * gui;
  
    void bindInput(ImageInput * _image); // Binds the image loader pointer to the obj
    void bindGUI(GUI * _gui);
  
    ofImage delImage; // Image with which to perform triangulation on
    bool loadImage(function<void()> callback); // loads the image into delImage from image loader. returns false if failed. Takes a callback func
    vector<ofPoint> triVec; // Contains the points to draw the triangles
    float transPerc = 245;
    void updateTrans(float & newTrans);
    void mount();
};

#endif /* defined(____triang__) */
