#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int mul = 1;
    int clothesSize = clothes.size();
    map<string, int> m;
    
    for(int i = 0; i < clothesSize; i++){
        if (m.find(clothes[i][1]) != m.end())
            m[clothes[i][1]] += 1;
        else
            m.insert({clothes[i][1], 2});
    }
    for(auto it = m.begin(); it != m.end(); it++){
        mul *= it->second;
    }
    return  mul - 1;
}
