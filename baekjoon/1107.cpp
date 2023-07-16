#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define INIT_NUM 100

using namespace std;

bool err[10];

int hasErrorNum(string str){
    for(int i = 0; i < str.size(); i++){
        int num = str[i] - '0';
        if (err[num] == true){
            return str.size() - i - 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int answer = 0;
    string target;
    int errCount;

    for(int i = 0 ; i < 10; i++){
        err[i] = false;
    }
    cin >> target;
    cin >> errCount;
    for(int i = 0 ; i < errCount; i++){
        int temp;
        cin >> temp;
        err[temp] = true;
    }

    if (target == "100"){
        cout << 0 << endl;
    }

    //only press +, -
    answer = abs(stoi(target) - INIT_NUM);

    //press num buttons - under
    int tempUnder = stoi(target);
    while(true){
        int result = hasErrorNum(to_string(tempUnder));
        if (result == -1){
            break;
        }
        if (tempUnder == 0){
            break;
        }
        tempUnder--;
    }
    int tempUnderSize = to_string(tempUnder).size();
    answer = min(answer, abs(stoi(target) - tempUnder) + tempUnderSize );

    // cout << "answer: " << answer << endl;
    // cout << "stoi(target): " << stoi(target) << endl;
    // cout << "tempUnder " << tempUnder << endl;
    // cout << "tempUnderSize: " << tempUnderSize << endl;
    // cout << "abs(stoi(target) - tempUnder): " <<abs(stoi(target) - tempUnder)<< endl;
    // cout << "abs(stoi(target) - tempUnder) + tempUnderSize: " <<abs(stoi(target) - tempUnder) + tempUnderSize<< endl;


    //press num buttons - over
    int tempOver = stoi(target);
    while(hasErrorNum(to_string(tempOver)) == true){
        if (tempOver == 0){
            break;
        }
        tempOver++;
    }
    int tempOverSize = to_string(tempOver).size();
    answer = min(answer, abs(stoi(target) - tempOver) + tempOverSize );


    // cout << "answer: " << answer << endl;
    // cout << "stoi(target): " << stoi(target) << endl;
    // cout << "tempOver " << tempOver << endl;
    // cout << "tempOverSize: " << tempOverSize << endl;
    // cout << "abs(stoi(target) - tempOver): " <<abs(stoi(target) - tempOver)<< endl;
    // cout << "abs(stoi(target) - tempOver) + tempOverSize: " <<abs(stoi(target) - tempOver) + tempOverSize<< endl;


    cout << answer << endl;

}

