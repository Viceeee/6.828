# learning os
# lab 1
所以，系统的启动就是从boot.S里面的一行代码调用main.c里的bootmain函数，前提是要首先设置stack

在16位系统实模式里，seletor的值就是物理内存，在保护模式里，selector的值为decriptor table的一个index(In protected mode, a selector value is an index into a " descriptor table")

在两种模式里，程序都是被分割成段的形式。

> In real mode, these segments are at fixed positions in physical memory and the selector value denotes the paragraph number of the beginning of the segment. In protected mode, the segments are not at fixed positions in physical memory. In fact, they do not have to be in emory at all!
>
> [^https://pdos.csail.mit.edu/6.828/2018/readings/pcasm-book.pdf]: source by :chapter 1.2.7&1.2.8 

**所以就是说实模式的地址表示就是物理内存的编号，而保护模式则是不一定会将代码给加载到硬盘里？**

#### 
## The C programming language chap5.1-5.5
### chap5.1 讲了指针的原理就是指针指向地址(title:pointers and address)和一元运算符&和指针符 * 和双重指针  
### chap5.2 

**&a is a pointer to a  ~~* a is a pointer to a~~ :nonono * a is not a pointer to a because pointer means address to a value pointer is not a value!!!!!!**

### chap5.3  
****

exercises5.1 need to be done,copy this file to here 

***

## 为什么会有实模式和保护模式？
因为一开始计算机是只有20 位的，能够直接操作物理地址，实模式是直接操作在真实物理地址上的，20位的1MB空间比较好管理一点，所以就比较容易管理,但是目前是32位和64位，所以更加难以管理，所以引进了保护模式，同时也引进了内存管理(分页管理那些的),现代的计算机一开始都是运行与实模式上的，就是一开始启动的时候是直接实模式，后面成功启动后就是保护模式，这时的虚拟内存那些的就出来了。

### 6.828 chap  Loading the Kernel 
解释了JOS的顶层设计：使用了objdump展示了JOS obj/kern/kernel program-header 
					    obj/kern/kernel section-header
					    obj/boot/boot.out section-header


#### exercises 5
不明白为什么我的在boot/Makefrag中的第28行修改成0x7c01，然后gdb会卡在
[ 0:7c30] => 0x7c30:	ljmp   $0x8,$0x7c36
这里，为什么我把它修改成7c01就变成7c30了？
所以这里后面才会有part 3 的事情吧？

### exercises 7
在经过这个提示后The target architecture is set to "i386".后，使用x *0x00100000和x *0xf0100000 由原来的

```gdb
(gdb) x *0x00100000
   0x0:	add    %al,(%bx,%si)
(gdb) x *0xf0100000
   0x0:	add    %al,(%bx,%si)

The target architecture is set to "i386"
(gdb) x *0x00100000
   0x0:	add    %al,(%eax)
(gdb) x *0xf0100000
   0x0:	add    %al,(%eax)


```

我个人对于这个变化的猜测是因为是检测到了i386以后eax寄存器就可以直接取代由(%bx,%si)寄存器组成的寄存器？



```gdb
(gdb) x 0x00100000
   0x100000:	add    %al,(%bx,%si)
(gdb) x 0xf0100000
   0xf0100000 <_start-268435468>:	add    %al,(%bx,%si)
(gdb) si
The target architecture is set to "i386".
=> 0xfd18f:	mov    $0x10,%eax
0x000fd18f in ?? ()
(gdb) x 0x00100000
   0x100000:	add    %al,(%eax)
(gdb) x 0xf0100000
   0xf0100000 <_start-268435468>:	add    %al,(%eax)
```


结束了实验以后我说的这个不一定正确，我的视角有问题，并不应该关注于寄存器上面，而是应该关注在地址上。在把kern/entry.S 注释掉以后，因为现在还没有进行map，所以就只有256MB，256MB的物理地址应该是从0x00000000-0xf0000000之间，所以这个第二个examine检查的是超过了256MB的内存，所以才会有<_start-268435468>这个东西


### exercises 8
修补printfmt.c里面的%o

#### after exercises 8
1、console.c里面的是比较底层的端口比如说COM这类串行的端口,console应该是接收电平输入的端口？printf.c里面是封装了console.c的底层函数和printfmt.c的处理函数，让其能够直接使用？
printf.c 通过putch()这个函数调用console.c里的cputchar()，这个cputchar是封装了console.c里cons_putc()这个函数的，是和cons_putc这个函数相比更加high-level的I/O函数，能够直接使用来读行(readline)和打印，而这个函数调用了console.c里的serial_putc()函数，这个函数又用调用了inc/x86.h里的inb函数。

2、猜测是屏幕一行打满了以后换行的作用，

```C
if (crt_pos >= CRT_SIZE) {
             int i;
             memmove(crt_buf, crt_buf + CRT_COLS, (CRT_SIZE - CRT_COLS) * sizeof(uint16_t));//直接将buf移动到新的地方
             for (i = CRT_SIZE - CRT_COLS; i < CRT_SIZE; i++)/超过buf的部分把crt_buf置为0x700或者是' '?
                     crt_buf[i] = 0x0700 | ' ';
             crt_pos -= CRT_COLS;//重置crt_pos
}
```

感觉不是？应该是这个指示针的位置?假如超过这整个屏幕的size就直接换新的页？

3、
4、



