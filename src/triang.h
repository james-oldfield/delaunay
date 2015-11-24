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
#include "helper.hpp"

class Triang {
  private:
    bool delImagePopulated; // Keep track of whether the ofImage has been loaded
    Delaunay triangulation; // Triangulation object
  public:
    Triang(ImageInput * _image, GUI * _gui);
    ~Triang();
  
    bool state; // State - show this module?
  
    unique_ptr<Helper> helper; // Helper object for information
    vector<string> loadHelperText();
  
    function<void()> cb = [&] { image->dismount(); }; // Lambda to Capture function callback to dismount image
    function<void()> reset = [&] { triangulation.reset(); }; // Alias to the reset method in triangulation
    function<void()> removeLast = [&] { triangulation.removeLastPoint(); }; // Alias to the removeLastPoint method
  
    // Bind the mousepressed event
    void _mousePressed(ofMouseEventArgs & e);
    // Bind the keypress event
    void _keyPressed(ofKeyEventArgs & e);
  
    ImageInput * image; // Pointer to the image loader
    GUI * gui;
  
    ofImage delImage; // Image with which to perform triangulation on
    bool bgMode = true; // Controls whether to show the image or not
    bool loadImage(function<void()> callback); // loads the image into delImage from image loader. returns false if failed. Takes a callback func
    void updateTrans(float const & newTrans);
    void mount();
};

#endif /* defined(____triang__) */
