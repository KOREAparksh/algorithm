#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> q;
    int n, temp;
    cin >> n;

    while(n--){
        cin >> temp;
        
        if (temp == 0){
            if (q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        q.push(temp);
    }
}

