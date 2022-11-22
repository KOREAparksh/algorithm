#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VALUE 50

using namespace std;

vector<int> crane;
int craneCount = 0;
vector<int> box;
int boxCount = 0;


int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> craneCount;
	for(int i = 0; i < craneCount; i++){
		int a;
		cin >> a;
		crane.push_back(a);
	}
	
	cin >> boxCount;
	for(int i = 0; i < boxCount; i++){
		int a;
		cin >> a;
		box.push_back(a);
	}
	sort(crane.begin(), crane.end(), greater<>());
	sort(box.begin(), box.end(), greater<>());
	
	int answer = 0;
	
	if (box[0] > crane[0]){
		cout << -1 << endl;
		return 0;
	}
	
	while(1){
		
		
		for(int craneIndex = 0; craneIndex < craneCount; craneIndex++){
			for(int boxIndex = 0; boxIndex < box.size(); boxIndex++){
				if(box[boxIndex] <= crane[craneIndex]){
					box.erase(box.begin() + boxIndex);
					break;
				}
			}
		}
		answer += 1;
		if ( box.empty()){
			cout << answer << endl;
			return 0;
		}
		
	}
}

