//
//  uva442.cpp
//  AOAPC
//
//  Created by apple on 2019/9/18.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <string.h>

// 

using namespace std;

int m[26][2];

int idx(char c) { return c-'A'; }

void solve() {

    int n; cin >> n; getchar();
    for (int i = 0; i < n; i++) {
        char c; int u, v; scanf("%c %d%d\n", &c, &u, &v);
        m[idx(c)][0] = u; m[idx(c)][1] = v;
    }
    while (true) {
        int ans = 0; char c = 0;
        stack<int> row, col;
        while (scanf("%c", &c) == 1 && c != '\n') {
            if (ans == -1) continue;
            if (c == ')') {
                int r2 = row.top(); row.pop();
                int r1 = row.top(); row.pop();
                int c2 = col.top(); col.pop();
                int c1 = col.top(); col.pop();
                if (c1 != r2) {
                    ans = -1; printf("error\n");
                } else {
                    ans += r1*c1*c2;
                    row.push(r1); col.push(c2);
                }
            } else if (c >= 'A' && c <= 'Z') {
                row.push(m[idx(c)][0]);
                col.push(m[idx(c)][1]);
            }
        }
        if (!c) break;
        if (ans != -1) printf("%d\n", ans);
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
