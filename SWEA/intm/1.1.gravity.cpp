/*

    상자들이 쌓여있는 방을 시계방향으로 90도 회전했을 때, 가장 큰 낙차 값을 출력

*/

#include <bits/stdc++.h>
using namespace std;
#define ROOM 9

int main(){

    int boxes[ROOM] = {7,4,2,0,0,6,0,7,0};
    int max_height = boxes[0];
    for(int i = 1; i<ROOM; i++)
        max_height = max(max_height, boxes[i]);

    int ans = 0;
    for(int i = 0; i<max_height; i++){
        int fall = 0;
        for(int j = 8; j>=0; j--){
            if(boxes[j] == 0) fall++;
            else {
                ans = max(fall, ans);
                boxes[j]--;
            }
        }
    }
    cout << ans;

    return 0;
}