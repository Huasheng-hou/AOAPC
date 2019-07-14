//
//  CallingCircles.cpp
//  AOAPC
//
//  Created by apple on 2019/7/14.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class CallingCircles {
    public: void getCallingCircles() {
    
        int m, n, count = 0;
        
        while (true) {
            
            scanf("%d%d", &m, &n);
            if (m == 0 && n == 0) break;
            
            count ++;
            printf("Calling circles for data set %d:\n", count);
            
            vector<bool *> d;
            vector<string> names;
            
            for (int i = 0; i < m; i ++) {
                d.push_back((bool *)calloc(m, sizeof(bool)));
            }
            
            map<string, int> p;
            string p1, p2;
            
            while (n > 0) {
                n--;
                cin >> p1;
                cin >> p2;
                
                int i, j; // 通过map提取名字下标
                if (p.count(p1)) {
                    i = p[p1];
                } else {
                    i = (int)p.size();
                    p[p1] = i;
                    names.push_back(p1);
                }
                if (p.count(p2)) {
                    j = p[p2];
                } else {
                    j = (int)p.size();
                    p[p2] = j;
                    names.push_back(p2);
                }
                
                d[i][j] = true;
            }
            searchCircles(m, d, names);
            printf("\n");
        }
    }
    
    private: void searchCircles(int m, vector<bool *> d,
                                vector<string> p) {
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                for (int k = 0; k < m; k ++) {
                    d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
                }
            }
        }
        
        int fathers[m];
        for (int i = 0; i < m; i ++) fathers[i] = i;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < i; j ++) {
                if (d[i][j] && d[j][i]) {
                    fathers[findRoot(i, fathers)] = findRoot(j, fathers);
                }
            }
        }
        
        for (int i = 0; i < m; i ++) {
            bool empty = true;
            for (int j = 0; j < m; j ++) {
                if (fathers[j] == i) {
                    
                    if (p.size() > j) {
                        cout << p[j];
                        printf(", ");
                        empty = false;
                    }
                }
            }
            if (!empty) printf("\n");
        }
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
};
