.global main
.data
var8:
	.byte "x != y: ", 0 
var7:
	.byte "x <= y: ", 0 
var9:
	.byte "x == y: ", 0 
var6:
	.byte "x >= y: ", 0 
var4:
	.byte "x > y: ", 0 
var3:
	.byte "y = ", 0 
var2:
	.byte "x = ", 0 
y: .word 0
var1:
	.byte "Enter another number: ", 0 
x: .word 0
var5:
	.byte "x < y: ", 0 
var0:
	.byte "Enter a number: ", 0 

.text

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
sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var3
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, y
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var4
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
slt		 $t2, $t1, $t0
sw		 $ra, 0($sp)
move		 $a0,$t2
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var5
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
slt		 $t2, $t0, $t1
sw		 $ra, 0($sp)
move		 $a0,$t2
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var6
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
slt		 $t2, $t1, $t0
sub		 $t3, $t0, $t1
slt		 $t0, $t3, $zero
slt		 $t1, $zero, $t3
xori		 $t0, $t0, 1
xori		 $t1, $t1, 0
xor		 $t3, $t0, $t1
or		 $t0, $t2, $t3
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var7
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
slt		 $t4, $t0, $t1
sub		 $t5, $t0, $t1
slt		 $t0, $t5, $zero
slt		 $t1, $zero, $t5
xori		 $t0, $t0, 1
xori		 $t1, $t1, 0
xor		 $t5, $t0, $t1
or		 $t0, $t4, $t5
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var8
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
sub		 $t6, $t0, $t1
slt		 $t0, $t6, $zero
slt		 $t1, $zero, $t6
xor		 $t6, $t0, $t1
sw		 $ra, 0($sp)
move		 $a0,$t6
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var9
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
sub		 $t6, $t0, $t1
slt		 $t0, $t6, $zero
slt		 $t1, $zero, $t6
xori		 $t0, $t0, 1
xori		 $t1, $t1, 0
xor		 $t6, $t0, $t1
sw		 $ra, 0($sp)
move		 $a0,$t6
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
