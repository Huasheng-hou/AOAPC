//
//  SpyInMetro.cpp
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

// * 递推法，从后向前，DAG最长路问题

using namespace std;

class SpyInMetro {
  
    int n, T, M1, M2, t[100], dp[200+2][50+2];
    bool has_train[200 + 2][50 + 2][2];
    
    public: void minimalTime() {
        
        int count = 0;
        while (cin >> n >> T) {
            
            count ++;
            
            memset(has_train, 0, sizeof(has_train));
            
            int time, m; t[0] = 0; t[n] = 0;
            for (int i = 1; i <= n-1; i ++) {
                    
                cin >> time;
                t[i] = time;
            }
            
            cin >> M1;
            for (int i = 0; i < M1; i ++) {
                
                cin >> m;
                
                for (int k = 1; k <= n; k ++) {
                    m += t[k-1];
                    if (m > T) break;
                    has_train[m][k][0] = true;
                }
            }
            cin >> M2;
            for (int i = 0; i < M2; i ++) {
                
                cin >> m;
                
                for (int k = n; k >= 1; k --) {
                    m += t[k];
                    if (m > T) break;
                    has_train[m][k][1] = true;
                }
            }
            
            // * 分支定界法，不可接受的值
            for (int i = 1; i <= n-1; i ++) dp[T][i] = 1<<20;
            dp[T][n] = 0;
            
            for (int i = T-1; i >= 0; i --) {
                for (int j = 1; j <= n; j ++) {
                    dp[i][j] = dp[i+1][j] + 1;
                    if (j < n && has_train[i][j][0] && i + t[j] <= T) {
                        dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
                    }
                    if (j > 1 && has_train[i][j][1] && i + t[j-1] <= T) {
                        dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
                    }
                }
            }
            
            cout << "Case Number " << count << ": ";
            if (dp[0][1] >= 1<<20) {
                cout << "impossible";
            } else {
                cout << dp[0][1];
            }
            cout <<"\n";
        }
    }
};
