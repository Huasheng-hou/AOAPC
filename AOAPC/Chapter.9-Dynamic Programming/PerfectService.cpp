//
//  PerfectService.cpp
//  AOAPC
//
//  Created by apple on 2019/7/23.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

// * 1218 Perfect Service
// * 树状DP，按结点进行分类

using namespace std;

static const int maxN = 10000 + 2;
static const int INF = 1<<30;

class PerfectService {
    
    vector<int> sons[maxN];
    int N, dp[maxN][3];
    // s = 0, u 是服务器；s = 1，u 的父亲是服务器；s = 2，u和u的父亲都不是服务器
    
public:
    void solve() {
     
        while (cin >> N && N > 0) {
            
            for (int i = 1; i <= N; i ++) sons[i].clear();
            
            int u, v;
            for (int i = 0; i < N-1; i ++) {
                cin >> u >> v;
                sons[u].push_back(v);
            }
            
            memset(dp, -1, sizeof(dp));
            cout << min(DP(1, 0), DP(1, 2)) << "\n";
            
            cin >> u; if (u != 0) break;
        }
    }
    
private:
    int DP(int i, int s) {
     
        if (sons[i].size() == 0) {
            dp[i][s] = s == 0 ? 1 : 0;
            if (s == 2) dp[i][s] = maxN;
        }
        if (dp[i][s] > -1) return dp[i][s];
        
        int &ans = dp[i][s];
        ans = s == 0 ? 1 : 0;
        if (s == 0) {
            
            for (int j = 0; j < (int)sons[i].size(); j++) {
                ans += min(DP(sons[i][j], 0), DP(sons[i][j], 1));
            }
        } else if (s == 1) {
            
            for (int j = 0; j < (int)sons[i].size(); j++) {
                ans += DP(sons[i][j], 2);
            }
        } else {
            
            int delta = INF;
            for (int j = 0; j < (int)sons[i].size(); j++) {
                
                int child = sons[i][j];
                ans += DP(child, 2);
                if (DP(child, 0) - DP(child, 2) < delta) {
                    delta = DP(child, 0) - DP(child, 2);
                }
            }
            ans += delta;
        }
        
        return ans;
    }
};
