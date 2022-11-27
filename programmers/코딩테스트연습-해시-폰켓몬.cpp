#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int numsSize = nums.size();
    set<int> s;
    for(auto it = nums.begin(); it != nums.end(); it++){
        s.insert(*it);
    }
    if (s.size() > numsSize / 2)
        return numsSize / 2;
    else
        return s.size();
}
