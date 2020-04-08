	;; Header
	.arch msp430g2553
	.p2align 1,0

	;; Build the jump table
	.text
jt:	.word default
	.word case1
	.word case2
	.word case3

	;; define the function
	.global swch
swch:	;; R12 is state, R13 is ledFlags
	;; R14, R15 are LED_RED and LED_GREEN
	
	;; First check if we are in range and jump if not
	cmp #4, r12
	jnc default
	
	;;  Move index into JT
	add r12, r12
	mov jt(r12), r0

	;; Build Case1
case1:	bis r14, r13 		;r13 |= r14 -> ledFlags |= LED_RED
	jmp end

	;; Build Case2
case2:	bis r15, r13		;r13 |= r15 -> ledFlags |= LED_GREEN
	jmp end

	;; Build Case3
case3:	bis r14, r13
	bis r15, r13
	jmp end

default:
end:
	mov r13, r12
	pop r0



