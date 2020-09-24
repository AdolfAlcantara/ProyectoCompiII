.global main
.data
var1:
	.byte "This is what you entered: ", 0 
num: .word 0
var0:
	.byte "Enter a number : ", 0 

.text

main:
addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, num
sw		 $t0, 0($t1)
sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, num
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
