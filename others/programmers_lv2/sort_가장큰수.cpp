#include <bits/stdc++.h>

using namespace std;

bool myfunc(const string& a, const string& b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector<string> num;
    for(int i=0; i<numbers.size(); i++)
        num.push_back(to_string(numbers[i]));
    
    sort(num.begin(), num.end(), myfunc);
    if(num[0] == "0") return "0";
    
    string answer = "";
    for(string x : num)
        answer += x;
    return answer;
}