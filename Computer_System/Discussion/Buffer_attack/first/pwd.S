
./pwd.out：     文件格式 elf32-i386


Disassembly of section .init:

08048394 <_init>:
 8048394:	53                   	push   %ebx
 8048395:	83 ec 08             	sub    $0x8,%esp
 8048398:	e8 e3 00 00 00       	call   8048480 <__x86.get_pc_thunk.bx>
 804839d:	81 c3 63 1c 00 00    	add    $0x1c63,%ebx
 80483a3:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80483a9:	85 c0                	test   %eax,%eax
 80483ab:	74 05                	je     80483b2 <_init+0x1e>
 80483ad:	e8 8e 00 00 00       	call   8048440 <__isoc99_scanf@plt+0x10>
 80483b2:	83 c4 08             	add    $0x8,%esp
 80483b5:	5b                   	pop    %ebx
 80483b6:	c3                   	ret    

Disassembly of section .plt:

080483c0 <strcmp@plt-0x10>:
 80483c0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80483c6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80483cc:	00 00                	add    %al,(%eax)
	...

080483d0 <strcmp@plt>:
 80483d0:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 80483d6:	68 00 00 00 00       	push   $0x0
 80483db:	e9 e0 ff ff ff       	jmp    80483c0 <_init+0x2c>

080483e0 <printf@plt>:
 80483e0:	ff 25 10 a0 04 08    	jmp    *0x804a010
 80483e6:	68 08 00 00 00       	push   $0x8
 80483eb:	e9 d0 ff ff ff       	jmp    80483c0 <_init+0x2c>

080483f0 <__stack_chk_fail@plt>:
 80483f0:	ff 25 14 a0 04 08    	jmp    *0x804a014
 80483f6:	68 10 00 00 00       	push   $0x10
 80483fb:	e9 c0 ff ff ff       	jmp    80483c0 <_init+0x2c>

08048400 <strcpy@plt>:
 8048400:	ff 25 18 a0 04 08    	jmp    *0x804a018
 8048406:	68 18 00 00 00       	push   $0x18
 804840b:	e9 b0 ff ff ff       	jmp    80483c0 <_init+0x2c>

08048410 <puts@plt>:
 8048410:	ff 25 1c a0 04 08    	jmp    *0x804a01c
 8048416:	68 20 00 00 00       	push   $0x20
 804841b:	e9 a0 ff ff ff       	jmp    80483c0 <_init+0x2c>

08048420 <__libc_start_main@plt>:
 8048420:	ff 25 20 a0 04 08    	jmp    *0x804a020
 8048426:	68 28 00 00 00       	push   $0x28
 804842b:	e9 90 ff ff ff       	jmp    80483c0 <_init+0x2c>

08048430 <__isoc99_scanf@plt>:
 8048430:	ff 25 24 a0 04 08    	jmp    *0x804a024
 8048436:	68 30 00 00 00       	push   $0x30
 804843b:	e9 80 ff ff ff       	jmp    80483c0 <_init+0x2c>

Disassembly of section .plt.got:

08048440 <.plt.got>:
 8048440:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 8048446:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

08048450 <_start>:
 8048450:	31 ed                	xor    %ebp,%ebp
 8048452:	5e                   	pop    %esi
 8048453:	89 e1                	mov    %esp,%ecx
 8048455:	83 e4 f0             	and    $0xfffffff0,%esp
 8048458:	50                   	push   %eax
 8048459:	54                   	push   %esp
 804845a:	52                   	push   %edx
 804845b:	68 c0 86 04 08       	push   $0x80486c0
 8048460:	68 60 86 04 08       	push   $0x8048660
 8048465:	51                   	push   %ecx
 8048466:	56                   	push   %esi
 8048467:	68 a0 85 04 08       	push   $0x80485a0
 804846c:	e8 af ff ff ff       	call   8048420 <__libc_start_main@plt>
 8048471:	f4                   	hlt    
 8048472:	66 90                	xchg   %ax,%ax
 8048474:	66 90                	xchg   %ax,%ax
 8048476:	66 90                	xchg   %ax,%ax
 8048478:	66 90                	xchg   %ax,%ax
 804847a:	66 90                	xchg   %ax,%ax
 804847c:	66 90                	xchg   %ax,%ax
 804847e:	66 90                	xchg   %ax,%ax

08048480 <__x86.get_pc_thunk.bx>:
 8048480:	8b 1c 24             	mov    (%esp),%ebx
 8048483:	c3                   	ret    
 8048484:	66 90                	xchg   %ax,%ax
 8048486:	66 90                	xchg   %ax,%ax
 8048488:	66 90                	xchg   %ax,%ax
 804848a:	66 90                	xchg   %ax,%ax
 804848c:	66 90                	xchg   %ax,%ax
 804848e:	66 90                	xchg   %ax,%ax

08048490 <deregister_tm_clones>:
 8048490:	b8 33 a0 04 08       	mov    $0x804a033,%eax
 8048495:	2d 30 a0 04 08       	sub    $0x804a030,%eax
 804849a:	83 f8 06             	cmp    $0x6,%eax
 804849d:	76 1a                	jbe    80484b9 <deregister_tm_clones+0x29>
 804849f:	b8 00 00 00 00       	mov    $0x0,%eax
 80484a4:	85 c0                	test   %eax,%eax
 80484a6:	74 11                	je     80484b9 <deregister_tm_clones+0x29>
 80484a8:	55                   	push   %ebp
 80484a9:	89 e5                	mov    %esp,%ebp
 80484ab:	83 ec 14             	sub    $0x14,%esp
 80484ae:	68 30 a0 04 08       	push   $0x804a030
 80484b3:	ff d0                	call   *%eax
 80484b5:	83 c4 10             	add    $0x10,%esp
 80484b8:	c9                   	leave  
 80484b9:	f3 c3                	repz ret 
 80484bb:	90                   	nop
 80484bc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

080484c0 <register_tm_clones>:
 80484c0:	b8 30 a0 04 08       	mov    $0x804a030,%eax
 80484c5:	2d 30 a0 04 08       	sub    $0x804a030,%eax
 80484ca:	c1 f8 02             	sar    $0x2,%eax
 80484cd:	89 c2                	mov    %eax,%edx
 80484cf:	c1 ea 1f             	shr    $0x1f,%edx
 80484d2:	01 d0                	add    %edx,%eax
 80484d4:	d1 f8                	sar    %eax
 80484d6:	74 1b                	je     80484f3 <register_tm_clones+0x33>
 80484d8:	ba 00 00 00 00       	mov    $0x0,%edx
 80484dd:	85 d2                	test   %edx,%edx
 80484df:	74 12                	je     80484f3 <register_tm_clones+0x33>
 80484e1:	55                   	push   %ebp
 80484e2:	89 e5                	mov    %esp,%ebp
 80484e4:	83 ec 10             	sub    $0x10,%esp
 80484e7:	50                   	push   %eax
 80484e8:	68 30 a0 04 08       	push   $0x804a030
 80484ed:	ff d2                	call   *%edx
 80484ef:	83 c4 10             	add    $0x10,%esp
 80484f2:	c9                   	leave  
 80484f3:	f3 c3                	repz ret 
 80484f5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80484f9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048500 <__do_global_dtors_aux>:
 8048500:	80 3d 30 a0 04 08 00 	cmpb   $0x0,0x804a030
 8048507:	75 13                	jne    804851c <__do_global_dtors_aux+0x1c>
 8048509:	55                   	push   %ebp
 804850a:	89 e5                	mov    %esp,%ebp
 804850c:	83 ec 08             	sub    $0x8,%esp
 804850f:	e8 7c ff ff ff       	call   8048490 <deregister_tm_clones>
 8048514:	c6 05 30 a0 04 08 01 	movb   $0x1,0x804a030
 804851b:	c9                   	leave  
 804851c:	f3 c3                	repz ret 
 804851e:	66 90                	xchg   %ax,%ax

08048520 <frame_dummy>:
 8048520:	b8 10 9f 04 08       	mov    $0x8049f10,%eax
 8048525:	8b 10                	mov    (%eax),%edx
 8048527:	85 d2                	test   %edx,%edx
 8048529:	75 05                	jne    8048530 <frame_dummy+0x10>
 804852b:	eb 93                	jmp    80484c0 <register_tm_clones>
 804852d:	8d 76 00             	lea    0x0(%esi),%esi
 8048530:	ba 00 00 00 00       	mov    $0x0,%edx
 8048535:	85 d2                	test   %edx,%edx
 8048537:	74 f2                	je     804852b <frame_dummy+0xb>
 8048539:	55                   	push   %ebp
 804853a:	89 e5                	mov    %esp,%ebp
 804853c:	83 ec 14             	sub    $0x14,%esp
 804853f:	50                   	push   %eax
 8048540:	ff d2                	call   *%edx
 8048542:	83 c4 10             	add    $0x10,%esp
 8048545:	c9                   	leave  
 8048546:	e9 75 ff ff ff       	jmp    80484c0 <register_tm_clones>

0804854b <verify>:
 804854b:	55                   	push   %ebp
 804854c:	89 e5                	mov    %esp,%ebp
 804854e:	83 ec 28             	sub    $0x28,%esp	;向下开辟28字节空间
 8048551:	8b 45 08             	mov    0x8(%ebp),%eax	;传参
 8048554:	89 45 e4             	mov    %eax,-0x1c(%ebp)	;
 8048557:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax	;关键:堆栈金丝雀,将值0x14放在数组结束处
																;并在结束时判断这数有没有改变,以此判断堆栈是否溢出
 804855d:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048560:	31 c0                	xor    %eax,%eax
 8048562:	83 ec 08             	sub    $0x8,%esp
 8048565:	68 e0 86 04 08       	push   $0x80486e0
 804856a:	ff 75 e4             	pushl  -0x1c(%ebp)
 804856d:	e8 5e fe ff ff       	call   80483d0 <strcmp@plt>
 8048572:	83 c4 10             	add    $0x10,%esp
 8048575:	89 45 e8             	mov    %eax,-0x18(%ebp)
 8048578:	83 ec 08             	sub    $0x8,%esp
 804857b:	ff 75 e4             	pushl  -0x1c(%ebp)
 804857e:	8d 45 ec             	lea    -0x14(%ebp),%eax
 8048581:	50                   	push   %eax
 8048582:	e8 79 fe ff ff       	call   8048400 <strcpy@plt>
 8048587:	83 c4 10             	add    $0x10,%esp
 804858a:	8b 45 e8             	mov    -0x18(%ebp),%eax
 804858d:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048590:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx	;判断是否和原值相等
 8048597:	74 05                	je     804859e <verify+0x53>
 8048599:	e8 52 fe ff ff       	call   80483f0 <__stack_chk_fail@plt>
 804859e:	c9                   	leave  
 804859f:	c3                   	ret    

080485a0 <main>:
 80485a0:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 80485a4:	83 e4 f0             	and    $0xfffffff0,%esp
 80485a7:	ff 71 fc             	pushl  -0x4(%ecx)
 80485aa:	55                   	push   %ebp
 80485ab:	89 e5                	mov    %esp,%ebp
 80485ad:	51                   	push   %ecx
 80485ae:	81 ec 14 04 00 00    	sub    $0x414,%esp
 80485b4:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 80485ba:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80485bd:	31 c0                	xor    %eax,%eax
 80485bf:	c7 85 f0 fb ff ff 00 	movl   $0x0,-0x410(%ebp)
 80485c6:	00 00 00 
 80485c9:	83 ec 0c             	sub    $0xc,%esp
 80485cc:	68 e8 86 04 08       	push   $0x80486e8
 80485d1:	e8 0a fe ff ff       	call   80483e0 <printf@plt>
 80485d6:	83 c4 10             	add    $0x10,%esp
 80485d9:	83 ec 08             	sub    $0x8,%esp
 80485dc:	8d 85 f4 fb ff ff    	lea    -0x40c(%ebp),%eax
 80485e2:	50                   	push   %eax
 80485e3:	68 fd 86 04 08       	push   $0x80486fd
 80485e8:	e8 43 fe ff ff       	call   8048430 <__isoc99_scanf@plt>
 80485ed:	83 c4 10             	add    $0x10,%esp
 80485f0:	83 ec 0c             	sub    $0xc,%esp
 80485f3:	8d 85 f4 fb ff ff    	lea    -0x40c(%ebp),%eax
 80485f9:	50                   	push   %eax
 80485fa:	e8 4c ff ff ff       	call   804854b <verify>
 80485ff:	83 c4 10             	add    $0x10,%esp
 8048602:	89 85 f0 fb ff ff    	mov    %eax,-0x410(%ebp)
 8048608:	83 bd f0 fb ff ff 00 	cmpl   $0x0,-0x410(%ebp)
 804860f:	74 12                	je     8048623 <main+0x83>
 8048611:	83 ec 0c             	sub    $0xc,%esp
 8048614:	68 00 87 04 08       	push   $0x8048700
 8048619:	e8 f2 fd ff ff       	call   8048410 <puts@plt>
 804861e:	83 c4 10             	add    $0x10,%esp
 8048621:	eb a6                	jmp    80485c9 <main+0x29>
 8048623:	83 ec 0c             	sub    $0xc,%esp
 8048626:	68 13 87 04 08       	push   $0x8048713
 804862b:	e8 e0 fd ff ff       	call   8048410 <puts@plt>
 8048630:	83 c4 10             	add    $0x10,%esp
 8048633:	90                   	nop
 8048634:	b8 00 00 00 00       	mov    $0x0,%eax
 8048639:	8b 55 f4             	mov    -0xc(%ebp),%edx
 804863c:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 8048643:	74 05                	je     804864a <main+0xaa>
 8048645:	e8 a6 fd ff ff       	call   80483f0 <__stack_chk_fail@plt>
 804864a:	8b 4d fc             	mov    -0x4(%ebp),%ecx
 804864d:	c9                   	leave  
 804864e:	8d 61 fc             	lea    -0x4(%ecx),%esp
 8048651:	c3                   	ret    
 8048652:	66 90                	xchg   %ax,%ax
 8048654:	66 90                	xchg   %ax,%ax
 8048656:	66 90                	xchg   %ax,%ax
 8048658:	66 90                	xchg   %ax,%ax
 804865a:	66 90                	xchg   %ax,%ax
 804865c:	66 90                	xchg   %ax,%ax
 804865e:	66 90                	xchg   %ax,%ax

08048660 <__libc_csu_init>:
 8048660:	55                   	push   %ebp
 8048661:	57                   	push   %edi
 8048662:	56                   	push   %esi
 8048663:	53                   	push   %ebx
 8048664:	e8 17 fe ff ff       	call   8048480 <__x86.get_pc_thunk.bx>
 8048669:	81 c3 97 19 00 00    	add    $0x1997,%ebx
 804866f:	83 ec 0c             	sub    $0xc,%esp
 8048672:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 8048676:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804867c:	e8 13 fd ff ff       	call   8048394 <_init>
 8048681:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048687:	29 c6                	sub    %eax,%esi
 8048689:	c1 fe 02             	sar    $0x2,%esi
 804868c:	85 f6                	test   %esi,%esi
 804868e:	74 25                	je     80486b5 <__libc_csu_init+0x55>
 8048690:	31 ff                	xor    %edi,%edi
 8048692:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048698:	83 ec 04             	sub    $0x4,%esp
 804869b:	ff 74 24 2c          	pushl  0x2c(%esp)
 804869f:	ff 74 24 2c          	pushl  0x2c(%esp)
 80486a3:	55                   	push   %ebp
 80486a4:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 80486ab:	83 c7 01             	add    $0x1,%edi
 80486ae:	83 c4 10             	add    $0x10,%esp
 80486b1:	39 f7                	cmp    %esi,%edi
 80486b3:	75 e3                	jne    8048698 <__libc_csu_init+0x38>
 80486b5:	83 c4 0c             	add    $0xc,%esp
 80486b8:	5b                   	pop    %ebx
 80486b9:	5e                   	pop    %esi
 80486ba:	5f                   	pop    %edi
 80486bb:	5d                   	pop    %ebp
 80486bc:	c3                   	ret    
 80486bd:	8d 76 00             	lea    0x0(%esi),%esi

080486c0 <__libc_csu_fini>:
 80486c0:	f3 c3                	repz ret 

Disassembly of section .fini:

080486c4 <_fini>:
 80486c4:	53                   	push   %ebx
 80486c5:	83 ec 08             	sub    $0x8,%esp
 80486c8:	e8 b3 fd ff ff       	call   8048480 <__x86.get_pc_thunk.bx>
 80486cd:	81 c3 33 19 00 00    	add    $0x1933,%ebx
 80486d3:	83 c4 08             	add    $0x8,%esp
 80486d6:	5b                   	pop    %ebx
 80486d7:	c3                   	ret    
