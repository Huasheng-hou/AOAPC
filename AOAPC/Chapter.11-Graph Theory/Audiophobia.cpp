//
//  Audiophobia.cpp
//  AOAPC
//
//  Created by apple on 2019/7/15.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> edge;

class Audiophobia {
    public: void queryPath () {
        
        int c, s, q, count = 0;
        while (true) {
            
            scanf("%d%d%d", &c, &s, &q);
            if (c == 0 && s == 0 && q == 0) break;
            
            count++;
            printf("Case #%d\n", count);
            
            int * dp[c];
            for (int i = 0; i < c; i ++) {
                dp[i] = (int *)malloc(c * sizeof(int));
                for (int j = 0; j < c; j ++) {
                    dp[i][j] = INT_MAX;
                }
            }
            
            int u, v, w;
            for (int i = 0; i < s; i ++) {
                
                scanf("%d%d%d", &u, &v, &w);
                u--;
                v--;
                
                dp[u][v] = w;
                dp[v][u] = w;
            }
            
            makeLowPath(c, dp);
            
            for (int i = 0; i < q; i ++) {
                scanf("%d%d", &u, &v);
                u--;
                v--;
                
                if (dp[u][v] < INT_MAX) {
                   
                    printf("%d\n", dp[u][v]);
                } else {
                    printf("no path\n");
                }
            }
            printf("\n");
        }
    }
    
    private: void makeLowPath(int c, int ** dp) {
        
        for (int k = 0; k < c; k ++) {
            for (int i = 0; i < c; i ++) {
                for (int j = 0; j < c; j ++) {
                    
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                }
            }
        }
    }
};
