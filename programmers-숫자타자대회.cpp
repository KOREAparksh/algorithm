#include <string>
#include <algorithm>

#include <iostream>

using namespace std;

int arr[10][10] = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},//0
    {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},//1
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},//2
    {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},//3
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},//4
    {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},//5
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},//6
    {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},//7
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},//8
    {3, 6, 5, 4, 5, 3, 2, 4, 2, 1},//9
};

int maxValue = 0;
int maxIndex = 0;

void re(string str, int i, int left, int right, int w){
    // if (i == maxIndex){
    //     if (maxValue == -1 || maxValue > w)
    //         maxValue = w;
    //     return ;
    // }

    // int target = str[i] - '0';
    // if (target == left){
    //     re(str, i + 1, target, right, w + arr[left][target]);
    // }
    // else if (target == right){
    //     re(str, i + 1, left, target, w + arr[right][target]);
    // }
    // else{
    //     re(str, i + 1, target, right, w + arr[left][target]);
    //     re(str, i + 1, left, target, w + arr[right][target]);
    // }
     cout << "len : " << str.length() << endl;
    int size = str.length();
    bool isOK = true;
    for(int i = 0 ; i <= size; i++){
        int target = str[i] - '0';
        int fromLeft = arr[left][target];
        int fromRight = arr[right][target];

        if (i == size)
            break;

        if (target == left || target == right){
            maxValue += 1;
            continue;
        }

        else if (isOK &&  fromLeft == fromRight){
            int k = 1;
            while(1){
                if (i == size){
                    isOK = false;
                    break;
                }
                int newtarget = str[i + k] - '0';
                int newLeft = arr[left][newtarget];
                int newRight = arr[right][newtarget];
                if (newLeft == newRight){
                    k++;
                    continue;
                }
                else if (newLeft < newRight)
                    fromLeft +=1;
                else if (newLeft > newRight)
                    fromRight +=1;
                break;
            }
        }

        if (fromLeft < fromRight){
            left = target;
            maxValue += fromLeft;
        }
        else{
            right = target;
            maxValue += fromRight;
        }
    }
}

int solution(string numbers) {
    int left = 4, right = 6;
    maxIndex = numbers.length();

    re(numbers, 0, left, right, 0);


    return maxValue;
}
