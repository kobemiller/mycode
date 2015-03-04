
a.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x1db>
  400248:	78 38                	js     400282 <_init-0x1ce>
  40024a:	36                   	ss
  40024b:	2d 36 34 2e 73       	sub    $0x732e3436,%eax
  400250:	6f                   	outsl  %ds:(%rsi),(%dx)
  400251:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    $0x0,%al
  400256:	00 00                	add    %al,(%rax)
  400258:	10 00                	adc    %al,(%rax)
  40025a:	00 00                	add    %al,(%rax)
  40025c:	01 00                	add    %eax,(%rax)
  40025e:	00 00                	add    %al,(%rax)
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push %rbp
  400263:	00 00                	add    %al,(%rax)
  400265:	00 00                	add    %al,(%rax)
  400267:	00 02                	add    %al,(%rdx)
  400269:	00 00                	add    %al,(%rax)
  40026b:	00 06                	add    %al,(%rsi)
  40026d:	00 00                	add    %al,(%rax)
  40026f:	00 18                	add    %bl,(%rax)
  400271:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    $0x0,%al
  400276:	00 00                	add    %al,(%rax)
  400278:	14 00                	adc    $0x0,%al
  40027a:	00 00                	add    %al,(%rax)
  40027c:	03 00                	add    (%rax),%eax
  40027e:	00 00                	add    %al,(%rax)
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push %rbp
  400283:	00 b8 c5 9d aa da    	add    %bh,-0x2555623b(%rax)
  400289:	08 5c ec 3c          	or     %bl,0x3c(%rsp,%rbp,8)
  40028d:	cb                   	lret   
  40028e:	df cf                	(bad)  
  400290:	f3 d5                	repz (bad) 
  400292:	a8 43                	test   $0x43,%al
  400294:	8e                   	.byte 0x8e
  400295:	a7                   	cmpsl  %es:(%rdi),%ds:(%rsi)
  400296:	ea                   	(bad)  
  400297:	2b                   	.byte 0x2b

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	01 00                	add    %eax,(%rax)
  40029a:	00 00                	add    %al,(%rax)
  40029c:	01 00                	add    %eax,(%rax)
  40029e:	00 00                	add    %al,(%rax)
  4002a0:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

00000000004002b8 <.dynsym>:
	...
  4002d0:	0b 00                	or     (%rax),%eax
  4002d2:	00 00                	add    %al,(%rax)
  4002d4:	12 00                	adc    (%rax),%al
	...
  4002e6:	00 00                	add    %al,(%rax)
  4002e8:	10 00                	adc    %al,(%rax)
  4002ea:	00 00                	add    %al,(%rax)
  4002ec:	12 00                	adc    (%rax),%al
	...
  4002fe:	00 00                	add    %al,(%rax)
  400300:	1e                   	(bad)  
  400301:	00 00                	add    %al,(%rax)
  400303:	00 12                	add    %dl,(%rdx)
	...
  400315:	00 00                	add    %al,(%rax)
  400317:	00 30                	add    %dh,(%rax)
  400319:	00 00                	add    %al,(%rax)
  40031b:	00 20                	add    %ah,(%rax)
	...
  40032d:	00 00                	add    %al,(%rax)
  40032f:	00 17                	add    %dl,(%rdi)
  400331:	00 00                	add    %al,(%rax)
  400333:	00 12                	add    %dl,(%rdx)
	...

Disassembly of section .dynstr:

0000000000400348 <.dynstr>:
  400348:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40034c:	63 2e                	movslq (%rsi),%ebp
  40034e:	73 6f                	jae    4003bf <_init-0x91>
  400350:	2e 36 00 70 75       	cs add %dh,%cs:%ss:0x75(%rax)
  400355:	74 73                	je     4003ca <_init-0x86>
  400357:	00 70 72             	add    %dh,0x72(%rax)
  40035a:	69 6e 74 66 00 6d 61 	imul   $0x616d0066,0x74(%rsi),%ebp
  400361:	6c                   	insb   (%dx),%es:(%rdi)
  400362:	6c                   	insb   (%dx),%es:(%rdi)
  400363:	6f                   	outsl  %ds:(%rsi),(%dx)
  400364:	63 00                	movslq (%rax),%eax
  400366:	5f                   	pop    %rdi
  400367:	5f                   	pop    %rdi
  400368:	6c                   	insb   (%dx),%es:(%rdi)
  400369:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400370:	72 74                	jb     4003e6 <_init-0x6a>
  400372:	5f                   	pop    %rdi
  400373:	6d                   	insl   (%dx),%es:(%rdi)
  400374:	61                   	(bad)  
  400375:	69 6e 00 5f 5f 67 6d 	imul   $0x6d675f5f,0x0(%rsi),%ebp
  40037c:	6f                   	outsl  %ds:(%rsi),(%dx)
  40037d:	6e                   	outsb  %ds:(%rsi),(%dx)
  40037e:	5f                   	pop    %rdi
  40037f:	73 74                	jae    4003f5 <_init-0x5b>
  400381:	61                   	(bad)  
  400382:	72 74                	jb     4003f8 <_init-0x58>
  400384:	5f                   	pop    %rdi
  400385:	5f                   	pop    %rdi
  400386:	00 47 4c             	add    %al,0x4c(%rdi)
  400389:	49                   	rex.WB
  40038a:	42                   	rex.X
  40038b:	43 5f                	rex.XB pop %r15
  40038d:	32 2e                	xor    (%rsi),%ch
  40038f:	32 2e                	xor    (%rsi),%ch
  400391:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400394 <.gnu.version>:
  400394:	00 00                	add    %al,(%rax)
  400396:	02 00                	add    (%rax),%al
  400398:	02 00                	add    (%rax),%al
  40039a:	02 00                	add    (%rax),%al
  40039c:	00 00                	add    %al,(%rax)
  40039e:	02 00                	add    (%rax),%al

Disassembly of section .gnu.version_r:

00000000004003a0 <.gnu.version_r>:
  4003a0:	01 00                	add    %eax,(%rax)
  4003a2:	01 00                	add    %eax,(%rax)
  4003a4:	01 00                	add    %eax,(%rax)
  4003a6:	00 00                	add    %al,(%rax)
  4003a8:	10 00                	adc    %al,(%rax)
  4003aa:	00 00                	add    %al,(%rax)
  4003ac:	00 00                	add    %al,(%rax)
  4003ae:	00 00                	add    %al,(%rax)
  4003b0:	75 1a                	jne    4003cc <_init-0x84>
  4003b2:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  4003b8:	3f                   	(bad)  
  4003b9:	00 00                	add    %al,(%rax)
  4003bb:	00 00                	add    %al,(%rax)
  4003bd:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

00000000004003c0 <.rela.dyn>:
  4003c0:	f8                   	clc    
  4003c1:	1f                   	(bad)  
  4003c2:	60                   	(bad)  
  4003c3:	00 00                	add    %al,(%rax)
  4003c5:	00 00                	add    %al,(%rax)
  4003c7:	00 06                	add    %al,(%rsi)
  4003c9:	00 00                	add    %al,(%rax)
  4003cb:	00 04 00             	add    %al,(%rax,%rax,1)
	...

Disassembly of section .rela.plt:

00000000004003d8 <.rela.plt>:
  4003d8:	18 20                	sbb    %ah,(%rax)
  4003da:	60                   	(bad)  
  4003db:	00 00                	add    %al,(%rax)
  4003dd:	00 00                	add    %al,(%rax)
  4003df:	00 07                	add    %al,(%rdi)
  4003e1:	00 00                	add    %al,(%rax)
  4003e3:	00 01                	add    %al,(%rcx)
	...
  4003ed:	00 00                	add    %al,(%rax)
  4003ef:	00 20                	add    %ah,(%rax)
  4003f1:	20 60 00             	and    %ah,0x0(%rax)
  4003f4:	00 00                	add    %al,(%rax)
  4003f6:	00 00                	add    %al,(%rax)
  4003f8:	07                   	(bad)  
  4003f9:	00 00                	add    %al,(%rax)
  4003fb:	00 02                	add    %al,(%rdx)
	...
  400405:	00 00                	add    %al,(%rax)
  400407:	00 28                	add    %ch,(%rax)
  400409:	20 60 00             	and    %ah,0x0(%rax)
  40040c:	00 00                	add    %al,(%rax)
  40040e:	00 00                	add    %al,(%rax)
  400410:	07                   	(bad)  
  400411:	00 00                	add    %al,(%rax)
  400413:	00 03                	add    %al,(%rbx)
	...
  40041d:	00 00                	add    %al,(%rax)
  40041f:	00 30                	add    %dh,(%rax)
  400421:	20 60 00             	and    %ah,0x0(%rax)
  400424:	00 00                	add    %al,(%rax)
  400426:	00 00                	add    %al,(%rax)
  400428:	07                   	(bad)  
  400429:	00 00                	add    %al,(%rax)
  40042b:	00 04 00             	add    %al,(%rax,%rax,1)
	...
  400436:	00 00                	add    %al,(%rax)
  400438:	38 20                	cmp    %ah,(%rax)
  40043a:	60                   	(bad)  
  40043b:	00 00                	add    %al,(%rax)
  40043d:	00 00                	add    %al,(%rax)
  40043f:	00 07                	add    %al,(%rdi)
  400441:	00 00                	add    %al,(%rax)
  400443:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 400449 <_init-0x7>
  400449:	00 00                	add    %al,(%rax)
  40044b:	00 00                	add    %al,(%rax)
  40044d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init:

0000000000400450 <_init>:
  400450:	48 83 ec 08          	sub    $0x8,%rsp
  400454:	48 8b 05 9d 1b 20 00 	mov    0x201b9d(%rip),%rax        # 601ff8 <_DYNAMIC+0x1d0>
  40045b:	48 85 c0             	test   %rax,%rax
  40045e:	74 05                	je     400465 <_init+0x15>
  400460:	e8 4b 00 00 00       	callq  4004b0 <__gmon_start__@plt>
  400465:	48 83 c4 08          	add    $0x8,%rsp
  400469:	c3                   	retq   

Disassembly of section .plt:

0000000000400470 <puts@plt-0x10>:
  400470:	ff 35 92 1b 20 00    	pushq  0x201b92(%rip)        # 602008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400476:	ff 25 94 1b 20 00    	jmpq   *0x201b94(%rip)        # 602010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40047c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400480 <puts@plt>:
  400480:	ff 25 92 1b 20 00    	jmpq   *0x201b92(%rip)        # 602018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400486:	68 00 00 00 00       	pushq  $0x0
  40048b:	e9 e0 ff ff ff       	jmpq   400470 <_init+0x20>

0000000000400490 <printf@plt>:
  400490:	ff 25 8a 1b 20 00    	jmpq   *0x201b8a(%rip)        # 602020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400496:	68 01 00 00 00       	pushq  $0x1
  40049b:	e9 d0 ff ff ff       	jmpq   400470 <_init+0x20>

00000000004004a0 <__libc_start_main@plt>:
  4004a0:	ff 25 82 1b 20 00    	jmpq   *0x201b82(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  4004a6:	68 02 00 00 00       	pushq  $0x2
  4004ab:	e9 c0 ff ff ff       	jmpq   400470 <_init+0x20>

00000000004004b0 <__gmon_start__@plt>:
  4004b0:	ff 25 7a 1b 20 00    	jmpq   *0x201b7a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4004b6:	68 03 00 00 00       	pushq  $0x3
  4004bb:	e9 b0 ff ff ff       	jmpq   400470 <_init+0x20>

00000000004004c0 <malloc@plt>:
  4004c0:	ff 25 72 1b 20 00    	jmpq   *0x201b72(%rip)        # 602038 <_GLOBAL_OFFSET_TABLE_+0x38>
  4004c6:	68 04 00 00 00       	pushq  $0x4
  4004cb:	e9 a0 ff ff ff       	jmpq   400470 <_init+0x20>

Disassembly of section .text:

00000000004004d0 <_start>:
  4004d0:	31 ed                	xor    %ebp,%ebp
  4004d2:	49 89 d1             	mov    %rdx,%r9
  4004d5:	5e                   	pop    %rsi
  4004d6:	48 89 e2             	mov    %rsp,%rdx
  4004d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4004dd:	50                   	push   %rax
  4004de:	54                   	push   %rsp
  4004df:	49 c7 c0 20 09 40 00 	mov    $0x400920,%r8
  4004e6:	48 c7 c1 b0 08 40 00 	mov    $0x4008b0,%rcx
  4004ed:	48 c7 c7 e9 06 40 00 	mov    $0x4006e9,%rdi
  4004f4:	e8 a7 ff ff ff       	callq  4004a0 <__libc_start_main@plt>
  4004f9:	f4                   	hlt    
  4004fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400500 <deregister_tm_clones>:
  400500:	b8 57 20 60 00       	mov    $0x602057,%eax
  400505:	55                   	push   %rbp
  400506:	48 2d 50 20 60 00    	sub    $0x602050,%rax
  40050c:	48 83 f8 0e          	cmp    $0xe,%rax
  400510:	48 89 e5             	mov    %rsp,%rbp
  400513:	77 02                	ja     400517 <deregister_tm_clones+0x17>
  400515:	5d                   	pop    %rbp
  400516:	c3                   	retq   
  400517:	b8 00 00 00 00       	mov    $0x0,%eax
  40051c:	48 85 c0             	test   %rax,%rax
  40051f:	74 f4                	je     400515 <deregister_tm_clones+0x15>
  400521:	5d                   	pop    %rbp
  400522:	bf 50 20 60 00       	mov    $0x602050,%edi
  400527:	ff e0                	jmpq   *%rax
  400529:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400530 <register_tm_clones>:
  400530:	b8 50 20 60 00       	mov    $0x602050,%eax
  400535:	55                   	push   %rbp
  400536:	48 2d 50 20 60 00    	sub    $0x602050,%rax
  40053c:	48 c1 f8 03          	sar    $0x3,%rax
  400540:	48 89 e5             	mov    %rsp,%rbp
  400543:	48 89 c2             	mov    %rax,%rdx
  400546:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40054a:	48 01 d0             	add    %rdx,%rax
  40054d:	48 d1 f8             	sar    %rax
  400550:	75 02                	jne    400554 <register_tm_clones+0x24>
  400552:	5d                   	pop    %rbp
  400553:	c3                   	retq   
  400554:	ba 00 00 00 00       	mov    $0x0,%edx
  400559:	48 85 d2             	test   %rdx,%rdx
  40055c:	74 f4                	je     400552 <register_tm_clones+0x22>
  40055e:	5d                   	pop    %rbp
  40055f:	48 89 c6             	mov    %rax,%rsi
  400562:	bf 50 20 60 00       	mov    $0x602050,%edi
  400567:	ff e2                	jmpq   *%rdx
  400569:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400570 <__do_global_dtors_aux>:
  400570:	80 3d d9 1a 20 00 00 	cmpb   $0x0,0x201ad9(%rip)        # 602050 <__TMC_END__>
  400577:	75 11                	jne    40058a <__do_global_dtors_aux+0x1a>
  400579:	55                   	push   %rbp
  40057a:	48 89 e5             	mov    %rsp,%rbp
  40057d:	e8 7e ff ff ff       	callq  400500 <deregister_tm_clones>
  400582:	5d                   	pop    %rbp
  400583:	c6 05 c6 1a 20 00 01 	movb   $0x1,0x201ac6(%rip)        # 602050 <__TMC_END__>
  40058a:	f3 c3                	repz retq 
  40058c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400590 <frame_dummy>:
  400590:	48 83 3d 88 18 20 00 	cmpq   $0x0,0x201888(%rip)        # 601e20 <__JCR_END__>
  400597:	00 
  400598:	74 1e                	je     4005b8 <frame_dummy+0x28>
  40059a:	b8 00 00 00 00       	mov    $0x0,%eax
  40059f:	48 85 c0             	test   %rax,%rax
  4005a2:	74 14                	je     4005b8 <frame_dummy+0x28>
  4005a4:	55                   	push   %rbp
  4005a5:	bf 20 1e 60 00       	mov    $0x601e20,%edi
  4005aa:	48 89 e5             	mov    %rsp,%rbp
  4005ad:	ff d0                	callq  *%rax
  4005af:	5d                   	pop    %rbp
  4005b0:	e9 7b ff ff ff       	jmpq   400530 <register_tm_clones>
  4005b5:	0f 1f 00             	nopl   (%rax)
  4005b8:	e9 73 ff ff ff       	jmpq   400530 <register_tm_clones>

00000000004005bd <max>:
  4005bd:	55                   	push   %rbp
  4005be:	48 89 e5             	mov    %rsp,%rbp
  4005c1:	48 83 ec 30          	sub    $0x30,%rsp
  4005c5:	89 7d dc             	mov    %edi,-0x24(%rbp)
  4005c8:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  4005cf:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  4005d6:	bf 0a 00 00 00       	mov    $0xa,%edi
  4005db:	e8 e0 fe ff ff       	callq  4004c0 <malloc@plt>
  4005e0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4005e4:	bf 38 09 40 00       	mov    $0x400938,%edi
  4005e9:	e8 92 fe ff ff       	callq  400480 <puts@plt>
  4005ee:	be bd 05 40 00       	mov    $0x4005bd,%esi
  4005f3:	bf 4e 09 40 00       	mov    $0x40094e,%edi
  4005f8:	b8 00 00 00 00       	mov    $0x0,%eax
  4005fd:	e8 8e fe ff ff       	callq  400490 <printf@plt>
  400602:	bf 68 09 40 00       	mov    $0x400968,%edi
  400607:	e8 74 fe ff ff       	callq  400480 <puts@plt>
  40060c:	48 8d 45 dc          	lea    -0x24(%rbp),%rax
  400610:	48 89 c6             	mov    %rax,%rsi
  400613:	bf 87 09 40 00       	mov    $0x400987,%edi
  400618:	b8 00 00 00 00       	mov    $0x0,%eax
  40061d:	e8 6e fe ff ff       	callq  400490 <printf@plt>
  400622:	bf a0 09 40 00       	mov    $0x4009a0,%edi
  400627:	e8 54 fe ff ff       	callq  400480 <puts@plt>
  40062c:	be 5c 20 60 00       	mov    $0x60205c,%esi
  400631:	bf c5 09 40 00       	mov    $0x4009c5,%edi
  400636:	b8 00 00 00 00       	mov    $0x0,%eax
  40063b:	e8 50 fe ff ff       	callq  400490 <printf@plt>
  400640:	be 60 20 60 00       	mov    $0x602060,%esi
  400645:	bf d9 09 40 00       	mov    $0x4009d9,%edi
  40064a:	b8 00 00 00 00       	mov    $0x0,%eax
  40064f:	e8 3c fe ff ff       	callq  400490 <printf@plt>
  400654:	be 64 20 60 00       	mov    $0x602064,%esi
  400659:	bf ed 09 40 00       	mov    $0x4009ed,%edi
  40065e:	b8 00 00 00 00       	mov    $0x0,%eax
  400663:	e8 28 fe ff ff       	callq  400490 <printf@plt>
  400668:	bf 08 0a 40 00       	mov    $0x400a08,%edi
  40066d:	e8 0e fe ff ff       	callq  400480 <puts@plt>
  400672:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
  400676:	48 89 c6             	mov    %rax,%rsi
  400679:	bf 2d 0a 40 00       	mov    $0x400a2d,%edi
  40067e:	b8 00 00 00 00       	mov    $0x0,%eax
  400683:	e8 08 fe ff ff       	callq  400490 <printf@plt>
  400688:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  40068c:	48 89 c6             	mov    %rax,%rsi
  40068f:	bf 41 0a 40 00       	mov    $0x400a41,%edi
  400694:	b8 00 00 00 00       	mov    $0x0,%eax
  400699:	e8 f2 fd ff ff       	callq  400490 <printf@plt>
  40069e:	48 8d 45 f4          	lea    -0xc(%rbp),%rax
  4006a2:	48 89 c6             	mov    %rax,%rsi
  4006a5:	bf 55 0a 40 00       	mov    $0x400a55,%edi
  4006aa:	b8 00 00 00 00       	mov    $0x0,%eax
  4006af:	e8 dc fd ff ff       	callq  400490 <printf@plt>
  4006b4:	bf 70 0a 40 00       	mov    $0x400a70,%edi
  4006b9:	e8 c2 fd ff ff       	callq  400480 <puts@plt>
  4006be:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4006c2:	48 89 c6             	mov    %rax,%rsi
  4006c5:	bf 98 0a 40 00       	mov    $0x400a98,%edi
  4006ca:	b8 00 00 00 00       	mov    $0x0,%eax
  4006cf:	e8 bc fd ff ff       	callq  400490 <printf@plt>
  4006d4:	8b 45 dc             	mov    -0x24(%rbp),%eax
  4006d7:	85 c0                	test   %eax,%eax
  4006d9:	74 07                	je     4006e2 <max+0x125>
  4006db:	b8 01 00 00 00       	mov    $0x1,%eax
  4006e0:	eb 05                	jmp    4006e7 <max+0x12a>
  4006e2:	b8 00 00 00 00       	mov    $0x0,%eax
  4006e7:	c9                   	leaveq 
  4006e8:	c3                   	retq   

00000000004006e9 <main>:
  4006e9:	55                   	push   %rbp
  4006ea:	48 89 e5             	mov    %rsp,%rbp
  4006ed:	48 83 ec 30          	sub    $0x30,%rsp
  4006f1:	89 7d dc             	mov    %edi,-0x24(%rbp)
  4006f4:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  4006f8:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
  4006ff:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  400706:	bf 0a 00 00 00       	mov    $0xa,%edi
  40070b:	e8 b0 fd ff ff       	callq  4004c0 <malloc@plt>
  400710:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400714:	bf b0 0a 40 00       	mov    $0x400ab0,%edi
  400719:	e8 62 fd ff ff       	callq  400480 <puts@plt>
  40071e:	be 54 20 60 00       	mov    $0x602054,%esi
  400723:	bf e7 0a 40 00       	mov    $0x400ae7,%edi
  400728:	b8 00 00 00 00       	mov    $0x0,%eax
  40072d:	e8 5e fd ff ff       	callq  400490 <printf@plt>
  400732:	be 74 20 60 00       	mov    $0x602074,%esi
  400737:	bf fb 0a 40 00       	mov    $0x400afb,%edi
  40073c:	b8 00 00 00 00       	mov    $0x0,%eax
  400741:	e8 4a fd ff ff       	callq  400490 <printf@plt>
  400746:	be 58 20 60 00       	mov    $0x602058,%esi
  40074b:	bf 0f 0b 40 00       	mov    $0x400b0f,%edi
  400750:	b8 00 00 00 00       	mov    $0x0,%eax
  400755:	e8 36 fd ff ff       	callq  400490 <printf@plt>
  40075a:	bf 28 0b 40 00       	mov    $0x400b28,%edi
  40075f:	e8 1c fd ff ff       	callq  400480 <puts@plt>
  400764:	bf 60 0b 40 00       	mov    $0x400b60,%edi
  400769:	e8 12 fd ff ff       	callq  400480 <puts@plt>
  40076e:	be e9 06 40 00       	mov    $0x4006e9,%esi
  400773:	bf 83 0b 40 00       	mov    $0x400b83,%edi
  400778:	b8 00 00 00 00       	mov    $0x0,%eax
  40077d:	e8 0e fd ff ff       	callq  400490 <printf@plt>
  400782:	bf 98 0b 40 00       	mov    $0x400b98,%edi
  400787:	e8 f4 fc ff ff       	callq  400480 <puts@plt>
  40078c:	48 8d 45 dc          	lea    -0x24(%rbp),%rax
  400790:	48 89 c6             	mov    %rax,%rsi
  400793:	bf ae 0b 40 00       	mov    $0x400bae,%edi
  400798:	b8 00 00 00 00       	mov    $0x0,%eax
  40079d:	e8 ee fc ff ff       	callq  400490 <printf@plt>
  4007a2:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  4007a6:	48 89 c6             	mov    %rax,%rsi
  4007a9:	bf c3 0b 40 00       	mov    $0x400bc3,%edi
  4007ae:	b8 00 00 00 00       	mov    $0x0,%eax
  4007b3:	e8 d8 fc ff ff       	callq  400490 <printf@plt>
  4007b8:	bf d8 0b 40 00       	mov    $0x400bd8,%edi
  4007bd:	e8 be fc ff ff       	callq  400480 <puts@plt>
  4007c2:	be 68 20 60 00       	mov    $0x602068,%esi
  4007c7:	bf fd 0b 40 00       	mov    $0x400bfd,%edi
  4007cc:	b8 00 00 00 00       	mov    $0x0,%eax
  4007d1:	e8 ba fc ff ff       	callq  400490 <printf@plt>
  4007d6:	be 6c 20 60 00       	mov    $0x60206c,%esi
  4007db:	bf 11 0c 40 00       	mov    $0x400c11,%edi
  4007e0:	b8 00 00 00 00       	mov    $0x0,%eax
  4007e5:	e8 a6 fc ff ff       	callq  400490 <printf@plt>
  4007ea:	be 70 20 60 00       	mov    $0x602070,%esi
  4007ef:	bf 25 0c 40 00       	mov    $0x400c25,%edi
  4007f4:	b8 00 00 00 00       	mov    $0x0,%eax
  4007f9:	e8 92 fc ff ff       	callq  400490 <printf@plt>
  4007fe:	bf 40 0c 40 00       	mov    $0x400c40,%edi
  400803:	e8 78 fc ff ff       	callq  400480 <puts@plt>
  400808:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
  40080c:	48 89 c6             	mov    %rax,%rsi
  40080f:	bf 65 0c 40 00       	mov    $0x400c65,%edi
  400814:	b8 00 00 00 00       	mov    $0x0,%eax
  400819:	e8 72 fc ff ff       	callq  400490 <printf@plt>
  40081e:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  400822:	48 89 c6             	mov    %rax,%rsi
  400825:	bf 79 0c 40 00       	mov    $0x400c79,%edi
  40082a:	b8 00 00 00 00       	mov    $0x0,%eax
  40082f:	e8 5c fc ff ff       	callq  400490 <printf@plt>
  400834:	48 8d 45 f4          	lea    -0xc(%rbp),%rax
  400838:	48 89 c6             	mov    %rax,%rsi
  40083b:	bf 8d 0c 40 00       	mov    $0x400c8d,%edi
  400840:	b8 00 00 00 00       	mov    $0x0,%eax
  400845:	e8 46 fc ff ff       	callq  400490 <printf@plt>
  40084a:	bf a8 0c 40 00       	mov    $0x400ca8,%edi
  40084f:	e8 2c fc ff ff       	callq  400480 <puts@plt>
  400854:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400858:	48 89 c6             	mov    %rax,%rsi
  40085b:	bf cd 0c 40 00       	mov    $0x400ccd,%edi
  400860:	b8 00 00 00 00       	mov    $0x0,%eax
  400865:	e8 26 fc ff ff       	callq  400490 <printf@plt>
  40086a:	bf 28 0b 40 00       	mov    $0x400b28,%edi
  40086f:	e8 0c fc ff ff       	callq  400480 <puts@plt>
  400874:	8b 45 ec             	mov    -0x14(%rbp),%eax
  400877:	89 c7                	mov    %eax,%edi
  400879:	e8 3f fd ff ff       	callq  4005bd <max>
  40087e:	bf 28 0b 40 00       	mov    $0x400b28,%edi
  400883:	e8 f8 fb ff ff       	callq  400480 <puts@plt>
  400888:	bf e2 0c 40 00       	mov    $0x400ce2,%edi
  40088d:	e8 ee fb ff ff       	callq  400480 <puts@plt>
  400892:	be bd 05 40 00       	mov    $0x4005bd,%esi
  400897:	bf fe 0c 40 00       	mov    $0x400cfe,%edi
  40089c:	b8 00 00 00 00       	mov    $0x0,%eax
  4008a1:	e8 ea fb ff ff       	callq  400490 <printf@plt>
  4008a6:	b8 00 00 00 00       	mov    $0x0,%eax
  4008ab:	c9                   	leaveq 
  4008ac:	c3                   	retq   
  4008ad:	0f 1f 00             	nopl   (%rax)

00000000004008b0 <__libc_csu_init>:
  4008b0:	41 57                	push   %r15
  4008b2:	41 89 ff             	mov    %edi,%r15d
  4008b5:	41 56                	push   %r14
  4008b7:	49 89 f6             	mov    %rsi,%r14
  4008ba:	41 55                	push   %r13
  4008bc:	49 89 d5             	mov    %rdx,%r13
  4008bf:	41 54                	push   %r12
  4008c1:	4c 8d 25 48 15 20 00 	lea    0x201548(%rip),%r12        # 601e10 <__frame_dummy_init_array_entry>
  4008c8:	55                   	push   %rbp
  4008c9:	48 8d 2d 48 15 20 00 	lea    0x201548(%rip),%rbp        # 601e18 <__init_array_end>
  4008d0:	53                   	push   %rbx
  4008d1:	4c 29 e5             	sub    %r12,%rbp
  4008d4:	31 db                	xor    %ebx,%ebx
  4008d6:	48 c1 fd 03          	sar    $0x3,%rbp
  4008da:	48 83 ec 08          	sub    $0x8,%rsp
  4008de:	e8 6d fb ff ff       	callq  400450 <_init>
  4008e3:	48 85 ed             	test   %rbp,%rbp
  4008e6:	74 1e                	je     400906 <__libc_csu_init+0x56>
  4008e8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4008ef:	00 
  4008f0:	4c 89 ea             	mov    %r13,%rdx
  4008f3:	4c 89 f6             	mov    %r14,%rsi
  4008f6:	44 89 ff             	mov    %r15d,%edi
  4008f9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4008fd:	48 83 c3 01          	add    $0x1,%rbx
  400901:	48 39 eb             	cmp    %rbp,%rbx
  400904:	75 ea                	jne    4008f0 <__libc_csu_init+0x40>
  400906:	48 83 c4 08          	add    $0x8,%rsp
  40090a:	5b                   	pop    %rbx
  40090b:	5d                   	pop    %rbp
  40090c:	41 5c                	pop    %r12
  40090e:	41 5d                	pop    %r13
  400910:	41 5e                	pop    %r14
  400912:	41 5f                	pop    %r15
  400914:	c3                   	retq   
  400915:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40091c:	00 00 00 00 

0000000000400920 <__libc_csu_fini>:
  400920:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400924 <_fini>:
  400924:	48 83 ec 08          	sub    $0x8,%rsp
  400928:	48 83 c4 08          	add    $0x8,%rsp
  40092c:	c3                   	retq   

Disassembly of section .rodata:

0000000000400930 <_IO_stdin_used>:
  400930:	01 00                	add    %eax,(%rax)
  400932:	02 00                	add    (%rax),%al
  400934:	00 00                	add    %al,(%rax)
  400936:	00 00                	add    %al,(%rax)
  400938:	e6 89                	out    %al,$0x89
  40093a:	93                   	xchg   %eax,%ebx
  40093b:	e5 8d                	in     $0x8d,%eax
  40093d:	b0 6d                	mov    $0x6d,%al
  40093f:	61                   	(bad)  
  400940:	78 e7                	js     400929 <_fini+0x5>
  400942:	a8 8b                	test   $0x8b,%al
  400944:	e5 ba                	in     $0xba,%eax
  400946:	8f                   	(bad)  
  400947:	e5 9c                	in     $0x9c,%eax
  400949:	b0 e5                	mov    $0xe5,%al
  40094b:	9d                   	popfq  
  40094c:	80 00 69             	addb   $0x69,(%rax)
  40094f:	6e                   	outsb  %ds:(%rsi),(%dx)
  400950:	20 6d 61             	and    %ch,0x61(%rbp)
  400953:	78 3a                	js     40098f <_IO_stdin_used+0x5f>
  400955:	20 20                	and    %ah,(%rax)
  400957:	20 20                	and    %ah,(%rax)
  400959:	20 30                	and    %dh,(%rax)
  40095b:	78 25                	js     400982 <_IO_stdin_used+0x52>
  40095d:	30 38                	xor    %bh,(%rax)
  40095f:	78 0a                	js     40096b <_IO_stdin_used+0x3b>
  400961:	0a 00                	or     (%rax),%al
  400963:	00 00                	add    %al,(%rax)
  400965:	00 00                	add    %al,(%rax)
  400967:	00 e6                	add    %ah,%dh
  400969:	89 93 e5 8d b0 6d    	mov    %edx,0x6db08de5(%rbx)
  40096f:	61                   	(bad)  
  400970:	78 e4                	js     400956 <_IO_stdin_used+0x26>
  400972:	bc a0 e5 85 a5       	mov    $0xa585e5a0,%esp
  400977:	e5 8f                	in     $0x8f,%eax
  400979:	82                   	(bad)  
  40097a:	e6 95                	out    %al,$0x95
  40097c:	b0 e7                	mov    $0xe7,%al
  40097e:	9a                   	(bad)  
  40097f:	84 e5                	test   %ah,%ch
  400981:	9c                   	pushfq 
  400982:	b0 e5                	mov    $0xe5,%al
  400984:	9d                   	popfq  
  400985:	80 00 69             	addb   $0x69,(%rax)
  400988:	6e                   	outsb  %ds:(%rsi),(%dx)
  400989:	20 6d 61             	and    %ch,0x61(%rbp)
  40098c:	78 2c                	js     4009ba <_IO_stdin_used+0x8a>
  40098e:	20 69 3a             	and    %ch,0x3a(%rcx)
  400991:	20 20                	and    %ah,(%rax)
  400993:	30 78 25             	xor    %bh,0x25(%rax)
  400996:	30 38                	xor    %bh,(%rax)
  400998:	78 0a                	js     4009a4 <_IO_stdin_used+0x74>
  40099a:	0a 00                	or     (%rax),%al
  40099c:	00 00                	add    %al,(%rax)
  40099e:	00 00                	add    %al,(%rax)
  4009a0:	e6 89                	out    %al,$0x89
  4009a2:	93                   	xchg   %eax,%ebx
  4009a3:	e5 8d                	in     $0x8d,%eax
  4009a5:	b0 6d                	mov    $0x6d,%al
  4009a7:	61                   	(bad)  
  4009a8:	78 e5                	js     40098f <_IO_stdin_used+0x5f>
  4009aa:	87 bd e6 95 b0 e4    	xchg   %edi,-0x1b4f6a1a(%rbp)
  4009b0:	b8 ad e9 9d 99       	mov    $0x999de9ad,%eax
  4009b5:	e6 80                	out    %al,$0x80
  4009b7:	81 e5 8f 98 e9 87    	and    $0x87e9988f,%ebp
  4009bd:	8f                   	(bad)  
  4009be:	e5 9c                	in     $0x9c,%eax
  4009c0:	b0 e5                	mov    $0xe5,%al
  4009c2:	9d                   	popfq  
  4009c3:	80 00 6e             	addb   $0x6e,(%rax)
  4009c6:	31 5f 6d             	xor    %ebx,0x6d(%rdi)
  4009c9:	61                   	(bad)  
  4009ca:	78 3a                	js     400a06 <_IO_stdin_used+0xd6>
  4009cc:	20 20                	and    %ah,(%rax)
  4009ce:	20 20                	and    %ah,(%rax)
  4009d0:	20 30                	and    %dh,(%rax)
  4009d2:	78 25                	js     4009f9 <_IO_stdin_used+0xc9>
  4009d4:	30 38                	xor    %bh,(%rax)
  4009d6:	78 0a                	js     4009e2 <_IO_stdin_used+0xb2>
  4009d8:	00 6e 32             	add    %ch,0x32(%rsi)
  4009db:	5f                   	pop    %rdi
  4009dc:	6d                   	insl   (%dx),%es:(%rdi)
  4009dd:	61                   	(bad)  
  4009de:	78 3a                	js     400a1a <_IO_stdin_used+0xea>
  4009e0:	20 20                	and    %ah,(%rax)
  4009e2:	20 20                	and    %ah,(%rax)
  4009e4:	20 30                	and    %dh,(%rax)
  4009e6:	78 25                	js     400a0d <_IO_stdin_used+0xdd>
  4009e8:	30 38                	xor    %bh,(%rax)
  4009ea:	78 0a                	js     4009f6 <_IO_stdin_used+0xc6>
  4009ec:	00 6e 33             	add    %ch,0x33(%rsi)
  4009ef:	5f                   	pop    %rdi
  4009f0:	6d                   	insl   (%dx),%es:(%rdi)
  4009f1:	61                   	(bad)  
  4009f2:	78 3a                	js     400a2e <_IO_stdin_used+0xfe>
  4009f4:	20 20                	and    %ah,(%rax)
  4009f6:	20 20                	and    %ah,(%rax)
  4009f8:	20 30                	and    %dh,(%rax)
  4009fa:	78 25                	js     400a21 <_IO_stdin_used+0xf1>
  4009fc:	30 38                	xor    %bh,(%rax)
  4009fe:	78 0a                	js     400a0a <_IO_stdin_used+0xda>
  400a00:	0a 00                	or     (%rax),%al
  400a02:	00 00                	add    %al,(%rax)
  400a04:	00 00                	add    %al,(%rax)
  400a06:	00 00                	add    %al,(%rax)
  400a08:	e6 89                	out    %al,$0x89
  400a0a:	93                   	xchg   %eax,%ebx
  400a0b:	e5 8d                	in     $0x8d,%eax
  400a0d:	b0 6d                	mov    $0x6d,%al
  400a0f:	61                   	(bad)  
  400a10:	78 e5                	js     4009f7 <_IO_stdin_used+0xc7>
  400a12:	87 bd e6 95 b0 e4    	xchg   %edi,-0x1b4f6a1a(%rbp)
  400a18:	b8 ad e5 b1 80       	mov    $0x80b1e5ad,%eax
  400a1d:	e9 83 a8 e5 8f       	jmpq   ffffffff9025b2a5 <_end+0xffffffff8fc5922d>
  400a22:	98                   	cwtl   
  400a23:	e9 87 8f e5 9c       	jmpq   ffffffff9d2599af <_end+0xffffffff9cc57937>
  400a28:	b0 e5                	mov    $0xe5,%al
  400a2a:	9d                   	popfq  
  400a2b:	80 00 6d             	addb   $0x6d,(%rax)
  400a2e:	31 3a                	xor    %edi,(%rdx)
  400a30:	20 20                	and    %ah,(%rax)
  400a32:	20 20                	and    %ah,(%rax)
  400a34:	20 20                	and    %ah,(%rax)
  400a36:	20 20                	and    %ah,(%rax)
  400a38:	20 30                	and    %dh,(%rax)
  400a3a:	78 25                	js     400a61 <_IO_stdin_used+0x131>
  400a3c:	30 38                	xor    %bh,(%rax)
  400a3e:	78 0a                	js     400a4a <_IO_stdin_used+0x11a>
  400a40:	00 6d 32             	add    %ch,0x32(%rbp)
  400a43:	3a 20                	cmp    (%rax),%ah
  400a45:	20 20                	and    %ah,(%rax)
  400a47:	20 20                	and    %ah,(%rax)
  400a49:	20 20                	and    %ah,(%rax)
  400a4b:	20 20                	and    %ah,(%rax)
  400a4d:	30 78 25             	xor    %bh,0x25(%rax)
  400a50:	30 38                	xor    %bh,(%rax)
  400a52:	78 0a                	js     400a5e <_IO_stdin_used+0x12e>
  400a54:	00 6d 33             	add    %ch,0x33(%rbp)
  400a57:	3a 20                	cmp    (%rax),%ah
  400a59:	20 20                	and    %ah,(%rax)
  400a5b:	20 20                	and    %ah,(%rax)
  400a5d:	20 20                	and    %ah,(%rax)
  400a5f:	20 20                	and    %ah,(%rax)
  400a61:	30 78 25             	xor    %bh,0x25(%rax)
  400a64:	30 38                	xor    %bh,(%rax)
  400a66:	78 0a                	js     400a72 <_IO_stdin_used+0x142>
  400a68:	0a 00                	or     (%rax),%al
  400a6a:	00 00                	add    %al,(%rax)
  400a6c:	00 00                	add    %al,(%rax)
  400a6e:	00 00                	add    %al,(%rax)
  400a70:	e6 89                	out    %al,$0x89
  400a72:	93                   	xchg   %eax,%ebx
  400a73:	e5 8d                	in     $0x8d,%eax
  400a75:	b0 6d                	mov    $0x6d,%al
  400a77:	61                   	(bad)  
  400a78:	78 e5                	js     400a5f <_IO_stdin_used+0x12f>
  400a7a:	87 bd e6 95 b0 e4    	xchg   %edi,-0x1b4f6a1a(%rbp)
  400a80:	b8 ad 6d 61 6c       	mov    $0x6c616dad,%eax
  400a85:	6c                   	insb   (%dx),%es:(%rdi)
  400a86:	6f                   	outsl  %ds:(%rsi),(%dx)
  400a87:	63 e5                	movslq %ebp,%esp
  400a89:	88 86 e9 85 8d e7    	mov    %al,-0x18727a17(%rsi)
  400a8f:	9a                   	(bad)  
  400a90:	84 e5                	test   %ah,%ch
  400a92:	9c                   	pushfq 
  400a93:	b0 e5                	mov    $0xe5,%al
  400a95:	9d                   	popfq  
  400a96:	80 00 70             	addb   $0x70,(%rax)
  400a99:	5f                   	pop    %rdi
  400a9a:	6d                   	insl   (%dx),%es:(%rdi)
  400a9b:	61                   	(bad)  
  400a9c:	78 3a                	js     400ad8 <_IO_stdin_used+0x1a8>
  400a9e:	20 20                	and    %ah,(%rax)
  400aa0:	20 20                	and    %ah,(%rax)
  400aa2:	20 20                	and    %ah,(%rax)
  400aa4:	30 78 25             	xor    %bh,0x25(%rax)
  400aa7:	30 38                	xor    %bh,(%rax)
  400aa9:	78 0a                	js     400ab5 <_IO_stdin_used+0x185>
  400aab:	0a 00                	or     (%rax),%al
  400aad:	00 00                	add    %al,(%rax)
  400aaf:	00 e6                	add    %ah,%dh
  400ab1:	89 93 e5 8d b0 e5    	mov    %edx,-0x1a4f721b(%rbx)
  400ab7:	90                   	nop
  400ab8:	84 e5                	test   %ah,%ch
  400aba:	85 a8 e5 b1 80 e5    	test   %ebp,-0x1a7f4e1b(%rax)
  400ac0:	8f                   	(bad)  
  400ac1:	98                   	cwtl   
  400ac2:	e9 87 8f ef bc       	jmpq   ffffffffbd2f9a4e <_end+0xffffffffbccf79d6>
  400ac7:	88 e5                	mov    %ah,%ch
  400ac9:	b7 b2                	mov    $0xb2,%bh
  400acb:	e5 88                	in     $0x88,%eax
  400acd:	9d                   	popfq  
  400ace:	e5 a7                	in     $0xa7,%eax
  400ad0:	8b e5                	mov    %ebp,%esp
  400ad2:	8c 96 ef bc 89 e7    	mov    %ss,-0x18764311(%rsi)
  400ad8:	9a                   	(bad)  
  400ad9:	84 e5                	test   %ah,%ch
  400adb:	86 85 e5 ad 98 e5    	xchg   %al,-0x1a67521b(%rbp)
  400ae1:	9c                   	pushfq 
  400ae2:	b0 e5                	mov    $0xe5,%al
  400ae4:	9d                   	popfq  
  400ae5:	80 00 67             	addb   $0x67,(%rax)
  400ae8:	31 3a                	xor    %edi,(%rdx)
  400aea:	20 20                	and    %ah,(%rax)
  400aec:	20 20                	and    %ah,(%rax)
  400aee:	20 20                	and    %ah,(%rax)
  400af0:	20 20                	and    %ah,(%rax)
  400af2:	20 30                	and    %dh,(%rax)
  400af4:	78 25                	js     400b1b <_IO_stdin_used+0x1eb>
  400af6:	30 38                	xor    %bh,(%rax)
  400af8:	78 0a                	js     400b04 <_IO_stdin_used+0x1d4>
  400afa:	00 67 32             	add    %ah,0x32(%rdi)
  400afd:	3a 20                	cmp    (%rax),%ah
  400aff:	20 20                	and    %ah,(%rax)
  400b01:	20 20                	and    %ah,(%rax)
  400b03:	20 20                	and    %ah,(%rax)
  400b05:	20 20                	and    %ah,(%rax)
  400b07:	30 78 25             	xor    %bh,0x25(%rax)
  400b0a:	30 38                	xor    %bh,(%rax)
  400b0c:	78 0a                	js     400b18 <_IO_stdin_used+0x1e8>
  400b0e:	00 67 33             	add    %ah,0x33(%rdi)
  400b11:	3a 20                	cmp    (%rax),%ah
  400b13:	20 20                	and    %ah,(%rax)
  400b15:	20 20                	and    %ah,(%rax)
  400b17:	20 20                	and    %ah,(%rax)
  400b19:	20 20                	and    %ah,(%rax)
  400b1b:	30 78 25             	xor    %bh,0x25(%rax)
  400b1e:	30 38                	xor    %bh,(%rax)
  400b20:	78 0a                	js     400b2c <_IO_stdin_used+0x1fc>
  400b22:	0a 00                	or     (%rax),%al
  400b24:	00 00                	add    %al,(%rax)
  400b26:	00 00                	add    %al,(%rax)
  400b28:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b2d:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b32:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b37:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b3c:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b41:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b46:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b4b:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b50:	3d 3d 3d 3d 3d       	cmp    $0x3d3d3d3d,%eax
  400b55:	3d 3d 3d 3d 00       	cmp    $0x3d3d3d,%eax
  400b5a:	00 00                	add    %al,(%rax)
  400b5c:	00 00                	add    %al,(%rax)
  400b5e:	00 00                	add    %al,(%rax)
  400b60:	e6 89                	out    %al,$0x89
  400b62:	93                   	xchg   %eax,%ebx
  400b63:	e5 8d                	in     $0x8d,%eax
  400b65:	b0 e7                	mov    $0xe7,%al
  400b67:	a8 8b                	test   $0x8b,%al
  400b69:	e5 ba                	in     $0xba,%eax
  400b6b:	8f                   	(bad)  
  400b6c:	e5 88                	in     $0x88,%eax
  400b6e:	9d                   	popfq  
  400b6f:	e5 a7                	in     $0xa7,%eax
  400b71:	8b e7                	mov    %edi,%esp
  400b73:	a8 8b                	test   $0x8b,%al
  400b75:	e5 ba                	in     $0xba,%eax
  400b77:	8f                   	(bad)  
  400b78:	6d                   	insl   (%dx),%es:(%rdi)
  400b79:	61                   	(bad)  
  400b7a:	69 6e e5 9c b0 e5 9d 	imul   $0x9de5b09c,-0x1b(%rsi),%ebp
  400b81:	80 00 6d             	addb   $0x6d,(%rax)
  400b84:	61                   	(bad)  
  400b85:	69 6e 3a 20 20 20 20 	imul   $0x20202020,0x3a(%rsi),%ebp
  400b8c:	20 20                	and    %ah,(%rax)
  400b8e:	20 30                	and    %dh,(%rax)
  400b90:	78 25                	js     400bb7 <_IO_stdin_used+0x287>
  400b92:	30 38                	xor    %bh,(%rax)
  400b94:	78 0a                	js     400ba0 <_IO_stdin_used+0x270>
  400b96:	0a 00                	or     (%rax),%al
  400b98:	e6 89                	out    %al,$0x89
  400b9a:	93                   	xchg   %eax,%ebx
  400b9b:	e5 8d                	in     $0x8d,%eax
  400b9d:	b0 e4                	mov    $0xe4,%al
  400b9f:	b8 bb e5 8f 82       	mov    $0x828fe5bb,%eax
  400ba4:	e6 95                	out    %al,$0x95
  400ba6:	b0 e5                	mov    $0xe5,%al
  400ba8:	9c                   	pushfq 
  400ba9:	b0 e5                	mov    $0xe5,%al
  400bab:	9d                   	popfq  
  400bac:	80 00 61             	addb   $0x61,(%rax)
  400baf:	72 67                	jb     400c18 <_IO_stdin_used+0x2e8>
  400bb1:	63 3a                	movslq (%rdx),%edi
  400bb3:	20 20                	and    %ah,(%rax)
  400bb5:	20 20                	and    %ah,(%rax)
  400bb7:	20 20                	and    %ah,(%rax)
  400bb9:	20 30                	and    %dh,(%rax)
  400bbb:	78 25                	js     400be2 <_IO_stdin_used+0x2b2>
  400bbd:	30 38                	xor    %bh,(%rax)
  400bbf:	78 0a                	js     400bcb <_IO_stdin_used+0x29b>
  400bc1:	0a 00                	or     (%rax),%al
  400bc3:	61                   	(bad)  
  400bc4:	72 67                	jb     400c2d <_IO_stdin_used+0x2fd>
  400bc6:	76 3a                	jbe    400c02 <_IO_stdin_used+0x2d2>
  400bc8:	20 20                	and    %ah,(%rax)
  400bca:	20 20                	and    %ah,(%rax)
  400bcc:	20 20                	and    %ah,(%rax)
  400bce:	20 30                	and    %dh,(%rax)
  400bd0:	78 25                	js     400bf7 <_IO_stdin_used+0x2c7>
  400bd2:	30 38                	xor    %bh,(%rax)
  400bd4:	78 0a                	js     400be0 <_IO_stdin_used+0x2b0>
  400bd6:	0a 00                	or     (%rax),%al
  400bd8:	e6 89                	out    %al,$0x89
  400bda:	93                   	xchg   %eax,%ebx
  400bdb:	e5 8d                	in     $0x8d,%eax
  400bdd:	b0 e5                	mov    $0xe5,%al
  400bdf:	90                   	nop
  400be0:	84 e9                	test   %ch,%cl
  400be2:	9d                   	popfq  
  400be3:	99                   	cltd   
  400be4:	e6 80                	out    %al,$0x80
  400be6:	81 e5 8f 98 e9 87    	and    $0x87e9988f,%ebp
  400bec:	8f                   	(bad)  
  400bed:	e7 9a                	out    %eax,$0x9a
  400bef:	84 e5                	test   %ah,%ch
  400bf1:	86 85 e5 ad 98 e5    	xchg   %al,-0x1a67521b(%rbp)
  400bf7:	9c                   	pushfq 
  400bf8:	b0 e5                	mov    $0xe5,%al
  400bfa:	9d                   	popfq  
  400bfb:	80 00 73             	addb   $0x73,(%rax)
  400bfe:	31 3a                	xor    %edi,(%rdx)
  400c00:	20 20                	and    %ah,(%rax)
  400c02:	20 20                	and    %ah,(%rax)
  400c04:	20 20                	and    %ah,(%rax)
  400c06:	20 20                	and    %ah,(%rax)
  400c08:	20 30                	and    %dh,(%rax)
  400c0a:	78 25                	js     400c31 <_IO_stdin_used+0x301>
  400c0c:	30 38                	xor    %bh,(%rax)
  400c0e:	78 0a                	js     400c1a <_IO_stdin_used+0x2ea>
  400c10:	00 73 32             	add    %dh,0x32(%rbx)
  400c13:	3a 20                	cmp    (%rax),%ah
  400c15:	20 20                	and    %ah,(%rax)
  400c17:	20 20                	and    %ah,(%rax)
  400c19:	20 20                	and    %ah,(%rax)
  400c1b:	20 20                	and    %ah,(%rax)
  400c1d:	30 78 25             	xor    %bh,0x25(%rax)
  400c20:	30 38                	xor    %bh,(%rax)
  400c22:	78 0a                	js     400c2e <_IO_stdin_used+0x2fe>
  400c24:	00 73 33             	add    %dh,0x33(%rbx)
  400c27:	3a 20                	cmp    (%rax),%ah
  400c29:	20 20                	and    %ah,(%rax)
  400c2b:	20 20                	and    %ah,(%rax)
  400c2d:	20 20                	and    %ah,(%rax)
  400c2f:	20 20                	and    %ah,(%rax)
  400c31:	30 78 25             	xor    %bh,0x25(%rax)
  400c34:	30 38                	xor    %bh,(%rax)
  400c36:	78 0a                	js     400c42 <_IO_stdin_used+0x312>
  400c38:	0a 00                	or     (%rax),%al
  400c3a:	00 00                	add    %al,(%rax)
  400c3c:	00 00                	add    %al,(%rax)
  400c3e:	00 00                	add    %al,(%rax)
  400c40:	e6 89                	out    %al,$0x89
  400c42:	93                   	xchg   %eax,%ebx
  400c43:	e5 8d                	in     $0x8d,%eax
  400c45:	b0 e5                	mov    $0xe5,%al
  400c47:	90                   	nop
  400c48:	84 e5                	test   %ah,%ch
  400c4a:	b1 80                	mov    $0x80,%cl
  400c4c:	e9 83 a8 e5 8f       	jmpq   ffffffff9025b4d4 <_end+0xffffffff8fc5945c>
  400c51:	98                   	cwtl   
  400c52:	e9 87 8f e7 9a       	jmpq   ffffffff9b279bde <_end+0xffffffff9ac77b66>
  400c57:	84 e5                	test   %ah,%ch
  400c59:	86 85 e5 ad 98 e5    	xchg   %al,-0x1a67521b(%rbp)
  400c5f:	9c                   	pushfq 
  400c60:	b0 e5                	mov    $0xe5,%al
  400c62:	9d                   	popfq  
  400c63:	80 00 76             	addb   $0x76,(%rax)
  400c66:	31 3a                	xor    %edi,(%rdx)
  400c68:	20 20                	and    %ah,(%rax)
  400c6a:	20 20                	and    %ah,(%rax)
  400c6c:	20 20                	and    %ah,(%rax)
  400c6e:	20 20                	and    %ah,(%rax)
  400c70:	20 30                	and    %dh,(%rax)
  400c72:	78 25                	js     400c99 <_IO_stdin_used+0x369>
  400c74:	30 38                	xor    %bh,(%rax)
  400c76:	78 0a                	js     400c82 <_IO_stdin_used+0x352>
  400c78:	00 76 32             	add    %dh,0x32(%rsi)
  400c7b:	3a 20                	cmp    (%rax),%ah
  400c7d:	20 20                	and    %ah,(%rax)
  400c7f:	20 20                	and    %ah,(%rax)
  400c81:	20 20                	and    %ah,(%rax)
  400c83:	20 20                	and    %ah,(%rax)
  400c85:	30 78 25             	xor    %bh,0x25(%rax)
  400c88:	30 38                	xor    %bh,(%rax)
  400c8a:	78 0a                	js     400c96 <_IO_stdin_used+0x366>
  400c8c:	00 76 33             	add    %dh,0x33(%rsi)
  400c8f:	3a 20                	cmp    (%rax),%ah
  400c91:	20 20                	and    %ah,(%rax)
  400c93:	20 20                	and    %ah,(%rax)
  400c95:	20 20                	and    %ah,(%rax)
  400c97:	20 20                	and    %ah,(%rax)
  400c99:	30 78 25             	xor    %bh,0x25(%rax)
  400c9c:	30 38                	xor    %bh,(%rax)
  400c9e:	78 0a                	js     400caa <_IO_stdin_used+0x37a>
  400ca0:	0a 00                	or     (%rax),%al
  400ca2:	00 00                	add    %al,(%rax)
  400ca4:	00 00                	add    %al,(%rax)
  400ca6:	00 00                	add    %al,(%rax)
  400ca8:	e6 89                	out    %al,$0x89
  400caa:	93                   	xchg   %eax,%ebx
  400cab:	e5 8d                	in     $0x8d,%eax
  400cad:	b0 6d                	mov    $0x6d,%al
  400caf:	61                   	(bad)  
  400cb0:	6c                   	insb   (%dx),%es:(%rdi)
  400cb1:	6c                   	insb   (%dx),%es:(%rdi)
  400cb2:	6f                   	outsl  %ds:(%rsi),(%dx)
  400cb3:	63 e5                	movslq %ebp,%esp
  400cb5:	88 86 e9 85 8d e7    	mov    %al,-0x18727a17(%rsi)
  400cbb:	9a                   	(bad)  
  400cbc:	84 e5                	test   %ah,%ch
  400cbe:	a0 86 e5 86 85 e5 ad 	movabs 0xe598ade58586e586,%al
  400cc5:	98 e5 
  400cc7:	9c                   	pushfq 
  400cc8:	b0 e5                	mov    $0xe5,%al
  400cca:	9d                   	popfq  
  400ccb:	80 00 70             	addb   $0x70,(%rax)
  400cce:	3a 20                	cmp    (%rax),%ah
  400cd0:	20 20                	and    %ah,(%rax)
  400cd2:	20 20                	and    %ah,(%rax)
  400cd4:	20 20                	and    %ah,(%rax)
  400cd6:	20 20                	and    %ah,(%rax)
  400cd8:	20 30                	and    %dh,(%rax)
  400cda:	78 25                	js     400d01 <_IO_stdin_used+0x3d1>
  400cdc:	30 38                	xor    %bh,(%rax)
  400cde:	78 0a                	js     400cea <_IO_stdin_used+0x3ba>
  400ce0:	0a 00                	or     (%rax),%al
  400ce2:	e6 89                	out    %al,$0x89
  400ce4:	93                   	xchg   %eax,%ebx
  400ce5:	e5 8d                	in     $0x8d,%eax
  400ce7:	b0 e5                	mov    $0xe5,%al
  400ce9:	ad                   	lods   %ds:(%rsi),%eax
  400cea:	90                   	nop
  400ceb:	e5 87                	in     $0x87,%eax
  400ced:	bd e6 95 b0 e8       	mov    $0xe8b095e6,%ebp
  400cf2:	b5 b7                	mov    $0xb7,%ch
  400cf4:	e5 a7                	in     $0xa7,%eax
  400cf6:	8b e5                	mov    %ebp,%esp
  400cf8:	9c                   	pushfq 
  400cf9:	b0 e5                	mov    $0xe5,%al
  400cfb:	9d                   	popfq  
  400cfc:	80 00 6d             	addb   $0x6d,(%rax)
  400cff:	61                   	(bad)  
  400d00:	78 3a                	js     400d3c <_IO_stdin_used+0x40c>
  400d02:	20 20                	and    %ah,(%rax)
  400d04:	20 20                	and    %ah,(%rax)
  400d06:	20 20                	and    %ah,(%rax)
  400d08:	20 20                	and    %ah,(%rax)
  400d0a:	30 78 25             	xor    %bh,0x25(%rax)
  400d0d:	30 38                	xor    %bh,(%rax)
  400d0f:	78 0a                	js     400d1b <_IO_stdin_used+0x3eb>
  400d11:	0a 00                	or     (%rax),%al

Disassembly of section .eh_frame_hdr:

0000000000400d14 <.eh_frame_hdr>:
  400d14:	01 1b                	add    %ebx,(%rbx)
  400d16:	03 3b                	add    (%rbx),%edi
  400d18:	38 00                	cmp    %al,(%rax)
  400d1a:	00 00                	add    %al,(%rax)
  400d1c:	06                   	(bad)  
  400d1d:	00 00                	add    %al,(%rax)
  400d1f:	00 5c f7 ff          	add    %bl,-0x1(%rdi,%rsi,8)
  400d23:	ff 84 00 00 00 bc f7 	incl   -0x8440000(%rax,%rax,1)
  400d2a:	ff                   	(bad)  
  400d2b:	ff 54 00 00          	callq  *0x0(%rax,%rax,1)
  400d2f:	00 a9 f8 ff ff ac    	add    %ch,-0x53000008(%rcx)
  400d35:	00 00                	add    %al,(%rax)
  400d37:	00 d5                	add    %dl,%ch
  400d39:	f9                   	stc    
  400d3a:	ff                   	(bad)  
  400d3b:	ff cc                	dec    %esp
  400d3d:	00 00                	add    %al,(%rax)
  400d3f:	00 9c fb ff ff ec 00 	add    %bl,0xecffff(%rbx,%rdi,8)
  400d46:	00 00                	add    %al,(%rax)
  400d48:	0c fc                	or     $0xfc,%al
  400d4a:	ff                   	(bad)  
  400d4b:	ff 34 01             	pushq  (%rcx,%rax,1)
	...

Disassembly of section .eh_frame:

0000000000400d50 <__FRAME_END__-0x110>:
  400d50:	14 00                	adc    $0x0,%al
  400d52:	00 00                	add    %al,(%rax)
  400d54:	00 00                	add    %al,(%rax)
  400d56:	00 00                	add    %al,(%rax)
  400d58:	01 7a 52             	add    %edi,0x52(%rdx)
  400d5b:	00 01                	add    %al,(%rcx)
  400d5d:	78 10                	js     400d6f <_IO_stdin_used+0x43f>
  400d5f:	01 1b                	add    %ebx,(%rbx)
  400d61:	0c 07                	or     $0x7,%al
  400d63:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
  400d69:	00 00                	add    %al,(%rax)
  400d6b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  400d6e:	00 00                	add    %al,(%rax)
  400d70:	60                   	(bad)  
  400d71:	f7 ff                	idiv   %edi
  400d73:	ff 2a                	ljmpq  *(%rdx)
	...
  400d7d:	00 00                	add    %al,(%rax)
  400d7f:	00 14 00             	add    %dl,(%rax,%rax,1)
  400d82:	00 00                	add    %al,(%rax)
  400d84:	00 00                	add    %al,(%rax)
  400d86:	00 00                	add    %al,(%rax)
  400d88:	01 7a 52             	add    %edi,0x52(%rdx)
  400d8b:	00 01                	add    %al,(%rcx)
  400d8d:	78 10                	js     400d9f <_IO_stdin_used+0x46f>
  400d8f:	01 1b                	add    %ebx,(%rbx)
  400d91:	0c 07                	or     $0x7,%al
  400d93:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  400d99:	00 00                	add    %al,(%rax)
  400d9b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  400d9e:	00 00                	add    %al,(%rax)
  400da0:	d0                   	(bad)  
  400da1:	f6 ff                	idiv   %bh
  400da3:	ff 60 00             	jmpq   *0x0(%rax)
  400da6:	00 00                	add    %al,(%rax)
  400da8:	00 0e                	add    %cl,(%rsi)
  400daa:	10 46 0e             	adc    %al,0xe(%rsi)
  400dad:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  400db0:	0b 77 08             	or     0x8(%rdi),%esi
  400db3:	80 00 3f             	addb   $0x3f,(%rax)
  400db6:	1a 3b                	sbb    (%rbx),%bh
  400db8:	2a 33                	sub    (%rbx),%dh
  400dba:	24 22                	and    $0x22,%al
  400dbc:	00 00                	add    %al,(%rax)
  400dbe:	00 00                	add    %al,(%rax)
  400dc0:	1c 00                	sbb    $0x0,%al
  400dc2:	00 00                	add    %al,(%rax)
  400dc4:	44 00 00             	add    %r8b,(%rax)
  400dc7:	00 f5                	add    %dh,%ch
  400dc9:	f7 ff                	idiv   %edi
  400dcb:	ff 2c 01             	ljmpq  *(%rcx,%rax,1)
  400dce:	00 00                	add    %al,(%rax)
  400dd0:	00 41 0e             	add    %al,0xe(%rcx)
  400dd3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400dd9:	03 27                	add    (%rdi),%esp
  400ddb:	01 0c 07             	add    %ecx,(%rdi,%rax,1)
  400dde:	08 00                	or     %al,(%rax)
  400de0:	1c 00                	sbb    $0x0,%al
  400de2:	00 00                	add    %al,(%rax)
  400de4:	64 00 00             	add    %al,%fs:(%rax)
  400de7:	00 01                	add    %al,(%rcx)
  400de9:	f9                   	stc    
  400dea:	ff                   	(bad)  
  400deb:	ff c4                	inc    %esp
  400ded:	01 00                	add    %eax,(%rax)
  400def:	00 00                	add    %al,(%rax)
  400df1:	41 0e                	rex.B (bad) 
  400df3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  400df9:	03 bf 01 0c 07 08    	add    0x8070c01(%rdi),%edi
  400dff:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
  400e03:	00 84 00 00 00 a8 fa 	add    %al,-0x5580000(%rax,%rax,1)
  400e0a:	ff                   	(bad)  
  400e0b:	ff 65 00             	jmpq   *0x0(%rbp)
  400e0e:	00 00                	add    %al,(%rax)
  400e10:	00 42 0e             	add    %al,0xe(%rdx)
  400e13:	10 8f 02 45 0e 18    	adc    %cl,0x180e4502(%rdi)
  400e19:	8e 03                	mov    (%rbx),%es
  400e1b:	45 0e                	rex.RB (bad) 
  400e1d:	20 8d 04 45 0e 28    	and    %cl,0x280e4504(%rbp)
  400e23:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86701c71 <_end+0xffffffff860ffbf9>
  400e29:	06                   	(bad)  
  400e2a:	48 0e                	rex.W (bad) 
  400e2c:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
  400e32:	6c                   	insb   (%dx),%es:(%rdi)
  400e33:	0e                   	(bad)  
  400e34:	38 41 0e             	cmp    %al,0xe(%rcx)
  400e37:	30 41 0e             	xor    %al,0xe(%rcx)
  400e3a:	28 42 0e             	sub    %al,0xe(%rdx)
  400e3d:	20 42 0e             	and    %al,0xe(%rdx)
  400e40:	18 42 0e             	sbb    %al,0xe(%rdx)
  400e43:	10 42 0e             	adc    %al,0xe(%rdx)
  400e46:	08 00                	or     %al,(%rax)
  400e48:	14 00                	adc    $0x0,%al
  400e4a:	00 00                	add    %al,(%rax)
  400e4c:	cc                   	int3   
  400e4d:	00 00                	add    %al,(%rax)
  400e4f:	00 d0                	add    %dl,%al
  400e51:	fa                   	cli    
  400e52:	ff                   	(bad)  
  400e53:	ff 02                	incl   (%rdx)
	...

0000000000400e60 <__FRAME_END__>:
  400e60:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000601e10 <__frame_dummy_init_array_entry>:
  601e10:	90                   	nop
  601e11:	05 40 00 00 00       	add    $0x40,%eax
	...

Disassembly of section .fini_array:

0000000000601e18 <__do_global_dtors_aux_fini_array_entry>:
  601e18:	70 05                	jo     601e1f <__do_global_dtors_aux_fini_array_entry+0x7>
  601e1a:	40 00 00             	add    %al,(%rax)
  601e1d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .jcr:

0000000000601e20 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000601e28 <_DYNAMIC>:
  601e28:	01 00                	add    %eax,(%rax)
  601e2a:	00 00                	add    %al,(%rax)
  601e2c:	00 00                	add    %al,(%rax)
  601e2e:	00 00                	add    %al,(%rax)
  601e30:	01 00                	add    %eax,(%rax)
  601e32:	00 00                	add    %al,(%rax)
  601e34:	00 00                	add    %al,(%rax)
  601e36:	00 00                	add    %al,(%rax)
  601e38:	0c 00                	or     $0x0,%al
  601e3a:	00 00                	add    %al,(%rax)
  601e3c:	00 00                	add    %al,(%rax)
  601e3e:	00 00                	add    %al,(%rax)
  601e40:	50                   	push   %rax
  601e41:	04 40                	add    $0x40,%al
  601e43:	00 00                	add    %al,(%rax)
  601e45:	00 00                	add    %al,(%rax)
  601e47:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 601e4d <_DYNAMIC+0x25>
  601e4d:	00 00                	add    %al,(%rax)
  601e4f:	00 24 09             	add    %ah,(%rcx,%rcx,1)
  601e52:	40 00 00             	add    %al,(%rax)
  601e55:	00 00                	add    %al,(%rax)
  601e57:	00 19                	add    %bl,(%rcx)
  601e59:	00 00                	add    %al,(%rax)
  601e5b:	00 00                	add    %al,(%rax)
  601e5d:	00 00                	add    %al,(%rax)
  601e5f:	00 10                	add    %dl,(%rax)
  601e61:	1e                   	(bad)  
  601e62:	60                   	(bad)  
  601e63:	00 00                	add    %al,(%rax)
  601e65:	00 00                	add    %al,(%rax)
  601e67:	00 1b                	add    %bl,(%rbx)
  601e69:	00 00                	add    %al,(%rax)
  601e6b:	00 00                	add    %al,(%rax)
  601e6d:	00 00                	add    %al,(%rax)
  601e6f:	00 08                	add    %cl,(%rax)
  601e71:	00 00                	add    %al,(%rax)
  601e73:	00 00                	add    %al,(%rax)
  601e75:	00 00                	add    %al,(%rax)
  601e77:	00 1a                	add    %bl,(%rdx)
  601e79:	00 00                	add    %al,(%rax)
  601e7b:	00 00                	add    %al,(%rax)
  601e7d:	00 00                	add    %al,(%rax)
  601e7f:	00 18                	add    %bl,(%rax)
  601e81:	1e                   	(bad)  
  601e82:	60                   	(bad)  
  601e83:	00 00                	add    %al,(%rax)
  601e85:	00 00                	add    %al,(%rax)
  601e87:	00 1c 00             	add    %bl,(%rax,%rax,1)
  601e8a:	00 00                	add    %al,(%rax)
  601e8c:	00 00                	add    %al,(%rax)
  601e8e:	00 00                	add    %al,(%rax)
  601e90:	08 00                	or     %al,(%rax)
  601e92:	00 00                	add    %al,(%rax)
  601e94:	00 00                	add    %al,(%rax)
  601e96:	00 00                	add    %al,(%rax)
  601e98:	f5                   	cmc    
  601e99:	fe                   	(bad)  
  601e9a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  601e9d:	00 00                	add    %al,(%rax)
  601e9f:	00 98 02 40 00 00    	add    %bl,0x4002(%rax)
  601ea5:	00 00                	add    %al,(%rax)
  601ea7:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 601ead <_DYNAMIC+0x85>
  601ead:	00 00                	add    %al,(%rax)
  601eaf:	00 48 03             	add    %cl,0x3(%rax)
  601eb2:	40 00 00             	add    %al,(%rax)
  601eb5:	00 00                	add    %al,(%rax)
  601eb7:	00 06                	add    %al,(%rsi)
  601eb9:	00 00                	add    %al,(%rax)
  601ebb:	00 00                	add    %al,(%rax)
  601ebd:	00 00                	add    %al,(%rax)
  601ebf:	00 b8 02 40 00 00    	add    %bh,0x4002(%rax)
  601ec5:	00 00                	add    %al,(%rax)
  601ec7:	00 0a                	add    %cl,(%rdx)
  601ec9:	00 00                	add    %al,(%rax)
  601ecb:	00 00                	add    %al,(%rax)
  601ecd:	00 00                	add    %al,(%rax)
  601ecf:	00 4b 00             	add    %cl,0x0(%rbx)
  601ed2:	00 00                	add    %al,(%rax)
  601ed4:	00 00                	add    %al,(%rax)
  601ed6:	00 00                	add    %al,(%rax)
  601ed8:	0b 00                	or     (%rax),%eax
  601eda:	00 00                	add    %al,(%rax)
  601edc:	00 00                	add    %al,(%rax)
  601ede:	00 00                	add    %al,(%rax)
  601ee0:	18 00                	sbb    %al,(%rax)
  601ee2:	00 00                	add    %al,(%rax)
  601ee4:	00 00                	add    %al,(%rax)
  601ee6:	00 00                	add    %al,(%rax)
  601ee8:	15 00 00 00 00       	adc    $0x0,%eax
	...
  601ef5:	00 00                	add    %al,(%rax)
  601ef7:	00 03                	add    %al,(%rbx)
	...
  601f01:	20 60 00             	and    %ah,0x0(%rax)
  601f04:	00 00                	add    %al,(%rax)
  601f06:	00 00                	add    %al,(%rax)
  601f08:	02 00                	add    (%rax),%al
  601f0a:	00 00                	add    %al,(%rax)
  601f0c:	00 00                	add    %al,(%rax)
  601f0e:	00 00                	add    %al,(%rax)
  601f10:	78 00                	js     601f12 <_DYNAMIC+0xea>
  601f12:	00 00                	add    %al,(%rax)
  601f14:	00 00                	add    %al,(%rax)
  601f16:	00 00                	add    %al,(%rax)
  601f18:	14 00                	adc    $0x0,%al
  601f1a:	00 00                	add    %al,(%rax)
  601f1c:	00 00                	add    %al,(%rax)
  601f1e:	00 00                	add    %al,(%rax)
  601f20:	07                   	(bad)  
  601f21:	00 00                	add    %al,(%rax)
  601f23:	00 00                	add    %al,(%rax)
  601f25:	00 00                	add    %al,(%rax)
  601f27:	00 17                	add    %dl,(%rdi)
  601f29:	00 00                	add    %al,(%rax)
  601f2b:	00 00                	add    %al,(%rax)
  601f2d:	00 00                	add    %al,(%rax)
  601f2f:	00 d8                	add    %bl,%al
  601f31:	03 40 00             	add    0x0(%rax),%eax
  601f34:	00 00                	add    %al,(%rax)
  601f36:	00 00                	add    %al,(%rax)
  601f38:	07                   	(bad)  
  601f39:	00 00                	add    %al,(%rax)
  601f3b:	00 00                	add    %al,(%rax)
  601f3d:	00 00                	add    %al,(%rax)
  601f3f:	00 c0                	add    %al,%al
  601f41:	03 40 00             	add    0x0(%rax),%eax
  601f44:	00 00                	add    %al,(%rax)
  601f46:	00 00                	add    %al,(%rax)
  601f48:	08 00                	or     %al,(%rax)
  601f4a:	00 00                	add    %al,(%rax)
  601f4c:	00 00                	add    %al,(%rax)
  601f4e:	00 00                	add    %al,(%rax)
  601f50:	18 00                	sbb    %al,(%rax)
  601f52:	00 00                	add    %al,(%rax)
  601f54:	00 00                	add    %al,(%rax)
  601f56:	00 00                	add    %al,(%rax)
  601f58:	09 00                	or     %eax,(%rax)
  601f5a:	00 00                	add    %al,(%rax)
  601f5c:	00 00                	add    %al,(%rax)
  601f5e:	00 00                	add    %al,(%rax)
  601f60:	18 00                	sbb    %al,(%rax)
  601f62:	00 00                	add    %al,(%rax)
  601f64:	00 00                	add    %al,(%rax)
  601f66:	00 00                	add    %al,(%rax)
  601f68:	fe                   	(bad)  
  601f69:	ff                   	(bad)  
  601f6a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  601f6d:	00 00                	add    %al,(%rax)
  601f6f:	00 a0 03 40 00 00    	add    %ah,0x4003(%rax)
  601f75:	00 00                	add    %al,(%rax)
  601f77:	00 ff                	add    %bh,%bh
  601f79:	ff                   	(bad)  
  601f7a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  601f7d:	00 00                	add    %al,(%rax)
  601f7f:	00 01                	add    %al,(%rcx)
  601f81:	00 00                	add    %al,(%rax)
  601f83:	00 00                	add    %al,(%rax)
  601f85:	00 00                	add    %al,(%rax)
  601f87:	00 f0                	add    %dh,%al
  601f89:	ff                   	(bad)  
  601f8a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  601f8d:	00 00                	add    %al,(%rax)
  601f8f:	00 94 03 40 00 00 00 	add    %dl,0x40(%rbx,%rax,1)
	...

Disassembly of section .got:

0000000000601ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000602000 <_GLOBAL_OFFSET_TABLE_>:
  602000:	28 1e                	sub    %bl,(%rsi)
  602002:	60                   	(bad)  
	...
  602017:	00 86 04 40 00 00    	add    %al,0x4004(%rsi)
  60201d:	00 00                	add    %al,(%rax)
  60201f:	00 96 04 40 00 00    	add    %dl,0x4004(%rsi)
  602025:	00 00                	add    %al,(%rax)
  602027:	00 a6 04 40 00 00    	add    %ah,0x4004(%rsi)
  60202d:	00 00                	add    %al,(%rax)
  60202f:	00 b6 04 40 00 00    	add    %dh,0x4004(%rsi)
  602035:	00 00                	add    %al,(%rax)
  602037:	00 c6                	add    %al,%dh
  602039:	04 40                	add    $0x40,%al
  60203b:	00 00                	add    %al,(%rax)
  60203d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000602040 <__data_start>:
	...

0000000000602048 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000602050 <__bss_start>:
  602050:	00 00                	add    %al,(%rax)
	...

0000000000602054 <g1>:
  602054:	00 00                	add    %al,(%rax)
	...

0000000000602058 <g3>:
  602058:	00 00                	add    %al,(%rax)
	...

000000000060205c <n1_max.2186>:
  60205c:	00 00                	add    %al,(%rax)
	...

0000000000602060 <n2_max.2187>:
  602060:	00 00                	add    %al,(%rax)
	...

0000000000602064 <n3_max.2188>:
  602064:	00 00                	add    %al,(%rax)
	...

0000000000602068 <s1.2194>:
  602068:	00 00                	add    %al,(%rax)
	...

000000000060206c <s2.2195>:
  60206c:	00 00                	add    %al,(%rax)
	...

0000000000602070 <s3.2196>:
  602070:	00 00                	add    %al,(%rax)
	...

0000000000602074 <g2>:
  602074:	00 00                	add    %al,(%rax)
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x4003d8>
   a:	74 75                	je     81 <_init-0x4003cf>
   c:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
   f:	38 2e                	cmp    %ch,(%rsi)
  11:	32 2d 31 39 75 62    	xor    0x62753931(%rip),%ch        # 62753948 <_end+0x621518d0>
  17:	75 6e                	jne    87 <_init-0x4003c9>
  19:	74 75                	je     90 <_init-0x4003c0>
  1b:	31 29                	xor    %ebp,(%rcx)
  1d:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
  20:	38 2e                	cmp    %ch,(%rsi)
  22:	32 00                	xor    (%rax),%al
