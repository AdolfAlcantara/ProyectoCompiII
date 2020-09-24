.global main
.data
var0:
	.byte "Hello World", 0 

.text

main:
addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
