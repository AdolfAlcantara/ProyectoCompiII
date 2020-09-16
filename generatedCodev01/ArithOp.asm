.global main
.data
var3:
	.byte "Sub ", 0 
var2:
	.byte "Add ", 0 
var0:
	.byte "X = ", 0 
var1:
	.byte " Y = ", 0 
y: .word 0
x: .word 0

.text

main:
addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, x
sw		 $t0, 0($t1)
sw		 $ra, 0($sp)
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t2, y
sw		 $t0, 0($t2)
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, y
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t3, y
lw		 $t3, 0($t3)
add		 $t4, $t0, $t3
sw		 $ra, 0($sp)
move		 $a0,$t4
jal		 print_int
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var3
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t3, y
lw		 $t3, 0($t3)
sub		 $t4, $t0, $t3
sw		 $ra, 0($sp)
move		 $a0,$t4
jal		 print_int
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
