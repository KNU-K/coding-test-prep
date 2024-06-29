#include <iostream>
#include <cassert>
#include "../../test/test.hpp"
#include <vector>
#define M 10 + 1
#define getPrevValue(idx) (idx <= 0 ?0 : mat[idx]);
using namespace std;
int mat[M] = {0,1,2,3,4,5,6,7,8,9,10};
/**
 * 사전 배열을 초기화한다.
 */
void initPrefixArray(){
    int preValue = 0;
    for(int i=1;i<=M;i++){
        mat[i] += preValue;
        preValue = mat[i];
    }
}
/**
 * @param {int} a
 * @param {int} b
 * a ~ b까지의 구간을 구할 수 있는 함수이다.
 */
int calcPrefixSum(int a,int b){
    return mat[b] - getPrevValue(a-1);
}
void test(){
    TestSuite ts;
    ts.describe("prefix sum test")
        .expect(calcPrefixSum(1,10),55)
        .expect(calcPrefixSum(3,5),12);

    ts.getResults();
}
int main(){
    initPrefixArray();

    /** test */
    test();
}