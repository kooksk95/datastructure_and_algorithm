#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    set<int> s;
    for(int x : nums) s.emplace(x);
    
    return min(s.size(), nums.size()/2);
}