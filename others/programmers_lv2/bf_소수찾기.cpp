#include <bits/stdc++.h>
using namespace std;
#define MX 10000000

bool not_prime[MX];    
string str;
int s;
set<int> answer;

void dfs(string curr, int visited){
    int num = stoi(curr);
    if(!not_prime[num]) answer.insert(num);
    
    if(visited == (1<<s)-1) return;
    
    for(int i=0; i<s; i++){
        if(visited & (1<<i)) continue;
        
        dfs(curr + str[i], visited | (1<<i));
    }
}

int solution(string numbers) {
    memset(not_prime, 0, sizeof(not_prime));
    s = numbers.size();
    str = numbers;

    not_prime[0] = 1, not_prime[1] = 1;
    for(int i=2; i<MX; i++){
        if(not_prime[i]) continue;
        
        for(int j=2*i; j<MX; j+=i)
            not_prime[j] = 1;
    }
    
    for(int i=0; i<s; i++)
        dfs(numbers.substr(i, 1), 1<<i);
    
    return answer.size();
}