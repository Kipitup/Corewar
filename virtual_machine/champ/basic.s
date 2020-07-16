.name "basic"
.comment "I'm basic"

l2:		sti r1, %:live, %1
		and %0, %0, r2

live:	live %1
		zjmp %:live
