
/*
    트럭 여러 대가 1차선 다리를 정해진 순으로 건널 때 모든 트럭이 다리를 건너는 최단시간을 구하시오.
    트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 weight까지 견딥니다.
    예를 들어, 다리길이가 2이고 10kg까지 견디며, 무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너는데 8초가 걸립니다.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0, s = truck_weights.size();
    int next_truck = 0, front_truck = 0;
    vector<int> times(s, 0);
    while(front_truck < s){
        
        if(times[front_truck] == bridge_length){
            sum -= truck_weights[front_truck++];
        }
        
        if(next_truck<s && sum+truck_weights[next_truck]<=weight){
            sum += truck_weights[next_truck++];
        }
        
        for(int i = front_truck; i<next_truck; i++){
            times[i]++;
        }
        
        answer++;

    }
    return answer;
}