#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    set<int> l, r;
    for(int i=0; i<lost.size(); i++)
        l.insert(lost[i]);
    for(int i=0; i<reserve.size(); i++){
        if(l.count(reserve[i])) l.erase(reserve[i]);
        else r.insert(reserve[i]);
    }
    
    for(int x : r){
        if(l.count(x-1)){
            l.erase(x-1);
            r.erase(x);
        } else if (l.count(x+1)) {
            l.erase(x+1);
            r.erase(x);
        }
    }
    
    return n-l.size();
}