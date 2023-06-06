#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

struct compare2{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int max;
	int n;
	priority_queue<pair<int, int>, vector<pair<int, int> > , compare> q;
	priority_queue<int, vector<int> , compare2> room;
	cin >> n;
	
	for(int i = 0 ; i < n; i++){
		int s, e;
		cin >> s >> e;
		q.push({s, e});
	}
	
	room.push(q.top().second);
	q.pop();
	while(!q.empty()){
		if (room.top() <= q.top().first){
			room.pop();
		}
		room.push(q.top().second);
		q.pop();
	}
	
	cout << room.size()  << endl;

}

