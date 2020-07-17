#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> s;
    for(int i=0; i<skill.size(); i++)
        s.insert(skill[i]);

    for(int i=0; i<skill_trees.size(); i++){
        int pos = 0;
        answer++;
        for(int k = 0; k<skill_trees[i].size(); k++){
            if(s.count(skill_trees[i][k]) == 0) continue;
            
            if(skill[pos] == skill_trees[i][k])
                pos++;
            else {
                answer--;
                break;
            }
        }
        
    }
    return answer;
}