#include <iostream>
#include <cassert>
#include "../../test/test.hpp"
#include <vector>
#define M 4 + 1
#define getPrevValue(idx) (idx <= 0 ?0 : mat[idx]);
using namespace std;
int mat[M][M] = {{0,0,0,0,0}
                ,{0,1,2,3,4}
                ,{0,2,3,4,5}
                ,{0,3,4,5,6}
                ,{0,4,5,6,7}};
                
int sumMat[M][M] = {0,};
/**
 * 사전 배열을 초기화한다.
 */
void initPrefix2DArray(){
    int preValue = 0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=M;j++){
            sumMat[i][j] = mat[i][j] + sumMat[i][j-1] + sumMat[i-1][j] - sumMat[i-1][j-1];
        }
    }
}
/**
 * @param {int} x1
 * @param {int} y1
 * @param {int} x2
 * @param {int} y2
 * (x1,y1) ~ (x2,y2)까지의 구간을 구할 수 있는 함수이다.
 */
int calcPrefixSum(int x1,int y1, int x2,int y2){
    return sumMat[x2][y2] - sumMat[x1-1][y2] - sumMat[x2][y1-1] + sumMat[x1-1][y1-1];
}
void test(){
    TestSuite ts;
    ts.describe("calcPrefixSum(with 2D array prefix sum)")
        .expect(calcPrefixSum(2,2,3,4),27)
        .expect(calcPrefixSum(3,4,3,4),6)
        .expect(calcPrefixSum(1,1,4,4),64);
    ts.getResults();
}
int main(){
    initPrefix2DArray();

    /** test */
    test();
}