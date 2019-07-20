//
//  OptimalBusRoute.cpp
//  AOAPC
//
//  Created by apple on 2019/7/20.
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

using namespace std;

struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w):
    from(u),to(v),cap(c),flow(f),cost(w) {};
};

static int s = 0, t = 1;
static int maxn = 99 + 2;
static vector<Edge> e;
static vector<int> G[101];
static int inq[101];
static int d[101];
static int p[101];
static int a[101];
static int flow;
static long long cost;

class OptimalBusRoute {
public: void optimalRoute() {

    int n;
    while (cin >> n && n > 0) {
        
        int to, w;
        for (int i = 0; i < n; i ++) {

            addEdge(s, i + t + 1, 1, 0);
            addEdge(i + t + 1 + n, t, 1, 0);
            cin >> to;
            while (to != 0) {
                
                int tmp = to;
                cin >> w >> to;
                addEdge(i + t + 1, tmp + t + n, 1, w);
            }
        }

        flow = 0;
        cost = 0;
        while (BellmanFord());
        
        if (flow < n) {
            cout << "N" << "\n";
        }
        cout << cost << "\n";
        
        e.clear();for (int i = 0; i < 101; i ++) G[i].clear();
    }
}
    
private: bool BellmanFord () {
    
    for (int i = 0; i < maxn; i ++) d[i] = 1<<20;
    memset(inq, 0, sizeof(inq));
    
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = 1<<20;
    
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        
        int u = q.front(); q.pop();
        inq[u] = 0; // *将取出的元素重新作为待遍历对象
        for (int i = 0; i < (int)G[u].size(); i ++) {
            Edge edge = e[G[u][i]];
            if (edge.cost + d[u] < d[edge.to] && edge.cap > edge.flow) {
                
                d[edge.to] = d[u] + edge.cost;
                p[edge.to] = G[u][i];
                a[edge.to] = min(a[u], edge.cap - edge.flow);
                if (!inq[edge.to]) {q.push(edge.to); inq[edge.to] = 1;}
            }
        }
    }
    if (d[t] == 1<<20) return false;
    flow += a[t];
    cost += (long long)d[t] * (long long)a[t];
    
    for (int u = t; u != s; u = e[p[u]].from) {
        e[p[u]].flow += a[t];
        e[p[u]^1].flow -= a[t];
    }
    
    return true;
}
    
private: void addEdge(int from, int to, int cap, int cost) {
    
    e.push_back(Edge(from, to, cap, 0, cost));
    e.push_back(Edge(to, from, 0, 0, -cost));
    
    int m = (int)e.size();
    
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}
    
};
