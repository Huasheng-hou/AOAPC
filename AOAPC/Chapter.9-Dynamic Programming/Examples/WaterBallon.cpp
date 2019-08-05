//
//  WaterBallon.cpp
//  AOAPC
//
//  Created by apple on 2019/8/5.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>

// * 10934 Dropping water ballons
// * 用气球数 k 和实验次数 t 作为状态参数
// * 状态转移方程：dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;

static const int maxK = 100;
static const int maxT = 64;

using namespace std;

class WaterBallon {
    int k, t;
    unsigned long long n, dp[maxK+2][maxT+2];
    
public:
    void solve() {
        
        memset(dp, 0, sizeof(dp)); // * 必须完全确定气球强度
        
        for (int i = 1; i <= maxK; i++) {
            for (int j = 1; j <= maxT; j++) {
                
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1;
            }
        }
        
        while (cin >> k >> n && k > 0 && n > 0) {
        
            t = 65;
            for (int i = 1; i <= maxT; i ++) {
                if (dp[k][i] >= n) { t = i; break; }
            }
            
            if (t < 64) {
                cout << t;
            } else {
                cout << "More than 63 trials needed.";
            }
            cout << "\n";
        }
    }
};
