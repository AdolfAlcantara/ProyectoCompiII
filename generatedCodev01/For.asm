.global main
.data
var1:
	.byte "End of loop", 0 
x: .word 0
var0:
	.byte "i = ", 0 
i: .word 0

.text

main:
addi		 $sp, $sp, -4
li		 $t0, 0
move		 $a0, $t0
li		 $t0, 15
move		 $a1, $t0
move		 $t0, $a0
move		 $t1, $a1
la		 $t2, i
sw		 $t0, 0($t2)
label_for_0:

slt		 $t2, $t0, $t1
beq		 $t2, $zero, label_end_for_1

sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
lw		 $ra, 0($sp)
la		 $t2, i
lw		 $t2, 0($t2)
sw		 $ra, 0($sp)
move		 $a0,$t2
jal		 print_int
lw		 $ra, 0($sp)
li		 $t2, 10
la		 $t3, i
lw		 $t3, 0($t3)
add		 $t4, $t2, $t3
la		 $t2, x
sw		 $t4, 0($t2)
la		 $t3, x
lw		 $t3, 0($t3)
sw		 $ra, 0($sp)
move		 $a0,$t3
jal		 print_int
lw		 $ra, 0($sp)
addi		 $t0, $t0, 1
la		 $t3, i
sw		 $t0, 0($t3)
j		 label_for_0

label_end_for_1:

sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra

