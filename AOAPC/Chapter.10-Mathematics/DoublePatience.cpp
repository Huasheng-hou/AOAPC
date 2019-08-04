//
//  DoublePatience.cpp
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

// 1637 Double Patience

using namespace std;

static const int maxr = 9;
static const int maxc = 4;

class DoublePatience {
    
    double prob;
    char card[maxr][maxc][3];
    vector<int> cnt;
    map<vector<int>, double> dp;
    
public:
    void solve() {
        
        while (true) {
        
            int i;
            for (i = 0; i < maxr; i++) {
                if (scanf("%s%s%s%s", card[i][0], card[i][1], card[i][2],
                      card[i][3]) != 4) break;
            }
            if (i == 0) break;
            
            prob = 0;
            for (int i = 0; i < maxr; i ++) cnt.push_back(0);
            
            dfs(36, 1);
            
            printf("%.6lf\n", prob);
        }
    }
    
private:
    void dfs(int c, double p) {
        
//        if (dp.find(cnt) > 0) return;
        if (c == 0) {
            prob += p; return;
        }
        double num = 0;
        for (int i = 0; i < maxr; i ++) {
            for (int j = i+1; j < maxr; j ++) {
                if (cnt[i] < 4 && cnt[j] < 4) {
                    if (card[i][cnt[i]][0] == card[j][cnt[j]][0])
                    {
                        num++;
                    }
                }
            }
        }
        
        if (num == 0) {
            return;
        }
        p /= num;
        for (int i = 0; i < maxr; i ++) {
            for (int j = i+1; j < maxr; j ++) {
                if (cnt[i] < 4 && cnt[j] < 4) {
                    if (card[i][cnt[i]][0] == card[j][cnt[j]][0]) {
                     
                        cnt[i]++; cnt[j]++;
                        dfs(c-2, p);
                        cnt[i]--; cnt[j]--;
                    }
                }
            }
        }
    }
};
