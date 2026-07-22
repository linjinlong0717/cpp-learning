ASCII、Unicode 与 C++ std::string / wstring / u16string / u32string 关系梳理
一、基础概念区分
ASCII
是 字符集：只定义 0~127 共 128 个基础字符（英文字母、数字、符号、控制符），配套单字节存储形式
ASCII 是 Unicode 的 子集 ：Unicode 中 U+0000 ~U+007F 和 ASCII 字符一一对应。

Unicode
是 统一字符集，定义全球所有文字的唯一编号（码点 Code Point，格式 U + xxxx）；
Unicode 本身不是编码，需要 UTF - 8 / UTF - 16 / UTF - 32 这些编码方案把码点转换成二进制字节。

// 字符集：规定有哪些字符；编码：规定字符如何存成字节。

二、各个 C++ 字符串类型详解
所有字符串都基于模板 std::basic_string<T>，只是模板参数字符类型不同：

类型(字符串容器)	底层字符类型	           典型编码	                         字节宽度	                      
std::string	        char	                 默认：本地多字节；                   1 字节	                       
                                             常承载 UTF - 8 字节流
std::wstring        wchar_t                Windows：UTF - 16；                     平台不固定
                                          Linux / macOS：UTF - 32           （Win = 2 字节，Linux = 4 字节）
std::u16string	    char16_t	       UTF - 16（C++11 起，标准固定 16 位）	     固定 2 字节	                     
std::u32string	    char32_t	     UTF - 32（C++11 起，标准固定 32 位）	     固定 4 字节	                    

//总结我们选定一种 std::xxxstring 文本容器（确定存储单元大小），使用与之约定匹配的
编码规则（UTF - 8 / UTF - 16 / UTF - 32），把 ASCII或Unicode 字符转换成对应尺寸的存储单元，存入容器中。