#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    multiset<int> set;

    cin >> count;
    while(count--){
        set.clear();
        int n;
        cin >> n;

        while(n--){
            string str;
            int n;

            cin >> str >> n;

            if (str == "I"){
                set.insert(n);
            }
            else if (str == "P"){
                cout << "length : " << set.size() << endl;
            }
            else{
                if (n == -1){
                    if (set.empty()){
                        continue;
                    }
                    set.erase(set.begin());
                }
                else{
                    if (set.empty()){
                        continue;
                    }
                    set.erase(--(set.end()));
                }
            }
        }
        if (set.empty() == 1){
            cout << "EMPTY" << endl;
        }
        else{
            cout <<  *(--(set.end())) << " " << *(set.begin()) << endl;
        }
    }
   
}
