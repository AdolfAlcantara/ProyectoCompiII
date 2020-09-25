.global main
.data
true:
	.byte "true", 0
false:
	.byte "false", 0
var4:
	.byte "X is not equal to Y", 0 
var3:
	.byte "X is less than Y", 0 
var2:
	.byte "X is equal to Y", 0 
y: .word 0
var1:
	.byte "Enter another number : ", 0 
x: .word 0
var0:
	.byte "Enter a number: ", 0 

.text
print_true:

addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
la		 $a0, true
jal		 print_str
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

print_false:

addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
la		 $a0, false
jal		 print_str
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

main:
addi		 $sp, $sp, -4
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, x
sw		 $t0, 0($t1)
sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, y
sw		 $t0, 0($t1)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
sub		 $t2, $t0, $t1
slt		 $t0, $t2, $zero
slt		 $t1, $zero, $t2
xori		 $t0, $t0, 1
xori		 $t1, $t1, 0
xor		 $t2, $t0, $t1

label_if_0:

beq		 $t2, $zero, label_else_1
sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
j		 label_end_if_2

label_else_1:

la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
slt		 $t2, $t0, $t1

label_if_3:

beq		 $t2, $zero, label_else_4
sw		 $ra, 0($sp)
la		 $a0,var3
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
j		 label_end_if_5

label_else_4:

sw		 $ra, 0($sp)
la		 $a0,var4
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
label_end_if_5:

label_end_if_2:

addi		 $sp, $sp, 4
jr		 $ra
