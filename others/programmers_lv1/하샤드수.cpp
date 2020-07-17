#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int h = 0;
    int tmp = x;
    while(x){
        h += x%10;
        x /= 10;
    }
    return tmp%h == 0;
}