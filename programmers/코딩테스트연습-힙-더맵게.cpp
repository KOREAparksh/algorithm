#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;


int solution(vector<int> scoville, int K) {
    int count = 0;
    int size = scoville.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < size; i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K){
        if (pq.size() <= 1)
            return -1;
        
        int min = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        
        pq.push(min + min2 * 2);
        count++;
    }
    return count;
}
