//
//  BiggerBetter.cpp
//  AOAPC
//
//  Created by apple on 2019/7/29.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <math.h>
#include <string.h>

// * Problem ID:1336 Fixing the Great Wall
// * 实际上取BFS，但要注意合并状态

using namespace std;

static const int maxn = 10 + 2;
static const int maxd = 50 + 2;
static const int maxm = 3000 + 2;
static const int kn[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

typedef pair<int, int> node;

class BiggerBetter {
  
    int n, m, r[maxn], dp[maxd][maxm];
    vector<int> num[maxm], ans;
    
    public: void matchs() {
    
        int count = 0;
        while (cin >> n >> m && n > 0) {
            
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < maxm; i ++)
                num[i].clear();
            
            for (int i = 1; i < maxn; i ++) {
                r[i] = i%m;
            }
            
            for (int i = 1; i < maxd; i++) {
                for (int j = 0; j < m; j++ ) {
                    for (int k = 0; k <= 9; k++) {
                        
                        
                    }
                }
            }
            
            count ++;
            cout << "Case " << count << ":" << "\n";
        }
    }
};
