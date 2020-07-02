#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> l, k;
int m, n;

bool trial(int x, int y){
    bool res = 1;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            // cout << "i,j = " << i << " " << j << "\n";
            if(i>=x && i<x+m && j>=y && j<y+m){
                int fit = l[i][j] + k[i-x][j-y];
                res = fit == 1 ? 1 : 0;
                // cout << res << " " << fit << "\n";
                cout << "lock(" << i << "," << j << ")="<< l[i][j]
                    << " key (" << i-x << "," << j-y << ")=" << k[i-x][j-y] <<"\n";
            } else
                res &= l[i][j];
            
            if(!res) break;         // not filled or collision happened
        }
        if(!res) break;  
    }
    return res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    l = lock, k = key, m = key.size(), n = lock.size();
    
    for(int i = -m+1; i< n; i++){
        for(int j = -m+1; j< n; j++){
            cout << "~~~ TRY from key " << i << "," << j << "\n";            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }
    for(int i = n-1; i>-m ; i--){
        for(int j = n-1; j>-m; j--){
            answer = trial(i, j);
            if(answer) return answer;
        }
    }
    for(int j =n-1; j>-m; j--){
        for(int i = -m+1; i<n; i++){
            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }
    for(int j = -m+1; j< n; j++){
        for(int i = n-1; i>-m ; i--){
            answer = trial(i, j);
            if(answer) return answer;
        }
    }
    
    return answer;
}