#include <string>
using namespace std;

int solution(string s) {
    int answer=1, ss=s.size(), dp[2501][2501];
    for(int j=0; j<ss; j++)
        dp[j][j] = 1;
    for(int j=0; j<ss-1; j++){
        if(s[j]==s[j+1]){
            dp[j][j+1] = 1;
            answer = 2;
        }
    }
    
    for(int k=2; k<ss; k++){
        for(int j=0; j<ss-k; j++){
            if(dp[j+1][j+k-1] && s[j]==s[j+k]){
                dp[j][j+k] = 1;
                answer = k+1;
            }
        }
    }
    
    return answer;
}