#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    while(k){
    	if(k > number.size() - 1) return answer;
    	
        auto it = max_element(number.begin(), number.begin()+k+1);
        answer += *it;
        k -= it - number.begin();
        number = number.substr(it-number.begin()+1);
    }
    answer += number;
    return answer;
}