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
 
****

exercises5.1 need to be done,copy this file to here 

***

### 

