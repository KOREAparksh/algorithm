#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    int n, cost, temp, count = 0;
    cin >> n >> cost;

    for(int i = 0 ;i < n ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    int index = v.size() - 1;
    while (cost > 0 && index >= 0){
        if (cost - v[index] < 0){
            index--;
        }
        else{
            cost -= v[index];
            count++;
        }
    }
    cout << count << endl;
}

