.global main
.data
var1:
	.byte "The total is ", 0 
number: .word 0
var0:
	.byte "Enter a number: ", 0 
count: .word 0
total: .word 0

.text

main:
addi		 $sp, $sp, -4
li		 $t0, 0
la		 $t1, total
sw		 $t0, 0($t1)
li		 $t0, 0
la		 $t1, count
sw		 $t0, 0($t1)

label_while_0:
la		 $t0, count
lw		 $t0, 0($t0)
li		 $t1, 3
slt		 $t2, $t0, $t1
beq		 $t2, $zero, label_while_end_1
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t1, number
sw		 $t0, 0($t1)
la		 $t0, count
lw		 $t0, 0($t0)
li		 $t1, 1
add		 $t2, $t0, $t1
la		 $t0, count
sw		 $t2, 0($t0)
la		 $t0, total
lw		 $t0, 0($t0)
la		 $t1, number
lw		 $t1, 0($t1)
add		 $t2, $t0, $t1
la		 $t0, total
sw		 $t2, 0($t0)
j		 label_while_0

label_while_end_1:
sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, total
lw		 $t0, 0($t0)
sw		 $ra, 0($sp)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
