
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

int dr[] = {1,-1,0,0}, dc[]={0,0,1,-1};


int main(){
    IOS
    
    int test; cin>>test;
    while(test--){
        string str; cin>>str;
        int s = str.size(), x = 0;
        
        bool yes = 1;
        while(s--){
            if(str[s] == ')') x++;
            else x--;
            
            if(x<0) yes = 0;
        }

        if(x != 0) yes = 0;
        
        if(yes) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
    
    
    return 0;
}

