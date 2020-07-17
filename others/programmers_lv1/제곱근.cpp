#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    double d = sqrt(n);
    long long i = d;
    return d == i ? (i+1)*(i+1) : -1;
}