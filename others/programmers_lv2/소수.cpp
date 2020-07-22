#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    bool is_prime[50001];
    memset(is_prime, 1, sizeof(is_prime));
    for(int i=2; i<50001; i++){
        if(!is_prime[i]) continue;
        
        for(int j=i+i; j<50001; j+=i)
            is_prime[j] = 0;
    }
    
    int answer = 0, s = nums.size();
    for(int i=0; i<s; i++)
        for(int j=i+1; j<s; j++)
            for(int k=j+1; k<s; k++)
                answer += is_prime[nums[i]+nums[j]+nums[k]];

    return answer;
}