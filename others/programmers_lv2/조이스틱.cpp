#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0, s = name.size(), loc = -1;
    vector<int> changes(s);
    for(int i=0; i<s; i++){
        if(name[i] == 'A') continue;
        changes[i] = name[i]<'N'? name[i]-'A' : 'A'+26-name[i];
        loc = i;
    }
    
    if(loc == -1) return 0;
    
    int l=0, comp = 0;
    for(int i=0; i<s; i++){
        if(!changes[loc]) comp++;
        else {
            l = max(l, comp);
            comp = 0;
        }
        loc = (loc+1)%s;
    }
    
    l = max(l, comp);
    for(int x : changes) answer += x;
    
    return answer + name.size() - l - 1;
}