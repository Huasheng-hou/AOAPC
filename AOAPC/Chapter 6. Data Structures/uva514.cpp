//
//  uva514.cpp
//  AOAPC
//
//  Created by apple on 2019/9/18.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <math.h>
#include <string.h>

// 

using namespace std;

void solve() {

    int n; int flag = 0;
    while (scanf("%d", &n) && n > 0) {
        while (true) {
            int u = 0, v = 0; int judge = 0; // 需要一个变量 v 记录已入栈的位置
            stack<int> s;
            for (int i = 1; i <= n; i++) {
                scanf("%d", &u); if (!u) break;
                if (judge) continue;
                if (!s.empty() && s.top() == u) s.pop();
                else if (v < u) {
                    while (v < u) {
                        v++; s.push(v);
                    }
                    s.pop();
                } else {
                    judge = 1;
                }
            }
            if (!u) break;
            if (judge) printf("No\n"); else printf("Yes\n");
        }
        printf("\n");
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
