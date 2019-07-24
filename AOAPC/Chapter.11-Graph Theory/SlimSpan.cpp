//
//  SlimSpan.cpp
//  AOAPC
//
//  Created by apple on 2019/7/14.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

// 最小生成树，Kruskal算法，并查集

using namespace std;

class SlimSpan {
    public: void getSlimSpan() {
     
        int m, n;
        
        scanf("%d%d", &m, &n);
        while (m > 0 || n > 0) {

            if (m == 0) {
                
                printf("-1\n");
                scanf("%d%d", &m, &n);
                continue;
                
            } else if (n == 0 && m > 1) {
                
                printf("-1\n");
                scanf("%d%d", &m, &n);
                continue;
            } 

            int u, v, w;
            vector <int *> edges;
            
            for (int i = 0; i < n; i ++) {
                scanf("%d %d %d", &u, &v, &w);
                
                u --;
                v --;
                edges.push_back((int *)malloc(2 * sizeof(int)));
                edges[i][0] = u;
                edges[i][1] = v;
                edges[i][2] = w;
            }
            searchSlimSpan(m, edges);

            scanf("%d%d", &m, &n);
        }
    }
    
    private: void searchSlimSpan (int n, vector<int *>edges) {
        
        long e = edges.size();
        if (e < n - 1) {
            printf("-1\n"); return;
        }
        
        int fathers[n];
        for (int i = 0; i < n; i ++) fathers[i] = i;
        
        int minGap = -1;
        sort(edges.begin(), edges.end(), compare);
        
        for (int i = 0; i <= e - n + 1; i ++) {
            
            int node = 0;
            for (int j = i; j < e; j ++) {
                
                int u = edges[j][0];
                int v = edges[j][1];

                int p = findRoot(u, fathers);
                int q = findRoot(v, fathers);

                if (p == q) {
                    
                    continue;
                } else {
                    
                    node ++;
                    fathers[p] = q;
                    if (node == n-1) {

                        int gap = edges[j][2] - edges[i][2];
                        if (minGap == -1) {
                            minGap = gap;
                        } else if (gap < minGap) {
                            minGap = gap;
                        }
                    }
                }
            }
            for (int k = 0; k < n; k ++) {
             
                fathers[k] = k;
            }
        }
        printf("%d\n", minGap);
    }
    
    // * 并查集
    
    int findRoot (int u, int * fathers) {
        
        int p = fathers[u];
        if (p == u) return p;
        
        while (p != fathers[p]) {
            p = fathers[p];
        }
        while (u != p) {
            int a = fathers[u];
            fathers[u] = p;
            
            u = a;
        }
        
        return p;
    }
    
    static bool compare (int * a, int * b) {
        return a[2] < b[2];
    }
};
