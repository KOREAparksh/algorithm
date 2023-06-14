#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int map_y, map_x;
int map[500][500];
int visit[500][500]; // 0: not yet  1: visit

int dfs(int x, int y, int depth, int visit[][500]){
    if (x < 0 || x >= map_x || y < 0 || y >= map_y || visit[y][x] != 0){
        return 0;
    }
    if (depth >= 4){
        return map[y][x];
    }
    visit[y][x] = 1;

    int max = 0;
    int v1 = dfs(x - 1, y, depth + 1, visit);
    int v2 = dfs(x + 1, y, depth + 1, visit);
    int v3 = dfs(x, y - 1, depth + 1, visit);
    int v4 = dfs(x, y + 1, depth + 1, visit);
    max = (v1 > v2)? v1 : v2;
    max = (max > v3)? max : v3;
    max = (max > v4)? max : v4;
    return max + map[y][x];
}

int fuckShape(){
    int max = 0;

    /*
    ㅏ
    */
    for(int y = 0; y < map_y - 3; y++){
        for(int x = 0; x < map_x - 1; x++){
            int num = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]; 
            max = (max > num)? max : num;
        }
    }
    /*
    ㅓ
    */
    for(int y = 0; y < map_y - 3; y++){
        for(int x = 1; x < map_x; x++){
            int num = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]; 
            max = (max > num)? max : num;
        }
    }
    /*
    ㅗ
    */
    for(int y = 0; y < map_y - 1; y++){
        for(int x = 1; x < map_x - 1; x++){
            int num = map[y][x] + map[y + 1][x - 1] + map[y + 1][x] + map[y + 1][x + 1]; 
            max = (max > num)? max : num;
        }
    }
    /*
    ㅜ
    */
    for(int y = 0; y < map_y - 1; y++){
        for(int x = 0; x < map_x - 2; x++){
            int num = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]; 
            max = (max > num)? max : num;
        }
    }
    return max;
}

void init(){
    for(int y = 0; y < map_y; y++){
        for(int x = 0; x < map_x; x++){
            visit[y][x] = 0;
        }
    }
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
            int visit[500][500]= {0}; // 0: not yet  1: visit
            // init();
            int value = dfs(x, y, 1, visit);
            max = (max > value)? max : value;
            // cout << "x: " << x << "  y: " << y << "  value: " << value << endl;
        }
    }
    int fuckShapeCount = fuckShape();
    max = (max > fuckShapeCount)? max : fuckShapeCount;
    cout << max << endl;
}

