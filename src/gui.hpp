//
//  gui.hpp
//  delaunay
//
//  Created by James Oldfield on 12/11/2015.
//
//

#ifndef gui_hpp
#define gui_hpp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofEvents.h"

class GUI {
  
  public:
    explicit GUI();
    ~GUI();
    ofxPanel panel;
    float transPerc = 75; // Default value of 75
    ofxSlider<float> transp; // float slider from the template class
};

#endif /* gui_hpp */
