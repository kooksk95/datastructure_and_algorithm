#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land) {
    int r;
    for(r=1; r<land.size(); r++){
        land[r][0] += max(land[r-1][1], max(land[r-1][2],land[r-1][3]));
        land[r][1] += max(land[r-1][0], max(land[r-1][2],land[r-1][3]));
        land[r][2] += max(land[r-1][0], max(land[r-1][1],land[r-1][3]));
        land[r][3] += max(land[r-1][0], max(land[r-1][1],land[r-1][2]));
    }
    return max(max(land[r-1][0],land[r-1][1]), max(land[r-1][2],land[r-1][3]));
}