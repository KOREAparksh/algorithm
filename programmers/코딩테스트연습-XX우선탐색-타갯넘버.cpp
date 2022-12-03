#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<int> q;
    q.push(numbers[0]);
    q.push(numbers[0] * -1);
    int index = 1;

    while(index< numbers.size()){
        int size = q.size();
        for(int i = 0 ; i < size; i++){
            int nowValue = q.front();
            q.pop();
            q.push(nowValue - numbers[index]);
            q.push(nowValue + numbers[index]);
        }
        index++;
    }
    
    while(!q.empty()){
        int nowValue = q.front();
        q.pop();
        if(nowValue == target){
            answer++;
        }
    }
    
    return answer;
}
