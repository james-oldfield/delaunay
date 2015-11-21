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
  
    template<typename Callback>
    void handleError(string errorCode, Callback &cb = NULL); // generic error handler with callback
    int triangulate();
    void addColour(ofColor _c);
    void draw();
    void drawTri();
    void reset();
    void removeLastPoint();
  
    vector<ofColor> pointCols; // Stores the colours of the added triangles
};

#endif /* defined(____del__) */
