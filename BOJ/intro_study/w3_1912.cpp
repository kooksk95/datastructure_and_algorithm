#include <bits/stdc++.h>

using namespace std;
#define MIN -200000000
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define REP(i,a,b) for(auto i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ENT cout<<"\n";
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef long long ll;
typedef pair<int,int> pi;

// O(n) - Kadane's algorithm
int main(){
    IOS
    int n; cin>>n;
    vi arr(n);
    int ans = MIN, sum = 0;

    for(int& x : arr) {
        cin>>x;
        sum += x;
        ans = max(ans, sum);

        if(sum < 0) sum = 0;
    }

    cout << ans;

    return 0;
}


// // O(n^2) - Prefix sum
// int main(){
//     IOS
//     int n; cin>>n;
//     vi arr(n+1), prefix(n+1, 0);
    
//     REP(i, 1, n) {
//         cin>>arr[i];
//         prefix[i] = arr[i] + prefix[i-1];
//     }


//     int ans = MIN;
    
//     // Sum[i, j]
//     REP(i, 1, n)
//         REP(j, i, n)
//             ans = max(ans, prefix[j] - prefix[i-1]);

//     cout << ans;

//     return 0;
// }