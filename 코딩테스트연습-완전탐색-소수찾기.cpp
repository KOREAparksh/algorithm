#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

int arr[10000000] = {0,};

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int maxValue = 0;
    
    sort(numbers.begin(), numbers.end(), greater<char>());
    
    stringstream ss(numbers);
    ss >> maxValue;
    
    for(int i = 2; i <= maxValue; i++){
        if (arr[i] != 0) continue;
        for(int k = 1; k * i <= maxValue; k++){
            arr[k * i] = 1;
        }
        
        string str = to_string(i);
        for(int k = 0 ; k < numbers.size(); k++){
            auto it = std::find(str.begin(), str.end(), numbers[k]);
            if (it != str.end())
                str.erase(it);
        }
        if (str.empty())
            answer++;
    }
    
    return answer;
}
