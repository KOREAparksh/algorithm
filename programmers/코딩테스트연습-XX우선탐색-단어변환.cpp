#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct s_node{
    string str;
    int count = 0;
    vector<string> history;
};
bool visit[50];

int solution(string begin, string target, vector<string> words) {
    int min = 0;
    int wordsSize = words.size();
    
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    stack<s_node> stack;
    vector<string> vec;
    s_node init;
    init.str = begin;
    init.count = 0;
    init.history = vec;
    stack.push(init);
    
    while(!stack.empty()){
        s_node node = stack.top();
        stack.pop();
        
        if (node.str == target){
            if (min == 0 || node.count < min){
                min = node.count;
            }
        }
        
        for(int i = 0; i < words.size(); i++){
            if (node.str == words[i]){
                continue;
            }
            if (find(node.history.begin(), node.history.end(), words[i]) != node.history.end())
                continue;
            
            //변형가능한 단어인지 확인'
            int wordSize = words[i].size();
            int sameCount = 0;
            for(int k = 0; k < wordSize; k++){
                if (node.str[k] == words[i][k]){
                    sameCount++;
                }
            }
            if (wordSize - 1 != sameCount)
                continue;
            
            vector<string> vec(node.history);
            s_node temp;
            temp.history = vec;
            temp.history.push_back(node.str);
            temp.count = node.count + 1;
            temp.str = words[i];
            stack.push(temp);
        }
    }
    
    return min;
}
