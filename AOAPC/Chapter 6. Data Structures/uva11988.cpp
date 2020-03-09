//
//  uva11988.cpp
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

const int maxn = 100010;
char w[maxn];
int nxt[maxn];

void solve() {

    while (true) {
        memset(nxt, -1, sizeof(nxt));
        // pre保存cursor位置，tail保存链表尾部
        int pre = 0, tail = 0, cnt = 1; char c = 0;
        while (scanf("%c", &c) == 1 && c != '\n') {
            if (c == '[') {
                if (nxt[pre] == -1) tail = pre;
                pre = 0;
            } else if (c == ']') {
                pre = tail;
            } else { // 链表插入
                int tmp = nxt[pre];
                nxt[pre] = cnt; nxt[cnt] = tmp;
                if (tmp == -1) tail = cnt;
                pre = cnt;
                w[cnt] = c; cnt++;
            }
        }
        if (!c) break;
        int u = 0;
        while (nxt[u] != -1) {
            u = nxt[u]; printf("%c", w[u]);
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
