#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end());
    int vectorSize = phone_book.size();
    
    
    for(int i = 0; i < vectorSize - 1; i++){
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())){
            return false;
        }
    }
    return true;
}
