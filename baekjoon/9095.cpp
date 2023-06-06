#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec(12);
    int n;
    cin >> n;

    vec[1] = 1;
    vec[2] = 2;
    vec[3] = 4;
    for(int i = 4 ; i < 12 ; i++){
        vec[i] = vec[i - 3] + vec[i - 2] + vec[i - 1];
    }

    int num;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        cout << vec[num] << endl;
    }
}

