#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()

long long solution(int n, vector<int> works) {
    set<int, greater<int>> times;
    int cnt[50001] = {0};
    for(int i=0; i<works.size(); i++){
        times.insert(works[i]);
        cnt[works[i]]++;
    }

    while(1){
        int a1 = *times.begin(), c=cnt[a1];
        cnt[a1]=0;
        times.erase(a1);
        int a2 = times.empty() ? 0 : *times.begin();
        int df = (a1-a2)*c;
        
        if(df<=n){
            if(a2 == 0) return 0;
            cnt[a2] += c;
            n -= df;
        } else {
            int total = a1*c-n;
            int each = total/c;
            times.insert(each);
            cnt[each] += c-total%c;
            if(total % c){
                times.insert(each+1);
                cnt[each+1] = total % c;
            }
            break;
        }
        
    }
    
    long long answer = 0;
    for(int x : times) answer += x*x*cnt[x];
    
    return answer;
}