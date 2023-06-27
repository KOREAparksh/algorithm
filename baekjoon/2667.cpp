#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    for(int y = 0; y < n; y++){
        string temp;
        cin >> temp;
        for(int x = 0; x < n; x++){
            map[y][x] = temp[x] - '0';
        }
    }


    vector<int> answer;
    queue<pair<int, int> > q;

    for(int search_y = 0; search_y < n; search_y++){
        for(int search_x = 0; search_x < n; search_x++){

            if (map[search_y][search_x] != 1){
                continue;
            }

            int count = 0;
            q.push(make_pair(search_x, search_y));

            while(q.empty() == 0){
                pair<int, int> node = q.front();
                q.pop();

                if (map[node.second][node.first] == 0){
                    continue;
                }
                map[node.second][node.first] = 0;
                count++;

                for(int i = 0; i < 4; i++){
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n){
                        continue;
                    }
                    if (map[ny][nx] == 0){
                        continue;
                    }
                    q.push(make_pair(nx, ny));
                }
            }

            answer.push_back(count);
        }
    }
    
    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << *it << "\n";
    }
}

