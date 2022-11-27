#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int arrSize = arr.size();
    
    for(int i = 0 ; i < arrSize ; i++){
        if (i == 0)
            answer.push_back(arr[i]);
        else if (*(answer.end() - 1) != arr[i])
            answer.push_back(arr[i]);
    }
    return answer;
}
