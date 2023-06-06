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

    int n, m;
    cin >> n >> m;

    vector<string> answer;
    unordered_map<string, int> map;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        map.insert(make_pair(temp, i));
    }

    for(int i = 0 ; i < m; i++){
        cin >> temp;

        if (map.find(temp) != map.end()){
            answer.push_back(temp);
        }
    }
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
}

