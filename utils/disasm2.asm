
client:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x11b>
  400248:	78 38                	js     400282 <_init-0x10e>
  40024a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
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
  40026f:	00 20                	add    %ah,(%rax)
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
  400283:	00 5a 40             	add    %bl,0x40(%rdx)
  400286:	a3 b9 b1 9c 42 0f ae 	movabs %eax,0xfcebae0f429cb1b9
  40028d:	eb fc 
  40028f:	df e9                	fucomip %st(1),%st
  400291:	4e 30 12             	rex.WRX xor %r10b,(%rdx)
  400294:	4f c6                	rex.WRXB (bad) 
  400296:	6c                   	insb   (%dx),%es:(%rdi)
  400297:	02                   	.byte 0x2

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
  4002e8:	1d 00 00 00 20       	sbb    $0x20000000,%eax
	...

Disassembly of section .dynstr:

0000000000400300 <.dynstr>:
  400300:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  400304:	63 2e                	movslq (%rsi),%ebp
  400306:	73 6f                	jae    400377 <_init-0x19>
  400308:	2e 36 00 5f 5f       	cs add %bl,%ss:0x5f(%rdi)
  40030d:	6c                   	insb   (%dx),%es:(%rdi)
  40030e:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  400315:	72 74                	jb     40038b <_init-0x5>
  400317:	5f                   	pop    %rdi
  400318:	6d                   	insl   (%dx),%es:(%rdi)
  400319:	61                   	(bad)  
  40031a:	69 6e 00 5f 5f 67 6d 	imul   $0x6d675f5f,0x0(%rsi),%ebp
  400321:	6f                   	outsl  %ds:(%rsi),(%dx)
  400322:	6e                   	outsb  %ds:(%rsi),(%dx)
  400323:	5f                   	pop    %rdi
  400324:	73 74                	jae    40039a <_init+0xa>
  400326:	61                   	(bad)  
  400327:	72 74                	jb     40039d <_init+0xd>
  400329:	5f                   	pop    %rdi
  40032a:	5f                   	pop    %rdi
  40032b:	00 47 4c             	add    %al,0x4c(%rdi)
  40032e:	49                   	rex.WB
  40032f:	42                   	rex.X
  400330:	43 5f                	rex.XB pop %r15
  400332:	32 2e                	xor    (%rsi),%ch
  400334:	32 2e                	xor    (%rsi),%ch
  400336:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

0000000000400338 <.gnu.version>:
  400338:	00 00                	add    %al,(%rax)
  40033a:	02 00                	add    (%rax),%al
	...

Disassembly of section .gnu.version_r:

0000000000400340 <.gnu.version_r>:
  400340:	01 00                	add    %eax,(%rax)
  400342:	01 00                	add    %eax,(%rax)
  400344:	01 00                	add    %eax,(%rax)
  400346:	00 00                	add    %al,(%rax)
  400348:	10 00                	adc    %al,(%rax)
  40034a:	00 00                	add    %al,(%rax)
  40034c:	00 00                	add    %al,(%rax)
  40034e:	00 00                	add    %al,(%rax)
  400350:	75 1a                	jne    40036c <_init-0x24>
  400352:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  400358:	2c 00                	sub    $0x0,%al
  40035a:	00 00                	add    %al,(%rax)
  40035c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000400360 <.rela.dyn>:
  400360:	f8                   	clc    
  400361:	0f 60 00             	punpcklbw (%rax),%mm0
  400364:	00 00                	add    %al,(%rax)
  400366:	00 00                	add    %al,(%rax)
  400368:	06                   	(bad)  
  400369:	00 00                	add    %al,(%rax)
  40036b:	00 02                	add    %al,(%rdx)
	...

Disassembly of section .rela.plt:

0000000000400378 <.rela.plt>:
  400378:	18 10                	sbb    %dl,(%rax)
  40037a:	60                   	(bad)  
  40037b:	00 00                	add    %al,(%rax)
  40037d:	00 00                	add    %al,(%rax)
  40037f:	00 07                	add    %al,(%rdi)
  400381:	00 00                	add    %al,(%rax)
  400383:	00 01                	add    %al,(%rcx)
	...

Disassembly of section .init:

0000000000400390 <_init>:
  400390:	48 83 ec 08          	sub    $0x8,%rsp
  400394:	48 8b 05 5d 0c 20 00 	mov    0x200c5d(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  40039b:	48 85 c0             	test   %rax,%rax
  40039e:	74 05                	je     4003a5 <_init+0x15>
  4003a0:	e8 2b 00 00 00       	callq  4003d0 <__libc_start_main@plt+0x10>
  4003a5:	48 83 c4 08          	add    $0x8,%rsp
  4003a9:	c3                   	retq   

Disassembly of section .plt:

00000000004003b0 <__libc_start_main@plt-0x10>:
  4003b0:	ff 35 52 0c 20 00    	pushq  0x200c52(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4003b6:	ff 25 54 0c 20 00    	jmpq   *0x200c54(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4003bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004003c0 <__libc_start_main@plt>:
  4003c0:	ff 25 52 0c 20 00    	jmpq   *0x200c52(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4003c6:	68 00 00 00 00       	pushq  $0x0
  4003cb:	e9 e0 ff ff ff       	jmpq   4003b0 <_init+0x20>

Disassembly of section .plt.got:

00000000004003d0 <.plt.got>:
  4003d0:	ff 25 22 0c 20 00    	jmpq   *0x200c22(%rip)        # 600ff8 <_DYNAMIC+0x1d0>
  4003d6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000004003e0 <main>:
  4003e0:	b8 1c 00 00 00       	mov    $0x1c,%eax
  4003e5:	c3                   	retq   
  4003e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4003ed:	00 00 00 

00000000004003f0 <_start>:
  4003f0:	31 ed                	xor    %ebp,%ebp
  4003f2:	49 89 d1             	mov    %rdx,%r9
  4003f5:	5e                   	pop    %rsi
  4003f6:	48 89 e2             	mov    %rsp,%rdx
  4003f9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4003fd:	50                   	push   %rax
  4003fe:	54                   	push   %rsp
  4003ff:	49 c7 c0 40 05 40 00 	mov    $0x400540,%r8
  400406:	48 c7 c1 d0 04 40 00 	mov    $0x4004d0,%rcx
  40040d:	48 c7 c7 e0 03 40 00 	mov    $0x4003e0,%rdi
  400414:	e8 a7 ff ff ff       	callq  4003c0 <__libc_start_main@plt>
  400419:	f4                   	hlt    
  40041a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400420 <deregister_tm_clones>:
  400420:	b8 38 10 60 00       	mov    $0x601038,%eax
  400425:	48 3d 38 10 60 00    	cmp    $0x601038,%rax
  40042b:	74 13                	je     400440 <deregister_tm_clones+0x20>
  40042d:	b8 00 00 00 00       	mov    $0x0,%eax
  400432:	48 85 c0             	test   %rax,%rax
  400435:	74 09                	je     400440 <deregister_tm_clones+0x20>
  400437:	bf 38 10 60 00       	mov    $0x601038,%edi
  40043c:	ff e0                	jmpq   *%rax
  40043e:	66 90                	xchg   %ax,%ax
  400440:	c3                   	retq   
  400441:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400446:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40044d:	00 00 00 

0000000000400450 <register_tm_clones>:
  400450:	be 38 10 60 00       	mov    $0x601038,%esi
  400455:	48 81 ee 38 10 60 00 	sub    $0x601038,%rsi
  40045c:	48 89 f0             	mov    %rsi,%rax
  40045f:	48 c1 ee 3f          	shr    $0x3f,%rsi
  400463:	48 c1 f8 03          	sar    $0x3,%rax
  400467:	48 01 c6             	add    %rax,%rsi
  40046a:	48 d1 fe             	sar    %rsi
  40046d:	74 11                	je     400480 <register_tm_clones+0x30>
  40046f:	b8 00 00 00 00       	mov    $0x0,%eax
  400474:	48 85 c0             	test   %rax,%rax
  400477:	74 07                	je     400480 <register_tm_clones+0x30>
  400479:	bf 38 10 60 00       	mov    $0x601038,%edi
  40047e:	ff e0                	jmpq   *%rax
  400480:	c3                   	retq   
  400481:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400486:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40048d:	00 00 00 

0000000000400490 <__do_global_dtors_aux>:
  400490:	80 3d 9d 0b 20 00 00 	cmpb   $0x0,0x200b9d(%rip)        # 601034 <_edata>
  400497:	75 17                	jne    4004b0 <__do_global_dtors_aux+0x20>
  400499:	55                   	push   %rbp
  40049a:	48 89 e5             	mov    %rsp,%rbp
  40049d:	e8 7e ff ff ff       	callq  400420 <deregister_tm_clones>
  4004a2:	c6 05 8b 0b 20 00 01 	movb   $0x1,0x200b8b(%rip)        # 601034 <_edata>
  4004a9:	5d                   	pop    %rbp
  4004aa:	c3                   	retq   
  4004ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4004b0:	c3                   	retq   
  4004b1:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4004b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004bd:	00 00 00 

00000000004004c0 <frame_dummy>:
  4004c0:	eb 8e                	jmp    400450 <register_tm_clones>
  4004c2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4004c9:	00 00 00 
  4004cc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004d0 <__libc_csu_init>:
  4004d0:	41 57                	push   %r15
  4004d2:	41 56                	push   %r14
  4004d4:	41 89 ff             	mov    %edi,%r15d
  4004d7:	41 55                	push   %r13
  4004d9:	41 54                	push   %r12
  4004db:	4c 8d 25 36 09 20 00 	lea    0x200936(%rip),%r12        # 600e18 <__frame_dummy_init_array_entry>
  4004e2:	55                   	push   %rbp
  4004e3:	48 8d 2d 36 09 20 00 	lea    0x200936(%rip),%rbp        # 600e20 <__init_array_end>
  4004ea:	53                   	push   %rbx
  4004eb:	49 89 f6             	mov    %rsi,%r14
  4004ee:	49 89 d5             	mov    %rdx,%r13
  4004f1:	4c 29 e5             	sub    %r12,%rbp
  4004f4:	48 83 ec 08          	sub    $0x8,%rsp
  4004f8:	48 c1 fd 03          	sar    $0x3,%rbp
  4004fc:	e8 8f fe ff ff       	callq  400390 <_init>
  400501:	48 85 ed             	test   %rbp,%rbp
  400504:	74 20                	je     400526 <__libc_csu_init+0x56>
  400506:	31 db                	xor    %ebx,%ebx
  400508:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40050f:	00 
  400510:	4c 89 ea             	mov    %r13,%rdx
  400513:	4c 89 f6             	mov    %r14,%rsi
  400516:	44 89 ff             	mov    %r15d,%edi
  400519:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40051d:	48 83 c3 01          	add    $0x1,%rbx
  400521:	48 39 eb             	cmp    %rbp,%rbx
  400524:	75 ea                	jne    400510 <__libc_csu_init+0x40>
  400526:	48 83 c4 08          	add    $0x8,%rsp
  40052a:	5b                   	pop    %rbx
  40052b:	5d                   	pop    %rbp
  40052c:	41 5c                	pop    %r12
  40052e:	41 5d                	pop    %r13
  400530:	41 5e                	pop    %r14
  400532:	41 5f                	pop    %r15
  400534:	c3                   	retq   
  400535:	90                   	nop
  400536:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40053d:	00 00 00 

0000000000400540 <__libc_csu_fini>:
  400540:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400544 <_fini>:
  400544:	48 83 ec 08          	sub    $0x8,%rsp
  400548:	48 83 c4 08          	add    $0x8,%rsp
  40054c:	c3                   	retq   

Disassembly of section .rodata:

0000000000400550 <_IO_stdin_used>:
  400550:	01 00                	add    %eax,(%rax)
  400552:	02 00                	add    (%rax),%al

Disassembly of section .eh_frame_hdr:

0000000000400554 <__GNU_EH_FRAME_HDR>:
  400554:	01 1b                	add    %ebx,(%rbx)
  400556:	03 3b                	add    (%rbx),%edi
  400558:	30 00                	xor    %al,(%rax)
  40055a:	00 00                	add    %al,(%rax)
  40055c:	05 00 00 00 5c       	add    $0x5c000000,%eax
  400561:	fe                   	(bad)  
  400562:	ff                   	(bad)  
  400563:	ff                   	(bad)  
  400564:	7c 00                	jl     400566 <__GNU_EH_FRAME_HDR+0x12>
  400566:	00 00                	add    %al,(%rax)
  400568:	8c fe                	mov    %?,%esi
  40056a:	ff                   	(bad)  
  40056b:	ff a4 00 00 00 9c fe 	jmpq   *-0x1640000(%rax,%rax,1)
  400572:	ff                   	(bad)  
  400573:	ff 4c 00 00          	decl   0x0(%rax,%rax,1)
  400577:	00 7c ff ff          	add    %bh,-0x1(%rdi,%rdi,8)
  40057b:	ff                   	(bad)  
  40057c:	bc 00 00 00 ec       	mov    $0xec000000,%esp
  400581:	ff                   	(bad)  
  400582:	ff                   	(bad)  
  400583:	ff 04 01             	incl   (%rcx,%rax,1)
	...

Disassembly of section .eh_frame:

0000000000400588 <__FRAME_END__-0xe8>:
  400588:	14 00                	adc    $0x0,%al
  40058a:	00 00                	add    %al,(%rax)
  40058c:	00 00                	add    %al,(%rax)
  40058e:	00 00                	add    %al,(%rax)
  400590:	01 7a 52             	add    %edi,0x52(%rdx)
  400593:	00 01                	add    %al,(%rcx)
  400595:	78 10                	js     4005a7 <__GNU_EH_FRAME_HDR+0x53>
  400597:	01 1b                	add    %ebx,(%rbx)
  400599:	0c 07                	or     $0x7,%al
  40059b:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
  4005a1:	00 00                	add    %al,(%rax)
  4005a3:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4005a6:	00 00                	add    %al,(%rax)
  4005a8:	48 fe                	rex.W (bad) 
  4005aa:	ff                   	(bad)  
  4005ab:	ff 2a                	ljmp   *(%rdx)
	...
  4005b5:	00 00                	add    %al,(%rax)
  4005b7:	00 14 00             	add    %dl,(%rax,%rax,1)
  4005ba:	00 00                	add    %al,(%rax)
  4005bc:	00 00                	add    %al,(%rax)
  4005be:	00 00                	add    %al,(%rax)
  4005c0:	01 7a 52             	add    %edi,0x52(%rdx)
  4005c3:	00 01                	add    %al,(%rcx)
  4005c5:	78 10                	js     4005d7 <__GNU_EH_FRAME_HDR+0x83>
  4005c7:	01 1b                	add    %ebx,(%rbx)
  4005c9:	0c 07                	or     $0x7,%al
  4005cb:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  4005d1:	00 00                	add    %al,(%rax)
  4005d3:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4005d6:	00 00                	add    %al,(%rax)
  4005d8:	d8 fd                	fdivr  %st(5),%st
  4005da:	ff                   	(bad)  
  4005db:	ff 20                	jmpq   *(%rax)
  4005dd:	00 00                	add    %al,(%rax)
  4005df:	00 00                	add    %al,(%rax)
  4005e1:	0e                   	(bad)  
  4005e2:	10 46 0e             	adc    %al,0xe(%rsi)
  4005e5:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4005e8:	0b 77 08             	or     0x8(%rdi),%esi
  4005eb:	80 00 3f             	addb   $0x3f,(%rax)
  4005ee:	1a 3b                	sbb    (%rbx),%bh
  4005f0:	2a 33                	sub    (%rbx),%dh
  4005f2:	24 22                	and    $0x22,%al
  4005f4:	00 00                	add    %al,(%rax)
  4005f6:	00 00                	add    %al,(%rax)
  4005f8:	14 00                	adc    $0x0,%al
  4005fa:	00 00                	add    %al,(%rax)
  4005fc:	44 00 00             	add    %r8b,(%rax)
  4005ff:	00 e0                	add    %ah,%al
  400601:	fd                   	std    
  400602:	ff                   	(bad)  
  400603:	ff 06                	incl   (%rsi)
	...
  40060d:	00 00                	add    %al,(%rax)
  40060f:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
  400613:	00 5c 00 00          	add    %bl,0x0(%rax,%rax,1)
  400617:	00 b8 fe ff ff 65    	add    %bh,0x65fffffe(%rax)
  40061d:	00 00                	add    %al,(%rax)
  40061f:	00 00                	add    %al,(%rax)
  400621:	42 0e                	rex.X (bad) 
  400623:	10 8f 02 42 0e 18    	adc    %cl,0x180e4202(%rdi)
  400629:	8e 03                	mov    (%rbx),%es
  40062b:	45 0e                	rex.RB (bad) 
  40062d:	20 8d 04 42 0e 28    	and    %cl,0x280e4204(%rbp)
  400633:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86701481 <__TMC_END__+0xffffffff86100449>
  400639:	06                   	(bad)  
  40063a:	48 0e                	rex.W (bad) 
  40063c:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
  400642:	72 0e                	jb     400652 <__GNU_EH_FRAME_HDR+0xfe>
  400644:	38 41 0e             	cmp    %al,0xe(%rcx)
  400647:	30 41 0e             	xor    %al,0xe(%rcx)
  40064a:	28 42 0e             	sub    %al,0xe(%rdx)
  40064d:	20 42 0e             	and    %al,0xe(%rdx)
  400650:	18 42 0e             	sbb    %al,0xe(%rdx)
  400653:	10 42 0e             	adc    %al,0xe(%rdx)
  400656:	08 00                	or     %al,(%rax)
  400658:	14 00                	adc    $0x0,%al
  40065a:	00 00                	add    %al,(%rax)
  40065c:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
  40065d:	00 00                	add    %al,(%rax)
  40065f:	00 e0                	add    %ah,%al
  400661:	fe                   	(bad)  
  400662:	ff                   	(bad)  
  400663:	ff 02                	incl   (%rdx)
	...

0000000000400670 <__FRAME_END__>:
  400670:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000600e18 <__frame_dummy_init_array_entry>:
  600e18:	c0 04 40 00          	rolb   $0x0,(%rax,%rax,2)
  600e1c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000600e20 <__do_global_dtors_aux_fini_array_entry>:
  600e20:	90                   	nop
  600e21:	04 40                	add    $0x40,%al
  600e23:	00 00                	add    %al,(%rax)
  600e25:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000600e28 <_DYNAMIC>:
  600e28:	01 00                	add    %eax,(%rax)
  600e2a:	00 00                	add    %al,(%rax)
  600e2c:	00 00                	add    %al,(%rax)
  600e2e:	00 00                	add    %al,(%rax)
  600e30:	01 00                	add    %eax,(%rax)
  600e32:	00 00                	add    %al,(%rax)
  600e34:	00 00                	add    %al,(%rax)
  600e36:	00 00                	add    %al,(%rax)
  600e38:	0c 00                	or     $0x0,%al
  600e3a:	00 00                	add    %al,(%rax)
  600e3c:	00 00                	add    %al,(%rax)
  600e3e:	00 00                	add    %al,(%rax)
  600e40:	90                   	nop
  600e41:	03 40 00             	add    0x0(%rax),%eax
  600e44:	00 00                	add    %al,(%rax)
  600e46:	00 00                	add    %al,(%rax)
  600e48:	0d 00 00 00 00       	or     $0x0,%eax
  600e4d:	00 00                	add    %al,(%rax)
  600e4f:	00 44 05 40          	add    %al,0x40(%rbp,%rax,1)
  600e53:	00 00                	add    %al,(%rax)
  600e55:	00 00                	add    %al,(%rax)
  600e57:	00 19                	add    %bl,(%rcx)
  600e59:	00 00                	add    %al,(%rax)
  600e5b:	00 00                	add    %al,(%rax)
  600e5d:	00 00                	add    %al,(%rax)
  600e5f:	00 18                	add    %bl,(%rax)
  600e61:	0e                   	(bad)  
  600e62:	60                   	(bad)  
  600e63:	00 00                	add    %al,(%rax)
  600e65:	00 00                	add    %al,(%rax)
  600e67:	00 1b                	add    %bl,(%rbx)
  600e69:	00 00                	add    %al,(%rax)
  600e6b:	00 00                	add    %al,(%rax)
  600e6d:	00 00                	add    %al,(%rax)
  600e6f:	00 08                	add    %cl,(%rax)
  600e71:	00 00                	add    %al,(%rax)
  600e73:	00 00                	add    %al,(%rax)
  600e75:	00 00                	add    %al,(%rax)
  600e77:	00 1a                	add    %bl,(%rdx)
  600e79:	00 00                	add    %al,(%rax)
  600e7b:	00 00                	add    %al,(%rax)
  600e7d:	00 00                	add    %al,(%rax)
  600e7f:	00 20                	add    %ah,(%rax)
  600e81:	0e                   	(bad)  
  600e82:	60                   	(bad)  
  600e83:	00 00                	add    %al,(%rax)
  600e85:	00 00                	add    %al,(%rax)
  600e87:	00 1c 00             	add    %bl,(%rax,%rax,1)
  600e8a:	00 00                	add    %al,(%rax)
  600e8c:	00 00                	add    %al,(%rax)
  600e8e:	00 00                	add    %al,(%rax)
  600e90:	08 00                	or     %al,(%rax)
  600e92:	00 00                	add    %al,(%rax)
  600e94:	00 00                	add    %al,(%rax)
  600e96:	00 00                	add    %al,(%rax)
  600e98:	f5                   	cmc    
  600e99:	fe                   	(bad)  
  600e9a:	ff 6f 00             	ljmp   *0x0(%rdi)
  600e9d:	00 00                	add    %al,(%rax)
  600e9f:	00 98 02 40 00 00    	add    %bl,0x4002(%rax)
  600ea5:	00 00                	add    %al,(%rax)
  600ea7:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 600ead <_DYNAMIC+0x85>
  600ead:	00 00                	add    %al,(%rax)
  600eaf:	00 00                	add    %al,(%rax)
  600eb1:	03 40 00             	add    0x0(%rax),%eax
  600eb4:	00 00                	add    %al,(%rax)
  600eb6:	00 00                	add    %al,(%rax)
  600eb8:	06                   	(bad)  
  600eb9:	00 00                	add    %al,(%rax)
  600ebb:	00 00                	add    %al,(%rax)
  600ebd:	00 00                	add    %al,(%rax)
  600ebf:	00 b8 02 40 00 00    	add    %bh,0x4002(%rax)
  600ec5:	00 00                	add    %al,(%rax)
  600ec7:	00 0a                	add    %cl,(%rdx)
  600ec9:	00 00                	add    %al,(%rax)
  600ecb:	00 00                	add    %al,(%rax)
  600ecd:	00 00                	add    %al,(%rax)
  600ecf:	00 38                	add    %bh,(%rax)
  600ed1:	00 00                	add    %al,(%rax)
  600ed3:	00 00                	add    %al,(%rax)
  600ed5:	00 00                	add    %al,(%rax)
  600ed7:	00 0b                	add    %cl,(%rbx)
  600ed9:	00 00                	add    %al,(%rax)
  600edb:	00 00                	add    %al,(%rax)
  600edd:	00 00                	add    %al,(%rax)
  600edf:	00 18                	add    %bl,(%rax)
  600ee1:	00 00                	add    %al,(%rax)
  600ee3:	00 00                	add    %al,(%rax)
  600ee5:	00 00                	add    %al,(%rax)
  600ee7:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 600eed <_DYNAMIC+0xc5>
	...
  600ef5:	00 00                	add    %al,(%rax)
  600ef7:	00 03                	add    %al,(%rbx)
	...
  600f01:	10 60 00             	adc    %ah,0x0(%rax)
  600f04:	00 00                	add    %al,(%rax)
  600f06:	00 00                	add    %al,(%rax)
  600f08:	02 00                	add    (%rax),%al
  600f0a:	00 00                	add    %al,(%rax)
  600f0c:	00 00                	add    %al,(%rax)
  600f0e:	00 00                	add    %al,(%rax)
  600f10:	18 00                	sbb    %al,(%rax)
  600f12:	00 00                	add    %al,(%rax)
  600f14:	00 00                	add    %al,(%rax)
  600f16:	00 00                	add    %al,(%rax)
  600f18:	14 00                	adc    $0x0,%al
  600f1a:	00 00                	add    %al,(%rax)
  600f1c:	00 00                	add    %al,(%rax)
  600f1e:	00 00                	add    %al,(%rax)
  600f20:	07                   	(bad)  
  600f21:	00 00                	add    %al,(%rax)
  600f23:	00 00                	add    %al,(%rax)
  600f25:	00 00                	add    %al,(%rax)
  600f27:	00 17                	add    %dl,(%rdi)
  600f29:	00 00                	add    %al,(%rax)
  600f2b:	00 00                	add    %al,(%rax)
  600f2d:	00 00                	add    %al,(%rax)
  600f2f:	00 78 03             	add    %bh,0x3(%rax)
  600f32:	40 00 00             	add    %al,(%rax)
  600f35:	00 00                	add    %al,(%rax)
  600f37:	00 07                	add    %al,(%rdi)
  600f39:	00 00                	add    %al,(%rax)
  600f3b:	00 00                	add    %al,(%rax)
  600f3d:	00 00                	add    %al,(%rax)
  600f3f:	00 60 03             	add    %ah,0x3(%rax)
  600f42:	40 00 00             	add    %al,(%rax)
  600f45:	00 00                	add    %al,(%rax)
  600f47:	00 08                	add    %cl,(%rax)
  600f49:	00 00                	add    %al,(%rax)
  600f4b:	00 00                	add    %al,(%rax)
  600f4d:	00 00                	add    %al,(%rax)
  600f4f:	00 18                	add    %bl,(%rax)
  600f51:	00 00                	add    %al,(%rax)
  600f53:	00 00                	add    %al,(%rax)
  600f55:	00 00                	add    %al,(%rax)
  600f57:	00 09                	add    %cl,(%rcx)
  600f59:	00 00                	add    %al,(%rax)
  600f5b:	00 00                	add    %al,(%rax)
  600f5d:	00 00                	add    %al,(%rax)
  600f5f:	00 18                	add    %bl,(%rax)
  600f61:	00 00                	add    %al,(%rax)
  600f63:	00 00                	add    %al,(%rax)
  600f65:	00 00                	add    %al,(%rax)
  600f67:	00 fe                	add    %bh,%dh
  600f69:	ff                   	(bad)  
  600f6a:	ff 6f 00             	ljmp   *0x0(%rdi)
  600f6d:	00 00                	add    %al,(%rax)
  600f6f:	00 40 03             	add    %al,0x3(%rax)
  600f72:	40 00 00             	add    %al,(%rax)
  600f75:	00 00                	add    %al,(%rax)
  600f77:	00 ff                	add    %bh,%bh
  600f79:	ff                   	(bad)  
  600f7a:	ff 6f 00             	ljmp   *0x0(%rdi)
  600f7d:	00 00                	add    %al,(%rax)
  600f7f:	00 01                	add    %al,(%rcx)
  600f81:	00 00                	add    %al,(%rax)
  600f83:	00 00                	add    %al,(%rax)
  600f85:	00 00                	add    %al,(%rax)
  600f87:	00 f0                	add    %dh,%al
  600f89:	ff                   	(bad)  
  600f8a:	ff 6f 00             	ljmp   *0x0(%rdi)
  600f8d:	00 00                	add    %al,(%rax)
  600f8f:	00 38                	add    %bh,(%rax)
  600f91:	03 40 00             	add    0x0(%rax),%eax
	...

Disassembly of section .got:

0000000000600ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000601000 <_GLOBAL_OFFSET_TABLE_>:
  601000:	28 0e                	sub    %cl,(%rsi)
  601002:	60                   	(bad)  
	...
  601017:	00 c6                	add    %al,%dh
  601019:	03 40 00             	add    0x0(%rax),%eax
  60101c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000601020 <__data_start>:
	...

0000000000601028 <__dso_handle>:
	...

0000000000601030 <literal>:
  601030:	1c 00                	sbb    $0x0,%al
	...

Disassembly of section .bss:

0000000000601034 <__bss_start>:
  601034:	00 00                	add    %al,(%rax)
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x400318>
   a:	74 75                	je     81 <_init-0x40030f>
   c:	20 39                	and    %bh,(%rcx)
   e:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  11:	30 2d 31 30 75 62    	xor    %ch,0x62753031(%rip)        # 62753048 <__TMC_END__+0x62152010>
  17:	75 6e                	jne    87 <_init-0x400309>
  19:	74 75                	je     90 <_init-0x400300>
  1b:	32 7e 31             	xor    0x31(%rsi),%bh
  1e:	36 2e 30 34 29       	ss xor %dh,%cs:(%rcx,%rbp,1)
  23:	20 39                	and    %bh,(%rcx)
  25:	2e 33 2e             	xor    %cs:(%rsi),%ebp
  28:	30 00                	xor    %al,(%rax)
