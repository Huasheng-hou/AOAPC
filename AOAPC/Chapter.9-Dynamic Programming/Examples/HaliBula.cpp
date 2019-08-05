//
//  HaliBula.cpp
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

// * 树状结构，按结点分类，递归+记忆化搜索

using namespace std;

static const int maxn = 200 + 2;

class HaliBula {
    
    int n, dp[maxn][2];
    bool f[maxn][2];
    vector<int> sons[maxn];
    
    public: void party() {
    
        while (cin >> n && n > 0) {
            
            memset(dp, 0, sizeof(dp));
            memset(f, 0, sizeof(f));
            for (int i = 0; i < maxn; i ++) sons[i].clear();
            
            string boss, employee, father;
            map<string, int> idx;
            
            cin >> boss;
            idx[boss] = 0;
            
            vector<string> e;
            vector<string> p;
            
            for (int i = 1; i <= n-1; i++) {
                
                cin >> employee >> father;
                idx[employee] = i;
                
                e.push_back(employee);
                p.push_back(father);
            }
            
            for (int i = 1; i <= n-1; i++) {
                
                father = p[i-1];
                sons[idx[father]].push_back(i);
            }
            
            bool unique = isUnique(0);
            int ans = max(DP(0, 0), DP(0, 1));
            
            if (unique) {
                cout << ans << " Yes" << "\n";
            } else {
                cout << ans << " No" << "\n";
            }
        }
    }
    
    private: int DP(int i, int s) {
    
        if (dp[i][s] > 0) return dp[i][s];
        
        int d = 0, len = (int)sons[i].size(); f[i][s] = true;
        if (len <= 0) {
            d = s;
        } else {
            if (s == 0) {
                
                for (int j = 0; j < len; j ++) {
                    
                    int q = sons[i][j];
                    d += max(DP(q, 0), DP(q, 1));
                    f[i][s] = f[i][s] && isUnique(q);
                }
            } else {
                for (int j = 0; j < len; j ++) {
                    
                    int q = sons[i][j];
                    d += DP(q, 0);
                    
                    f[i][s] = f[i][s] && f[q][0];
                }
                d++;
            }
        }
        dp[i][s] = d;
        
        return dp[i][s];
    }
    
    private: bool isUnique(int q) {
        
        if (DP(q, 0) == DP(q, 1)) return false;
        if (DP(q, 0) > DP(q, 1) && !f[q][0]) return false;
        if (DP(q, 1) > DP(q, 0) && !f[q][1]) return false;
        
        return true;
    }
};
