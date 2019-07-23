//
//  main.cpp
//  AOAPC
//
//  Created by apple on 2019/7/14.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
//#include "Chapter.9-Dynamic Programming/SpyInMetro.cpp"
#include "Chapter.9-Dynamic Programming/BabylonTower.cpp"
//#include "Chapter.9-Dynamic Programming/Tour.cpp"
//#include "Chapter.9-Dynamic Programming/JinGeJinQu.cpp"
#include "Chapter.11-Graph Theory/SlimSpan.cpp"
#include "Chapter.11-Graph Theory/CallingCircles.cpp"
#include "Chapter.11-Graph Theory/Audiophobia.cpp"
//#include "Chapter.11-Graph Theory/BugOrFeature.cpp"
//#include "Chapter.11-Graph Theory/PlugForUnix.cpp"
//#include "Chapter.11-Graph Theory/OptimalBusRoute.cpp"
#include "Chapter.11-Graph Theory/FunnyCarRacing.cpp"
#include "Chapter.10-Mathematics/ChooseAndDivide.cpp"

int main(int argc, const char * argv[]) {
    
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output","w",stdout);
    
    BabylonTower tower; tower.tallestTower();
    
    return 0;
}
