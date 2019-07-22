//
//  Tour.cpp
//  AOAPC
//
//  Created by apple on 2019/7/22.
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

using namespace std;

static const int maxn = 1000 + 2;

class Tour {
  
    int x[maxn][2], n;
    double dp[maxn][maxn];
    
    public: void shortPath () {
    
        while (scanf("%d", &n) >= 1) {

            for (int i = 1; i <= n; i ++) {

                scanf("%d%d", x[i], x[i] + 1);
            }

            for (int i = 1; i < n-1; i ++) {
                dp[n-1][i] = dist(x[n], x[n-1]) + dist(x[n], x[i]);
            }
            for (int i = n-2; i >= 2; i --) {
                for (int j = i-1; j >= 1; j --) {

                    double d1 = dist(x[i+1], x[i]) + dp[i+1][j];
                    double d2 = dist(x[i+1], x[j]) + dp[i+1][i];

                    dp[i][j] = min(d1, d2);
                }
            }

            printf("%.2lf\n", dp[2][1] + dist(x[1], x[2]));
        }
    }
    
    private: double dist(int * x, int * y) {
    
        return sqrt((x[0] - y[0]) * (x[0] - y[0])
                    + (x[1] - y[1])*(x[1] - y[1]));
    }
};
