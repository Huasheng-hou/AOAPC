//
//  Palindrome.cpp
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

// * Problem ID:11584 Partitioning by Palindromes
// * 线性DP，递推法，d[j] = min{d[k] + 1|s[k,j] is a palindrome}

using namespace std;

static const int maxn = 1000 + 2;

class Palindrome {
  
    int n, d[maxn], p[2*maxn], length;
    char ch[maxn];
    
    public: void partition () {
    
        cin >> n;
        for (int k = 1; k <= n; k ++) {
            
            length = 0;
            memset(p, 0, sizeof(p));
            
            cin >> ch;
            
            for (int i = 0; i < maxn; i ++) {
                if (ch[i] == 0) break;
                length++;
            }
            
            // * 1、求回文长度
            for (int i = 1; i <= 2*length-1; i ++) {

                int mid = (i-1) / 2;
                if (i % 2) {

                    while (ch[mid - p[i]] == ch[mid + p[i]]) {
                        p[i]++;
                    }
                    p[i] = 2*p[i]-1;
                } else {
                    while (ch[mid - p[i]] == ch[mid + p[i] + 1]) {
                        p[i]++;
                    }
                    p[i] *= 2;
                }
            }

            // * 1、递推求解
            d[0] = 0;
            for (int i = 1; i <= length; i ++) {
                d[i] = i;
                for (int j = i; j >= 1; j --) {

                    if (isPalindrome(j, i)) {
                        d[i] = min(d[i], d[j-1] + 1);
                    }
                }
            }

            cout << d[length];
            cout << "\n";
        }
    }
    
    private: bool isPalindrome (int i, int j) {
        
        if (i == j) return true;
        
        // * i和j的中s点为第 2*j-1 个位置和第 2*i-1 个位置的中点
        int mid = j+i - 1;
        return p[mid] >= j-i+1;
    }
};
