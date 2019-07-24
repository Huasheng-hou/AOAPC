//
//  FunnyCarRacing.cpp
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

// 单源最短路 Dijkstra

using namespace std;

struct Edge {
    int from, to, open, close, time;
    Edge(int u, int v, int a, int b, int w):
    from(u),to(v),open(a),close(b),time(w) {};
};

typedef pair<int, int> node;

class FunnyCarRacing {

    vector<Edge>edge;
    vector<int> G[400+2];
    int s, t = 0, d[400+2], maxn = 400 + 2;
    
    public: void carRacing() {
    
        int n, m, count = 0;
        while (cin >> n >> m >> s >> t) {
            
            count ++;
            
            int u, v, a, b, w = 0;
            for (int i = 0; i < m; i ++) {
                
                cin >> u >> v >> a >> b >> w;
                addEdge(u, v, a, b, w);
            }
            
            Dijkstra(n);
            cout << "Case " << count << ": " << d[t] << "\n";
            
            edge.clear(); for (int i = 0; i < maxn; i ++) G[i].clear();
        }
    }
    
    private: void Dijkstra(int n) {
    
        for (int i = 0; i < maxn; i ++) d[i] = INT_MAX;
        priority_queue<node, vector<node>, greater<node>> q;
        d[s] = 0;
        
        q.push(make_pair(0, s));
        while (!q.empty()) {
            
            node u = q.top(); q.pop();
            if (u.second == t) break;
            for (int i = 0; i < (int)G[u.second].size(); i++) {
                
                Edge e = edge[G[u.second][i]];
                
                if (e.open < e.time) continue;
                
                int offset = d[u.second] % (e.open + e.close);
                int w = offset + e.time <= e.open ? e.time :
                e.close - offset + e.open + e.time;
                
                if (d[e.to] > w + d[u.second]) {
                    d[e.to] = w + d[u.second];
                    q.push(make_pair(d[e.to], e.to));
                }
            }
        }
    }
    
    private: void addEdge(int from, int to, int open, int close, int time) {
    
        edge.push_back(Edge(from, to, open, close, time));
        G[from].push_back((int)edge.size() - 1);
    }
};
