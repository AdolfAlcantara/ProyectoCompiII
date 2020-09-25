.global main
.data
true:
	.byte "true", 0
false:
	.byte "false", 0
var8:
	.byte "Mod ", 0 
var7:
	.byte "Div ", 0 
var9:
	.byte "Exp ", 0 
var6:
	.byte "Mul ", 0 
var4:
	.byte "Add ", 0 
var3:
	.byte " Y = ", 0 
var2:
	.byte "X = ", 0 
y: .word 0
var1:
	.byte "Enter another number: ", 0 
x: .word 0
var5:
	.byte "Sub ", 0 
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
sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
la		 $t0, x
lw		 $t0, 0($t0)
move		 $a0,$t0
jal		 print_int
la		 $a0,var3
jal		 print_str
la		 $t0, y
lw		 $t0, 0($t0)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var4
jal		 print_str
la		 $t1, x
lw		 $t1, 0($t1)
la		 $t2, y
lw		 $t2, 0($t2)
add		 $t0, $t1, $t2
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var5
jal		 print_str
la		 $t1, x
lw		 $t1, 0($t1)
la		 $t2, y
lw		 $t2, 0($t2)
sub		 $t0, $t1, $t2
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var6
jal		 print_str
la		 $t1, x
lw		 $t1, 0($t1)
la		 $t2, y
lw		 $t2, 0($t2)
mult		 $t1, $t2

mflo		 $t0
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var7
jal		 print_str
la		 $t1, x
lw		 $t1, 0($t1)
la		 $t2, y
lw		 $t2, 0($t2)
div		 $t1, $t2

mflo		 $t0
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var8
jal		 print_str
la		 $t0, x
lw		 $t0, 0($t0)
la		 $t1, y
lw		 $t1, 0($t1)
div		 $t0, $t1

mfhi		 $t2
move		 $a0,$t2
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
sw		 $ra, 0($sp)
la		 $a0,var9
jal		 print_str
la		 $t1, x
lw		 $t1, 0($t1)
la		 $t2, y
lw		 $t2, 0($t2)
li		 $t0, 1
label_pwd_0:
beq		 $t2,$zero, label_pwd_1
mult		 $t0, $t1
mflo		 $t0

addi		 $t2, $t2, -1
j		 label_pwd_0
label_pwd_1:
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
