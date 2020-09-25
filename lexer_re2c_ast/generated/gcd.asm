.global main
.data
true:
	.byte "true", 0
false:
	.byte "false", 0
z: .word 0
y: .word 0
var1:
	.byte "Introduzca otro numero: ", 0 
x: .word 0
var0:
	.byte "Introduzca un numero: ", 0 
b: .word 0
var2:
	.byte "El maximo comun divisor es ", 0 
a: .word 0

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

label_gcd_0:

addi		 $sp, $sp, -4
la		 $t0, a
sw		 $a0, 0($t0)
la		 $t0, b
sw		 $a1, 0($t0)
la		 $t0, b
lw		 $t0, 0($t0)
li		 $t1, 0
sub		 $t2, $t0, $t1
slt		 $t0, $t2, $zero
slt		 $t1, $zero, $t2
xori		 $t0, $t0, 1
xori		 $t1, $t1, 0
xor		 $t2, $t0, $t1

label_if_1:

beq		 $t2, $zero, label_else_2
la		 $t0, a
lw		 $t0, 0($t0)
move		 $v0, $t0
addi		 $sp, $sp, 4
jr		 $ra

j		 label_end_if_3

label_else_2:

la		 $t1, b
lw		 $t1, 0($t1)
move		 $a0, $t1
la		 $t1, a
lw		 $t1, 0($t1)
la		 $t2, b
lw		 $t2, 0($t2)
div		 $t1, $t2

mfhi		 $t3
move		 $a1, $t3
sw		 $ra, 0($sp)
jal		 label_gcd_0

lw		 $ra, 0($sp)
move		 $t0, $v0

move		 $v0, $t0
addi		 $sp, $sp, 4
jr		 $ra

label_end_if_3:

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
la		 $t1, x
lw		 $t1, 0($t1)
move		 $a0, $t1
la		 $t1, y
lw		 $t1, 0($t1)
move		 $a1, $t1
sw		 $ra, 0($sp)
jal		 label_gcd_0

lw		 $ra, 0($sp)
move		 $t0, $v0

la		 $t1, z
sw		 $t0, 0($t1)
sw		 $ra, 0($sp)
la		 $a0,var2
jal		 print_str
la		 $t0, z
lw		 $t0, 0($t0)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
