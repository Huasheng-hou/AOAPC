//
//  BugOrFeature.cpp
//  AOAPC
//
//  Created by apple on 2019/7/15.
//  Copyright © 2019 huasheng. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

typedef pair<string, string> patch;

struct fixStep {
    int t;
    string p;
    char *s;
};

class BugOrFeature {
    
public: void fixSoftware() {
    
    int n, m, count = 0;
    
    while (cin >> n >> m && (n > 0 || m > 0)) {
        
        printf("Product %d\n", ++count);
        
        vector<patch> p;
        int t[m];
        
        for (int i = 0; i < m; i ++) {
            
            int time;
            string bug, patch;
            cin >> time >> bug >> patch;
            p.push_back(make_pair(bug, patch));
            t[i] = time;
        }
        
        int c = -1;
        queue<fixStep> q;
        char *s = (char *)malloc(n * sizeof(char));
        for (int i = 0; i < n; i ++) s[i] = '1';
        
        for (int i = 0; i < m; i ++) {
            if (isMatch(n, s, p[i].first)) {
                fixStep step;
                step.p = p[i].second;
                step.t = t[i];
                step.s = s;
                q.push(step);
            }
        }
        while (q.size() > 0) {
            
            fixStep step = q.front();
            q.pop();
            char *b = fixBugs(n, step.s, step.p);
            if (status(n, b)) {
                if (c == -1) {
                    c = step.t;
                } else {
                    c = min(c, step.t);
                }
                continue;
            }
            
            for (int i = 0; i < m; i ++) {
                if (isMatch(n, b, p[i].first)) {
                    fixStep in;
                    in.p = p[i].second;
                    in.t = t[i] + step.t;
                    in.s = b;
                    q.push(in);
                }
            }
        }
        if (c == -1) {
            cout << "Bugs can't be fixed!";
        } else {
            printf("%dseconds!\n", c);
        }
        printf("\n");
    }
}
    
private: bool isMatch(int n, char *b, string pattern) {
    
    for (int i = 0; i < n; i ++) {
        if (pattern[i] == '0') {
            continue;
        } else if (pattern[i] == '-' && b[i] == '0') {
            continue;
        } else if (pattern[i] == '+' && b[i] == '1') {
            continue;
        }
        return false;
    }
    return true;
}
    
private: char * fixBugs(int n, char *b, string patch) {
    
    char *s = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i ++) {
        if (patch[i] == '0') {
            s[i] = b[i];
        } else if (patch[i] == '-') {
            s[i] = '0';
        } else {
            s[i] = '1';
        }
    }
    
    return s;
}
    
private: bool status (int n, char *b) {
    
    for (int i = 0; i < n; i ++) {
        if (b[i] == '1') return false;
    }
    return true;
}
};
