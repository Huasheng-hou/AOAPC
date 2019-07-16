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
        
        int end = -1;
        
        int k = 0;
        while (k < v.size()) {
            
             for (int i = 0; i < m; i ++) {
                if (isMatch(n, v[k], p[i].first)) {

                    int f = fixBugs(n, v[k], p[i].second);
                    int index;
                    
                    if (idx.count(f) <= 0) {

                        index = (int)v.size();
                        v.push_back(f);
                        idx[f] = index;
                        if (f == 0) end = index;
                    } else {
                        index = idx[f];
                    }
                    w[make_pair(k, index)] = t[i];
                }
            }
            k++;
        }
        
        if (end == -1) {
            cout << "Bugs can't be fixed!";
        } else {
            searchPath((int)v.size(), end, v, w, m, p, idx);
        }
        printf("\n");
    }
}
    
private: void searchPath(int n, int end, vector<int> v,
                         map<pair<int, int>, int> w,
                         int nf, vector<patch> p,
                         map<int, int> idx) {
    
    int vi[n];
    memset(vi, 0, n * sizeof(int));
    int d[n];
    
    for (int i = 0; i < n; i ++) {
        
        if (w.count(make_pair(0, i)) > 0) {
            d[i] = w[make_pair(0, i)];
        } else {
            d[i] = i == 0 ? 0 : INT_MAX;
        }
    }
    
    for (int i = 0; i < n; i ++) {
        int x = 0, m = INT_MAX;
        for (int y = 0; y < n; y ++) {
            if (!vi[y] && d[y] <= m) {
                m = d[x = y];
            }
        }
        vi[x] = 1;
        for (int k = 0; k < nf; k ++) {
            if (isMatch(nf, v[x], p[k].first)) {
                
                int f = fixBugs(nf, v[x], p[k].second);
                int index = idx[f];
               
                int t = w[make_pair(x, index)];
                d[index] = min(d[index], d[x] + t);
            }
        }
    }
    if (d[end] < INT_MAX) {
        printf("%d\n", d[n-1]);
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
//            if ((b / (1 << (n-i-1))) % 2 != 0) {
            int x = (1 << n) - 1 - (1 << (n - i - 1));
            b = b & x;
        } else {
            b = b | 1 << (n - i - 1);
        }
    }
    
    return b;
}
};
