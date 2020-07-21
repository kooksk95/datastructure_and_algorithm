#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool comp(vector<int> v, int a){
    int x=v[0], s=0, b=0;
    int a1=a%10, a2=(a/10)%10, a3=a/100;
    bool ball[10] = {};
    ball[a1]=1, ball[a2]=1, ball[a3]=1;
    
    if(x%10 == a1) s++;
    else if(ball[x%10]) b++;
    x /= 10;
    if(x%10 == a2) s++;
    else if(ball[x%10]) b++;
    x /= 10;
    if(x == a3) s++;
    else if(ball[x%10]) b++;
    
    return (s==v[1] && b==v[2]);
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(i == j) continue;
            for(int k=1; k<10; k++){
                if(k==i || k==j) continue;
                
                bool possible = 1;
                int num = 100*i + 10*j + k;
                for(auto x : baseball){
                    if(!comp(x, num)) {
                        possible = 0;
                        break;
                    }
                }
                if(possible) answer++;
            }
        }
    }
    
    return answer;
}