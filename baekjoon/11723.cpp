#include <iostream>

using namespace std;

int bit = 0;

int check(int x){
    return (((bit & (1 << x)) == 0)? 0 : 1);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0 ; i < n; i++){
        string str;
        int x;
        cin >> str;

        if(str == "add"){
            cin >> x;
            bit |= (1 << x);
        }
        else if(str == "remove"){
            cin >> x;
            bit &= ~(1 << x);
        }
        else if(str == "check"){
            cin >> x;
            cout << check(x) << "\n";
        }
        else if (str == "toggle"){
            cin >> x;
            bit ^= (1 << x);
        }
        else if (str == "all"){
            bit = 0b111111111111111111111;
        }
        else if (str == "empty"){
            bit = 0;
        }
    }
}
