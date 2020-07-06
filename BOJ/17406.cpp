#include <bits/stdc++.h>
using namespace std;

int calc[6][3];
bool chosen[6];
set<int> answers;
int N, M, K, stage = 0;

int get_val(vector<vector<int>> arr){
    int ret = 0;
    for(int i = 0; i<N; i++){
        int sum = 0;
        for(int j = 0; j<M; j++){
            sum += arr[i][j];
        }
        ret = min(ret, sum);
    }
    return ret;
}

vector<vector<int>> rotate(vector<vector<int>> origin, int num){
    int r = calc[num][0], c = calc[num][1], s = calc[num][2];
    vector<vector<int>> ret(origin);

    for(int i = 1; i<=s; i++){
        for(int j = c-i; j<c+i; j++)
            ret[r-i][j+1] = origin[r-i][j];
        for(int j = r-i; j<r+i; j++)
            ret[j+1][c+s] = origin[j][c+s];
        for(int j = c+i; j>c-i; j--)
            ret[r+i][j-1] = origin[r+i][j];
        for(int j = r+i; j<r-i; j--)
            ret[j-1][c-i] = origin[j][c-i];
    }

    return ret;
}

void permute(vector<vector<int>> arr){
    if(stage == K){
        answers.insert(get_val(arr));
    } else {
        for (int i = 0; i<K; i++){
            if(!chosen[i]){
                stage++;
                vector<vector<int>> rotated = rotate(arr, i);
                chosen[i] = 1;
                permute(rotated);
                chosen[i] = 0;
                stage--;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(chosen, 0, sizeof(chosen));
    cin >>N>>M>>K;
    
    vector<vector<int>> arr;
    for(int i=0; i<N; i++){
        vector<int> tmp;
        for(int j=0; j<M; j++){
            int val; cin >> val;
            tmp.push_back(val);
        }
        arr.push_back(tmp);
    }

    for(int i = 0; i<K; i++){
        cin >> calc[i][0] >> calc[i][1] >> calc[i][2];
    }

    permute(arr);

    int ans = 0;
    for(int x : answers)
        ans = min(ans, x);

    cout << ans;

    return 0;
}