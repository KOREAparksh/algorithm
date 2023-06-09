#include <iostream>
#include <cmath>
using namespace std;

int dp[50001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    for(int i = 1; i * i <= n; i++){
        dp[i * i] = 1;
    }
    for(int i = 1; i <= n; i++){
        if (dp[i] != 0){
            continue;
        }
        else{
            for(int k = 1; k * k < i; k++){
                if (dp[i] == 0){
                    dp[i] = dp[k * k] + dp[i - k * k];
                }
                else {
                    dp[i] = min(dp[i], dp[k * k] + dp[i - k * k]);
                }
            }
        }
    }
    cout << dp[n] << endl;
}

