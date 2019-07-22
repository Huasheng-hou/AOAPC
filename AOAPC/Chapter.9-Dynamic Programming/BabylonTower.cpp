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

using namespace std;

const int maxn = 30 + 2;

class BabylonTower {
    
    int blocks[maxn][3], dp[maxn][maxn][3], s[maxn][2], n;
    
    public: void tallestTower() {
    
        int count = 0;
        while (cin >> n && n > 0) {
            
            memset(dp, 0, sizeof(dp));
            
            for (int i = 1; i <= n; i ++) {
                
                cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
            }
            
//            sort(blocks, n, <#_Compare __comp#>)
            
            for (int i = 1; i <= n; i ++) {
                dp[1][i][0] = blocks[i][0];
                dp[1][i][1] = blocks[i][1];
                dp[1][i][2] = blocks[i][2];
            }
            
            for (int i = 2; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    DP(i, n);
                }
            }
            
            count ++;
            cout << "Case " << count << "\n";
        }
    }
    
    private: void DP (int h, int m) {
        
        if (h < 2) return;
        for (int i = 1; i <= n; i ++) {
            if (i == m) continue;
            for (int k = 0; k <= 2; k ++) {
                if (dp[h-1][i][k] <= 0) continue;
                for (int j = 0; j <= 2; j ++) {
                    
                    
                }
            }
        }
    }
};
