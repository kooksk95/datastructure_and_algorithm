#include <bits/stdc++.h>
using namespace std;


// 문제: 정수 배열의 최대 증가 부분 배열을 찾아라

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input[8] = {6, 2, 5, 1, 7, 4, 8, 3};

    // O(N^2)
    int lis[8];

    for(int i = 0; i < 8; i++){
        lis[i] = 1;

        for(int l = 0; l < i; l++){
            
            if(input[i] > input[l]){
                lis[i] = max(lis[i], lis[l]+1);
            }
        }
    }

    int ans = -1;
    for(int i = 0; i<8; i++){
        cout << lis[i] << " ";
        ans = max(ans, lis[i]);
    }

    cout << "\n" << ans << "\n";


    // O(nlogn)
    vector<int> lis_val;
    lis_val.push_back(input[0]);
    
    for(int i = 1; i<8; i++){
        vector<int>::iterator it = lower_bound(lis_val.begin(), lis_val.end(), input[i]);
        
        if(it == lis_val.end())
            lis_val.push_back(input[i]);
        else
            *it = input[i];        
   
    }

    cout << lis_val.size();

    return 0;
}