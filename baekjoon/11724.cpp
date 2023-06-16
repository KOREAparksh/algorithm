#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[1001];
vector<int>  arr[1001];
queue<int> q;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int vertex, edge;
    int count = 0;
    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++){
        int s, e;
        cin >> s >> e;
        arr[s].push_back(e);
        arr[e].push_back(s);
    }

    for(int i = 1; i <= vertex; i++){
        if (visit[i] == 1){
            continue;
        }

        q.push(i);
        while(q.empty() == 0){
            int node =  q.front();
            q.pop();
            
            if (visit[node] == 1){
                continue;
            }
            visit[node] = 1;

            for(int k = 0; k < arr[node].size(); k++){
                q.push(arr[node][k]);
            }
        }
        count++;
    }
    cout << count << endl;
}
