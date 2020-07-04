// https://www.acmicpc.net/problem/16937
// first trial: ??
// final time: ??
#include <bits/stdc++.h>
using namespace std;

int H, W, N;

bool myfunc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first > b.first);
}

bool fit(int r, int c, int h, int w){
    return (r<=h && c<=w);
}

bool possible(int r1, int c1, int r2, int c2){
    bool ret = false;
    //not rotate sticker1
    if(fit(r1, c1, H, W)){
        ret = fit(r2, c2, H-r1, W)
            || fit(r2, c2, H, W-c1)
            || fit(c2, r2, H-r1, W)
            || fit(c2, r2, H, W-c1);
    }
    
    //rotate sticker1
    if(!ret && fit(c1, r1, H, W)){
        ret = fit(r2, c2, H-c1, W)
            || fit(r2, c2, H, W-r1)
            || fit(c2, r2, H-c1, W)
            || fit(c2, r2, H, W-r1);
    }
    //cout << r1 << "*" << c1 <<" " << r2 << "*" << c2 << ": " << ret << "\n";
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> H>>W>>N;
    //cout << H << "*" << W << "\n";
    
    vector<pair<int,int>> stickers(N), area(N);
    for(int i = 0; i<N; i++){
        cin>>stickers[i].first>>stickers[i].second;
        area[i].first = stickers[i].first * stickers[i].second;
        area[i].second = i;
    }
    
    sort(area.begin(), area.end(), myfunc);

    int answer = 0;
    for(int i = 0; i<N-1; i++){
        int idx1 = area[i].second;
        int r1 = stickers[idx1].first, c1 = stickers[idx1].second;
        
        for(int j = i+1; j<N; j++){
            int idx2 = area[j].second;
            int r2 = stickers[idx2].first, c2 = stickers[idx2].second;
            
            if(possible(r1, c1, r2, c2))
                answer = max(answer, area[i].first + area[j].first);
        }
    }
    
    cout << answer;
    
    return 0;
}