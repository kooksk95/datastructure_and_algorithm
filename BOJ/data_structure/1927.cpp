#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++) //repeat a~b
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;



int main(){
    IOS
    
    int N; cin>>N;
    priority_queue<int, vi, greater<int>> q;
    while(N--){
        int n; cin>>n;
        if(n) q.push(n);
        else if(q.empty()) cout << "0\n";
        else {
            int p = q.top(); q.pop();
            cout << p << "\n";
        } 
    }
    
    
    return 0;
}



