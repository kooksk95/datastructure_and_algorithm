#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n){
        int rem = n%3;
        n /= 3;
        if(rem == 0){
            rem = 4;
            n--;
        }
        answer = to_string(rem) + answer;
    }
    
    return answer;
}