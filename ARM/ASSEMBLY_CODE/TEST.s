
.global _star
_star:
	mov r1 ,#15
	mov r2 , #101
	
	//subs r2 , r1
	str r1, [r0]
//	ldr r5 ,[r0, #4]
		ldr r5 , [r0]

	mov r9 , r5
	//cmp r1 , r2P
	_end: