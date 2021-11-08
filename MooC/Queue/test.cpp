#include"MyQueue.cpp"
template class MyQueue<int>; // 对模板进行实例化
//C++不支持模板的分离式编译；所以最好实现模板时放到同一个文件下，
//修改名称为hpp