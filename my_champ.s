.name "basic"
.comment "I'm basic"

l2:		sti r1, %:live, %1		#change live by the right value
		and %0, %0, r2			#carry = 1	

ld	%1, r3
ld	%33, r6

live:	live %1
		zjmp %:live
