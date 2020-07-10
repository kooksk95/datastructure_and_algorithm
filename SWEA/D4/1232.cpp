/*
	사칙연산 - 실수로 계산하되 최종 결과는 정수로 출력
*/
#include<bits/stdc++.h>
using namespace std;

struct node { string val; int l,r; };
node tree[1001];

char op[] = {'+','-','*','/'};

float post_order(int n){
	node curr = tree[n];
	char c = curr.val[0];
	if(find(op, op+4, c) == op+4) return stoi(curr.val);

	float n1 = post_order(curr.l);
	float n2 = post_order(curr.r);
	
	float ret = -1;
	switch(c){
		case '+':
			ret = n1+n2;
			break;
		case '-':
			ret = n1-n2;
			break;
		case '*':
			ret = n1*n2;
			break;
		case '/':
			ret = n1/n2;
			break;
	}
	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T = 10, n, p, l, r;
	string val, s;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		getline(cin, s);
		while(n--){
			l = r = -1;
			getline(cin, s);
			stringstream ss(s);

			ss >>p>>val>>l>>r;
			tree[p] = {val,l, r};
		}

		int ans = post_order(1);
        cout << "#"<<test_case<<" "<< ans << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}