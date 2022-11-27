#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct s_node{
    int index;
    int value;
};

bool comp(const pair<string,int>& a, const pair<string,int>& b) {
	return a.second > b.second;
}
bool compStruct(const s_node& a, const s_node& b) {
	return a.value > b.value;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genresMap;
    unordered_map<string, vector<s_node> > playMap;
    int size = genres.size();
    
    for(int i = 0; i < size; i++){
        //genres count
        if (genresMap.find(genres[i]) != genresMap.end()){
            genresMap[genres[i]] += plays[i];
        }
        else{
            genresMap.insert({genres[i], plays[i]});
        }
        
        //plays insert
        if (playMap.find(genres[i]) != playMap.end()){
            playMap[genres[i]].push_back({i, plays[i]});
        }
        else{
            vector<s_node> temp;
            temp.push_back({i, plays[i]});
            playMap.insert({genres[i], temp});
        }
    }
    
    vector<pair<string,int> > genresVec(genresMap.begin(), genresMap.end());
    sort(genresVec.begin(), genresVec.end(), comp);
    int genresVecSize = genresVec.size();
    
    for(int i = 0; i < genresVecSize; i++){
        string &gen = genresVec[i].first;
        vector<s_node> &temp = playMap[gen];
        
        sort(temp.begin(), temp.end(), compStruct);
        
        answer.push_back(temp[0].index);
        if (temp.size() >= 2)
            answer.push_back(temp[1].index);
    }
    
    return answer;
}
