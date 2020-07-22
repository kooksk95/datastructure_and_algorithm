#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;
    while(1){
        if(abs(a-b)==1 && (min(a,b)&1)) break;
        
        answer++, a = (a+1)/2, b = (b+1)/2;
    }
    return answer;
}