//
//  GreatWall.cpp
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

// * Problem ID:1336 Fixing the Great Wall
// * 线性问题，刷表法，不是递推！
// * LRJ 用了记忆化搜索，WTF!
// * 要用double，可以将double设置为静态变量以增加空间分配

using namespace std;

static const int maxn = 1000 + 2;
static const int INF = 1<<30;

static double dp[maxn][maxn][2];

// * 结构体方便sort
struct Section {
    int l, c, d;
    Section(int l, int c, int d): l(l), c(c), d(d) {};
};

static bool compare (Section a, Section b) {
    return a.l < b.l;
}

class GreatWall {
  
    int n, v, x;
    int sum[maxn];
    vector<Section> sec;
    
    public: void fix() {
    
        while (cin >> n >> v >> x && n > 0) {

            sec.clear(); memset(sum, 0, sizeof(sum));
            
            int p = 0, q = 500000, l, c, d;
            sum[0] = 0;

            for (int i = 1; i <= n; i ++) {
                
                cin >> l >> c >> d;
                sec.push_back(Section(l, c, d));
            }
            
            sort(sec.begin(), sec.end(), compare);
            for (int i = 1; i <= n; i ++) {
                
                if (sec[i-1].l < x) {
                    p = i;
                }
                sum[i] = sum[i-1] + sec[i-1].d;
            }

            for (int i = 0; i < maxn; i ++) {
                for (int j = 0; j < maxn; j ++) {
                    
                    dp[i][j][0] = INF;
                    dp[i][j][1] = INF;
                }
            }
            
            q = p+1;
            DP(p, p, 0);
            DP(q, q, 0);

            float ans = min(dp[1][n][0], dp[1][n][1]);
            cout << (int)floor(ans) << "\n";
        }
    }
    
    private: void DP(int i, int j, int k) {
        
        float t1, t2;
        int delta;
        float tmp;
        if (j == i) {
        
            delta = sum[n]; int pos = x;
            t1 = t(pos, i); t2 = t(pos, j);
            
            dp[i][j][k] = (delta * t1) + sec[i-1].c;
            tmp = dp[i][j][k];
        }
        
        if (i == 1 && j == n) {
            return;
        }
        if (i < 1 || j > n) return;
        
        delta = c(i-1, j+1);
        {
            int p = k == 0 ? sec[i-1].l : sec[j-1].l;
            
            t1 = t(p, i-1);
            t2 = t(p, j+1);
            
            if (i-1 >= 1) {
                
                double d1 = (delta * t1) + sec[i-1-1].c + dp[i][j][k];
                if (d1 < dp[i-1][j][0]) {
                    dp[i-1][j][0] = d1;
                    DP(i-1, j, 0);
                }
            }
            if (j+1 <= n) {
                
                double d2 = (delta * t2) + sec[j+1-1].c + dp[i][j][k];
                if (d2 < dp[i][j+1][1]) {
                    dp[i][j+1][1] = d2;
                    DP(i, j+1, 1);
                }
            }
        }
    }
    
    private: float t(int p, int i) {
        return fabs(p-sec[i-1].l) / v;
    }
    private: int c(int i, int j) {
        return sum[n] - sum[j-1] + sum[i];
    }
};
