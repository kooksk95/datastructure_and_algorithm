/*
    String - 문장 내 패턴 횟수
*/

#include<bits/stdc++.h>

using namespace std;

int naive(string origin, string target){
    int count = 0;
    int ogn_size = origin.size(), tgt_size = target.size();
    for(int i = 0; i < ogn_size - tgt_size+1; i++) {
        bool is_same = 1;
        for(int j = 0; j < tgt_size; j++) {
            if(origin[i+j] != target[j]) {
                is_same = 0;
                break;
            }
        }
        count += is_same ? 1 : 0;
    }
    return count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int vv; cin >> vv;

		string str1, str2;
        cin >> str1 >>str2;
        cout << "#" << test_case << " " << naive(str2, str1) << "\n";

	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}