//
//  uva210.cpp
//  AOAPC
//
//  Created by apple on 2019/9/17.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>

//

using namespace std;

deque<int> q; queue<int> block;
int ip[100];

char file[1000][10];
int n, var[26];
int t1, t2, t3, t4, t5, quota, locked = 0;

int idx(char c) { return c-'a'; }

int gettime(char *x) {
    if (x[2] == 'd') return t5;
    if (x[2] == 'l') return t4;
    if (x[2] == 'c') return t3;
    if (x[2] == 'i') return t2;
    return t1;
}

void solve() {
    
    int t; cin >> t;
    while (t--) {
        
        memset(var, 0, sizeof(var));
        scanf("%d%d%d%d%d%d%d\n", &n, &t1, &t2, &t3, &t4, &t5, &quota);
        int line = 0;
        for (int i = 1; i <= n; i++) {
            ip[i] = line;
            fgets(file[line], 100, stdin);
            while (file[line][2] != 'd') {
                fgets(file[++line], 100, stdin);
            }
            line++;
            q.push_back(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            int t = quota, flag = 0;
            while (t > 0) {
                char *v = file[ip[u]];
                if (v[2] == 'c' && locked) { block.push(u); flag = 1; break; }
                t -= gettime(v); ip[u]++;
                if (v[2] == 'c') locked = 1;
                else if (v[2] == 'l') {
                    locked = 0;
                    if (!block.empty()) {
                        int first = block.front(); q.push_front(first);
                        block.pop();
                    }
                }
                else if (v[2] == 'd') { flag = 1; break; }
                else if (v[2] == 'i') {
                    char c = v[6];
                    printf("%d: %d\n", u, var[idx(c)]);
                } else {
                    char c; int val; sscanf(v, "%c = %d", &c, &val);
                    var[idx(c)] = val;
                }
            }
            if (!flag) q.push_back(u);
        }
        if (t > 0) printf("\n");
    }
}

int main() {
    
#ifdef AOAPC
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/input","r",stdin);
    remove("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output");
    freopen("/Users/apple/Develop/AOAPC/AOAPC/Inputs/output","w",stdout);
#endif
    
    solve();
    
    return 0;
}
