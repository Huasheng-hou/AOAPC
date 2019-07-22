//
//  JinGeJinQu.cpp
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

static const int maxn = 50 + 2;

class JinGeJinQu {
  
    public: void maxSongs () {
    
        int count, n, t, song[maxn], dp[maxn*180 + 678], inq[maxn];
        cin >> count;
        
        for (int k = 1; k <= count; k ++) {
            
            memset(dp, -1, sizeof(dp));
            memset(inq, 0, sizeof(inq));
            dp[0] = 0;
            
            cin >> n >> t;
            int len;
            for (int i = 1; i <= n; i ++) {
                cin >> len;
                song[i] = len;
            }
            
            for (int i = 1; i <= t; i ++) {
                dp[i] = 0;
            }
            
            for (int i = 1; i <= n; i ++) {
                for (int v = t - 1; v >= song[i]; v--) {
                    
                    if (dp[v - song[i]] >= 1 || v == song[i]) {   
                        dp[v] = max(dp[v], dp[v - song[i]] + 1);
                    }
                }
            }
            
            int max = 0, time = 0;
            for (int i = 1; i < t; i ++) {
                if (dp[i] >= max && dp[i] > 0) {
                    max = dp[i];
                    time = i;
                }
            }
            
            time += 678;
            
            cout << "Case " << k << ": " << max+1 << " " << time << "\n";
        }
    }
};
