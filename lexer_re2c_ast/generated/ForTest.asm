.global main
.data
true:
	.byte "true", 0
false:
	.byte "false", 0
var1:
	.byte "End of loop", 0 
var0:
	.byte "i = ", 0 
i: .word 0

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
li		 $t0, 0
move		 $a0, $t0
li		 $t0, 10
move		 $a1, $t0
move		 $t0, $a0
move		 $t1, $a1
la		 $t2, i
sw		 $t0, 0($t2)
label_for_0:

la		 $t2, i
lw		 $t2, 0($t2)
slt		 $t0, $t2, $t1
beq		 $t0, $zero, label_end_for_1

sw		 $ra, 0($sp)
la		 $a0,var0
jal		 print_str
la		 $t0, i
lw		 $t0, 0($t0)
move		 $a0,$t0
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, i
lw		 $t0, 0($t0)
addi		 $t0, $t0, 1
la		 $t2, i
sw		 $t0, 0($t2)
j		 label_for_0

label_end_for_1:

sw		 $ra, 0($sp)
la		 $a0,var1
jal		 print_str
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
addi		 $sp, $sp, 4
jr		 $ra
