#include <bits/stdc++.h>
using namespace std;

#define TGT 10

// 문제: x+y+z = 100의 자연수 해를 모두 출력
// 수정: x+y+z = 10 (36개)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> answers;

    for(int i=1; i<=TGT-2; i++){
        for(int j=1; j<=TGT-2; j++){
            if(i+j+1 > TGT) break;

            vector<int> tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            tmp.push_back(TGT-i-j);
            answers.push_back(tmp);
        }
    }

    
    for(auto x: answers){
        cout << x[0] << "+" << x[1] << "+" << x[2] << "\n";
    }
    cout << answers.size();

    return 0;
}