
#include <bits/stdc++.h>

using namespace std;
#define MAX 51
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);
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
    
    int n; cin >> n;
    queue<int> q;
    REP(i, 1, n) q.push(i);
    
    while(q.size() > 1){
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    
    cout << q.front();
    
    return 0;
}

