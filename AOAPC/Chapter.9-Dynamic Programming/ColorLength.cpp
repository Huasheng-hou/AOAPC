//
//  ColorLength.cpp
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

// * Problem ID: 1625
// * 线性DP，递推法，dp(i,j) = min{dp(i-1,j)+L(i), dp(i,j-1)+L(j)}
// * L(i)为增加颜色后 Lc 增量

using namespace std;

static const int maxn = 500 + 2;
static const int mc = 26 + 2;
static const int INF = 1<<30;

static int dp[maxn][maxn];

class ColorLength {
  
    int T, count, len1, len2, c1[mc][2], c2[mc][2];
    char s1[maxn], s2[maxn];
    
    public: void minLength () {
    
        cin >> T;
        for (int k = 1; k <= T; k ++) {
            
            // * 设置初值
            for (int i = 0; i < mc; i++ ) {
                c1[i][0] = INF;
                c1[i][1] = -INF;
                c2[i][0] = INF;
                c2[i][1] = -INF;
            }
            
            cin >> s1 >> s2;
            
            int i = 0, j = 0;
            while (s1[i]) {
                
                int index = idx(s1[i]);
                c1[index][0] = c1[index][0] == INF ? i+1 : c1[index][0];
                c1[index][1] = i+1;
                
                i++;
            }
            while (s2[j]) {
                
                int index = idx(s2[j]);
                c2[index][0] = c2[index][0] == INF ? j+1 : c2[index][0];
                c2[index][1] = j+1;
                j++;
            }
            
            len1 = i; len2 = j;
            
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][0] = 0;
            
            for (int i = 2; i <= len1; i ++) {
                dp[i][0] = dp[i-1][0] + L(i-1, -2);
            }
            for (int j = 2; j <= len2; j ++) {
                dp[0][j] = dp[0][j-1] + L(-2, j-1);
            }
            
            for (int i = 1; i <= len1; i ++) {
                for (int j = 1; j <= len2; j ++) {
                    
                    dp[i][j] = min(dp[i-1][j] + L(i-1, j),
                                   dp[i][j-1] + L(i, j-1));
                }
            }
            
            cout << dp[len1][len2] << "\n";
        }
    }
    
    private: int idx(char c) {return c - 'A' + 1;}
    private: int L(int i, int j) {
        
        int lc = 0;
        for (int k = 1; k <= 26; k ++) {
      
            // * 大坑，用-1表示没有出现的时候需要增加判断
            bool begin = c1[k][0] <= i || c2[k][0] <= j;
            bool end = c1[k][1] > i || c2[k][1] > j;
            
            if (end && begin) {
                lc++;
            }
        }
        
        return lc;
    }
};
