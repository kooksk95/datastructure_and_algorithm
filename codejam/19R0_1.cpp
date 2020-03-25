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

ll n, k;
int cost[MAX];
// bool seen[MAX];
int indeg[MAX];
vi adj[MAX];

// vi topo;


int main(){
    IOS
    
    int test; cin >> test;
    
    REP(i, 1, test){
        string N; cin >> N;
        int s = N.size();
        
        int len_A=0, len_B=0;
        vi A, B;
        while(s--){
            int dig = N[s] - '0';
            if(dig == 4){
                A.pb(1), B.pb(3);
                len_A++;
                len_B = len_A;
            } else {
                A.pb(dig);
                B.pb(0);
                len_A++;
            }

        }
        
        
        // OUT
        cout << "Case #"<<i<<": ";
        // <<A<<" "<<B<<"\n"; 
        for(int i = len_A-1; i >=0; i--){
            cout << A[i];
        }
        cout << " ";
        for(int i = len_B-1; i >=0; i--){
            cout << B[i];
        }
        ENT
        
    }
    
    
    return 0;
}



