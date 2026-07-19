 placement new（定位 new）
一、定义
placement new 是在已经分配好的原始内存地址上，直接调用构造函数来创建对象的操作。它不分配新内存，只负责构造对象。

二、必须包含头文件
#include <new>

三、语法格式
new (内存地址) 类型(构造参数);

示例：
char* buffer = new char[sizeof(MyClass)];
MyClass* p = new (buffer) MyClass(10);

四、底层原理
普通 new 干两件事：1.分配内存（operator new） 2.构造对象。
placement new 只干第二件事（构造对象），不参与内存分配。
它直接调用构造函数，将 this 指针指向用户提供的地址。

五、为什么叫 placement new
因为底层调用的标准库函数是 operator new(size_t, void* ptr)，它什么都不做，只是把对象“放置（Place）”在传入的地址上，所以称为 placement new。

六、常见应用场景
1.内存池：一次性申请大块内存，反复使用，避免频繁 new / delete 的开销。
2.共享内存通信：在映射到进程地址空间的共享内存上构建对象。
3.嵌入式开发：在指定的物理地址上构造设备对象。

七、正确释放方式（重要）
绝对不能使用 delete p，因为 p 指向的内存不是 new 分配的。
必须分两步手动释放：
1.手动调用析构函数：p->~MyClass();
2.释放原始内存：delete[] buffer; （或 free(buffer)，取决于原始内存如何申请）

八、与普通 new / delete 的对比
普通 new：分配内存 + 调用构造
普通 delete：调用析构 + 释放内存
placement new：只调用构造（不分配内存）
手动析构 + 释放原始内存：只调用析构 + 只释放内存（不构造）

九、注意事项
1.注意内存对齐：char buffer[sizeof(T)] 的起始地址通常满足对齐要求，特殊场景可用 alignas(alignof(T)) char buffer[sizeof(T)] 强制对齐。
2.placement new 构造的对象，严禁使用 delete 释放，必须手动调用析构函数并释放原始内存。