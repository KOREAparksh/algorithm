#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<int> status(101, 0);
vector<int> link[101];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int cumputerCount, n;
    cin >> cumputerCount >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        link[x].push_back(y);
        link[y].push_back(x);
    }

    /////////

    queue<int> q;
    int count = 0;
    q.push(1);

    while(q.empty() == 0){
        int now = q.front();
        q.pop();
        if (status[now] == 1){
            continue;
        }
        status[now] = 1;
        count++;

        for(auto iter = link[now].begin(); iter != link[now].end(); iter++){
            if (status[*iter] == 0){
                q.push(*iter);
            }
        }
    }
    cout << count - 1<< "\n";
}

