#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    return arr;
}

// vector<int> solution(vector<int> arr) 
// {
//     vector<int> answer(1, arr[0]);
//     for(int i=1; i<arr.size(); i++)
//         if(arr[i] != answer.back())
//             answer.push_back(arr[i]);
    
//     return answer;
// }