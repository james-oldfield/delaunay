//
//  gui.cpp
//  delaunay
//
//  Created by James Oldfield on 12/11/2015.
//
//

#include "gui.hpp"


GUI::GUI() {
  panel.setup();
  
  panel.add(transp.setup("triangulation transparency", transPerc, 0, 100));
}

GUI::~GUI() {
  delete this;
}

