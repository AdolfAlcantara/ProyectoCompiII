.global main
.data
var4:
	.byte "X is not equal", 0 
var3:
	.byte "X is less than Y", 0 
var2:
	.byte "X is not equal to Y", 0 
var0:
	.byte "X is equal to Y", 0 
var1:
	.byte "X is more than Y", 0 
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
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t3, y
lw		 $t3, 0($t3)
sub		 $t4, $t0, $t3
slt		 $t0, $t4, $zero
slt		 $t3, $zero, $t4
xori		 $t0, $t0, 1
xori		 $t3, $t3, 0
xor		 $t4, $t0, $t3

label_if_0:

beq		 $t4, $zero, label_else_1
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
lw		 $ra, 0($sp)
la		 $t0, y
lw		 $t0, 0($t0)
li		 $t3, 1
add		 $t4, $t0, $t3
la		 $t0, x
sw		 $t4, 0($t0)
la		 $t3, x
lw		 $t3, 0($t3)
sw		 $ra, 0($sp)
move		 $a0,$t3
jal		 print_int
lw		 $ra, 0($sp)
j		 label_end_if_2

label_else_1:

la		 $t3, x
lw		 $t3, 0($t3)
la		 $t4, y
lw		 $t4, 0($t4)
slt		 $t5, $t4, $t3

label_if_3:

beq		 $t5, $zero, label_else_4
sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
lw		 $ra, 0($sp)
la		 $t3, x
lw		 $t3, 0($t3)
li		 $t4, 10
add		 $t5, $t3, $t4
la		 $t3, y
sw		 $t5, 0($t3)
la		 $t4, y
lw		 $t4, 0($t4)
sw		 $ra, 0($sp)
move		 $a0,$t4
jal		 print_int
lw		 $ra, 0($sp)
j		 label_end_if_5

label_else_4:

sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
lw		 $ra, 0($sp)
la		 $t4, x
lw		 $t4, 0($t4)
la		 $t5, y
lw		 $t5, 0($t5)
slt		 $t6, $t4, $t5

label_if_6:

beq		 $t6, $zero, label_else_7
sw		 $ra, 0($sp)
la		 $a0,var3
jal		 print_str
lw		 $ra, 0($sp)
j		 label_end_if_8

label_else_7:

sw		 $ra, 0($sp)
la		 $a0,var4
jal		 print_str
lw		 $ra, 0($sp)
label_end_if_8:

label_end_if_5:

label_end_if_2:

li		 $t4, 10
la		 $t5, x
sw		 $t4, 0($t5)
la		 $t4, x
lw		 $t4, 0($t4)
sw		 $ra, 0($sp)
move		 $a0,$t4
jal		 print_int
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

