//
//  DisgruntleJudge.cpp
//  AOAPC
//
//  Created by apple on 2019/7/31.
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

// Problem ID 12169 Disgruntled Judge
// 暴力求解

using namespace std;

static const int N = 10001;

class DisgruntleJudge {
    
    int a, b, t, x1[100+2], x2[100+2];
    
public:
    void solve() {
        
        cin >> t;
        for (int i = 1; i <= t; i++) {
            cin >> x1[i];
        }
        
        if (t == 1) x2[1] = (x1[1] * 1 + 1) % N;
        
        int cursor = 0, x;
        for (a = 0; a < N; a++) {
            for (b = 0; b < N; b++) {
                for (cursor = 1; cursor <= t; cursor ++) {
                    x2[cursor] = next(x1[cursor]);
                    x = next(x2[cursor]);
                    if (x != x1[cursor + 1]) break;
                }
                if (cursor == t) break;
            }
            if (cursor == t) break;
        }
        
        for (int i = 1; i <= t; i++) {
            cout << x2[i] << "\n";
        }
    }
    
private:
    int next(int x) { return (a*x+b) % N; }
};
