# 抛异常类型

## std::bad_alloc
当动态内存分配（如使用new运算符）失败时，会抛出std::bad_alloc异常。\
这通常是由于系统内存不足导致的。

## std::out_of_range
当使用超出容器（如std::vector、std::string等）有效范围的索引进行访问时，\
会抛出std::out_of_range异常。

## std::invalid_argument
当传递给函数的参数不符合函数的要求时，会抛出std::invalid_argument异常。

## std::logic_error
这是一个通用的逻辑错误异常基类，用于表示程序逻辑中的错误。\
std::invalid_argument、std::out_of_range等异常都继承自std::logic_error。

## std::runtime_error
这是一个通用的运行时错误异常基类，用于表示在程序运行时发生的错误，\
如文件打开失败、网络连接中断等。

## auto& 和 auto的最大区别
auto 需要独立的副本 处理基础类型 int double 操作右值或者临时对象
auto& 避免大型拷贝 需要修改原对象 配个const 实现只读访问
auto 关键字 永远不会推导出引用类型
auto& 是 强制让变量成为左值引用 的声明方式

