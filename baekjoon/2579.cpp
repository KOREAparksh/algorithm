#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	int vec[300];
	int dp[300];
	cin >> n;
	
	for(int i = 0 ; i < n; i++){
		cin >> vec[i];
	}
	
	dp[0] = vec[0];
	dp[1] = vec[0] + vec[1];
	
	dp[2] = max(dp[0] + vec[2], vec[1] + vec[2]);
	for(int i = 3 ; i < n; i++){
		dp[i] = max(dp[i - 3] + vec[i - 1] + vec[i], dp[i - 2] + vec[i]);
	}
	cout << dp[n - 1] << endl;
}

