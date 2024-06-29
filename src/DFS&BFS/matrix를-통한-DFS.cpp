#include <iostream>
#include <stack>
#include "../../test/test.hpp"
#define M 5
using namespace std;
int mat[M][M] = {0,};
int visited[M][M] = {0,};
typedef struct POINT{ int x,y; }POINT;
stack<POINT> st;
POINT dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

bool isExistInFrontier(POINT p){
    return (0<=p.x)&& (p.x < M) && (0<=p.y)&& (p.y < M);
}
void initializeMatrix(int tempMat[M][M]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            mat[i][j] = tempMat[i][j];
        }
    }
}
void initializeVisited(){
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = 0;
        }
    }
}
int dfs(POINT cur){
    initializeVisited();
    while(!st.empty()){st.pop();}
    st.push(cur);
    visited[cur.x][cur.y] = 1;
    while (!st.empty())
    {
        cur = st.top();
        st.pop();
        if(cur.x == M - 1 && cur.y == M-1){
            return visited[cur.x][cur.y];
        }
        for(auto nextDir : dir){
            POINT next = {cur.x + nextDir.x,cur.y + nextDir.y};
            if(!isExistInFrontier(next)) continue;
            if(visited[next.x][next.y]) continue;
            if(!mat[next.x][next.y]) continue;
            st.push(next);
            visited[next.x][next.y] = visited[cur.x][cur.y] + 1;
        }
    }
    return -1;
    
}
void test(){
    TestSuite ts;
    ts.describe("DFS implement using matrix and stack")
    .expect(dfs({0,0}),11)
    .expect(dfs({1,0}),10)
    .expect(dfs({0,3}),-1)
    .getResults();
}
int main(){
   int tempMat[M][M] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };

    initializeMatrix(tempMat);
    test();
}