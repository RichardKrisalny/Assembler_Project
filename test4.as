.entry			  LOOP
.entry 			 LENGTH
.extern  			 L3 
.extern				 W
MAIN:		mov 	S1.1 ,W
			add r2 , STR
	 		jp  W
			macro m1          
			inc  K
			mov S1.2, #3
			endmacro   
			prn 	#500
			sub r1, r50
			m1             		
			bne	  L3
END:		hlt
STR:		.string	     		"abcdef"
LENGTH:	.data        		6,-9,15
K:			.data       		22
S1:			.struct         	8, "ab"
LENGTH:	.data        		   	6,-9,15
MAIN:		mov 	S1.1 ,W         
