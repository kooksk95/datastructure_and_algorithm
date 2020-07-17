#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int s = phone_number.size();
    string answer(s-4, '*');
    answer += phone_number.substr(s-4);
    return answer;
}