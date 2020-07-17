using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while(n != 1){
        n = n&1 ? n*3+1 : n/2;
        answer++;
    }
    
    return answer>500 ? -1 : answer;
}