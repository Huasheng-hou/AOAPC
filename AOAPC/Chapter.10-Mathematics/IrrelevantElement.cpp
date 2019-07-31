//
//  IrrelevantElement.cpp
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

using namespace std;

static const int maxm = 1000000000;
static const int sqrtm = 32000;
static const int maxp = 32;
// * 10^9的素因子不会超过32个，令2为素因子，2^32 = 4G = 4 * 10^9，共32个素因子

class IrrelevantElement {
    
    int n, m;
    vector<int> p, factor, power, c, ans;
    
public:
    void solve() {
        
        getPrimes();
        
        while (cin >> n >> m) {
        
            n--; // * 只有 n-1 个步骤
            factorize(); ans.clear(); c.clear();
            
            int count = 0, len = (int)factor.size();
            for (int i = 1; i <= len; i ++) c.push_back(0);
            
            for (int i = 1; i < n; i++) {
                
                bool have = true;
                for (int j = 0; j < len; j++) {
                    
                    int x = n-i+1;
                    while (x % factor[j] == 0) {
                        c[j]++; x /= factor[j];
                    }
                    x = i;
                    while (x % factor[j] == 0) {
                        c[j]--; x /= factor[j];
                    }
                    if (c[j] < power[j]) have = false;
                }
                if (have) { count++; ans.push_back(i+1); };
            }
            
            cout << count << "\n";
            for (int i = 0; i < (int)ans.size(); i ++) {
                cout << ans[i];
                if (i < (int)ans.size() - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    
private:
    void factorize() {
        
        factor.clear(); power.clear();
        int len = (int)p.size();
        
        // * 对 m 做唯一分解
        for (int i = 0; i < len; i ++) {
            int t = 0;
            while (m % p[i] == 0) {
                t++; m /= p[i];
            }
            if (t > 0) {
                factor.push_back(p[i]);
                power.push_back(t);
            }
        }
        if (m > 1) {
            factor.push_back(m);
            power.push_back(1);
        }
    }
    
    void getPrimes() {
    
        bool a[sqrtm+2];
        memset(a, 0, sizeof(a));
        
        // * 筛素数
        for (int i = 2; i <= (long long)ceil(sqrt(sqrtm)); i ++) {
            if (a[i]) continue;
            for (int j = i*i; j <= sqrtm; j+=i) a[j] = true;
        }
        for (int i = 2; i <= sqrtm; i++) { if (!a[i]) p.push_back(i); }
    }
};
