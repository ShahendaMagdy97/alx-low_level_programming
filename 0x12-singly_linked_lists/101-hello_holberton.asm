section		.text
	extern	printf
	global	main

main:
	mov		edi, wel
	mov		eax, 0
	call	printf


section		.data
	wel db 'Hello, Holberton', 0xa, 0
