//
//  Headmaster.cpp
//  AOAPC
//
//  Created by apple on 2019/7/27.
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

// * Problem ID:10817 Headmaster's headache
// * 记忆化搜索 d(i, s1, s2) = min(c(i) + d(i+1, s1', s2'), d(i+1, s1, s2))

using namespace std;

static const int maxn = 120 + 2;
static const int maxs = 8;
static const int INF = 1<<30;

class Headmaster {
  
    int S, M, N, c[maxn], st[maxn], cost, d[maxn][6561];
    string line;
    
    public: void headache() {
        
        while (getline(cin, line)) {

            stringstream ss(line);
            ss >> S >> M >> N;
            
            if (S <= 0) break;
            
            int x; memset(st, 0, sizeof(st)); cost = 0;
            memset(d, -1, sizeof(d));
            
            for (int i = 0; i < M+N; i ++) {
                
                getline(cin, line);
                stringstream ss(line);
                ss >> c[i];
                while (ss >> x) st[i] |= 1<<(x-1);
                
                if (i < M) cost += c[i];
            }
            
            cout << DP(0, 0, 0) << "\n";
        }
    }
    
    // * 设立终点，然后递归搜索
    private: int DP(int i, int s1, int s2) {
        
        if (i == M+N) {
            return s2 == (1<<S)-1 ? 0 : INF;
        }
        
        int index = idx(s1, s2);
        int ans = d[i][index];
        if (ans >= 0) return ans;
        
        ans = INF;
        if (i >= M) ans = DP(i+1, s1, s2);
        
        s2 = s2 | (s1 & st[i]);
        s1 = (~s2) & (s1 | st[i]);
        
        ans = min(ans, c[i] + DP(i+1, s1, s2));
        d[i][index] = ans;
        return ans;
    }
    
    // * 三进制
    private: int idx(int s1, int s2) {
        
        int index = 0;
        for (int i = maxs - 1; i >= 0; i--) {
            
            if (s2 & (1 << i)) index += exp3(i)*2;
            if (s1 & (1 << i)) index += exp3(i)*1;
        }
        
        return index;
    }
    
    private: int exp3(int i) {
        return floor(pow(3., i));
    }
};
