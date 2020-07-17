#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ') {
            answer.push_back(s[i]);
            continue;
        }
        
        bool capital = s[i] <= 'Z';
        int x = s[i] + n;
        if((capital && x>'Z')
           || (!capital && x>'z') )
            x -= 26;
        
        answer.push_back((char) x);
    }
    return answer;
}