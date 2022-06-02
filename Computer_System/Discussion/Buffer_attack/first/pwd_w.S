
./pwd_w.out：     文件格式 elf32-i386


Disassembly of section .init:

08048350 <_init>:
 8048350:	53                   	push   %ebx
 8048351:	83 ec 08             	sub    $0x8,%esp
 8048354:	e8 d7 00 00 00       	call   8048430 <__x86.get_pc_thunk.bx>
 8048359:	81 c3 a7 1c 00 00    	add    $0x1ca7,%ebx
 804835f:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 8048365:	85 c0                	test   %eax,%eax
 8048367:	74 05                	je     804836e <_init+0x1e>
 8048369:	e8 82 00 00 00       	call   80483f0 <__isoc99_scanf@plt+0x10>
 804836e:	83 c4 08             	add    $0x8,%esp
 8048371:	5b                   	pop    %ebx
 8048372:	c3                   	ret    

Disassembly of section .plt:

08048380 <strcmp@plt-0x10>:
 8048380:	ff 35 04 a0 04 08    	pushl  0x804a004
 8048386:	ff 25 08 a0 04 08    	jmp    *0x804a008
 804838c:	00 00                	add    %al,(%eax)
	...

08048390 <strcmp@plt>:
 8048390:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 8048396:	68 00 00 00 00       	push   $0x0
 804839b:	e9 e0 ff ff ff       	jmp    8048380 <_init+0x30>

080483a0 <printf@plt>:
 80483a0:	ff 25 10 a0 04 08    	jmp    *0x804a010
 80483a6:	68 08 00 00 00       	push   $0x8
 80483ab:	e9 d0 ff ff ff       	jmp    8048380 <_init+0x30>

080483b0 <strcpy@plt>:
 80483b0:	ff 25 14 a0 04 08    	jmp    *0x804a014
 80483b6:	68 10 00 00 00       	push   $0x10
 80483bb:	e9 c0 ff ff ff       	jmp    8048380 <_init+0x30>

080483c0 <puts@plt>:
 80483c0:	ff 25 18 a0 04 08    	jmp    *0x804a018
 80483c6:	68 18 00 00 00       	push   $0x18
 80483cb:	e9 b0 ff ff ff       	jmp    8048380 <_init+0x30>

080483d0 <__libc_start_main@plt>:
 80483d0:	ff 25 1c a0 04 08    	jmp    *0x804a01c
 80483d6:	68 20 00 00 00       	push   $0x20
 80483db:	e9 a0 ff ff ff       	jmp    8048380 <_init+0x30>

080483e0 <__isoc99_scanf@plt>:
 80483e0:	ff 25 20 a0 04 08    	jmp    *0x804a020
 80483e6:	68 28 00 00 00       	push   $0x28
 80483eb:	e9 90 ff ff ff       	jmp    8048380 <_init+0x30>

Disassembly of section .plt.got:

080483f0 <.plt.got>:
 80483f0:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80483f6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

08048400 <_start>:
 8048400:	31 ed                	xor    %ebp,%ebp
 8048402:	5e                   	pop    %esi
 8048403:	89 e1                	mov    %esp,%ecx
 8048405:	83 e4 f0             	and    $0xfffffff0,%esp
 8048408:	50                   	push   %eax
 8048409:	54                   	push   %esp
 804840a:	52                   	push   %edx
 804840b:	68 20 86 04 08       	push   $0x8048620
 8048410:	68 c0 85 04 08       	push   $0x80485c0
 8048415:	51                   	push   %ecx
 8048416:	56                   	push   %esi
 8048417:	68 2e 85 04 08       	push   $0x804852e
 804841c:	e8 af ff ff ff       	call   80483d0 <__libc_start_main@plt>
 8048421:	f4                   	hlt    
 8048422:	66 90                	xchg   %ax,%ax
 8048424:	66 90                	xchg   %ax,%ax
 8048426:	66 90                	xchg   %ax,%ax
 8048428:	66 90                	xchg   %ax,%ax
 804842a:	66 90                	xchg   %ax,%ax
 804842c:	66 90                	xchg   %ax,%ax
 804842e:	66 90                	xchg   %ax,%ax

08048430 <__x86.get_pc_thunk.bx>:
 8048430:	8b 1c 24             	mov    (%esp),%ebx
 8048433:	c3                   	ret    
 8048434:	66 90                	xchg   %ax,%ax
 8048436:	66 90                	xchg   %ax,%ax
 8048438:	66 90                	xchg   %ax,%ax
 804843a:	66 90                	xchg   %ax,%ax
 804843c:	66 90                	xchg   %ax,%ax
 804843e:	66 90                	xchg   %ax,%ax

08048440 <deregister_tm_clones>:
 8048440:	b8 2f a0 04 08       	mov    $0x804a02f,%eax
 8048445:	2d 2c a0 04 08       	sub    $0x804a02c,%eax
 804844a:	83 f8 06             	cmp    $0x6,%eax
 804844d:	76 1a                	jbe    8048469 <deregister_tm_clones+0x29>
 804844f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048454:	85 c0                	test   %eax,%eax
 8048456:	74 11                	je     8048469 <deregister_tm_clones+0x29>
 8048458:	55                   	push   %ebp
 8048459:	89 e5                	mov    %esp,%ebp
 804845b:	83 ec 14             	sub    $0x14,%esp
 804845e:	68 2c a0 04 08       	push   $0x804a02c
 8048463:	ff d0                	call   *%eax
 8048465:	83 c4 10             	add    $0x10,%esp
 8048468:	c9                   	leave  
 8048469:	f3 c3                	repz ret 
 804846b:	90                   	nop
 804846c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048470 <register_tm_clones>:
 8048470:	b8 2c a0 04 08       	mov    $0x804a02c,%eax
 8048475:	2d 2c a0 04 08       	sub    $0x804a02c,%eax
 804847a:	c1 f8 02             	sar    $0x2,%eax
 804847d:	89 c2                	mov    %eax,%edx
 804847f:	c1 ea 1f             	shr    $0x1f,%edx
 8048482:	01 d0                	add    %edx,%eax
 8048484:	d1 f8                	sar    %eax
 8048486:	74 1b                	je     80484a3 <register_tm_clones+0x33>
 8048488:	ba 00 00 00 00       	mov    $0x0,%edx
 804848d:	85 d2                	test   %edx,%edx
 804848f:	74 12                	je     80484a3 <register_tm_clones+0x33>
 8048491:	55                   	push   %ebp
 8048492:	89 e5                	mov    %esp,%ebp
 8048494:	83 ec 10             	sub    $0x10,%esp
 8048497:	50                   	push   %eax
 8048498:	68 2c a0 04 08       	push   $0x804a02c
 804849d:	ff d2                	call   *%edx
 804849f:	83 c4 10             	add    $0x10,%esp
 80484a2:	c9                   	leave  
 80484a3:	f3 c3                	repz ret 
 80484a5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80484a9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080484b0 <__do_global_dtors_aux>:
 80484b0:	80 3d 2c a0 04 08 00 	cmpb   $0x0,0x804a02c
 80484b7:	75 13                	jne    80484cc <__do_global_dtors_aux+0x1c>
 80484b9:	55                   	push   %ebp
 80484ba:	89 e5                	mov    %esp,%ebp
 80484bc:	83 ec 08             	sub    $0x8,%esp
 80484bf:	e8 7c ff ff ff       	call   8048440 <deregister_tm_clones>
 80484c4:	c6 05 2c a0 04 08 01 	movb   $0x1,0x804a02c
 80484cb:	c9                   	leave  
 80484cc:	f3 c3                	repz ret 
 80484ce:	66 90                	xchg   %ax,%ax

080484d0 <frame_dummy>:
 80484d0:	b8 10 9f 04 08       	mov    $0x8049f10,%eax
 80484d5:	8b 10                	mov    (%eax),%edx
 80484d7:	85 d2                	test   %edx,%edx
 80484d9:	75 05                	jne    80484e0 <frame_dummy+0x10>
 80484db:	eb 93                	jmp    8048470 <register_tm_clones>
 80484dd:	8d 76 00             	lea    0x0(%esi),%esi
 80484e0:	ba 00 00 00 00       	mov    $0x0,%edx
 80484e5:	85 d2                	test   %edx,%edx
 80484e7:	74 f2                	je     80484db <frame_dummy+0xb>
 80484e9:	55                   	push   %ebp
 80484ea:	89 e5                	mov    %esp,%ebp
 80484ec:	83 ec 14             	sub    $0x14,%esp
 80484ef:	50                   	push   %eax
 80484f0:	ff d2                	call   *%edx
 80484f2:	83 c4 10             	add    $0x10,%esp
 80484f5:	c9                   	leave  
 80484f6:	e9 75 ff ff ff       	jmp    8048470 <register_tm_clones>

080484fb <verify>:
 80484fb:	55                   	push   %ebp
 80484fc:	89 e5                	mov    %esp,%ebp
 80484fe:	83 ec 18             	sub    $0x18,%esp	;向下开辟0x18
 8048501:	83 ec 08             	sub    $0x8,%esp	
 8048504:	68 40 86 04 08       	push   $0x8048640
 8048509:	ff 75 08             	pushl  0x8(%ebp)
 804850c:	e8 7f fe ff ff       	call   8048390 <strcmp@plt>
 8048511:	83 c4 10             	add    $0x10,%esp	
 8048514:	89 45 f4             	mov    %eax,-0xc(%ebp)	;表明auth所在位置
															;推断可知buffer的起始地址M[ebp-14]
															;
 8048517:	83 ec 08             	sub    $0x8,%esp
 804851a:	ff 75 08             	pushl  0x8(%ebp)
 804851d:	8d 45 ec             	lea    -0x14(%ebp),%eax
 8048520:	50                   	push   %eax
 8048521:	e8 8a fe ff ff       	call   80483b0 <strcpy@plt>
 8048526:	83 c4 10             	add    $0x10,%esp
 8048529:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804852c:	c9                   	leave  
 804852d:	c3                   	ret    

0804852e <main>:
 804852e:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 8048532:	83 e4 f0             	and    $0xfffffff0,%esp
 8048535:	ff 71 fc             	pushl  -0x4(%ecx)
 8048538:	55                   	push   %ebp
 8048539:	89 e5                	mov    %esp,%ebp
 804853b:	51                   	push   %ecx
 804853c:	81 ec 14 04 00 00    	sub    $0x414,%esp
 8048542:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8048549:	83 ec 0c             	sub    $0xc,%esp
 804854c:	68 48 86 04 08       	push   $0x8048648
 8048551:	e8 4a fe ff ff       	call   80483a0 <printf@plt>
 8048556:	83 c4 10             	add    $0x10,%esp
 8048559:	83 ec 08             	sub    $0x8,%esp
 804855c:	8d 85 f4 fb ff ff    	lea    -0x40c(%ebp),%eax
 8048562:	50                   	push   %eax
 8048563:	68 5d 86 04 08       	push   $0x804865d
 8048568:	e8 73 fe ff ff       	call   80483e0 <__isoc99_scanf@plt>
 804856d:	83 c4 10             	add    $0x10,%esp
 8048570:	83 ec 0c             	sub    $0xc,%esp
 8048573:	8d 85 f4 fb ff ff    	lea    -0x40c(%ebp),%eax
 8048579:	50                   	push   %eax
 804857a:	e8 7c ff ff ff       	call   80484fb <verify>
 804857f:	83 c4 10             	add    $0x10,%esp
 8048582:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048585:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8048589:	74 12                	je     804859d <main+0x6f>
 804858b:	83 ec 0c             	sub    $0xc,%esp
 804858e:	68 60 86 04 08       	push   $0x8048660
 8048593:	e8 28 fe ff ff       	call   80483c0 <puts@plt>
 8048598:	83 c4 10             	add    $0x10,%esp
 804859b:	eb ac                	jmp    8048549 <main+0x1b>
 804859d:	83 ec 0c             	sub    $0xc,%esp
 80485a0:	68 73 86 04 08       	push   $0x8048673
 80485a5:	e8 16 fe ff ff       	call   80483c0 <puts@plt>
 80485aa:	83 c4 10             	add    $0x10,%esp
 80485ad:	90                   	nop
 80485ae:	b8 00 00 00 00       	mov    $0x0,%eax
 80485b3:	8b 4d fc             	mov    -0x4(%ebp),%ecx
 80485b6:	c9                   	leave  
 80485b7:	8d 61 fc             	lea    -0x4(%ecx),%esp
 80485ba:	c3                   	ret    
 80485bb:	66 90                	xchg   %ax,%ax
 80485bd:	66 90                	xchg   %ax,%ax
 80485bf:	90                   	nop

080485c0 <__libc_csu_init>:
 80485c0:	55                   	push   %ebp
 80485c1:	57                   	push   %edi
 80485c2:	56                   	push   %esi
 80485c3:	53                   	push   %ebx
 80485c4:	e8 67 fe ff ff       	call   8048430 <__x86.get_pc_thunk.bx>
 80485c9:	81 c3 37 1a 00 00    	add    $0x1a37,%ebx
 80485cf:	83 ec 0c             	sub    $0xc,%esp
 80485d2:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 80485d6:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 80485dc:	e8 6f fd ff ff       	call   8048350 <_init>
 80485e1:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 80485e7:	29 c6                	sub    %eax,%esi
 80485e9:	c1 fe 02             	sar    $0x2,%esi
 80485ec:	85 f6                	test   %esi,%esi
 80485ee:	74 25                	je     8048615 <__libc_csu_init+0x55>
 80485f0:	31 ff                	xor    %edi,%edi
 80485f2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 80485f8:	83 ec 04             	sub    $0x4,%esp
 80485fb:	ff 74 24 2c          	pushl  0x2c(%esp)
 80485ff:	ff 74 24 2c          	pushl  0x2c(%esp)
 8048603:	55                   	push   %ebp
 8048604:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 804860b:	83 c7 01             	add    $0x1,%edi
 804860e:	83 c4 10             	add    $0x10,%esp
 8048611:	39 f7                	cmp    %esi,%edi
 8048613:	75 e3                	jne    80485f8 <__libc_csu_init+0x38>
 8048615:	83 c4 0c             	add    $0xc,%esp
 8048618:	5b                   	pop    %ebx
 8048619:	5e                   	pop    %esi
 804861a:	5f                   	pop    %edi
 804861b:	5d                   	pop    %ebp
 804861c:	c3                   	ret    
 804861d:	8d 76 00             	lea    0x0(%esi),%esi

08048620 <__libc_csu_fini>:
 8048620:	f3 c3                	repz ret 

Disassembly of section .fini:

08048624 <_fini>:
 8048624:	53                   	push   %ebx
 8048625:	83 ec 08             	sub    $0x8,%esp
 8048628:	e8 03 fe ff ff       	call   8048430 <__x86.get_pc_thunk.bx>
 804862d:	81 c3 d3 19 00 00    	add    $0x19d3,%ebx
 8048633:	83 c4 08             	add    $0x8,%esp
 8048636:	5b                   	pop    %ebx
 8048637:	c3                   	ret    
