//
//  del.h
//  
//
//  Created by James Oldfield on 02/11/2015.
//
//

#ifndef ____del__
#define ____del__

#include "ofMain.h"
#include "ofxDelaunay.h"

// Extend the basic delaunay library class
class Delaunay : public ofxDelaunay {
  public:
    vector<ofPoint> getTriangles();
    void drawTriangles();
};

#endif /* defined(____del__) */
