cmake_minimum_required(VERSION 3.15)

# 1. 必须在project()前的设置
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. 项目定义
project(VectorAscend
    VERSION 0.1.0
    DESCRIPTION "智能钩爪模拟器 - 物理学习项目"
    LANGUAGES CXX
)

# 3. 编译选项（支持多配置生成器）
add_compile_options(
    "$<$<CONFIG:Debug>:-g -O0 -Wall -Wextra -Wpedantic>"
    "$<$<CONFIG:Release>:-O2 -DNDEBUG>"
)

# 4. 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 5. 源文件定义
set(SRC_FILES
    src/main.cpp
    src/Vector2.cpp
)
set(TEST_FILES tests/test_vector2.cpp)

# 6. 可执行文件
add_executable(VectorAscend ${SRC_FILES})
add_executable(TestVector2 ${TEST_FILES} src/Vector2.cpp)

# 7. 包含目录（现代方式）
target_include_directories(VectorAscend PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(TestVector2 PUBLIC ${CMAKE_SOURCE_DIR}/include)

# 8. 源文件分组（IDE支持）
source_group("src" FILES ${SRC_FILES})
source_group("tests" FILES ${TEST_FILES})

# 9. 测试配置
enable_testing()
add_test(NAME Vector2Test COMMAND TestVector2)

# 10. 安装规则
install(TARGETS VectorAscend
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)