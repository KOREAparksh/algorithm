#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int map_y, map_x;
int map[500][500];
int visit[500][500]; // 0: not yet  1: visit

int dfs(int x, int y, int depth){

    if (x < 0 || x >= map_x || y < 0 || y >= map_y || visit[y][x] != 0){
        return 0;
    }

    if (depth >= 4){
        return map[y][x];
    }
    visit[y][x] = 1;

    int max = 0;
    int v1 = dfs(x - 1, y, depth + 1);
    int v2 = dfs(x + 1, y, depth + 1);
    int v3 = dfs(x, y - 1, depth + 1);
    int v4 = dfs(x, y + 1, depth + 1);
    max = (v1 > v2)? v1 : v2;
    max = (max > v3)? max : v3;
    max = (max > v4)? max : v4;

    visit[y][x] = 0;
    return max + map[y][x];
}

int fuckShape(){
    int max = 0;


    for(int y = 0; y < map_y; y++){
        for(int x = 0; x < map_x; x++){
            /*
            ㅏ
            */
            if (y < map_y - 2 && x < map_x - 1){
                    int num = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]; 
                max = (max > num)? max : num;
            }
            /*
            ㅓ
            */
            if (y < map_y - 2 && ( 0 < x && x < map_x - 1)){
                int num = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]; 
                max = (max > num)? max : num;
            }
            /*
            ㅗ
            */
            if (y < map_y - 1 && ( 0 < x && x < map_x - 1)){
                int num = map[y][x] + map[y + 1][x - 1] + map[y + 1][x] + map[y + 1][x + 1]; 
                max = (max > num)? max : num;
            }
            /*
            ㅜ
            */
            if (y < map_y - 1 &&  x < map_x - 2){
                int num = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]; 
                max = (max > num)? max : num;
            }
        }
    }
    return max;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    

    cin >> map_y >> map_x;

    for(int y = 0; y < map_y; y++){
        for(int x = 0; x < map_x; x++){
            int n;
            cin >> n;
            map[y][x] = n; 
        }
    }

    //normal    
    int max = 0;
    for(int y = 0; y < map_y; y++){
        for(int x = 0; x < map_x; x++){
            int value = dfs(x, y, 1);
            max = (max > value)? max : value;
        }
    }
    int fuckShapeCount = fuckShape();
    max = (max > fuckShapeCount)? max : fuckShapeCount;
    cout << max << endl;
}

