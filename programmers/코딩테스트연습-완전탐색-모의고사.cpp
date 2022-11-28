#include <string>
#include <vector>
#include <algorithm>

int sp1[5] = {1, 2, 3, 4 ,5};
int sp1Size = 5;
int sp2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int sp2Size = 8;
int sp3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int sp3Size = 10;

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    
    int sp1Count = 0;
    int sp2Count = 0;
    int sp3Count = 0;
    
    for(int i = 0 ; i < answers.size(); i++){
        int answer = answers[i];
        
        if (sp1[i % sp1Size] == answer){
            sp1Count++;
        }
        if (sp2[i % sp2Size] == answer){
            sp2Count++;
        }
        if (sp3[i % sp3Size] == answer){
            sp3Count++;
        }
    }
    
    int m = max({sp1Count, sp2Count, sp3Count});
    if (m == sp1Count)
        result.push_back(1);
    if (m == sp2Count)
        result.push_back(2);
    if (m == sp3Count)
        result.push_back(3);
    
    return result;
}
