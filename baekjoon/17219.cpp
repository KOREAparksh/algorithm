#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, string> map;

    int n, m;
    cin >> n >> m;

    string key;
    string value;
    vector<string> splitStr;
    while(n--){
        cin >> key >> value;
        map.insert(make_pair(key, value));
    }

    while(m--){
        cin >> key;
        cout << map[key] << "\n";
    }
}
