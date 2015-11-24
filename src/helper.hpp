//
//  helper.hpp
//  delaunay
//
//  Created by James Oldfield on 24/11/2015.
//
//

#ifndef helper_hpp
#define helper_hpp

#include "ofMain.h"

class Helper {
  
  private:
    vector<string> messages;
    ofImage icon;
    ofVec2f pos;
    ofTrueTypeFont helvetica;
    int fontSize;
    bool colour;
  
  public:
    Helper(bool colour, vector<string> _messages);
    void drawHelper();
    void drawIcon();
};

#endif /* helper_hpp */
