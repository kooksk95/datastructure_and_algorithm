#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b==0? a : gcd(b, a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n>m ? gcd(n, m) : gcd(m,n);
    answer.push_back(a);
    answer.push_back(n*m/a);
    return answer;
}