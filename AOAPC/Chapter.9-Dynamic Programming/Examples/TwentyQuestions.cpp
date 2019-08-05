//
//  TwentyQuestions.cpp
//  AOAPC
//
//  Created by apple on 2019/7/28.
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

// * Problem ID:1252 Twenty Questions
// * 记忆化搜索 d(s,a) = max(d(s+k, a+k), d(s+k, a)) + 1;
// * 边界条件为 cnt(s, a) = 1
// * 位运算

using namespace std;

static const int maxm = 11;
static const int maxn = 128 + 2;
static const int INF = 1<<30;
static int cnt[1<<maxm][1<<maxm], dp[1<<maxm][1<<maxm];

class TwentyQuestions {
  
    int m, n, obj[maxn+2];
    char f[maxm+2];
    
    public: void ask () {
    
        while (cin >> m >> n && m > 0 && n > 0) {
            
            memset(cnt, 0, sizeof(cnt));
            memset(dp, -1, sizeof(dp));
            memset(obj, 0, sizeof(obj));
            
            for (int i = 1; i <= n; i ++) {
                
                cin >> f;
                for (int j = 0; j < m; j ++) {
                    if (f[j] == '1') {
                        obj[i] |= (1<<(m-j-1));
                    }
                }
            }
            
            for (int s = 0; s <= (1<<m)-1; s++ ) {
                for (int i = 1; i <= n; i ++) {
                    cnt[s][s&obj[i]] ++;
                }
            }
            
            cout << DP(0, 0) << "\n";
        }
    }
    
private:
    
    int DP(int s, int a) {
        
        if (dp[s][a] > -1) return dp[s][a];
        int &ans = dp[s][a];
        if (cnt[s][a] == 1) {
            ans = 0; return ans;
        }
        
        ans = INF;
        for (int i = m; i >= 1; i --) {
            int f = 1<<(i-1);
            if (!(f & s)) {
                int d = max(DP(s|f, a), DP(s|f, a|f));
                ans = min(ans, d);
            }
        }
        ans++;
        
        return ans;
    }
    
    int exp2(int i) { return floor(pow(2., i)); }
    int exp3(int i) { return floor(pow(3., i)); }
};
