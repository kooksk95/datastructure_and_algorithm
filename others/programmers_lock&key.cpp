#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> l, k;
int m, n;

void rotate(){
    vector<vector<int>> tmp;
    for(int y = 0; y<m; y++){
        vector<int> vec;
        for(int x = m-1; x>=0; x--){
            vec.push_back(k[x][y]);
        }
        tmp.push_back(vec);
    }
    k = tmp;
}

bool trial(int x, int y){
    bool res = 1;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            // cout << "i,j = " << i << " " << j << "\n";
            if(i>=x && i<x+m && j>=y && j<y+m){
                int fit = l[i][j] + k[i-x][j-y];
                res = fit == 1 ? 1 : 0;
                // cout << res << " " << fit << "\n";
                // cout << "lock(" << i << "," << j << ")="<< l[i][j]
                //     << " key (" << i-x << "," << j-y << ")=" << k[i-x][j-y] <<"\n";
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
            // cout << "~~~ TRY from key " << i << "," << j << "\n";            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }

    rotate();
    for(int i = -m+1; i< n; i++){
        for(int j = -m+1; j< n; j++){
            // cout << "~~~ TRY from key " << i << "," << j << "\n";            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }

    rotate();
    for(int i = -m+1; i< n; i++){
        for(int j = -m+1; j< n; j++){
            // cout << "~~~ TRY from key " << i << "," << j << "\n";            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }

    rotate();
    for(int i = -m+1; i< n; i++){
        for(int j = -m+1; j< n; j++){
            // cout << "~~~ TRY from key " << i << "," << j << "\n";            
            answer = trial(i, j);
            if(answer) return answer;
        }
    }

    return answer;
}