#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    vector<string> m1;
    m1.push_back("");
    unordered_map<string, int> m2;
    int inputCount, findCount;
    cin >> inputCount >> findCount;

    string temp;
    for(int i = 0; i < inputCount; i++){
        cin >> temp;
        m1.push_back(temp);
        m2.insert(make_pair(temp, i + 1));
    }

    for(int i = 0; i < findCount; i++){
        cin >> temp;
        
        if (isdigit(temp[0]) == 0){
            cout << m2[temp] << "\n";
        }
        else{
            cout << m1[stoi(temp)] << "\n";
        }
    }
}

