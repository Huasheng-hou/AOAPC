//
//  UniTSP.cpp
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

using namespace std;

static const int maxm = 10 + 2;
static const int maxn = 100 + 2;

class UniTSP {
    
    int dp[maxm][maxn], n, m, next[maxm][maxn];
    int matrix[maxm][maxn];
    
    public: void TSP () {
    
        while (cin >> m >> n) {
            
            memset(dp, 0, sizeof(dp));
            
            for (int i = 1; i <= m; i ++) {
                for (int j = 1; j <= n; j ++) {
                    cin >> matrix[i][j];
                }
            }
            
            for (int i = 1; i <= m; i ++) {
                dp[i][n] = matrix[i][n];
            }
            
            for (int i = n-1; i >= 1; i --) {
                for (int j = 1; j <= m; j++) {
                    
                    int rows[3];
                    
                    rows[0] = j - 1 <= 0 ? m : j - 1;
                    rows[1] = j;
                    rows[2] = j + 1 > m ? 1 : j + 1;
                    
                    sort(rows, rows + 3);
                    int a = matrix[j][i];
                    
                    int ans = dp[rows[2]][i+1] + a;
                    next[j][i] = rows[2];
                    
                    for (int k = 1; k >= 0; k --) {
                        if (dp[rows[k]][i+1] + a <= ans) {
                            ans = dp[rows[k]][i+1] + a;
                            next[j][i] = rows[k];
                        }
                    }
                    dp[j][i] = ans;
                }
            }
            
            int first = 1, ans = dp[m][1];
            for (int i = m; i >= 1; i --) {
                if (dp[i][1] <= ans) {
                    first = i;
                    ans = dp[i][1];
                }
            }
            
            for (int i = 1; i <= n; i ++) {
                cout << first;
                first = next[first][i];
                if (i < n) cout << " ";
            }
            cout << "\n";
            cout << ans << "\n";
        }
    }
};
