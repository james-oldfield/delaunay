//
//  imageInput.h
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#ifndef ____imageInput__
#define ____imageInput__

#include "ofApp.h"

class ImageInput {
  private:
    ImageInput();
    string url;
  
    void draw(int x, int y);
  
  
  public:
    void appendUrl(string s);
    void clearUrl();
    string getUrl();
};

#endif /* defined(____imageInput__) */
