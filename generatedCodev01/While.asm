.global main
.data
var0:
	.byte "The total is ", 0 
number: .word 0
count: .word 0
total: .word 0

.text

main:
addi		 $sp, $sp, -4
li		 $t0, 0
la		 $t1, total
sw		 $t0, 0($t1)
li		 $t0, 0
la		 $t2, count
sw		 $t0, 0($t2)

label_while_0:
la		 $t0, count
lw		 $t0, 0($t0)
li		 $t3, 3
slt		 $t4, $t0, $t3
beq		 $t4, $zero, label_while_end_1
sw		 $ra, 0($sp)
jal read_int
move		 $t0, $v0
lw		 $ra, 0($sp)
la		 $t3, number
sw		 $t0, 0($t3)
la		 $t0, count
lw		 $t0, 0($t0)
li		 $t4, 1
add		 $t5, $t0, $t4
la		 $t0, count
sw		 $t5, 0($t0)
la		 $t4, total
lw		 $t4, 0($t4)
la		 $t5, number
lw		 $t5, 0($t5)
add		 $t6, $t4, $t5
la		 $t4, total
sw		 $t6, 0($t4)
j		 label_while_0

label_while_end_1:
sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
lw		 $ra, 0($sp)
la		 $t5, total
lw		 $t5, 0($t5)
sw		 $ra, 0($sp)
move		 $a0,$t5
jal		 print_int
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

