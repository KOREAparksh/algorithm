#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define BLANK 0
#define BORDER 1
#define INNER 2

using namespace std;

int map[201][201];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    for(int recIndex = 0 ; recIndex < rectangle.size(); recIndex++ ){
        for(int y = rectangle[recIndex][1] * 2; y <= rectangle[recIndex][3] * 2; y++){
            for(int x = rectangle[recIndex][0] * 2; x <= rectangle[recIndex][2] * 2; x++){
                if (map[y][x] == INNER){
                    continue;
                }
                else if (y == rectangle[recIndex][1] * 2 || y == rectangle[recIndex][3] * 2){
                    map[y][x] = BORDER;
                }
                else if (x == rectangle[recIndex][0] * 2 || x == rectangle[recIndex][2] * 2){
                    map[y][x] = BORDER;
                }
                else{
                    map[y][x] = INNER;
                }
            }
        }
    }

    queue<pair<int,int> > q;
    q.push({characterX * 2, characterY * 2});

    while(!q.empty()){
        pair<int, int> node = q.front();
        if (node.first == itemX * 2 && node.second == itemY * 2){
            break;
        }
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            if (nx < 0 || nx >= 201 || ny < 0 || ny >= 201)
                continue;
            if (map[ny][nx] != BORDER)
                continue;
            map[ny][nx] = BLANK;
            q.push({nx, ny});
        }
        answer++;
    }


    return answer / 4;
}
