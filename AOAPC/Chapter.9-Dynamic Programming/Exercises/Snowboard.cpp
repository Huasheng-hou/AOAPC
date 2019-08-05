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
            
            cin >> name >> R >> C;
            
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> m[i][j];
                }
            }
            
            int ans = 1;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> m[i][j];
                }
            }
        }
    }
};
