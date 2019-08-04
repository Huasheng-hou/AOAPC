//
//  Probability.cpp
//  AOAPC
//
//  Created by apple on 2019/8/1.
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

// 11181 Probability | Given

using namespace std;
static const int maxn = 20;

class Probability {
    
    double p[maxn+2], q[maxn+2];
    int n, r, buys[maxn];
    double sum[maxn+2];
    
public:
    void solve() {
        
        int count = 0;
        while (scanf("%d%d", &n, &r) && n > 0) {
            
            memset(sum, 0, sizeof(sum));
            count ++;
            for (int i = 0; i < n; i ++) {
                cin >> p[i];
                q[i] = 1-p[i];
            }
            dfs(0, 0, 1);
            for (int i = 0; i < n; i ++)
                sum[i] /= sum[n];
            
            printf("Case %d:\n", count);
            for (int i = 0; i < n; i ++)
                printf("%.6lf\n", sum[i]);
        }
    }
    
private:
    // * 用深度优先遍历求不同的组合
    void dfs(int d, int c, double prob) {
        
        if (c > r || d-c > n-r) return;
        if (d == n) {
            
            sum[n] += prob;
            for (int i = 0; i < n; i ++) if (buys[i])
                sum[i] += prob;
            return;
        }
        buys[d] = 0;
        dfs(d+1, c, prob*q[d]);
        buys[d] = 1;
        dfs(d+1, c+1, prob*p[d]);
    }
};
