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
#include "Chapter.11-Graph Theory/Audiophobia.cpp"
#include "Chapter.11-Graph Theory/BugOrFeature.cpp"
#include "Chapter.11-Graph Theory/PlugForUnix.cpp"

int main(int argc, const char * argv[]) {
    
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output","w",stdout);
    
    clock_t start,end;
    start = clock();
    
    PlugForUnix plug;
    plug.maximalPlugins();
    
    //需要测试运行时间的程序段
    end = clock();
    
//    cout<<"F1运行时间"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    
    return 0;
}
