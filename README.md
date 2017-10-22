所有的manager类都应当是单例的。

自己编写的所有文件与类命名都应当带上“DB”前缀。

需要向控制台输出信息时，请都使用DBLog中的方法。目前有log、print和printLine，接收参数均为std::string。这样做的目的是方便日后的调试和修改。不再输出调试信息时，只需修改log函数的内容。需要修改输出方式，如cout转为printf，也只需修改print和printLine两个函数。

文件结构（暂定）：

第一页为信息页，按顺序存储如下内容：

  record_length，文件存储的记录的长度， int 类型
  
  page_number，文件的总页数，包含信息页在内， int 类型
  
  availability_of_page，文件每页是否有空闲空间， char* 类型，实际上是位数组，一位对应一页
  
  
其余为数据页，按record_length划分为若干个“槽”。页末的槽也是一个位数组，一位对应一个槽。如果一个record_length长度的槽不足以表示所有的槽，则用页末两个槽表示，依次类推。根据粗略计算，记录长度为L时，用来表示位数组的槽数n应满足n >= 8KB / (L * (8 * L + 1))。


记录结构（暂定）：
记录的第一项内容是rid，暂定为10字节长的字符串，前4字节为时间戳，中间2字节为进程id PID，后4字节为随机数，参考了mongoDB的objectID生成方法。
其余内容、支持的类型可以查看DBRecordInfo.h。
