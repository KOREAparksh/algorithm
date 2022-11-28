#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> width; // big
    vector<int> height;
    
    for(int i = 0 ; i < sizes.size(); i++){
        if (sizes[i][0] > sizes[i][1]){
            width.push_back(sizes[i][0]);
            height.push_back(sizes[i][1]);
        }
        else{
            width.push_back(sizes[i][1]);
            height.push_back(sizes[i][0]);
        }
    }
    
    return *max_element(width.begin(), width.end()) * *max_element(height.begin(), height.end());
}
