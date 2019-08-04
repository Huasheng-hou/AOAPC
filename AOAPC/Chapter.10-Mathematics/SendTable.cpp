//
//  SendTable.cpp
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

// 10820

using namespace std;

static const int maxn = 50000 + 2;

class SendTable {

    int phi[maxn], n, f[maxn];
    
public:
    void solve() {
        
        phi_table(); f[1] = 0;
        for (int i = 2; i < maxn; i ++) f[i] = f[i-1] + phi[i];
        
        while (cin >> n && n > 0) {
            
            cout << 2*f[n] + 1;
            cout << "\n";
        }
    }
    
private:
    void phi_table() {
        
        for (int i = 2; i <= maxn; i++) phi[i] = 0;
        phi[1] = 1;
        
        for (int i = 2; i <= maxn; i ++) {
            if (phi[i]) continue;
            for (int j = i; j <= maxn; j+=i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
};
