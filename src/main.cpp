// 包含我们自己的Vector2头文件
#include "Vector2.h"
// 包含输入输出流
#include <iostream>

// 每个C++程序都从这里开始执行
int main() {
    std::cout << "Smart Hook Simulator - Vector System Test" << std::endl;
    std::cout << "==========================================" << std::endl;
    
    // 创建两个向量，模拟钩爪起点和目标点
    Vector2 hookStart(0.0f, 0.0f);     // 钩爪发射点：原点
    Vector2 target(3.0f, 4.0f);        // 目标点：坐标(3,4)
    
    // 打印信息
    std::cout << "Hook Start Position: " << hookStart << std::endl;
    std::cout << "Target Position: " << target << std::endl;
    
    // 计算从起点到目标的向量（方向）
    Vector2 direction = target - hookStart;  // 向量减法
    std::cout << "Direction Vector: " << direction << std::endl;
    
    // 计算到目标的距离（向量长度）
    float distance = direction.length();     // 调用length()方法
    std::cout << "Distance to Target: " << distance << std::endl;
    
    // 验证：3-4-5三角形，距离应该是5
    if (distance > 4.99f && distance < 5.01f) {
        std::cout << "Vector calculation correct!" << std::endl;
    }
    
    // 测试归一化：获取单位方向向量
    Vector2 unitDirection = direction.normalized();
    std::cout << "Unit Direction: " << unitDirection << std::endl;
    std::cout << "Unit Direction Length: " << unitDirection.length() << std::endl;
    
    // 测试点积
    Vector2 a(1.0f, 0.0f);  // 水平向右
    Vector2 b(0.0f, 1.0f);  // 垂直向上
    float dot = a.dot(b);   // 应该为0（垂直）
    std::cout << "Dot product of (1,0) and (0,1): " << dot << std::endl;
    
    // 测试标量乘法
    Vector2 scaled = direction * 2.0f;
    std::cout << "Direction * 2: " << scaled << std::endl;
    
    std::cout << "==========================================" << std::endl;
    std::cout << "Toolchain verification completed!" << std::endl;
    std::cout << "Ready to implement physics simulation!" << std::endl;
    
    return 0;  // 程序正常退出
}