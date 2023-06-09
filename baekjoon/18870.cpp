// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <set>
// #include <unordered_map>
// using namespace std;

// int dp[50001];

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     vector<int> v;
//     unordered_map<int, int> m;
//     set<int> s;
//     int temp, n;
//     cin >> n;

//     for(int i = 0 ; i < n ; i++){
//         cin >> temp;
//         v.push_back(temp);
//         s.insert(temp);
//     }

//     int index = 0;
//     for(auto iter = s.begin(); iter != s.end(); iter++, index++){
//         m[*iter] = index;
//     }
    
//     for(auto iter = v.begin(); iter != v.end(); iter++){
//         cout << m[*iter]<< " ";
//     }
//     cout << endl;
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[50001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int temp, n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> cv(v);
    sort(cv.begin(), cv.end());
    cv.erase(unique(cv.begin(), cv.end()), cv.end());
    for(int i = 0; i < v.size(); i++){
        auto iter = lower_bound(cv.begin(), cv.end(), v[i]);
        cout << (iter - cv.begin()) << " ";
    }
    cout << endl;
}


