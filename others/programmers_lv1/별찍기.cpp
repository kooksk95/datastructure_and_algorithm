#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    while(b--){
        int t = a;
        while(t--){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}