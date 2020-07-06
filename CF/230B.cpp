#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<ll> t_prime;
    bool not_prime[10001] = {};
    for(int i = 2; i <= 100000; i++){
        if(not_prime[i]) continue;
        
        t_prime.insert(i*i);
        for(int j = 2*i; j <= 10000; j+=i)
            not_prime[j] = 1;
    }

    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        
        if(t_prime.count(x)) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}