/*
	사칙연산 유효성 검사
*/
#include<bits/stdc++.h>
using namespace std;

struct node{char val; int left,right;};
node tree[201];
char op[] = {'+', '-', '*', '/'};
int n;

bool post_order(int v){


	node curr = tree[v];
	if(curr.left>0 && curr.right>0
		&& find(op, op+4, curr.val)!=(op+4))
		return post_order(curr.left) & post_order(curr.right);
	if(curr.left<0 && curr.right<0
		&& find(op, op+4, curr.val)==(op+4))
		return true;

	return false;
}


int main(int argc, char** argv)
{
	int test_case;
	int T = 10, p, l, r;
	char val;
	string s;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		getline(cin, s);
		while(n--){
			l = r = -1;
			getline(cin, s);
			stringstream ss(s);

			ss >>p>>val>>l>>r;
			tree[p] = {val, l, r};
		}


        cout << "#"<<test_case<<" "<<post_order(1)<< "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}