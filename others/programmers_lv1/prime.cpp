#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool not_prime[1000001] = {0};
    for(int i=2; i<=n; i++){
        if(not_prime[i]) continue;
        answer++;
        for(int j=i*2; j<=n; j+=i)
            not_prime[j] = 1;
    }
    
    return answer;
}