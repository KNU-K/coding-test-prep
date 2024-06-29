#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// ANSI escape 코드를 사용하여 콘솔 색상 변경하는 함수
void changeConsoleColor(int colorCode) {
    switch (colorCode) {
        case 0: // 원래 색상으로 복원
            std::cout << "\033[0m";
            break;
        case 31: // 빨간색
            std::cout << "\033[1;31m";
            break;
        case 32: // 초록색
            std::cout << "\033[1;32m";
            break;
        default:
            std::cerr << "Unsupported color code!" << std::endl;
            break;
    }
}

// 테스트 유틸리티 클래스 정의
class TestSuite {
private:
    std::string current_description; // 현재 테스트 설명 저장
    int tests_passed;
    int tests_failed;

public:
    TestSuite() : tests_passed(0), tests_failed(0) {}

    // describe 함수: 테스트 설명을 설정하고 자신을 반환
    TestSuite& describe(const std::string& description) {
        current_description = description;
        return *this; // 자기 자신을 반환하여 체이닝을 지원
    }

    // expect 함수: 제네릭 테스트 함수
    template<typename T>
    TestSuite& expect(const T& a, const T& b) {
        bool pass = (a == b);
        printTestResult(pass);
        return *this;
    }

    // expect 함수: 벡터 타입에 대한 특수화
    template<typename T>
    TestSuite& expect(const std::vector<T>& a, const std::vector<T>& b) {
        bool pass = (a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()));
        printTestResult(pass);
        return *this;
    }

    // expect 함수: 문자열 타입에 대한 특수화
    TestSuite& expect(const std::string& a, const std::string& b) {
        bool pass = (a == b);
        printTestResult(pass);
        return *this;
    }

    // getResults 함수: 전체 테스트 결과 출력
    void getResults() const {
        std::cout << "\n\n=== Test Results ===\n";
        std::cout << "Tests Passed: " << tests_passed << "\n";
        std::cout << "Tests Failed: " << tests_failed << "\n";
    }

private:
    // printTestResult 함수: 테스트 결과 출력 및 결과 카운트
    void printTestResult(bool pass) {
        std::ostringstream oss;
        oss << "Test Description: " << current_description << " - ";
        if (pass) {
            oss << "\033[1;32mPassed\033[0m";
            tests_passed++;
        } else {
            oss << "\033[1;31mFailed\033[0m";
            tests_failed++;
        }
        std::cout << oss.str() << std::endl;
    }
};

#endif // TESTS_HPP
