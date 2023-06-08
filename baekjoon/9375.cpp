#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<string, vector<string> > map;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int count, answer = 1;
        cin >> count;
        map.clear();
        for(int k = 0; k < count; k++){
            string name, category;
            cin >> name >> category;
            map[category].push_back(name);
        }
        unordered_map<string, vector<string> >::iterator iter;
        for(iter = map.begin() ; iter != map.end(); iter++){
            vector<string> temp = iter->second;
            

            answer *= (temp.size() + 1);
        }
        cout << answer - 1 << endl;
    }
}

