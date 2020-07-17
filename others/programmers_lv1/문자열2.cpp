#include <string>
#include <vector>
#include <iostream>

using namespace std;
int adj = 'a' - 'A';

string solution(string s) {
    string answer = "";
    bool odd = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            answer.push_back(s[i]);
            odd = 0;
            continue;
        }
        
        if(odd && s[i]<'a') s[i] += adj;
        else if(!odd && s[i]>'Z') s[i] -= adj;
        answer.push_back(s[i]);
        odd = !odd;
    }
    return answer;
}