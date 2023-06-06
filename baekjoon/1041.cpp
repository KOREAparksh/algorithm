#include <iostream>
#include <algorithm>

#define MAX_VALUE 50

using namespace std;


int arr[6];


int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unsigned long long N, answer = 0;
	int max = 0;
	cin >> N;
	
	for(int i = 0; i < 6; i++){
		cin >> arr[i];
	}
	
	if (N == 1){
		sort(arr, arr + 6);	
		for(int i = 0 ; i < 5; i++)
			answer += arr[i];
		cout << answer << endl;
		return 0;
	}
	
	int temp[3];
	temp[0] = min (arr[0], arr[5]);
	temp[1] = min (arr[1], arr[4]);
	int temp[2] = min (arr[2], arr[3]);
	
	sort(temp, temp + 3);
	int min1 = temp[0];
	int min2 = temp[1];
	int min3 = temp[2];
	
	
	//1개짜리
	answer += min1 * ((N - 2) * (N - 1) * 4 + (N - 2) * (N - 2)); 
	//2개
	answer += (min1 + min2) * ((N - 1) * 4  + (N - 2) * 4);
	//3개
	answer += (min1 + min2 + min3) * 4;
	
	cout << answer << endl;
}

