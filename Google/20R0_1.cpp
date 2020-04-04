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

int sqr[100][100];


int main(){
    
    IOS

    int test; cin >> test;
    
    REP(t, 1, test){
        
        int N, k=0, r=0, c=0;
        cin>>N;
        REP(i, 0, N-1){
            bool row[N+1] = {};
            bool add = 0;
            
            REP(j, 0, N-1){
                int val; cin>>val;
                sqr[i][j] = val;
                
                if(i==j) k+=val;
                
                if(row[val]) add = 1;
                else row[val] = 1;
            }
            
            if(add) r++;
        }
        
        REP(j, 0, N-1){
            bool col[N+1] = {};
            bool add = 0;
            
            REP(i, 0, N-1){
                if(col[sqr[i][j]]) add = 1;
                else col[sqr[i][j]] = 1;
            }
            
            if(add) c++;
        
        }
        
        
        
        // OUT Case #x: k r c
        cout << "Case #"<<t<<": "<<k<<" "<<r<<" "<<c; ENT
        
    }
    
    
    return 0;
}
