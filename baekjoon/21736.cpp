#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[601][601] = {0};
int status[601][601] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int answer = 0;
    int y, x;
    int first_y, first_x;
    cin >> y >> x;

    for(int i = 0 ; i < y; i++){
        string str;
        cin >> str;
        for(int k = 0 ; k < str.size(); k++){
            map[i][k] = str[k];
            if (str[k] == 'I'){
                first_y = i;
                first_x = k;
            }
        }
    }
    map[first_y][first_x] = 'O';

    queue<pair<int, int> > q;
    q.push(make_pair(first_y, first_x));

    while(q.empty() == 0){
        pair<int, int> node = q.front();
        q.pop();

        cout << "nx : " << node.second << endl;
        cout << "ny : " << node.first << endl;
        cout << "map[ny][nx] : " << map[node.first][node.second] << endl;
        cout << endl;

        if (map[node.first][node.second] == 'P'){
            answer++;
        }

        for(int i = 0; i < 4; i++){
            int nx = node.second + dx[i];
            int ny = node.first + dy[i];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y){
                continue;
            }

            if (status[ny][nx] == 0 && map[ny][nx] != 'X'){
                status[ny][nx] = 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    if( answer == 0 ){
        cout << "TT" << endl;
    }
    else{
        cout << answer << endl;
    }
}

