// 头文件保护：防止同一个编译单元中多次包含此头文件
#ifndef VECTOR2_H
#define VECTOR2_H

// 包含标准库的输入输出流，我们需要std::ostream来重载<<运算符
#include <iostream>

// Vector2 类：表示二维空间中的向量（既有大小也有方向）
// 在游戏中，它可以表示：位置、速度、加速度、力等
class Vector2 {
public:
    // 公共成员变量：允许直接访问x和y坐标
    // 对于简单的值类型，这是可接受的；对于复杂类型，通常设为private并提供getter/setter
    float x, y;
    
    // 默认构造函数：创建一个零向量(0, 0)
    // 当声明 Vector2 v; 时调用
    Vector2() : x(0.0f), y(0.0f) {}
    
    // 带参数的构造函数：用指定的x和y值创建向量
    // 当声明 Vector2 v(3.0f, 4.0f); 时调用
    Vector2(float x, float y) : x(x), y(y) {}
    
    // 向量加法运算符重载
    // const成员函数：承诺不修改调用它的对象（左侧操作数）
    // 参数：const引用，承诺不修改右侧操作数，且避免拷贝
    // 返回：新的Vector2对象，是两个向量的和
    Vector2 operator+(const Vector2& other) const;
    
    // 向量减法运算符重载
    Vector2 operator-(const Vector2& other) const;
    
    // 标量乘法：向量乘以一个标量（数）
    Vector2 operator*(float scalar) const;
    
    // 标量除法：向量除以一个标量
    Vector2 operator/(float scalar) const;
    
    // 向量点积（内积）：返回一个标量，用于计算夹角等
    float dot(const Vector2& other) const;
    
    // 计算向量的长度（模、大小）
    // 公式：√(x² + y²) - 勾股定理
    float length() const;
    
    // 计算向量长度的平方（避免开方运算，用于比较距离）
    float lengthSquared() const;
    
    // 归一化：返回一个方向相同但长度为1的单位向量
    Vector2 normalized() const;
    
    // 原地归一化：直接修改当前向量为单位向量
    void normalize();
    
    // 判断两个向量是否近似相等（考虑浮点数误差）
    bool equals(const Vector2& other, float epsilon = 0.0001f) const;
    
    // 友元函数声明：重载输出运算符<<
    // 为什么是友元：因为运算符左侧是std::ostream，不是Vector2
    // 友元可以让这个函数访问Vector2的私有成员
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

// 头文件保护结束
#endif // VECTOR2_H