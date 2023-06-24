#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    int n, length;
    int count = 0;
    cin >> n >> length;
    cin >> str;

    for(int i = 0 ; i < length; i++){
        if (str[i] != 'I'){
            continue;
        }

        int k = 0;
        int index1 = i - 1, index2 = i;
        while(index2 <= length - 1){
            index1 += 2;
            index2 += 2;

            if (str[index1] != 'O' || str[index2] != 'I'){
                break;
            }

            k++;

            if (k == n){
                // cout << "i: " << i << "  index1: " << index1 << "  index2: " << index2 << endl;
                k--;
                count++;
            }
        }
        i = index1 - 1;
        // cout << "i: " << i << endl;
    }
    cout << count << endl;
}

