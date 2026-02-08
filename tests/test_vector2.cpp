// 包含必要的头文件
#include "Vector2.h"  // 要测试的类
#include <cassert>    // assert宏，用于验证条件
#include <iostream>   // 输出测试结果
#include <cmath>      // 用于fabs函数

// 测试1：向量加法
void test_vector_addition() {
    // 创建两个测试向量
    Vector2 a(1.0f, 2.0f);
    Vector2 b(3.0f, 4.0f);
    
    // 计算它们的和
    Vector2 c = a + b;  // 应该得到 (4, 6)
    
    // 验证结果是否正确
    assert(c.x == 4.0f);  // 如果条件为假，程序会终止
    assert(c.y == 6.0f);
    
    // 打印成功信息
    std::cout << "Vector addition test passed" << std::endl;
}

// 测试2：向量减法
void test_vector_subtraction() {
    Vector2 a(5.0f, 6.0f);
    Vector2 b(2.0f, 3.0f);
    Vector2 c = a - b;  // 应该得到 (3, 3)
    
    assert(c.x == 3.0f);
    assert(c.y == 3.0f);
    std::cout << "Vector subtraction test passed" << std::endl;
}

// 测试3：向量长度计算
void test_vector_length() {
    // 创建向量(3,4)，构成3-4-5直角三角形
    Vector2 a(3.0f, 4.0f);
    float len = a.length();  // 应该得到5.0
    
    // 验证长度（允许浮点数微小误差）
    assert(len > 4.999f && len < 5.001f);
    std::cout << "Vector length test passed" << std::endl;
}

// 测试4：向量归一化
void test_vector_normalization() {
    Vector2 a(3.0f, 4.0f);
    Vector2 norm = a.normalized();
    
    // 归一化后的长度应该为1
    float len = norm.length();
    assert(len > 0.999f && len < 1.001f);
    
    // 方向应该保持不变（与原向量成比例）
    assert(std::fabs(norm.x - 0.6f) < 0.001f);
    assert(std::fabs(norm.y - 0.8f) < 0.001f);
    std::cout << "Vector normalization test passed" << std::endl;
}

// 测试5：向量点积
void test_vector_dot_product() {
    Vector2 a(1.0f, 2.0f);
    Vector2 b(3.0f, 4.0f);
    float dot = a.dot(b);  // 1 * 3 + 2 * 4 = 11
    
    assert(std::fabs(dot - 11.0f) < 0.001f);
    std::cout << "Vector dot product test passed" << std::endl;
}

// 测试6：向量标量乘法
void test_vector_scalar_multiplication() {
    Vector2 a(2.0f, 3.0f);
    Vector2 b = a * 2.0f;  // 应该得到 (4, 6)
    
    assert(b.x == 4.0f && b.y == 6.0f);
    std::cout << "Vector scalar multiplication test passed" << std::endl;
}

// 主测试函数
int main() {
    std::cout << "Running Vector2 unit tests..." << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    
    // 运行所有测试
    test_vector_addition();
    test_vector_subtraction();
    test_vector_length();
    test_vector_normalization();
    test_vector_dot_product();
    test_vector_scalar_multiplication();
    
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}