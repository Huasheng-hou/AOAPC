//
//  Snowboard.cpp
//  AOAPC
//
//  Created by apple on 2019/8/5.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <string>

// 10285 Snowboard

using namespace std;

static const int maxR = 100;
static const int maxC = 100;

class Snowboard {
    int N, R, C, m[maxR][maxC], d[maxR][maxC];
    string name;
    
public:
    void solve() {
        
        cin >> N;
        while (N) {
            N--;
            memset(d, 0, sizeof(d));
            
            cin >> name >> R >> C;
            
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> m[i][j];
                }
            }
            
            int ans = 1;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    ans = max(ans, DP(i, j));
                }
            }
            
            cout << name << ": " << ans;
            cout << "\n";
        }
    }
    
private:
    int DP(int r, int c) {
        if (d[r][c] > 0) {
            return d[r][c];
        }
        
        int &ans = d[r][c]; ans = 1; int h = m[r][c];
        if (r > 0 && m[r-1][c] < h) ans = max(ans, DP(r-1, c)+1);
        if (r < R-1 && m[r+1][c] < h) ans = max(ans, DP(r+1, c)+1);
        if (c > 0 && m[r][c-1] < h) ans = max(ans, DP(r, c-1)+1);
        if (c < C-1 && m[r][c+1] < h) ans = max(ans, DP(r, c+1)+1);
        
        return ans;
    }
};
