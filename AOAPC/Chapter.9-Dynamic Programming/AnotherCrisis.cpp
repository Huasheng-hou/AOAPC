//
//  AnotherCrisis.cpp
//  AOAPC
//
//  Created by apple on 2019/7/23.
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

// * 树状结构，递归求解

using namespace std;

static const int maxn = 100000 + 2;

class AnotherCrisis {
  
    vector<int> sons[maxn];
    int dp[maxn], n, t, np;
    
    public: void Petition() {
    
        while (cin >> n >> t && n > 0 && t > 0) {
            
            for (int i = 0; i < maxn; i ++) dp[i] = 1;
            for (int i = 0; i < maxn; i ++) sons[i].clear();
            
            int father;
            for (int i = 1; i <= n; i ++) {
                cin >> father;
                sons[father].push_back(i);
            }
            
            np = 0;
            int span = (int)sons[0].size(); int a[span];
            for (int i = 0; i < span; i ++) {
                a[i] = DP(sons[0][i]);
            }
            sort(a, a + span);
            for (int i = 0; i < span * t / 100.; i ++) {
                np += a[i];
            }
            
            cout << np << "\n";
        }
    }
    
    int DP(int i) {
        
        if (dp[i] > 1 || sons[i].size() <= 0) return dp[i];
        
        int d = 0;
        int span = (int)sons[i].size(); int a[span];
        for (int j = 0; j < span; j ++) {
            a[j] = DP(sons[i][j]);
        }
        sort(a, a + span);
        for (int j = 0; j < span * t / 100.; j ++) {
            d += a[j];
        }
        dp[i] = d;
        return dp[i];
    }
};
