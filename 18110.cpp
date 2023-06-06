#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<int> vec;
    int n;
    int count = 0;
    cin >> n;

    if(n == 0){
        cout << 0 << endl;
        return 0;
    }

    int except = (int) round(n * 0.15);

    for(int i = 0 ; i < n ; i++){
        int temp ;
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    for(int i = except ; i < vec.size() - except; i ++){
        count += vec[i];
    }

    cout <<  round((double)count / (double)(vec.size() - (except * 2))) << endl;

}

