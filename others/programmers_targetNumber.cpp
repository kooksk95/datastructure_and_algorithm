#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> numbers, int target) {
    int s = numbers.size();
    int answer = 0, plus = target+numbers[0], minus = target-numbers[0];
    
    if(s == 1){
        return plus == 0 || minus == 0 ? 1 : 0;
    } else {
        vector<int> new_arr(s-1);
        copy(numbers.begin()+1, numbers.end(), new_arr.begin());
        
        answer += solve(new_arr, plus);
        answer += solve(new_arr, minus);
        return answer;
    }
}

int solution(vector<int> numbers, int target) {
    return solve(numbers, target);
}