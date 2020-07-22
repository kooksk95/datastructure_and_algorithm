#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    bool first = 1;
    for(char c : s){
        if(c==' ') first = 1;
        else if(!first) c = tolower(c);
        else
            first = 0, c = toupper(c);
        
        answer += c;
    }
    return answer;
}