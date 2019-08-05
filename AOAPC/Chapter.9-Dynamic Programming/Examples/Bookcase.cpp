//
//  Bookcase.cpp
//  AOAPC
//
//  Created by apple on 2019/8/5.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <vector>

// * 12099 The Bookcase，0-1背包问题

using namespace std;

static const int maxN = 70;
static const int maxT = 30;
static const int INF = 1<<30;

struct Book {
    int height, width;
    Book(int h, int w): height(h), width(w) {};
};

static bool compare(Book b1, Book b2) { return b1.height > b2.height; }

static int d[maxN*maxT][maxN*maxT][2];

class Bookcase {
    int N, T, sumW[maxN+2];
    vector<Book> books;
    
public:
    void solve() {
        
        cin >> T;
        while(T) {
            
            T--;
            memset(d, -1, sizeof(d)); sumW[0] = 0; books.clear();
            cin >> N;
            
            for (int i = 1; i <= N; i++) {
                
                int h, w;
                cin >> h >> w;
                books.push_back(Book(h, w));
                sumW[i] = sumW[i-1] + w;
            }
            
            sort(books.begin(), books.end(), compare);
            DP();
            
            int ans = INF;
            for (int i = 5; i < sumW[N]; i++) {
                for (int j = 5; j < sumW[N]-i; j++) {
                    int height = d[i][j][(N%2)^1];
                    if (height > 0) {
                        int volume = height * max(max(i, j), sumW[N]-i-j);
                        cout << volume << "\n";
                        ans = min(ans, volume);
                    }
                }
            }
            
            cout << ans;
            cout << "\n";
            cout << "\n";
        }
    }
    
private:
    void DP() {
        
        d[0][0][0] = books[0].height; // * 第1本书放入第1层
        
        for (int i = 1; i < N; i ++) {
            
            int c = i%2, p = 1^c;
            int w = books[i].width;
            int h = books[i].height;
            
            for (int j = 0; j <= sumW[i]; j ++) {
                for (int k = 0; k <= sumW[i] - j; k++) {
                    
                    if (d[j][k][p] < 0) continue; // 不允许状态转移
                    d[j][k][c] = d[j][k][p];
                    if (j == 0) {
                        d[j+w][k][c] = d[j][k][p] + h;
                    } else {
                        d[j+w][k][c] = d[j][k][p];
                    }
                    if (k == 0) {
                        d[j][k+w][c] = d[j][k][p] + h;
                    } else {
                        d[j][k+w][c] = d[j][k][p];
                    }
                }
            }
        }
    }
};
