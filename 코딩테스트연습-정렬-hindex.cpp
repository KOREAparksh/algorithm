#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int middle = citations.size() / 2;
    int h = 0;
    int i = 0;
    
    sort(citations.begin(), citations.end());
    
    for(; i <= citations.size(); i++){
        if (i == citations.size()){
            h = citations[i - 1];
            break;
        }
        if (i != 0){
            if (!(citations[i] <= citations.size() - i)){
                h = citations[i];
                break;
            }
        }
        else if ( !(citations[i] <= citations.size())){
            h = citations[0];
            break;
        }
    }
    
    if (i == citations.size() && h <= citations.size() - i + 1)
        return h;
    
    while (h > citations.size() - i && h > 0){
        h--;
        if (h <= citations[i - 1]){
            i--;
        }
    }
    return h;
}
