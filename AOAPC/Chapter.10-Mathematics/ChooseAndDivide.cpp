//
//  ChooseAndDivide.cpp
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

using namespace std;

class ChooseAndDivide {

public: void divide() {
    
    int p, q, r, s;
    vector<int> primes = getPrimes(10000);
    int np = (int)primes.size();
    int e[np];
    
    while (cin >> p >> q >> r >> s) {
        
        memset(e, 0, sizeof(e));
        factorize(p, primes, e, 1);
        factorize(q, primes, e, -1);
        factorize(p-q, primes, e, -1);
        factorize(r, primes, e, -1);
        factorize(s, primes, e, 1);
        factorize(r-s, primes, e, 1);
        
        double ans = 1;
        for (int i = 0; i < np; i ++) {
            ans *= pow(primes[i], e[i]);
        }
        printf("%.5lf\n", ans);
    }
}
    
private: void factorize(int n, vector<int> p, int *e, int d) {
    
    for (int i = 1; i <= n; i++) {
        
        int k = i;
        for (int j = 0; j < (int)p.size(); j ++) {
            
            while (k % p[j] == 0) {
                k /= p[j];
                e[j] += d;
            }
        }
    }
}
    
public: vector<int> getPrimes(int n) {
    
    bool v[n];
    int m = sqrt(n + .5);
    memset(v, 0, sizeof(v));
    
    for (int i = 2; i <= m; i ++) {
        if (v[i-1]) continue;
        for (int j = i*i; j <= n; j += i) {
            v[j-1] = true;
        }
    }
    vector<int> p;
    for (int i = 1; i < n; i ++) {
        if (!v[i]) p.push_back(i+1);
    }
    
    return p;
}
};
