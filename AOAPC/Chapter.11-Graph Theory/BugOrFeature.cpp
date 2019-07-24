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

// 有向非负权图 单源固定终点最短路 Dijkstra 算法 priority_queue

using namespace std;

typedef pair<int, int> node;

class BugOrFeature {
    
public: void fixSoftware() {
    
    int n, m, count = 0;
    
    while (scanf("%d%d", &n, &m) && (n > 0 || m > 0)) {
        
        printf("Product %d\n", ++count);
        
        int t[m];
        
        char bug [m][n + 1];
        char patch [m][n + 1];
        
        for (int i = 0; i < m; i ++) {
            
            scanf("%d%s%s", t + i, bug[i], patch[i]);
        }
        
        int dist[1<<n]; // 优化为c数组，存取效率是map的1/4
        for (int i = 0; i < (1<<n); i++) dist[i] = -1;
        dist[(1<<n) - 1] = 0;
        
        priority_queue<node, vector<node>, greater<node>> q;
        q.push(make_pair(0, (1 << n) - 1));
        
        int end = -1;
        while (!q.empty()) {
            
            pair<int, int> node = q.top();
            if (node.second == 0) break;
            q.pop();
            for (int i = 0; i < m; i ++) {
                if (isMatch(n, node.second, bug[i])) {
                    
                    int f = fixBugs(n, node.second, patch[i]);
                
                    int dp = dist[node.second] + t[i];
                    if (dist[f] == -1) {
                        
                        q.push(make_pair(dp, f));
                        dist[f] = dp; // *每次追溯最短距离即可
                    } else {
                        if (dp < dist[f]) {   // * 状态转移
                            dist[f] = dp;
                            q.push(make_pair(dp, f)); // * 发现新路径后再搜索一遍
                        }
                    }
                    if (f == 0) end = dist[f];
                }
            }
        }
        
        if (end == -1) {
            printf("Bugs cannot be fixed.\n\n");
        } else {
            printf("Fastest sequence takes %d seconds.\n\n", end);
        }
    }
}
    
private: bool isMatch(int n, int b, char * pattern) {
    
    int t = b;
    for (int i = 0; i < n; i ++) {
        if (pattern[i] == '-') {
            if (((t >> (n-i-1)) & 1)) { // 取二进制第bit位，b >> (bit - 1) & 1
                return false;
            }
        } else if (pattern[i] == '+') {
            if (!((t >> (n-i-1)) & 1)) {
                return false;
            }
        }
    }
    return true;
}
    
private: int fixBugs(int n, int b, char * patch) {
    
    for (int i = 0; i < n; i ++) {
        if (patch[i] == '0') {
            
        } else if (patch[i] == '-') {
            int x = ~(1 << (n - i - 1));
            b = b & x;
        } else {
            b = b | 1 << (n - i - 1);
        }
    }
    
    return b;
}
};
