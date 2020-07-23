#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    vector<vector<long long>> dp(N, vector<long long> (2));
    dp[0] = {2,2};
    for(int i=1; i<N; i++)
        dp[i][0] = dp[i-1][0]+dp[i-1][1], dp[i][1] = dp[i-1][0];
    
    return dp[N-1][0] + dp[N-1][1];
}