//
//  programState.h
//  
//
//  Created by James Oldfield on 31/10/2015.
//
//

#ifndef ____programState__
#define ____programState__

#include "ofApp.h"

/*
 * Singleton class to contain program state.
 * Created as singleton to avoid polution of global namespace
 * + to insure of only one instantiation.
 */

class State {
  private:
    State() {}; // Private constructor prevents instantiation by traditional methods
    State(State const&) = delete; // Removes the method to copy constructor, only want one program state obj
    void operator=(State const&) = delete; // Removes the method for the copy assignment operator
  
  public:
    /* Method declared as static so that it provides access to the class and lives until the end of the program.
     * getInstance provides a psuedo 'global' access to the singleton class containing Map of states.
     */
    static State & getInstance() {
      static State instance;
      return instance;
    };
};

#endif /* defined(____programState__) */
