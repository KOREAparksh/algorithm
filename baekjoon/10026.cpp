#include <iostream>
#include <string>
#include <queue>

char map[100][100];
int status[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int k = 0 ; k < n; k++){
            map[i][k] = str[k];
        }
    }

    queue<pair<int, int> > q;
    int count_normal = 0;
    int count_rb = 0;
    for(int y = 0; y < n; y++){
        for(int x =0; x < n; x++){
            if (status[y][x] == 1){
                continue;
            }

            char checker = map[y][x];
            q.push(make_pair(x,  y));
            while(q.empty() == 0){
                pair<int, int> node = q.front();
                q.pop();

                if (status[node.second][node.first] == 1){
                    continue;
                }
                status[node.second][node.first] = 1;

                for(int i = 0; i < 4; i++){
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n){
                        continue;
                    }

                    if (map[ny][nx] == checker){
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            count_normal++;
        }
    }

    for(int y = 0; y < n; y++){
        for(int x =0; x < n; x++){
            if (map[y][x] == 'G'){
                map[y][x] = 'R';
            }

            if (status[y][x] == 0){
                continue;
            }

            char checker = map[y][x];
            q.push(make_pair(x,  y));
            while(q.empty() == 0){
                pair<int, int> node = q.front();
                q.pop();

                if (status[node.second][node.first] == 0){
                    continue;
                }
                status[node.second][node.first] = 0;

                for(int i = 0; i < 4; i++){
                    int nx = node.first + dx[i];
                    int ny = node.second + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n){
                        continue;
                    }

                    if (map[ny][nx] == 'G'){
                        map[ny][nx] = 'R';
                    }

                    if (map[ny][nx] == checker){
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            count_rb++;
        }
    }
    cout << count_normal << " " << count_rb << endl;
    
}
