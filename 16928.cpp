#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node{
	int now = 1;
	int count = 0;
} t_node;

int movePort[101];
bool visit[101];
queue<t_node> que;


void bfs(){
	t_node init;
	init.now = 1;
	init.count = 0;
	que.push(init);
	
	while(!que.empty()){
		
		t_node init = que.front();
		que.pop();
		
		for(int i = 1; i <= 6; i++){
			int drive = init.now + i;
			
			if (drive > 100)
				break;
			if (visit[drive] == true)
				continue;
			visit[drive] = true;
			
			//100 도착
			if (drive == 100){
				cout << init.count + 1 << endl;
				return;
			}
			else if (movePort[drive] != 0){
				drive = movePort[drive];
			}
			
		
			t_node newNode;
			newNode.now = drive;
			newNode.count = init.count + 1;
			que.push(newNode);
			
		}
	}
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int ladderCount, snakeCount;
	cin >> ladderCount >> snakeCount;
	
	for(int i = 0; i < 101; i++){
		movePort[i] = 0;
		visit[i] = false;
	}
	
	for(int i = 0; i < ladderCount; i++){
		int s, e;
		cin >> s >> e;
		movePort[s] = e;
	}
	
	for(int i = 0; i < snakeCount; i++){
		int s, e;
		cin >> s >> e;
		movePort[s] = e;
	}
	bfs();
}

