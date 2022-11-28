#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    int size = operations.size();
    
    for(int i = 0; i < size; i++){
        string command = operations[i];
        
        if (command[0] == 'I'){
            dq.push_back( stoi(command.substr(2)) );
        }
        else if (!dq.empty()){
            if (command[2] == '1'){
                dq.pop_front();
            }
            else{
                dq.pop_back();
            }
        }
        
        sort(dq.begin(), dq.end(), greater<int>());
    }
    
    if (dq.empty() || dq.size() < 2)
        return {0,0};
    return {dq[0], dq[dq.size() - 1]};
}
