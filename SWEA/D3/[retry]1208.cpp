/*
    Flattern - 다른 높이로 쌓은 상자들을 dump번 옮겨서 최대한 flatten할 때, 최고점과 최저점의 높이 차이
*/


#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	//cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int dump; cin>>dump;
        int count[101] = {0};
        for(int i = 0; i < 100; i++) {
            int val; cin >> val;
            count[val]++;
        }
        
        int front[101] = {0}, back[101] = {0};
		for (int i = 1; i<=100; i++)
            front[i] = front[i-1] + count[i];
        back[100] = count[100];
        for (int i = 99; i>=1; i--)
            back[i] = count[i] + back[i+1];
        
        int f = 0, b = 100;
        while(front[f] == 0) f++;
        while(back[b] == 0) b--;
        
		while(dump) {
            if (f > b) break;
            
            if(front[f] == 0) {
                f++;
                continue;
            }
            if(back[b] == 0) {
                b--;
                continue;
            }
            
            front[f]--, back[b]--, dump--;
            
        }
        
        if(front[f] == 0) f++;
        if(back[b] == 0) b--;
        int ans = b-f;
        if (ans < 0) ans = 1;
        cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}