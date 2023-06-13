#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

deque<string> parsing(string str) {
    deque<string> deq;
    str.pop_back();
    str.erase(str.begin());

    istringstream iss(str);
    string buffer;
 
    deque<string> result;
    
    while (getline(iss, buffer, ',')) {
        result.push_back(buffer);
    }
    return result;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        string order, array;
        int length;
        int errorFlag = 0;
        int direct = 0; // 0: 순방향, 1: 역방향

        cin >> order;
        cin >> length;
        cin >> array;
        deque<string> deq =  parsing(array);

        for(auto iter = order.begin(); iter != order.end(); iter++){
            // R일 경우
            if (*iter == 'R'){
                direct = (direct == 0)? 1 : 0;
                continue;
            }

            // D일 경우
            if (deq.size() <= 0){
                errorFlag = 1;
                break;
            }
            if (direct == 0){
                deq.pop_front();
            }
            else {
                deq.pop_back();
            }
        }

        if (errorFlag == 1){
            cout << "error" << endl;
            continue;
        }

        string answer = "";
        if (direct == 0)
        {
            for(auto iter = deq.begin(); iter != deq.end(); iter++){
                answer += *iter;
                answer += ",";
            }
        }
        else{
            for(auto iter = deq.rbegin(); iter != deq.rend(); iter++){
                answer += *iter;
                answer += ",";
            }
        }
        if (answer.empty() == 0){
            answer.pop_back();
        }
        cout << "[" << answer << "]" << endl;
    }
}
