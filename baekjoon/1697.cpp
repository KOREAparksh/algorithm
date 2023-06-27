#include <iostream>
#include <queue>
#include <cmath>


using namespace std;

bool status[100001];


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int start, end;
    cin >> start >> end;

    int count = 0;
    queue<int> q;
    q.push(start);

    while(q.empty() == 0){
        int size = q.size();

        for(int i = 0; i < size; i++){
            int node = q.front();
            q.pop();

            if (node == end){
                cout << count << endl;
                return 0;
            }
            
            if (node * 2 < 100001 && status[node * 2] == false){
                status[node * 2] = true;
                q.push(node * 2);
            }
            if (node - 1 >= 0 && status[node - 1] == false){
                status[node - 1] = true;
                q.push(node - 1);
            }
            if (node + 1 < 100001 && status[node + 1] == false){
                status[node + 1] = true;
                q.push(node + 1);
            }
        }
        count++;
    }
}

