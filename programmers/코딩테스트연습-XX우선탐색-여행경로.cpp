#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, set<string> > routes;
unordered_map<string, bool> visit;


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    for(int i = 0; i < tickets.size(); i++){
        routes[tickets[i][0]].insert(tickets[i][1]);
        visit[tickets[i][0]] = false;
        visit[tickets[i][1]] = false;
    }

    stack<string> stack;
    stack.push("ICN");

    while(!stack.empty()){
        string now = stack.top();
        stack.pop();

        if (visit[now] == true && now != "ICN")
            continue;
        visit[now] = true;
        answer.push_back(now);

        if (routes.find(now) == routes.end() || routes.find(now)->second.size() == 0)
            continue;
        set<string> &s = routes.find(now)->second;
        for(auto it = s.begin(); it != s.end(); it++){
            if (visit[*it] == true && now != "ICN")
                continue;
            stack.push(*it);
        }
    }

    return answer;
}
