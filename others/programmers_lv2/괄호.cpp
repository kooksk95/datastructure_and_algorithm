#include<bits/stdc++.h>
using namespace std;

bool solution(string s) {
    int cnt = 0;
    for(char c : s){
        if(c == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return 0;
    }
    
    return cnt == 0;
}