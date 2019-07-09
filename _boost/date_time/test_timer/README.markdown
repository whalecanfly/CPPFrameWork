# 补充说明

timer的计时使用了标准库头文件利的<ctime>利的std::clock()函数，他返回的自进场启动以来的clock数，
每秒的clock数则由宏CLOCKS_PER_SEC定义。因操作系统的不同，win32是1000，而在linux下则是1000000，
也就是说win32下精度是毫秒，linux下精度是微妙。



