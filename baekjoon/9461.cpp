#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<long long> v(101, 0);
    long long count, n;

    cin >> count ;

    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    v[4] = 2;
    for(int i = 5 ; i < 101; i++){
        v[i] = v[i - 2] + v[i - 3];
    }

    for(int i = 0; i < count; i++){
        cin >> n;
        cout << v[n] << endl;
    }

    
}
