#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> t) {
    int s = t.size();
    
    for(int i=1; i<s; i++){
        t[i][0] += t[i-1][0];
        for(int j=1; j<i; j++)
            t[i][j] += max(t[i-1][j-1], t[i-1][j]);
        
        t[i][i] += t[i-1][i-1];
    }
    
    int answer = 0;
    for(int x : t[s-1]) answer = max(answer, x);
    
    return answer;
}