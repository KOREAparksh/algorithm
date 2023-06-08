#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);
    v[1] = 1;
    v[2] = 3;
    for(int i = 3; i <= n; i++){
        v[i] = (v[i - 2] * 2 + v[i - 1]) % 10007;
    }
    cout << v[n] << endl;
}

