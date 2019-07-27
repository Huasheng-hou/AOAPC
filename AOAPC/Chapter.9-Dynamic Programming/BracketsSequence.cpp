//
//  BracketsSequence.cpp
//  AOAPC
//
//  Created by apple on 2019/7/25.
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

// * 线性DP，递推法，d[S] = min(d[S'], d[i][k]+d[k+1][j])

using namespace std;

static const int maxn = 100 + 2;

class BracketsSequence {
  
    int d[maxn][maxn], n;
    char s[maxn];
    string rawStr;
    
    public: void extraBrackets () {
    
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            
            cin >> rawStr;
            
            int len = (int)rawStr.length();
            for (int j = 0; j < len; j ++) {
                
                s[j] = rawStr[j];
            }
            s[len] = '\0';
            
            for (int j = 0; j < len; j ++) {
                d[j][j] = 1;
                d[j+1][j] = 0;
            }
            
            for (int j = len-2; j >= 0; j --) {
                for (int k = j+1; k < len; k ++) {
                    
                    d[j][k] = len;
                    if (match(s[j], s[k])) {
                        d[j][k] = min(d[j][k], d[j+1][k-1]);
                    }
                    
                    for (int p = j; p < k; p++) {
                        d[j][k] = min(d[j][k], d[j][p]+d[p+1][k]);
                    }
                }
            }
            
            print(0, len-1);
            cout << "\n\n";
        }
    }
    
    private: void print (int i, int j) {
    
        if (i > j) return;
        if (i == j) {
            
            if (s[i] == '(' || s[i] == ')') {
                cout << "()";
            } else {
                cout << "[]";
            }
            return;
        }
        if (match(s[i], s[j]) && d[i][j] == d[i+1][j-1]) {
            cout << s[i];
            print(i+1, j-1);
            cout << s[j];
            return;
        }
        
        for (int k = i; k < j; k ++) {
            if (d[i][j] == d[i][k] + d[k+1][j]) {
                print(i, k);
                print(k+1, j);
                break;
            }
        }
    }
    
    private: bool match (char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']');
    }
};
