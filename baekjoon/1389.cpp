#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

set<int> edge[101];
int answer[101];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int peopleCount, m;
    cin >> peopleCount >> m;

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;

        edge[s].insert(e);
        edge[e].insert(s);
    }

    for(int i = 1; i <= peopleCount; i++){
        int state[peopleCount + 1];

        memset(state, 0, sizeof(state));

        int count = 0;
        queue<int> q;
        q.push(i);
        
        while(q.empty() == 0) {
            int length = q.size();

            while(length--){
                int node = q.front();
                q.pop();

                if (state[node] != 0){
                    continue;
                }
                state[node] = 1;
                answer[node] += count;


                for(auto iter = edge[node].begin(); iter != edge[node].end(); iter++){
                    if (state[*iter] != 0){
                        continue;
                    }

                    q.push(*iter);
                }
            }

            count++;
        }
    }

    int min = 2147483647;
    int index = 0;
    for (int i = 1; i <= peopleCount; i++){
        if (min > answer[i]){
            index = i;
            min = answer[i];
        }
    }
    cout << index << endl;

}
