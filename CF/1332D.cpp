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
    int k; cin>>k;
    
    int x = pow(2, 17);
    
    cout << "2 3\n";
    int arr[3][4] = {
        {k+x, x, 0},
        {k, k+x, k},
    };
    
    REP(i, 0, 1){
        REP(j, 0, 2) cout << arr[i][j] << " ";
        ENT
    }


    return 0;
}

        
