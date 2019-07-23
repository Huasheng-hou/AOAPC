//
//  LightingSystem.cpp
//  AOAPC
//
//  Created by apple on 2019/7/23.
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

using namespace std;

static const int maxn = 1000 + 2;

struct lamp {
    int volt, source, cost, num;
    lamp(int v, int k, int c, int l):
    volt(v),source(k),cost(c),num(l) {};
};

static bool compare(lamp v1, lamp v2) {
    return v1.volt < v2.volt;
}

class LightingSystem {
  
    int s[maxn], d[maxn], c[maxn], k[maxn], n;
    vector<lamp> Lamp;
    
    public: void design() {
        
        while (cin >> n && n > 0) {
            
            Lamp.clear();
            
            for (int i = 1; i <= n; i ++) {
    
                int v, k, c, l;
                
                cin >> v >> k >> c >> l;
                Lamp.push_back(lamp(v, k, c, l));
            }
            
            sort(Lamp.begin(), Lamp.end(), compare);
            
            s[0] = 0; d[0] = 0;
            for (int i = 1; i <= n; i ++) {
                s[i] = s[i-1] + Lamp[i-1].num;
                c[i] = Lamp[i-1].cost;
                k[i] = Lamp[i-1].source;
            }
            
            for (int i = 1; i <= n; i ++) {
                
                int m = 1<<30;
                for (int j = 0; j < i; j ++) {
                    m = min(m, d[j] + c[i]*(s[i]-s[j]) + k[i]);
                }
                d[i] = m;
            }
            
            cout << d[n] << "\n";
        }
    }
};
