#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> vec[201];
bool visit[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int nodeNumber = 1; nodeNumber <= n; nodeNumber++){
        if (visit[nodeNumber] == true){
            continue;
        }
        stack<int> stack;
        stack.push(nodeNumber);
        
        while(!stack.empty()){
            int linkedNumber = stack.top();
            stack.pop();
            visit[linkedNumber] = true;
            computers[linkedNumber - 1][linkedNumber - 1] = 0;
            
            for(int destination = 1; destination <= n; destination++){
                if (computers[linkedNumber - 1][destination - 1] == 0)
                    continue;

                if (linkedNumber == destination){
                    continue;
                }

                if (visit[destination] == true){
                    continue;
                }
                computers[linkedNumber - 1][destination - 1] = 0;
                computers[destination - 1][linkedNumber - 1] = 0;
                visit[destination] = true;
                stack.push(destination);
            }
        }
        answer++;
    }
    
    return answer;
}
