/*
	단순 2진 암호코드를 검증하라
*/
#include<bits/stdc++.h>
using namespace std;
#define ENT cout<<"\n";
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define MX
#define REP(i,a,b) for(auto i=a; i<b; i++)
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, m, ans;
string str;
unordered_map<string,int> mymap = { {"0001101", 0}
								, {"0011001", 1}
								, {"0010011", 2}
								, {"0111101", 3}
								, {"0100011", 4}
								, {"0110001", 5}
								, {"0101111", 6}
								, {"0111011", 7}
								, {"0110111", 8}
								, {"0001011", 9} };


int decryp(bool code[], int first_bit) {
	string tmp;
	first_bit -= 6;
	REP(i, 0, 7){
		tmp += code[first_bit+i] ? '1' : '0';
	}

	return mymap[tmp];
}

void verify(){
	// string parsing
	bool code[m];
	int first_bit = 0;
	REP(i,0,m){
		code[i]= str[i]=='1';
		if(code[i]) first_bit = i;
	}

	// verify and updated answer
	int verify_num = decryp(code, first_bit);
	first_bit -= 7;

	int even = 0, odd = 0;
	REP(i, 0, 7){
		if(i%2) even += decryp(code, first_bit);
		else odd += decryp(code, first_bit);

		first_bit -=7;
	}

	ans = ((odd*3+even+verify_num) % 10) ?
			0 : odd+even+verify_num;

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n>>m;
		ans = -1;
		int tmp;
		REP(i,0,n){
			cin >> str;
			stringstream ss(str);
			ss >> tmp;

			if(tmp == 0 || ans != -1) continue;

			verify();
		}

		cout << "#" << test_case << " " << ans; ENT
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}