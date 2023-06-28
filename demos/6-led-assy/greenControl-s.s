	.arch msp430g2553
	.p2align 1,0
	.text


	.global greenControl
	.extern P1OUT

greenControl:
	cmp #0, r12
	jz off
	bis #64, &P1OUT		;or
	pop r0
off:	and #~64, &P1OUT
	pop r0
