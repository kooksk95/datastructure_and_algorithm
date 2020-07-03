#include <bits/stdc++.h>

using namespace std;
vector<string> users, banned;
int banned_num, user_num;
vector<vector<int>> possible_id;
set<string> answers;


vector<int> possible(int n){
    vector<int> ret;
    int t = user_num;
    string compare = banned[n];

    while(t--){
        string candidate = users[t];

        if(compare.size() == candidate.size()){
            bool is_same = 1;
            int s = compare.size();
            while(s--){
                is_same = compare[s]=='*' || compare[s]==candidate[s];
                if(!is_same) break;
            }

            if(is_same) ret.push_back(t);
        }
    }

    return ret;
}

int solve(vector<int> crnt_sit, int stage){
    if(stage == banned_num) {
        string target;
        for(int x : crnt_sit)
            target.push_back('0'+x);

        if(answers.count(target)) return 0;
        answers.insert(target);
        return 1;
    }

    int ret = 0;
    vector<int> vec = possible_id[stage];
    for(int i = 0; i<vec.size(); i++){
        int ban = vec[i];
        if(!crnt_sit[ban]){
            crnt_sit[ban]++;
            ret += solve(crnt_sit, stage+1);
            crnt_sit[ban]--;
        }
    }
    return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    users = user_id;
    banned = banned_id;
    banned_num = banned_id.size();
    user_num = user_id.size();

    for(int i=0; i<banned_num; i++)
        possible_id.push_back(possible(i));

    vector<int> crnt_sit(user_num);
    return solve(crnt_sit, 0);
}