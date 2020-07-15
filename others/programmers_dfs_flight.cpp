/*
    여행경로 - 항공권 정보가 담긴 2차원 배열이 주어질 때, 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다.
                항상 ICN 공항에서 출발하며 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10001

int adj[MX][MX];
unordered_map<string, int> to_idx;
string to_airport[MX];
vector<string> path;

void euler(int s){
    for(int d=0; d<MX; d++){
        while(adj[s][d]){
            adj[s][d]--;
            euler(d);
        }
    }

    path.push_back(to_airport[s]);
}

vector<string> solution(vector<vector<string>> tickets) {
    memset(adj,0,sizeof(adj));

    int s = tickets.size(), idx = 0;
    set<string> ss;
    for(int i=0; i<s; i++){
        ss.insert(tickets[i][0]);
        ss.insert(tickets[i][1]);
    }

    for(string str : ss){
        to_idx[str] = idx;
        to_airport[idx++] = str;
    }


    for(int i=0; i<s; i++){
        int a=to_idx[tickets[i][0]], b=to_idx[tickets[i][1]];
        adj[a][b]++;
    }

    euler(to_idx["ICN"]);

    reverse(path.begin(), path.end());
    return path;
}