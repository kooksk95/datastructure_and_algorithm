#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = s.size()/2;
    if(s.size() & 1)
        answer = s[i];
    else
        answer = s.substr(i-1, 2);
    
    return answer;
}