#include <Calc.hpp>
#include <gtest/gtest.h>
#include <iostream>

using namespace gened::calculator;

class CalcTest : public ::testing::Test {
    
protected:
    Calc *calculator = nullptr;
    
    CalcTest() {
        calculator = new Calc();
    }
    
    ~CalcTest() {
        if (calculator != nullptr) {
            delete calculator;
        }
    }
};

TEST_F(CalcTest, AddOperation) {
    ASSERT_EQ(calculator->add(2, 2), 4);
}
