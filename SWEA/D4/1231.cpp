/*
    중위순회 - 트리를 중위순회로 출력
*/

#include<bits/stdc++.h>
using namespace std;

struct node{ char val; int left, right; };

int n;
node tree[101];

void in_order(int v){
    node curr = tree[v];
    
    if(curr.left > 0) in_order(curr.left);
    cout << curr.val;
    if(curr.right > 0) in_order(curr.right);
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10, p, l, r;
    char c;
    string s;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
        getline(cin,s);
		while(n--){
            l = r = -1;
            getline(cin,s);
            stringstream ss(s);

            ss >>p>>c>>l>>r;
            tree[p] = {c, l, r};
            // cout << s << " ==> ";
            // cout << p << ": " << c << "," << l << "," << r << "\n";
        }
        
        cout << "#"<<test_case<<" ";
        in_order(1);
        cout << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}