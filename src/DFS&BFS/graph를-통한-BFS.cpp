#include <iostream>
#include <stack>
#include <vector>
#include "../../test/test.hpp"
#define M 5
#define VERTEX_NUM 10
using namespace std;

typedef struct Edge {
    int s, e;
}CONNECTED;
vector<int> graph[VERTEX_NUM];
int visited[VERTEX_NUM];

stack<int> st;

void initializeGraph(CONNECTED conns[M]) {
    for(int i=0;i<M;i++){
        
        int s = conns[i].s;
        int e = conns[i].e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    
    }
    
}
void initializeVisited(){
    for (int i = 0; i < VERTEX_NUM; ++i) {
        visited[i] = 0;
    
    }
}
int dfs(int cur){
    initializeVisited();
    while(!st.empty()){st.pop();};
    st.push(cur);
    visited[cur] = 1;
    while (!st.empty())
    {
        cur = st.top();
        st.pop();
        if(cur == 9) return visited[cur];

        for(auto next : graph[cur]){
            if(visited[next]) continue;
            st.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    return -1;
    
}
void test(){
    TestSuite ts;
    ts.describe("DFS implement using graph and stack")
    .expect(dfs(1),5)
    .expect(dfs(2),4)
    .expect(dfs(10),-1)
    .getResults();
}
int main(){
    CONNECTED conn[M] = {{1,2},{2,3},{3,7},{7,9}};
    initializeGraph(conn);

    test();
}