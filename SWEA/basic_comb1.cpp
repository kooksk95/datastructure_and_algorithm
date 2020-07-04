#include <bits/stdc++.h>
using namespace std;

// 문제: 52장 카드에서 만들수 있는 페어가 하나만 있는 5장 조합을 모두 출력
// 수정 1: 52장 경우의 수를 정확히 세는가
// 수정 2: 8*3 = 24장의 카드에서 페어가 하나만 있는 3장 조합 모두 출력

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Q. Count 5 out of 52 in such case\n";


    cout << "Q. Try with description 2\n";
    int patterns = 3;
    string pattern[patterns] = {"Heart", "Diamond", "Spade"};
    vector<vector<string>> answer;

    for(int i = 1; i<=8; i++){
        // pattern of is
        for(int j = 0; j<patterns-1; j++){
            for(int k = j+1; k<patterns; k++){
                string card1, card2, card3;
                card1 = pattern[j] + " " + to_string(i);
                card2 = pattern[k] + " " + to_string(i);
                
                // other card
                for(int j = 1; j<=8; j++){
                    if(i == j) continue;
                    for(int k = 0; k < 3; k++){
                        string card3 = pattern[k] + " " + to_string(j);
                        vector<string> tmp;
                        tmp.push_back(card1);
                        tmp.push_back(card2);
                        tmp.push_back(card3);
                        answer.push_back(tmp);
                    }
                }
                
            }
        }
    }

    for(int i = 0; i<answer.size(); i++){
        vector<string> p = answer[i];
        cout << i+1 << ": " << p[0] << " " << p[1] << " " << p[2] << "\n";
    }



}