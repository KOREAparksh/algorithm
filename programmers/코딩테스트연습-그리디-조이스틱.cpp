#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int left = 0;
    int right = 0;
    int index = 0;
    int nameSize = name.size();
    
    //left
    while(index < nameSize){
        int leftIndex = index;
        int rightIndex;
        if (index == 0){
            rightIndex = 0;
        }
        else{
            rightIndex = nameSize - leftIndex;
        }
        
        
        //left
        if (name[leftIndex] == 'A'){}//nothing
        else if (name[leftIndex] < 'N'){
            left += name[leftIndex] - 'A';
        }
        else if ('N' < name[leftIndex]){
            left += 'Z' - name[leftIndex] + 1;
        }
        else{
            left += 13;
        }
        if (leftIndex + 1 != nameSize && name[leftIndex + 1] != 'A')
            left++;
        
        //right        
        if (name[rightIndex] == 'A'){}//nothing
        else if (name[rightIndex] < 'N'){
            right += name[rightIndex] - 'A';
        }
        else if ('N' < name[rightIndex]){
            right += 'Z' - name[rightIndex] + 1;
        }
        else{
            right += 13;
        }
        
        cout << "cahr : " << name[rightIndex] << "  count : " << right << endl;
        
        if (rightIndex - 1 != 0 && name[rightIndex - 1] != 'A')
            right++;
        index++;
    }
    return min(left, right);
}


// A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
// 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
// 0   -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9  -8. -7. -6  -5. -4. -3. -2  -1


// n = 5
// 0 1 2 3 4
// 0 4 3 2 1
