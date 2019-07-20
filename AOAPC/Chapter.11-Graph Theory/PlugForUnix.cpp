//
//  PlugForUnix.cpp
//  AOAPC
//
//  Created by apple on 2019/7/16.
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
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

static vector<int> G[400 + 2];
static vector<Edge> e;

static int s = 0, t = 1;

class PlugForUnix {
public: void maximalPlugins() {
    
    int count;
    cin >> count;
    while (count) {
        count -- ;
        
        for (int i = 0; i < 400+2; i ++) G[i].clear();
        e.clear();
        
        int n, m, k;
        map<string, int> v;
        int p, r;
        
        string recept, plug, name;
        
        cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> recept;
            
            r = v.count(recept) ? v[recept] : (int)v.size();
            v[recept] = r;
            addEdge(r + t + 1, t, 1);
        }
    
        cin >> m;
        for (int i = 0; i < m; i ++) {
            
            cin >> name >> plug;
            p = v.count(plug) ? v[plug] : (int)v.size();
            v[plug] = p;
            addEdge(s, p + t + 1, 1);
        }
        
        cin >> k;
        int from, to;
        for (int i = 0; i < k; i ++) {
            
            cin >> recept >> plug;
            from = v.count(recept) ? v[recept] : (int)v.size();
            v[recept] = from;
            
            to = v.count(plug) ? v[plug] : (int)v.size();
            v[plug] = to;
            
            addEdge(from + t + 1, to + t + 1, 1<<20);
        }
        
        int flow = maxFlow();
        cout << m - flow;
        cout << "\n";
        if (!count) continue;
        cout << "\n";
    }
}
    
private: int maxFlow() {
    
    int maxn = 400 + 2;
    int a[maxn], p[maxn], flow = 0;
    
    while (true) {
        memset(a, 0, maxn * sizeof(int));
        
        queue<int> q;
        a[s] = 1 << 20;
        q.push(s);
        while (!q.empty()) {
            
            int u = q.front(); q.pop();
            for (int i = 0; i < G[u].size(); i ++) {
                Edge edge = e[G[u][i]];
                if (!a[edge.to] && edge.cap > edge.flow) {
                    a[edge.to] = min(a[u], edge.cap - edge.flow);
                    p[edge.to] = G[u][i];
                    q.push(edge.to);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;
        
        int k = t;
        while (k != s ) {
            e[p[k]].flow += a[t];
            e[p[k]^1].flow -= a[t];
            k = e[p[k]].from;
        }
        flow += a[t];
    }
    return flow;
}
    
private: void addEdge(int from, int to, int cap) {
    
    e.push_back(Edge(from, to, cap, 0));
    e.push_back(Edge(to, from, 0, 0));
    
    int m = (int)e.size();
    
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}
};
