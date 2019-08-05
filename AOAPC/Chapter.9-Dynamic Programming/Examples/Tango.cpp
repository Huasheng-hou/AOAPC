//
//  Tango.cpp
//  AOAPC
//
//  Created by apple on 2019/8/4.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <iostream>
#include <queue>

// * 10618 Tango Tango Insurrection

using namespace std;

static const int maxN = 70+2;
static const int t_up     = 0;
static const int t_left   = 1;
static const int t_right  = 2;
static const int t_down   = 3;

struct Action {
    
    // state = 0, not move, 1, move left foot, 2, move right foot
    int index, left, right, state, energy;
    
    Action(int i, int l, int r, int s, int e):
    index(i), left(l), right(r), state(s), energy(e) {};
    
    friend bool operator < (Action a, Action b) {
        return a.energy > b.energy;
    }
};

class Tango {
    
    int N;
    char s[maxN];
    Action last;
    
public:
    void solve() {
        
        while (cin >> s && s[0] != '#') {
            
            N = 0;
            for (int i = 0; i <= maxN; i ++) if (s[i] != 0) N++;

            BellmanFord();
            
            cout << s;
            cout << "\n";
        }
    }
    
private:
    void BellmanFord() {

        priority_queue<Action> Q;

        Action a = Action(0, t_left, t_right, 0, 0);
        Q.push(a);

        while (!Q.empty()) {

            Action u = Q.top(); Q.pop();
            if (u.index == N) { last = u; break; }

            char next = s[u.index];
            int e; // energy
            if (next == '.') {
                for (int i = 0; i < 4; i ++) {
                    e = energy(u.state, u.left, u.right, i, u.right);
                    if (e > -1) {
                        Action v = Action(u.index++, i, u.right, 1, u.energy+e);
                        if (i == u.left) v.state = 0;
                        Q.push(v);
                    }
                    e = energy(u.state, u.left, u.right, u.left, i);
                    if (e > -1) {
                        Action v = Action(u.index++, u.left, i, 2, u.energy+e);
                        if (i == u.right) v.state = 0;
                        Q.push(v);
                    }
                }
            } else {
                
            }
        }
    }
    
    int energy(int s, int left, int right, int m_l, int m_r) {
        
        if (m_l == m_r) return -1; // 两脚不能在同一个踏板
        if (m_l == t_right && m_r == t_left) return -1; // 不能转身
        if (left != m_l && right != m_r) return -1;
        if (left != m_l) {
            if (right == t_left) return -1;
        } else {
            if (left == t_right) return -1;
        }
        if (s == 0) {
            if (left == m_l && right == m_r) return 0;
            return 1;
        }
        if (left == m_l && right == m_r) return 3;
        if (adjacent(left, m_l) || adjacent(right, m_r)) return 5;
        return 7;
    }
    
    bool adjacent(int f1, int f2) {
        if (f1 == t_left && (f2 == t_up || f2 == t_down)) return true;
        if (f1 == t_right && (f2 == t_up || f2 == t_down)) return true;
        if (f1 == t_up && (f2 == t_left || f2 == t_right)) return true;
        if (f1 == t_down && (f2 == t_left || f2 == t_right)) return true;
        return false;
    }
    
    int idx(char s) {
        if (s == 'U') return 0;
        if (s == 'L') return 1;
        if (s == 'R') return 2;
        if (s == 'D') return 3;
        return 0;
    }
};
