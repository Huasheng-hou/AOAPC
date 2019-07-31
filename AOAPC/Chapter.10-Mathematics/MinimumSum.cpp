//
//  MinimumSum.cpp
//  AOAPC
//
//  Created by apple on 2019/7/29.
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

// * Problem ID 10791 Minimum Sum LCM

using namespace std;

static const int sqrtn = 1<<16; // * 素数N大于 sqrt(N) 的质因子最多有1个
static bool a[sqrtn+1];

class MinimumSum {
  
    int N, count = 0;
    unsigned int sum;
    vector<int> p;
    
    public: void minimal() {
    
        memset(a, 0, sizeof(a));
        
        for (int i = 2; i <= 1<<8; i ++) {
            if (a[i]) continue;
            for (int j = i*i; j <= sqrtn; j+=i) {
                a[j] = true;
            }
        }
        for (int i = 2; i <= sqrtn; i ++) {
            if (!a[i]) p.push_back(i);
        }
        
        while (scanf("%d", &N) && N > 0) {
            
            count ++; sum = 0;
            int origin = N;
            
            if (N == 1) {
                sum = 2;
                printf("Case %d: %u\n", count, sum);
                continue;
            }
            
            int len = (int)p.size(), np = 0;
            for (int i = 0; i < len; i++) {
                
                if (N == 1) break;
                int factor = 1;
                while (N % p[i] == 0) {
                    factor *= p[i];
                    N /= p[i];
                }
                if (factor > 1) {
                    sum += factor; np++;
                }
            }
            
            if (N > 1) {
                sum += N;
                if (N == origin) sum ++;
            } else {
                if (np == 1) sum ++;
            }
            printf("Case %d: %u\n", count, sum);
        }
    }
};
