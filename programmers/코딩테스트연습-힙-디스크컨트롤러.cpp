#include <string>
#include <vector>

#include <algorithm>
#include <queue>

#include <iostream>
using namespace std;

struct comp_init{
    bool operator()(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
};

struct comp_temp{
    bool operator()(vector<int> &a, vector<int> &b){
        if (a[1] == b[1]){
            return a[0] > b[0];
        }
        return a[1] > b[1] ;
    }
};

bool comp(vector<int> &a, vector<int> &b){
    if(a[1] > b[0])
        return a[1] - a[0] < b[1] - b[0];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int nowTime = 0;

    priority_queue<vector<int>, vector<vector<int> >, comp_init > pq;
    priority_queue<vector<int>, vector<vector<int> >, comp_temp > temp_pq;
    
    for(int i = 0; i < jobs.size(); i++){
        pq.push(jobs[i]);
    }
    
    while(!pq.empty() || !temp_pq.empty()){
        //후보선정
        while(!pq.empty() && pq.top()[0] <= nowTime){
            temp_pq.push(pq.top());
            pq.pop();
        }
        //적절한거 추가 및 초 계산
        if(!temp_pq.empty()){
            vector<int> node = temp_pq.top();
            temp_pq.pop();

            int gap = nowTime + node[1] - node[0];

            nowTime =  nowTime + node[1];
            answer += gap;
        }
        else
            nowTime++;
    }
    return answer / jobs.size();
}
