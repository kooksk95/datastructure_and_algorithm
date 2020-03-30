#include <iostream>

using namespace std;

int main(){
    cout << 100 << "\n";
    for(int i = 0; i<99; i++){
        for(int j = 0; j<100; j++){
            if(i == j || j == 99) cout << "0 ";
            else cout << "100 ";
        }
        cout << "\n";
    }
    for(int j=0; j<100;j++) cout << "0 ";
    return 0;
}