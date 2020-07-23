#include <string>
#include <vector>
#define MX 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> v(n, vector<int> (m,1));
    for(vector<int> x : puddles)
        v[x[1]-1][x[0]-1] = 0;
    
    for(int i=0; i<n; i++){
        if(i) {
            v[i][0] = v[i][0] ? v[i-1][0] : 0;
        
            for(int j=1; j<m; j++)
                v[i][j] = v[i][j] ? (v[i-1][j]+v[i][j-1])%MX : 0;
        } else
            for(int j=1; j<m; j++)
                v[0][j] = v[0][j] ? v[0][j-1] : 0;
    }
    
    return v[n-1][m-1];
}