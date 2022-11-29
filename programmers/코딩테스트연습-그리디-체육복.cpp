#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    answer -= lost.size();
    
    for (auto lostIt = lost.begin(); lostIt != lost.end(); lostIt++){
        auto reserveIt = find(reserve.begin(), reserve.end(), *lostIt);
        if (reserveIt != reserve.end()){
            reserve.erase(reserveIt);
            lost.erase(lostIt--);
            answer++;
        }
    }
    
    while(!lost.empty() && !reserve.empty()){
        int lostNode = lost.back();
        lost.pop_back();
        
        while(!reserve.empty() && reserve.back() >= lostNode - 1){
            if (lostNode - 1 == reserve.back() || lostNode + 1 == reserve.back()){
                reserve.pop_back();
                answer++;
                break;
            }
            else if (reserve.back() > lostNode + 1){
                reserve.pop_back();
            }
        }
    }
    return answer;
}
