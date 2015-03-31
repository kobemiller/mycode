linux内核设计的艺术
一、第一章--启动
1、intel的CPU硬件都设计为加电即进入16位实模式状态运行。同时，将CPU硬件逻辑设计为加电瞬间强行将CS
的值置为0xF000，IP的值为0xFFF0，这样CS:IP就指向0xFFFF0。这个地址就是BIOS的入口地址
2、BIOS执行期间除了自检，还有一项很重要的工作就是在内存中建立中断向量表和中断服务程序。
3、BIOS在内存最开始的位置（0x00000）用1KB的内存空间构建中断向量表（0x00000-0x003FF），紧挨着用256字节
构建BIOS数据区（0x00400-0x004FF），并在大约57KB以后的位置（0x0E05B）加载8KB左右的与中断向量表相应的若干中断服务。
4、加载内核：分三批次
1）由BIOS中断int 0x19把第一扇区bootsect的内容加载到内存；（启动扇区的内容）
2）第二批，第三批在bootsect的指挥下，分别把其后的4个扇区和随后的240个扇区的内容加载到内存。bootsect首先要做的就是规划内存。5、
entry start
start:
mov 	ax, #BOOTSEG 	!bootset启动程序将自身从0x07C00处复制到0x90000处
mov 	ds, ax
mov 	ax, #INITSEG
mov 	es, ax
mov 	cx, #256
mov 	si, si
sub 	di, di
rep
movw

