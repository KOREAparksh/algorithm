#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100][100];

void dfs(){

}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            int temp;
            cin >> temp;
            arr[y][x] = temp;
        }
    }

    for(int y = 0; y < n; y++){
        queue<int> q;
        vector<int> visit(n, 0);

        q.push(y);
        while(q.empty() == 0){
            int node =  q.front();
            q.pop();
            
            if (visit[node] == 1){
                continue;
            }
            visit[node] = 1;

            for(int x = 0; x < n; x++){
                if (arr[node][x] == 1){
                    arr[y][x] = 1;
                    q.push(x);
                }
            }
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cout << arr[y][x] << " ";
        }
        cout << "\n";
    }
}
