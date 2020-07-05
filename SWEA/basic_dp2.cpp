#include <bits/stdc++.h>
using namespace std;


// 문제: n개의 행렬을 곱하는 데 필요한 계산량을 최소화하는 순서를 찾아라

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> price(N+1);
    for(int &x : price) cin >> x;

    
    long long int c[N+1][N+1] = {0};

    for(int s = 1; s <= N-1; s++){
        for(int i = 1; i <= N-s; i++){
            int j = i+s;
            int cost = INT_MAX;

            for(int k = i; k < j; k++){
                int compare = c[i][k] + c[k+1][j] + price[i-1]*price[k]*price[j];
                cost = min(cost, compare);
            }

            c[i][j] = cost;
        }
    }

    cout << c[1][N];

    return 0;
}