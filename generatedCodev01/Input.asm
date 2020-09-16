.global main
.data
var0:
	.byte "This is what you entered: ", 0 
num: .word 0

.text

main:
addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, num
sw		 $t0, 0($t1)
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, num
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

