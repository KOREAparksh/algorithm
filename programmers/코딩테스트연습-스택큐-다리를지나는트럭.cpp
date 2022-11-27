#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int second = 0;
    
    queue<int> q;
    int qWeight = 0;

    int nowWeight = 0;
    int index = 0;
    int size = truck_weights.size();
    
    for(int i = 0 ; i < bridge_length ; i++){
        q.push(0);
    }
    while(index < size || !q.empty()){
        qWeight -= q.front();
        q.pop();
        
        if (qWeight + truck_weights[index] <= weight && index < size && bridge_length){
            q.push(truck_weights[index]);
            qWeight += truck_weights[index];
            index++;
        }
        else if (index < size){
            q.push(0);
        }
        second++;
    }
    return second;
}
