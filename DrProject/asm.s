
a.out:     file format elf32-i386


Disassembly of section .init:

08048294 <_init>:
 8048294:	53                   	push   %ebx
 8048295:	83 ec 08             	sub    $0x8,%esp
 8048298:	e8 83 00 00 00       	call   8048320 <__x86.get_pc_thunk.bx>
 804829d:	81 c3 63 1d 00 00    	add    $0x1d63,%ebx
 80482a3:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80482a9:	85 c0                	test   %eax,%eax
 80482ab:	74 05                	je     80482b2 <_init+0x1e>
 80482ad:	e8 1e 00 00 00       	call   80482d0 <__gmon_start__@plt>
 80482b2:	83 c4 08             	add    $0x8,%esp
 80482b5:	5b                   	pop    %ebx
 80482b6:	c3                   	ret    

Disassembly of section .plt:

080482c0 <__gmon_start__@plt-0x10>:
 80482c0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80482c6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80482cc:	00 00                	add    %al,(%eax)
	...

080482d0 <__gmon_start__@plt>:
 80482d0:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 80482d6:	68 00 00 00 00       	push   $0x0
 80482db:	e9 e0 ff ff ff       	jmp    80482c0 <_init+0x2c>

080482e0 <__libc_start_main@plt>:
 80482e0:	ff 25 10 a0 04 08    	jmp    *0x804a010
 80482e6:	68 08 00 00 00       	push   $0x8
 80482eb:	e9 d0 ff ff ff       	jmp    80482c0 <_init+0x2c>

Disassembly of section .text:

080482f0 <_start>:
 80482f0:	31 ed                	xor    %ebp,%ebp
 80482f2:	5e                   	pop    %esi
 80482f3:	89 e1                	mov    %esp,%ecx
 80482f5:	83 e4 f0             	and    $0xfffffff0,%esp
 80482f8:	50                   	push   %eax
 80482f9:	54                   	push   %esp
 80482fa:	52                   	push   %edx
 80482fb:	68 90 84 04 08       	push   $0x8048490
 8048300:	68 20 84 04 08       	push   $0x8048420
 8048305:	51                   	push   %ecx
 8048306:	56                   	push   %esi
 8048307:	68 ed 83 04 08       	push   $0x80483ed
 804830c:	e8 cf ff ff ff       	call   80482e0 <__libc_start_main@plt>
 8048311:	f4                   	hlt    
 8048312:	66 90                	xchg   %ax,%ax
 8048314:	66 90                	xchg   %ax,%ax
 8048316:	66 90                	xchg   %ax,%ax
 8048318:	66 90                	xchg   %ax,%ax
 804831a:	66 90                	xchg   %ax,%ax
 804831c:	66 90                	xchg   %ax,%ax
 804831e:	66 90                	xchg   %ax,%ax

08048320 <__x86.get_pc_thunk.bx>:
 8048320:	8b 1c 24             	mov    (%esp),%ebx
 8048323:	c3                   	ret    
 8048324:	66 90                	xchg   %ax,%ax
 8048326:	66 90                	xchg   %ax,%ax
 8048328:	66 90                	xchg   %ax,%ax
 804832a:	66 90                	xchg   %ax,%ax
 804832c:	66 90                	xchg   %ax,%ax
 804832e:	66 90                	xchg   %ax,%ax

08048330 <deregister_tm_clones>:
 8048330:	b8 1f a0 04 08       	mov    $0x804a01f,%eax
 8048335:	2d 1c a0 04 08       	sub    $0x804a01c,%eax
 804833a:	83 f8 06             	cmp    $0x6,%eax
 804833d:	77 01                	ja     8048340 <deregister_tm_clones+0x10>
 804833f:	c3                   	ret    
 8048340:	b8 00 00 00 00       	mov    $0x0,%eax
 8048345:	85 c0                	test   %eax,%eax
 8048347:	74 f6                	je     804833f <deregister_tm_clones+0xf>
 8048349:	55                   	push   %ebp
 804834a:	89 e5                	mov    %esp,%ebp
 804834c:	83 ec 18             	sub    $0x18,%esp
 804834f:	c7 04 24 1c a0 04 08 	movl   $0x804a01c,(%esp)
 8048356:	ff d0                	call   *%eax
 8048358:	c9                   	leave  
 8048359:	c3                   	ret    
 804835a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

08048360 <register_tm_clones>:
 8048360:	b8 1c a0 04 08       	mov    $0x804a01c,%eax
 8048365:	2d 1c a0 04 08       	sub    $0x804a01c,%eax
 804836a:	c1 f8 02             	sar    $0x2,%eax
 804836d:	89 c2                	mov    %eax,%edx
 804836f:	c1 ea 1f             	shr    $0x1f,%edx
 8048372:	01 d0                	add    %edx,%eax
 8048374:	d1 f8                	sar    %eax
 8048376:	75 01                	jne    8048379 <register_tm_clones+0x19>
 8048378:	c3                   	ret    
 8048379:	ba 00 00 00 00       	mov    $0x0,%edx
 804837e:	85 d2                	test   %edx,%edx
 8048380:	74 f6                	je     8048378 <register_tm_clones+0x18>
 8048382:	55                   	push   %ebp
 8048383:	89 e5                	mov    %esp,%ebp
 8048385:	83 ec 18             	sub    $0x18,%esp
 8048388:	89 44 24 04          	mov    %eax,0x4(%esp)
 804838c:	c7 04 24 1c a0 04 08 	movl   $0x804a01c,(%esp)
 8048393:	ff d2                	call   *%edx
 8048395:	c9                   	leave  
 8048396:	c3                   	ret    
 8048397:	89 f6                	mov    %esi,%esi
 8048399:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080483a0 <__do_global_dtors_aux>:
 80483a0:	80 3d 1c a0 04 08 00 	cmpb   $0x0,0x804a01c
 80483a7:	75 13                	jne    80483bc <__do_global_dtors_aux+0x1c>
 80483a9:	55                   	push   %ebp
 80483aa:	89 e5                	mov    %esp,%ebp
 80483ac:	83 ec 08             	sub    $0x8,%esp
 80483af:	e8 7c ff ff ff       	call   8048330 <deregister_tm_clones>
 80483b4:	c6 05 1c a0 04 08 01 	movb   $0x1,0x804a01c
 80483bb:	c9                   	leave  
 80483bc:	f3 c3                	repz ret 
 80483be:	66 90                	xchg   %ax,%ax

080483c0 <frame_dummy>:
 80483c0:	a1 10 9f 04 08       	mov    0x8049f10,%eax
 80483c5:	85 c0                	test   %eax,%eax
 80483c7:	74 1f                	je     80483e8 <frame_dummy+0x28>
 80483c9:	b8 00 00 00 00       	mov    $0x0,%eax
 80483ce:	85 c0                	test   %eax,%eax
 80483d0:	74 16                	je     80483e8 <frame_dummy+0x28>
 80483d2:	55                   	push   %ebp
 80483d3:	89 e5                	mov    %esp,%ebp
 80483d5:	83 ec 18             	sub    $0x18,%esp
 80483d8:	c7 04 24 10 9f 04 08 	movl   $0x8049f10,(%esp)
 80483df:	ff d0                	call   *%eax
 80483e1:	c9                   	leave  
 80483e2:	e9 79 ff ff ff       	jmp    8048360 <register_tm_clones>
 80483e7:	90                   	nop
 80483e8:	e9 73 ff ff ff       	jmp    8048360 <register_tm_clones>

080483ed <main>:
 80483ed:	55                   	push   %ebp
 80483ee:	89 e5                	mov    %esp,%ebp
 80483f0:	83 ec 10             	sub    $0x10,%esp
 80483f3:	c7 45 f8 01 00 00 00 	movl   $0x1,-0x8(%ebp)
 80483fa:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80483fd:	89 45 fc             	mov    %eax,-0x4(%ebp)
 8048400:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
 8048404:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
 8048408:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%ebp)
 804840f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048414:	c9                   	leave  
 8048415:	c3                   	ret    
 8048416:	66 90                	xchg   %ax,%ax
 8048418:	66 90                	xchg   %ax,%ax
 804841a:	66 90                	xchg   %ax,%ax
 804841c:	66 90                	xchg   %ax,%ax
 804841e:	66 90                	xchg   %ax,%ax

08048420 <__libc_csu_init>:
 8048420:	55                   	push   %ebp
 8048421:	57                   	push   %edi
 8048422:	31 ff                	xor    %edi,%edi
 8048424:	56                   	push   %esi
 8048425:	53                   	push   %ebx
 8048426:	e8 f5 fe ff ff       	call   8048320 <__x86.get_pc_thunk.bx>
 804842b:	81 c3 d5 1b 00 00    	add    $0x1bd5,%ebx
 8048431:	83 ec 1c             	sub    $0x1c,%esp
 8048434:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8048438:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804843e:	e8 51 fe ff ff       	call   8048294 <_init>
 8048443:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048449:	29 c6                	sub    %eax,%esi
 804844b:	c1 fe 02             	sar    $0x2,%esi
 804844e:	85 f6                	test   %esi,%esi
 8048450:	74 27                	je     8048479 <__libc_csu_init+0x59>
 8048452:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048458:	8b 44 24 38          	mov    0x38(%esp),%eax
 804845c:	89 2c 24             	mov    %ebp,(%esp)
 804845f:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048463:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048467:	89 44 24 04          	mov    %eax,0x4(%esp)
 804846b:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 8048472:	83 c7 01             	add    $0x1,%edi
 8048475:	39 f7                	cmp    %esi,%edi
 8048477:	75 df                	jne    8048458 <__libc_csu_init+0x38>
 8048479:	83 c4 1c             	add    $0x1c,%esp
 804847c:	5b                   	pop    %ebx
 804847d:	5e                   	pop    %esi
 804847e:	5f                   	pop    %edi
 804847f:	5d                   	pop    %ebp
 8048480:	c3                   	ret    
 8048481:	eb 0d                	jmp    8048490 <__libc_csu_fini>
 8048483:	90                   	nop
 8048484:	90                   	nop
 8048485:	90                   	nop
 8048486:	90                   	nop
 8048487:	90                   	nop
 8048488:	90                   	nop
 8048489:	90                   	nop
 804848a:	90                   	nop
 804848b:	90                   	nop
 804848c:	90                   	nop
 804848d:	90                   	nop
 804848e:	90                   	nop
 804848f:	90                   	nop

08048490 <__libc_csu_fini>:
 8048490:	f3 c3                	repz ret 

Disassembly of section .fini:

08048494 <_fini>:
 8048494:	53                   	push   %ebx
 8048495:	83 ec 08             	sub    $0x8,%esp
 8048498:	e8 83 fe ff ff       	call   8048320 <__x86.get_pc_thunk.bx>
 804849d:	81 c3 63 1b 00 00    	add    $0x1b63,%ebx
 80484a3:	83 c4 08             	add    $0x8,%esp
 80484a6:	5b                   	pop    %ebx
 80484a7:	c3                   	ret    
