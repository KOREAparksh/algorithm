#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int size = progresses.size();
    int time = 0;
    int i = 0;
    
    while(i < size){
        while(100 > progresses[i] + time * speeds[i]){
            time++;
        }
        int temp = 1;
        i++;
        while(i < size && 100 <= progresses[i] + time * speeds[i]){
            temp++;
            i++;
        }
        answer.push_back(temp);
    }
    
    
    return answer;
}
