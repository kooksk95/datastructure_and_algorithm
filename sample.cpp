#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    set<int> s;
    for(int x : nums) s.emplace(x);
    int ss = nums.size()/2;
    int answer = min(s, ss);
    return answer;
}

int main(){
	int a[6] = {3,3,3,2,2,4};
	vector<int> vec;
	vec.insert(vec.begin(), a, a+6);
	cout<<solution(vec);

    return 0;
}