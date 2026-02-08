// 包含我们自己的头文件
// 注意：用双引号""包含自己的头文件，用尖括号<>包含系统/库头文件
#include "Vector2.h"

// 包含C++数学库，我们需要std::sqrt来计算平方根
#include <cmath>

// Vector2类成员函数的实现

// 实现向量加法：对应分量相加
// 返回一个新向量，不修改当前对象
Vector2 Vector2::operator+(const Vector2& other) const {
    // 创建临时对象并返回
    return Vector2(x + other.x, y + other.y);
}

// 实现向量减法：对应分量相减
Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

// 标量乘法：向量的每个分量乘以标量
Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

// 标量除法：向量的每个分量除以标量
// 注意：需要防止除以零的错误
Vector2 Vector2::operator/(float scalar) const {
    // 检查除数是否接近零
    if (std::fabs(scalar) < 1e-6f) {
        // 在实际游戏中，可能需要更健壮的错误处理
        // 这里简单返回零向量
        return Vector2();
    }
    return Vector2(x / scalar, y / scalar);
}

// 计算向量点积：a·b = a.x*b.x + a.y*b.y
// 几何意义：|a||b|cosθ，可判断两个向量的夹角
float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

// 计算向量长度：使用勾股定理
float Vector2::length() const {
    // std::sqrt 计算平方根
    return std::sqrt(x * x + y * y);
}

// 计算向量长度的平方：避免开方运算，效率更高
// 适用于比较距离大小（因为开方不影响大小关系）
float Vector2::lengthSquared() const {
    return x * x + y * y;
}

// 归一化：返回单位向量，方向与原向量相同，长度为1
Vector2 Vector2::normalized() const {
    float len = length();
    
    // 如果长度接近零，返回零向量
    if (len < 1e-6f) {
        return Vector2();
    }
    
    // 否则返回归一化后的向量
    return Vector2(x / len, y / len);
}

// 原地归一化：直接修改当前向量
void Vector2::normalize() {
    float len = length();
    
    // 如果长度接近零，设置为零向量
    if (len < 1e-6f) {
        x = y = 0.0f;
    } else {
        // 否则进行归一化
        x /= len;
        y /= len;
    }
}

// 判断两个向量是否近似相等（考虑浮点数精度误差）
bool Vector2::equals(const Vector2& other, float epsilon) const {
    // 比较x和y分量的差是否在允许的误差范围内
    return (std::fabs(x - other.x) < epsilon) && 
           (std::fabs(y - other.y) < epsilon);
}

// 实现输出运算符<<
// 这个函数不是Vector2的成员函数，而是独立函数（但声明为友元）
std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    // 将向量格式化为 (x, y) 的形式
    os << "(" << v.x << ", " << v.y << ")";
    
    // 返回流对象，支持链式调用：cout << a << b << endl;
    return os;
}