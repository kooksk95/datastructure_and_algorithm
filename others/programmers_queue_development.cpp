/*
    기능개발 - 작업의 진도와 개발 속도가 적힌 정수 배열이 주어질 때 각 배포마다 몇 개의 기능이 배포되는지를 return하세요.
              배포는 하루에 한 번만 할 수 있으며, 선행 작업이 배포돼야 후행작업이 배포될 수 있습니다. (동시 배포는 가능)
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int release_day = 0, complete_day;
    for(int i = 0; i<progresses.size(); i++){
    	complete_day = (99-progresses[i])/speeds[i]+1;
        
    	if(release_day >= complete_day)
    		++answer.back();
    	else{
    		answer.push_back(1);
    		release_day = complete_day;
    	}
        
    }

    return answer;
}