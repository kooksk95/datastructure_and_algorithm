#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n--){
        if(n&1) answer = "박" + answer;
        else answer = "수" + answer;
    }
    return answer;
}