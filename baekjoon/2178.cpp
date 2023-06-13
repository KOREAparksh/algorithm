#include <iostream>
#include <string>
#include <queue>

int map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int map_y, map_x;
    cin >> map_y >> map_x;

    for(int y = 1; y <= map_y; y++){
        string str;
        cin >> str;
        for(int x = 1; x <= map_x; x++){
            map[y][x] = (str[x - 1] - '0');
        }
    }

    // for(int y = 1; y <= map_y; y++){
    //     for(int x = 1; x <= map_x; x++){
    //         cout << map[y][x] << " ";
    //     }
    //     cout << endl;
    // }

    int count = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    while(q.empty() == 0){
        int length = q.size();

        for(int i = 0 ; i < length; i++){
            pair<int, int> node = q.front();
            q.pop();

            if (node.first == map_x && node.second == map_y){
                cout << count + 1 << endl;
                return 0;
            }

            for(int k = 0; k < 4; k++){
                int nx = node.first + dx[k];
                int ny = node.second + dy[k];

                if (nx <= 0 || nx > map_x || ny <= 0 || ny > map_y){
                    continue;
                }

                if (map[ny][nx] == 1){
                    map[ny][nx] = 0;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        count++;
    }
    cout << count << endl;
}
