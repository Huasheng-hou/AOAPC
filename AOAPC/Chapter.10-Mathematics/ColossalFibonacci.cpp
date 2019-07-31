//
//  ColossalFibonacci.cpp
//  AOAPC
//
//  Created by apple on 2019/7/19.
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

// * Problem ID 11582 Colossal Fibonacci Numbers!

using namespace std;

static const int maxn = 1000;
static int f[maxn*maxn + 2];

class ColossalFibonacci {
    
    int t, n, p, r;
    unsigned long long a, b, d;
    
public:
    void solve() {
        
        cin >> t;
        while (t) {
            t--;
            
            cin >> a >> b >> n;
            
            if (n == 1 || a == 0) {cout << 0 << "\n"; continue;}
            if (a == 1 || b == 0) {cout << 1 << "\n"; continue;}
            
            f[0] = 0; f[1] = 1;
            for (int i = 2; i <= n*n; i++) {
                f[i] = (f[i-2] + f[i-1]) % n;
                f[i+1] = (f[i-1] + f[i]) % n;
                if (f[i] == f[0] && f[i+1] == f[1]) {
                    p = i; break;
                }
            }
            
            r = a%p;
            d = r; unsigned long long tmp = 1;
            while (b / 2) {
                tmp = b%2 == 1 ? d*tmp : tmp;
                tmp = tmp%p;
                d = (d*d) % p;
                b = b/2;
            }
            d = (d*tmp) % p;
            
            cout << f[d] << "\n";
        }
    }
};
