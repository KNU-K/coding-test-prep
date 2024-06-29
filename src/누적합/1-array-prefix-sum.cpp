#include <iostream>
#include <cassert>
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
void changeConsoleColor(int colorCode) {
    std::cout << "\033[" << colorCode << "m";
}
void test(){

    if (calcPrefixSum(1, 10) == 55) {
        changeConsoleColor(32);
        cout << "Test 1 Passed" << std::endl;
    } else {
        changeConsoleColor(31);
        cout << "Test 1 Failed" << std::endl;
    }

    if (calcPrefixSum(1, 3) == 6) {
        changeConsoleColor(32);
        cout << "Test 2 Passed" << std::endl;
    } else {
        changeConsoleColor(31);
        cout << "Test 2 Failed" << std::endl;
    }

    changeConsoleColor(0); 
}
int main(){
    initPrefixArray();

    /** test */
    test();
}