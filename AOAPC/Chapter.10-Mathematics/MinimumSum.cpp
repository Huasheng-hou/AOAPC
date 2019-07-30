//
//  MinimumSum.cpp
//  AOAPC
//
//  Created by apple on 2019/7/29.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <math.h>
#include <string.h>

// * Problem ID 10791 Minimum Sum LCM

using namespace std;

static bool a[1<<30];

class MinimumSum {
  
    public: void minimal() {
    
        for (int i = 0; i < 1<<30; i ++) {
            a[i] = true;
        }
    }
};
