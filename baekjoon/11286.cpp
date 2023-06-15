#include <iostream>
#include <queue>
#include <vector>
// #include <cmath>

using namespace std;

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int, vector<int>, comp> q;
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
        else{
            q.push(temp);
        }
    }
}

