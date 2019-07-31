//
//  GcdXOR.cpp
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

// * Problem ID 12716 GCD XOR
// * a^b = c => a^c = b

using namespace std;

static const int maxn = 30000000;
static int cnt[maxn+2], sum[maxn+2];

class GcdXOR {
    
    int T, N;
    vector<int> p, f;
    
public:
    void xors() {
     
        memset(cnt, 0, sizeof(cnt));
        
        for (int c = 1; c <= maxn; c++) {
            for (int a = 2*c; a<= maxn; a+=c) {
                int b = a-c;
                if (c == (a^b)) cnt[a]++;
            }
        }
        for (int i = 1; i <= maxn; i ++) sum[i] = sum[i-1] + cnt[i];
        
        int count = 0;
        
        scanf("%d", &T);
        while (count != T) {
            count++;
            scanf("%d", &N);
            
            printf("Case %d: %d\n", count, sum[N]);
        }
    }
};
