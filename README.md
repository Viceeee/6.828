# learning os
# lab 1
## 所以，系统的启动就是从boot.S里面的一行代码调用main.c里的bootmain函数，前提是要首先设置stack
## 在16位系统实模式里，seletor的值就是物理内存，在保护模式里，selector的值为decriptor table的一个index(In protected mode, a selector value is an index into a " descriptor table")
## 在两种模式里，程序都是被分割成段的形式。
## In real mode, these segments are at fixed positions in physical memory and the selector value denotes the paragraph number of the beginning of the segment. In protected mode, the segments are not at fixed positions in physical memory. In fact, they do not have to be in emory at all!
### 所以就是说实模式的地址表示就是物理内存的编号，而保护模式则是不一定会将代码给加载到硬盘里？
#### source by :chapter 1.2.7&1.2.8 https://pdos.csail.mit.edu/6.828/2018/readings/pcasm-book.pdf 
## The C programming language chap5.1-5.5
### chap5.1 讲了指针的原理就是指针指向地址(title:pointers and address)和一元运算符&和指针符 * 和双重指针  
### chap5.2 **&a is a pointer to a [^ ~~ * a is a pointer to a ~~]:nonono * a is not a pointer to a because pointer means address to a value not a value!!!!!!**
### chap5.3  
****

exercises5.1 need to be done,copy this file to here 

***

## 为什么会有实模式和保护模式？
因为一开始计算机是只有20 位的，能够直接操作物理地址，实模式是直接操作在真实物理地址上的，20位的1MB空间比较好管理一点，所以就比较容易管理,但是目前是32位和64位，所以更加难以管理，所以引进了保护模式，同时也引进了内存管理(分页管理那些的),现代的计算机一开始都是运行与实模式上的，就是一开始启动的时候是直接实模式，后面成功启动后就是保护模式，这时的虚拟内存那些的就出来了。


