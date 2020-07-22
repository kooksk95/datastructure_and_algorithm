#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    int x, mn, mx;
    stringstream ss(s);
    ss>>mn;
    mx = mn;
    while(ss>>x)
        mn = min(mn, x), mx = max(mx, x);
    
    return to_string(mn)+" "+to_string(mx);
}