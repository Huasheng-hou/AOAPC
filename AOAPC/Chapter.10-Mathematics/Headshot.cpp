//
//  Headshot.cpp
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

// 1636 Headshot

using namespace std;

static const int maxn = 100+2;

class Headshot {
    
    char p[maxn];
    float n0, n1, len;
    
public:
    void solve() {
     
        while (cin >> p) {
            
            n0 = 0; n1 = 0; len = 0.;
            
            for (int i = 0; i < maxn; i ++) {
                if (p[i] == '0') {
                    char next;
                    if (p[i+1] == '\0') {
                        next = p[0];
                    } else {
                        next = p[i+1];
                    }
                    if (next == '0') n0++; else n1++;
                }
                len ++;
                if (p[i+1] == '\0') break;
            }
            
            double p1 = (n0+n1) / len;
            double p2 = n0 / (n0 + n1);
            
            if (p1 == p2) cout << "EQUAL";
            if (p1 > p2) cout << "ROTATE";
            if (p1 < p2) cout << "SHOOT";
            cout << "\n";
        }
    }
};
