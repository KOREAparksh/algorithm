#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int width = maps[0].size();
    int height = maps.size();
    
    queue<pair<int, int> > q;
    q.push({0,0});
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0 ; i < size; i++){
            pair<int, int> node = q.front();
            q.pop();

            if (node.first == width - 1 && node.second == height - 1)
                return answer + 1;
            maps[node.second][node.first] = 0;
            
            for(int d = 0; d < 4; d++){
                int nx = node.first + dx[d];
                int ny = node.second + dy[d];
                
                if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                    continue;
                if (maps[ny][nx] == 1)
                    q.push({nx, ny});
                maps[ny][nx] = 0;
            }
        }
        answer++;
    }
    
    return -1;
}
