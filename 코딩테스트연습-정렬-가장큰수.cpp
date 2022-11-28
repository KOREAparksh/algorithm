#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b){    
    int i1 = 0, i2 = 0;
	std::stringstream s1((a + b));
	std::stringstream s2((b + a));
	s1 >> i1;
	s2 >> i2;
    
    return i1 - i2 > 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    
    for(int i = 0; i < numbers.size(); i++){
        strs.push_back(to_string(numbers[i]));
    }
    sort(strs.begin(), strs.end(), comp);
    for(int i = 0; i < numbers.size(); i++){
        answer += strs[i];
    }
    while (answer.size() > 1 && answer[0] == '0'){
        answer = answer.substr(1);
    }
    return answer;
}
