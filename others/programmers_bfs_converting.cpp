/*
    begin, target과 단어의 집합 words가 있습니다. 한 번에 한개의 알파벳만
    바꿔서 begint에서 target으로 가는 짧은 변환 과정을 찾으시오.
    단, words에 있는 단어로만 변환할 수 있습니다.
*/
#include <bits/stdc++.h>

using namespace std;
int n, dist[51];
bool visited[51];

bool possible(string a, string b){
    int s = a.size();
    int diff = 0;
    while(s--){
        if(a[s] != b[s])
            diff++;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int answer = 0, n = words.size()-1;
    
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    dist[n] = 0;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        if(words[c].compare(target)==0){
            answer = dist[c];
            break;
        }
        
        for(int i = 0; i<n; i++){
            if(visited[i] || !possible(words[c], words[i])) continue;
            
            visited[i] = 1;
            dist[i] = dist[c] + 1;
            q.push(i);
        }
    }
    
    return answer;
}