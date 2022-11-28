#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(int brown, int yellow) {
    deque<int> dq;
    for(int i = 1 ; i <= yellow; i++){
        int temp = yellow / i;
        if (temp * i == yellow)
            dq.push_back(i);
    }

    while(!dq.empty()){
        int x = dq.back(); dq.pop_back();
        int y;
        if (dq.empty())
            y = x;
        else
            y = dq.front(); dq.pop_front();
        
        if (x * 2 + y * 2 + 4 == brown)
            return {x + 2, y + 2};
    }
    
}
