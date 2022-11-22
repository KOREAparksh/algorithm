#include <iostream>
#include <queue>

using namespace std;

struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b){
		if(a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	};
};

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> q;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		q.push({s, e});
	}
	
	int end = 0;
	int count = 0;
	while(!q.empty()){
		int s = q.top().first;
		int e = q.top().second;
		q.pop();
		
		if (end <= s){
			count++;
			end = e;
		}
	}
	cout << count <<endl;
}

