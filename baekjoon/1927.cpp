#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<int> > q;

    int n;
    cin >> n;

    int num = 0;

    while(n--){
        cin >> num;

        if (num == 0){
            if (q.empty()){
                cout << 0 << "\n";
                continue;
            }
            cout << q.top() << "\n";
            q.pop();
            continue;
        }

        q.push(num);
    }

}
