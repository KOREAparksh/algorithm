#include <string>
#include <stack>
#include <algorithm>
#include <cstring>

#include <iostream>

using namespace std;

struct s_node{
    int index;
    int left;
    int right;
    int weight;
};

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

int dp[10][10][2][10];

stack<s_node> s;
int maxValue = -1;
int maxIndex = 0;

void re(string str, int i, int left, int right, int w){
//     if (i == maxIndex){
//         if (maxValue == -1 || maxValue > w)
//             maxValue = w;
//         return ;
//     }
//     else if (maxValue != -1 && maxValue <= w)
//         return ;

//     int target = str[i] - '0';
//     if (target == left){
//         re(str, i + 1, target, right, w + arr[left][target]);
//     }
//     else if (target == right){
//         re(str, i + 1, left, target, w + arr[right][target]);
//     }
//     else{
//         re(str, i + 1, target, right, w + arr[left][target]);
//         re(str, i + 1, left, target, w + arr[right][target]);
//     }

//     s_node init;
//     init.index = 0;
//     init.left = 4;
//     init.right = 6;
//     init.weight = 0;
//     s.push(init);
//     while(!s.empty()){
//         s_node node = s.top();
//         s.pop();


//         if (node.index == maxIndex){
//             if (maxValue == -1 || node.weight < maxValue)
//                 maxValue = node.weight;
//             continue;
//         }
//         else if (maxValue != -1 && node.weight >= maxValue)
//             continue;

//         int target = str[node.index] - '0';
//         if (target == node.left || target == node.right){
//             s_node newNode = node;
//             newNode.index += 1;
//             newNode.weight += 1;
//             s.push(newNode);
//         }
//         else{
//             s_node leftNode = node;
//             leftNode.weight += arr[node.left][target];
//             leftNode.left = target;
//             leftNode.index += 1;
//             s.push(leftNode);

//             s_node rightNode = node;
//             rightNode.weight += arr[node.right][target];
//             rightNode.right = target;
//             rightNode.index += 1;
//             s.push(rightNode);
//         }
//     }



}

int solution(string numbers) {
    int left = 4, right = 6;
    maxIndex = numbers.length();
    memset(dp, 0, sizeof(dp));

    re(numbers, 0, left, right, 0);


    return maxValue;
}
