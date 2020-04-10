#include <bits/stdc++.h>

using namespace std;
#define MAX 1001
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef pair<int,int> pi;




int main(){
    
    IOS
    
    int w[3], p[3], x;
    double ans = 0;
    REP(i, 0, 2) cin >> p[i] >> w[i];
    
    REP(i, 0, 2){
        int weight = w[i]*10;
        int price = p[i] * 10;
        if(price >= 5000) price -= 500;
        
        if(ans < (double) weight / price){
            ans = (double) weight / price;
            x = i;
        }
    }
    
    char pp[3] = {'S', 'N', 'U'};
    cout << pp[x];
    
    return 0;
}


