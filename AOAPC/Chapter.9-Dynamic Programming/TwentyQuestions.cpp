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
// * 边界条件为

using namespace std;

static const int maxm = 11;
static const int maxn = 128 + 2;
static const int maxs = 177147;

class TwentyQuestions {
  
    int m, n, cnt[2048], d[maxs], ms;
    char obj[maxn][maxm];
    
    public: void ask () {
    
        while (cin >> m >> n && m > 0 && n > 0) {
            
            memset(cnt, -1, sizeof(cnt));
            memset(d, -1, sizeof(d));
            ms = 0;
            
            for (int i = 1; i <= n; i ++) {
                
                cin >> obj[i];
                for (int j = 0; j < m; j ++) {
                    if (obj[i][j] == '1') {
                        ms |= (1<<j);
                    }
                }
            }
            
            cout << DP(0, 0) << "\n";
        }
    }
    
    private: int DP(int s, int a) {
        
        if (count(a) == 1) return 0;
        if (count(a) <= 1 && count2(s & (~a)) <= 1) {
            return 0;
        }
        if (count(a) == 2 && count2(s & (~a)) == 2) {
            return 1;
        }
        int &ans = d[idx(s, a)];
        if (ans >= 0) return ans;
        ans = m;
        for (int i = 0; i < m; i ++) {
            if (!(s & (1<<i))) {
                
                s |= (1<<i);
                int t = max(DP(s, a), DP(s, a | (1<<i)));
                ans = min(ans, t+1);
            }
        }
        
        return ans;
    }
    
    private: int count(int s) {
        
        int index = idx2(s);
        if (cnt[index] >= 0) return cnt[index];
        
        int c = 0;
        for (int i = 1; i <= n; i ++) {
            
            bool have = true;
            for (int j = 0; j < m; j++ ) {
                if (s & (1<<j)) {
                    if (obj[i][j] == '1') {
                        continue;
                    } else {
                        have = false;
                        break;
                    }
                }
            }
            if (have) c++;
        }
        
        cnt[index] = c;
        return c;
    }
    
    private: int count2(int s) {
        
        int c = 0;
        for (int i = 1; i <= n; i ++) {
            
            bool nothave = true;
            for (int j = 0; j < m; j++ ) {
                if (s & (1<<j)) {
                    if (obj[i][j] == '1') {
                        nothave = false;
                        break;
                    } else {
                        continue;
                    }
                }
            }
            if (nothave) c++;
        }
        
        return c;
    }
    
    private: int idx2(int s) {
        
        int index = 0;
        for (int i = 0; i < m; i ++ ) {
            if (s & 1<<i) index += exp2(i);
        }
        
        return index;
    }
    
    private: int idx(int s, int a) {
    
        int index = 0;
        for (int i = 0; i < m; i ++ ) {
            if (s & 1<<i) index += exp3(i);
            if (a & 1<<i) index += exp3(i);
        }
        
        return index;
    }
    
    private: int exp2(int i) { return floor(pow(2., i)); }
    private: int exp3(int i) { return floor(pow(3., i)); }
};
