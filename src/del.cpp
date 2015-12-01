//
//  del.cpp
//  
//
//  Created by James Oldfield on 02/11/2015.
//
//

#include "del.h"

/*
 * Generic error handler with optional callback parameter
 * Takes a string to print error and a lambda callback, defaulting to NULL
 */
template<typename Callback>
void Delaunay::handleError(string error, Callback &cb) {
  cout << error << endl;
  // If optional callback is supplied, exectute
   cb();
}

vector <ofPoint> Delaunay::getTriangles() {
  vector <ofPoint> myTris;
  // So long as there's at least one triangle, return a vector of ITRIANGLE objs
  if(getNumTriangles() > 0) {
    ITRIANGLE t;
    vector <ofPoint> points;
    
    // NOTE - I have edited the library header file and changed all PRIVATE members to PROTECTED
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

/*
 * Pretty much the library method, simply overriding it to add the ability to add colour when verticies are added to the mesh.
 */
int Delaunay::triangulate(){
  
  if(vertices.size() < 3){
    return NULL;
  }
  
  int nv = vertices.size();
  
  // make clone not to destroy vertices
  vector<XYZI> verticesTemp = vertices;
  qsort( &verticesTemp[0], verticesTemp.size(), sizeof( XYZI ), XYZICompare );
  
  //vertices required for Triangulate
  vector<XYZ> verticesXYZ;
  
  //copy XYZIs to XYZ
  for (int i = 0; i < nv; i++) {
    XYZ v;
    v.x = verticesTemp.at(i).x;
    v.y = verticesTemp.at(i).y;
    v.z = verticesTemp.at(i).z;
    verticesXYZ.push_back(v);
  }
  
  //add 3 emptly slots, required by the Triangulate call
  verticesXYZ.push_back(XYZ());
  verticesXYZ.push_back(XYZ());
  verticesXYZ.push_back(XYZ());
  
  //allocate space for triangle indices
  triangles.resize(3*nv);
  
  Triangulate( nv, &verticesXYZ[0], &triangles[0], ntri );
  
  // clear the mesh
  triangleMesh.clear();
  triangleMesh.setMode(OF_PRIMITIVE_TRIANGLES);
  
  //copy vertices
  for (int i = 0; i < nv; i++){
    triangleMesh.addVertex(ofVec3f(vertices[i].x,vertices[i].y,vertices[i].z));
    triangleMesh.addColor(pointCols[i]);
  }
  
  //copy triangles
  for(int i = 0; i < ntri; i++){
    triangleMesh.addIndex(verticesTemp.at(triangles[ i ].p1).i);
    triangleMesh.addIndex(verticesTemp.at(triangles[ i ].p2).i);
    triangleMesh.addIndex(verticesTemp.at(triangles[ i ].p3).i);
  }
  
  return ntri;
}

/*
 * Function to add the colour of the point to a vector used in the triangulate method.
 */
void Delaunay::addColour(ofColor _c) {
  this->pointCols.push_back(_c);
  
  return;
}

/*
 * Perform a hard-reset on the whole triangulation
 */
void Delaunay::reset(){
  vertices.clear();
  triangles.clear();
  triangleMesh.clear();
  pointCols.clear();
  
  ntri = 0;
}

/*
 * Function to remove the last added point from the triangulation and the colour
 */
void Delaunay::removeLastPoint() {
  auto callback = [&] () { triangulate(); };
  if(vertices.size() != 0) {
    vertices.erase(vertices.end()-1); // Delete the point from mesh
    pointCols.erase(pointCols.end()-1); // Delete the colour value
    callback();
  } else {
    reset();
    handleError("can't remove anymore vertices!", callback);
    return;
  }
}

/*
 * Override the inherited draw method
 */
void Delaunay::draw(){
  triangleMesh.draw();
  ofSetColor(255);
  triangleMesh.drawWireframe();
}
