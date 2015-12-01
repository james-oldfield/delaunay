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
  
  panel.add(transPerc.set("Triangles' transparency", 200, 0, 255));
  panel.setPosition(50, ofGetHeight()-50);
}

void GUI::initListeners() {
  if(state) {
    transPerc.addListener(this, &GUI::paramChanged);
  } else {
    transPerc.removeListener(this, &GUI::paramChanged);
  }
}

void GUI::paramChanged(int & param) {
  newTransVal = true;
}

GUI::~GUI() {
  delete this;
}

