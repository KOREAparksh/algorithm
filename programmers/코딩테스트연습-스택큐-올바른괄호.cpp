#include<string>

using namespace std;

bool solution(string s)
{
    int stack = 0;
    int size = s.size();
    for(int i = 0 ; i < size; i++){
        if (stack == 0 && s[i] == ')')
            return false;
        if (s[i] == '(')
            stack++;
        else
            stack--;
    }
    return (stack == 0)? true : false;
}
