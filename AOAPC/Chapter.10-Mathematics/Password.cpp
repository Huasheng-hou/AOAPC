//
//  Password.cpp
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

// 1262

using namespace std;

static const int numr = 6;
static const int numc = 5;

class Password {
    
    int T, K, p[7];
    char m1[numr+2][numc+2], m2[numr+2][numc+2];
    map<char, int> code[5+1];
    
public:
    void solve() {
        
        cin >> T;
        while (T > 0) {
            T--;
            
            cin >> K;
            for (int i = 1; i <= 6; i ++) cin >> m1[i];
            for (int i = 1; i <= 6; i ++) cin >> m2[i];
        
            getCode();
            
            if (K > p[1]) { cout << "NO"; continue; }
            for (int i = 1; i <= 5; i ++) {
             
            }
            cout << "\n";
        }
    }
    
private:
    void getCode() {
        
        for (int k = 1; k <= 5; k ++) {
            code[k].clear();
            for (int i = 1; i <= 6; i ++) {
                for (int j = 1; j <= 6; j ++) {
                    if (m1[i][k-1] == m2[j][k-1]) {
                        code[k][m1[i][k-1]] = 1;
                    }
                }
            }
        }
        p[6] = 1;
        for (int j = 5; j >= 1; j--) {
            p[j] = (int)(code[j].size()) * p[j+1];
        }
    }
};
