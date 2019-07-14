//
//  main.cpp
//  AOAPC
//
//  Created by apple on 2019/7/14.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include "Chapter.11-Graph Theory/SlimSpan.cpp"
#include "Chapter.11-Graph Theory/CallingCircles.cpp"

int main(int argc, const char * argv[]) {
    
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output","w",stdout);
    
    CallingCircles callCircle;
    callCircle.getCallingCircles();
    
    return 0;
}
