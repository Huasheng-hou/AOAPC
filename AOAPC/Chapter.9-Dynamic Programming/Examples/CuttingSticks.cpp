//
//  CuttingSticks.cpp
//  AOAPC
//
//  Created by apple on 2019/7/24.
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

// * 线性DP，状态方程：dp(i,j) = min{dp(i,k)+dp(k,j)}, i<k<j;
// * 实际求解使用记忆化搜索

using namespace std;

static const int maxn = 50 + 2;

class CuttingSticks {
  
    int dp[maxn][maxn], L, n, c[maxn];
    
    public: void cut() {
    
        while (cin >> L >> n && L > 0) {
            
            memset(dp, 0, sizeof(dp));
            
            for (int i = 1; i <=n; i ++) {
                cin >> c[i];
            }
            c[n+1] = L; c[0] = 0;
            for (int i = 2; i <= n+1; i ++) {
                dp[i-1][i] = c[i] - c[i-2];
            }
            
            cout << "The minimum cutting is " << DP(1, n+1) << ".\n";
        }
    }
    
    private: int DP(int i, int j) {
        
        if (i == j) return 0;
        if (dp[i][j]) return dp[i][j];
        
        int d = 1<<30;
        for (int k = i; k < j; k ++) {
            d = min(d, DP(i, k) + DP(k+1, j));
        }
        dp[i][j] = d + c[j]-c[i-1];
        
        return dp[i][j];
    }
};
