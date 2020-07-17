#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int N;
bool myfunc(const string& a, const string& b){
    return a[N] == b[N] ? a < b : a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n; 
    sort(strings.begin(), strings.end(), myfunc);
    return strings;
}