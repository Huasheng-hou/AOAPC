//
//  BugOrFeature.cpp
//  AOAPC
//
//  Created by apple on 2019/7/15.
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

using namespace std;

typedef pair<string, string> patch;

class BugOrFeature {
    
public: void fixSoftware() {
    
    int n, m, count = 0;
    
    while (cin >> n >> m && (n > 0 || m > 0)) {
        
        if (count > 0) printf("\n");
        printf("Product %d\n", ++count);
        
        
        vector<patch> p;
        int t[m];
        
        for (int i = 0; i < m; i ++) {
            
            int time;
            string bug, patch;
            cin >> time >> bug >> patch;
            p.push_back(make_pair(bug, patch));
            t[i] = time;
        }
        
        vector<int> v; // 用 int 存储状态
        map<int, int> idx;
        map<pair<int, int>, int> w;
        
        v.push_back((1 << n) - 1 );
        idx[(1 << n) - 1] = 0;
        w[make_pair(0, 0)] = 0;
        
        int end = -1;
        
        int k = 0;
        while (k < v.size()) {
            
             for (int i = 0; i < m; i ++) {
                if (isMatch(n, v[k], p[i].first)) {

                    int f = fixBugs(n, v[k], p[i].second);
                    int index;
                    int pre = idx[v[k]];
                    
                    int dp = w[make_pair(0, pre)] + t[i];
                    if (idx.count(f) <= 0) {

                        index = (int)idx.size();
                        v.push_back(f);
                        idx[f] = index;
                        if (f == 0) end = index;
                        w[make_pair(0, index)] = dp; // *每次追溯最短距离即可
                    } else {
                        index = idx[f];
                        int d = w[make_pair(0, index)];
                        if (dp < d) {   // * 状态转移
                            w[make_pair(0, index)] = dp;
                            v.push_back(f); // * 发现新路径后再搜索一遍
                        }
                    }
                }
            }
            k++;
        }
        
        if (end == -1) {
            cout << "Bugs cannot be fixed.\n";
        } else {
            printf("Fastest sequence takes %d seconds.\n", w[make_pair(0, end)]);
        }
    }
}
    
private: bool isMatch(int n, int b, string pattern) {
    
    for (int i = 0; i < n; i ++) {
        if (pattern[i] == '0') {
            continue;
        } else if (pattern[i] == '-') {
            if ((b / (1 << (n-i-1))) % 2 == 0) {
                continue;
            }
        } else if (pattern[i] == '+') {
            if ((b / (1 << (n-i-1))) % 2 == 1) {
                continue;
            }
        }
        return false;
    }
    return true;
}
    
private: int fixBugs(int n, int b, string patch) {
    
    for (int i = 0; i < n; i ++) {
        if (patch[i] == '0') {
            
        } else if (patch[i] == '-') {
            int x = (1 << n) - 1 - (1 << (n - i - 1));
            b = b & x;
        } else {
            b = b | 1 << (n - i - 1);
        }
    }
    
    return b;
}
};
