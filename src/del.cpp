//
//  del.cpp
//  
//
//  Created by James Oldfield on 02/11/2015.
//
//

#include "del.h"

vector <ofPoint> Delaunay::getTriangles() {
  vector <ofPoint> myTris;
  // So long as there's at least one triangle, return a vector of ITRIANGLE objs
  if(getNumTriangles() > 0) {
    ITRIANGLE t;
    vector <ofPoint> points;
    
    // NOTE - I have edited the library header file and changed PRIVATE members to PROTECTED
    // So that i can inherit them.
    
    for(int i=0; i<getNumTriangles(); i++) {
      t = getTriangleAtIndex(i);
      points.push_back( ofPoint(vertices[t.p1].x, vertices[t.p1].y, vertices[t.p1].z));
      points.push_back( ofPoint(vertices[t.p2].x, vertices[t.p2].y, vertices[t.p2].z));
      points.push_back( ofPoint(vertices[t.p3].x, vertices[t.p3].y, vertices[t.p3].z));
    }
    return points;
  }
}
