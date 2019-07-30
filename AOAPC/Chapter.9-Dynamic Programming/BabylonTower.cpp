//
//  BabylonTower.cpp
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

// * 记忆化搜索

using namespace std;

static const int maxn  = 30 + 2;
static const int dim   = 3;

class BabylonTower {
    
    int blocks[maxn][dim], dp[maxn][dim], n;
    
    public: void tallestTower() {
    
        int count = 0;
        while (cin >> n && n > 0) {
            
            memset(dp, 0, sizeof(dp));
            
            for (int i = 1; i <= n; i ++) {
                
                cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
                sort(blocks[i], blocks[i] + 3);
            }
            
            int ans = 0;
            for (int i = 1; i <= n; i ++) {
                for (int j = 0; j < 3; j ++) {
                    ans = max(ans, DP(i, j));
                }
            }
            
            count ++;
            cout << "Case " << count << ": maximum height = " << ans << "\n";
        }
    }
    
    private: int DP (int i, int j) {
        
        int &ans = dp[i][j];
        if (ans > 0) return ans; // * 记忆化搜索
        ans = 0;
        for (int m = 1; m <= n; m ++) {
            for (int k = 0; k <= 2; k ++) {
                if (canStack(i, m, j, k)) {
                    ans = max(ans, DP(m, k));
                }
            }
        }
        ans += blocks[i][j];
        return ans;
    }
    
    private: bool canStack(int u, int v, int m1, int m2) {
    
        int v1[2], v2[2], idx1 = 0, idx2 = 0;
        for (int i = 0; i <= 2; i ++) {
            
            if (m1!=i) {
                v1[idx1] = blocks[u][i]; idx1 ++;
            }
            if (m2!=i) {
                v2[idx2] = blocks[v][i]; idx2 ++;
            }
        }
        
        if (v1[0] > v2[0] && v1[1] > v2[1]) return true;
        
        return false;
    }
};
