#include <bits/stdc++.h>
using namespace std; 

int solution(vector<vector<int>> board) {
    int answer = 0, r_len = board.size(), c_len = board[0].size();

    int max = board[0][0];

    for(int i=1; i<r_len; i++) {
        for(int j=1; j<c_len; j++) {
            if(board[i][j]) {
                int m = min(board[i][j-1], min(board[i-1][j-1], board[i-1][j]));
                board[i][j] = m+1;
                if(max < board[i][j]) max = board[i][j];
            }
        }
    }

    answer = max*max;

    return answer;
}