#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;



vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int size = prices.size();
    stack<int> s;
    
    for(int i = 0 ; i < size; i++){
        int count = 0;
        for(int k = i + 1; k < size; k++){
            count++;
            if (prices[i] > prices[k])
                break;
        }
        answer.push_back(count);
    }
    
    
    return answer;
}
