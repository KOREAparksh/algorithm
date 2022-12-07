#include <string>
#include <vector>
#include <stack>

#define MAX_INDEX 201
#define NOT_LINKED 0

using namespace std;

bool visit[MAX_INDEX];
stack<int> linkedVertexStack;

bool isLinked(int linkedInfo){
    if (linkedInfo == NOT_LINKED)
        return false;
    return true;
}

void findLinkedVertex(int &vertexSize, vector<vector<int>> &computers){
    int starting = linkedVertexStack.top();
    linkedVertexStack.pop();
    visit[starting] = true;
    computers[starting - 1][starting - 1] = NOT_LINKED;

    for(int destination = 1; destination <= vertexSize; destination++){
        if (isLinked(computers[starting - 1][destination - 1]) == false)
            continue;
        if (starting == destination){
            continue;
        }
        if (visit[destination] == true){
            continue;
        }
        computers[starting - 1][destination - 1] = NOT_LINKED;
        computers[destination - 1][starting - 1] = NOT_LINKED;
        visit[destination] = true;
        linkedVertexStack.push(destination);
    }
}

void visitLinkedVertex(int vertexSize, vector<vector<int>> computers){
    while(!linkedVertexStack.empty()){
        findLinkedVertex(vertexSize, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int networkCount = 0;

    for(int beginVertexNumber = 1; beginVertexNumber <= n; beginVertexNumber++){
        if (visit[beginVertexNumber] == true) continue;
        linkedVertexStack.push(beginVertexNumber);
        visitLinkedVertex(n, computers);
        networkCount++;
    }

    return networkCount;
}
