#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

int solution(vector<int> arr) {
    if(arr.size() == 1) return arr[0];
    
    int lcm = arr[0]*arr[1]/gcd(arr[0],arr[1]);
    for(int i=2; i<arr.size(); i++){
        lcm = lcm*arr[i]/gcd(lcm, arr[i]);
    }
    
    return lcm;
}