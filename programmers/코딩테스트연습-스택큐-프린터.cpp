#include <string>
#include <queue>
#include <vector>
using namespace std;

struct s_node{
    int index;
    int value;
};


int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();
    priority_queue<int> pq;
    queue<s_node> q;
    
    for(int i = 0 ; i < size; i++){\
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(1){
        s_node front = q.front();
        q.pop();
        
        if (front.value == pq.top()){
            answer++;
            pq.pop();
            if (front.index == location)
                break;
        }
        else{
            q.push(front);
        }
    }
    
    return answer;
}
