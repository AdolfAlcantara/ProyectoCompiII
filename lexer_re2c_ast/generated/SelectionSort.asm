.global main
.data
temp: .word 0
pos: .word 0
min_idx: .word 0
i: .word 0
end: .word 0
start: .word 0
arr: .word 0

.text

label_getMin_0:

addi		 $sp, $sp, -4
la		 $t0, arr
sw		 $a0, 0($t0)
la		 $t0, start
sw		 $a1, 0($t0)
la		 $t0, end
sw		 $a2, 0($t0)
la		 $t0, start
lw		 $t0, 0($t0)
la		 $t1, min_idx
sw		 $t0, 0($t1)
la		 $t0, start
lw		 $t0, 0($t0)
move		 $a0, $t0
la		 $t0, end
lw		 $t0, 0($t0)
li		 $t1, 1
add		 $t2, $t0, $t1
move		 $a1, $t2
move		 $t0, $a0
move		 $t1, $a1
la		 $t2, i
sw		 $t0, 0($t2)
label_for_1:

la		 $t2, i
lw		 $t2, 0($t2)
slt		 $t0, $t2, $t1
beq		 $t0, $zero, label_end_for_2

la		 $t0, min_idx
lw		 $t0, 0($t0)
sll		 $t0, $t0, 2
addi		 $t0,$t0, 4
la		 $t2, arr
lw		 $t2, 0($t2)
add		 $t2, $t0, $t2

lw $t3, 0($t2)

la		 $t2, i
lw		 $t2, 0($t2)
sll		 $t2, $t2, 2
addi		 $t2,$t2, 4
la		 $t4, arr
lw		 $t4, 0($t4)
add		 $t4, $t2, $t4

lw $t5, 0($t4)

slt		 $t4, $t5, $t3

label_if_3:

beq		 $t4, $zero, label_else_4
la		 $t3, i
lw		 $t3, 0($t3)
la		 $t4, min_idx
sw		 $t3, 0($t4)
j		 label_end_if_5

label_else_4:

label_end_if_5:

la		 $t0, i
lw		 $t0, 0($t0)
addi		 $t0, $t0, 1
la		 $t3, i
sw		 $t0, 0($t3)
j		 label_for_1

label_end_for_2:

la		 $t0, min_idx
lw		 $t0, 0($t0)
move		 $v0, $t0
addi		 $sp, $sp, 4
jr		 $ra

addi		 $sp, $sp, 4
jr		 $ra


label_printArray_6:

addi		 $sp, $sp, -4
la		 $t0, arr
sw		 $a0, 0($t0)
li		 $t0, 0
move		 $a0, $t0
li		 $t0, 10
move		 $a1, $t0
move		 $t0, $a0
move		 $t1, $a1
la		 $t3, i
sw		 $t0, 0($t3)
label_for_7:

la		 $t3, i
lw		 $t3, 0($t3)
slt		 $t0, $t3, $t1
beq		 $t0, $zero, label_end_for_8

la		 $t0, i
lw		 $t0, 0($t0)
sll		 $t0, $t0, 2
addi		 $t0,$t0, 4
la		 $t3, arr
lw		 $t3, 0($t3)
add		 $t3, $t0, $t3

lw $t4, 0($t3)

sw		 $ra, 0($sp)
move		 $a0,$t4
jal		 print_int
li		 $a0, 10
jal		 print_char
lw		 $ra, 0($sp)
la		 $t0, i
lw		 $t0, 0($t0)
addi		 $t0, $t0, 1
la		 $t3, i
sw		 $t0, 0($t3)
j		 label_for_7

label_end_for_8:

addi		 $sp, $sp, 4
jr		 $ra


label_selectionSort_9:

addi		 $sp, $sp, -4
la		 $t0, arr
sw		 $a0, 0($t0)
la		 $t0, start
sw		 $a1, 0($t0)
la		 $t0, end
sw		 $a2, 0($t0)
la		 $t0, start
lw		 $t0, 0($t0)
la		 $t1, end
lw		 $t1, 0($t1)
slt		 $t3, $t0, $t1

label_if_10:

beq		 $t3, $zero, label_else_11
la		 $t0, arr
lw		 $t0, 0($t0)
move		 $a0, $t0
la		 $t0, start
lw		 $t0, 0($t0)
move		 $a1, $t0
la		 $t0, end
lw		 $t0, 0($t0)
move		 $a2, $t0
sw		 $ra, 0($sp)
jal		 label_getMin_0

lw		 $ra, 0($sp)
move		 $t0, $v0

la		 $t1, pos
sw		 $t0, 0($t1)
la		 $t0, pos
lw		 $t0, 0($t0)
la		 $t1, start
lw		 $t1, 0($t1)
sub		 $t3, $t0, $t1
slt		 $t0, $t3, $zero
slt		 $t1, $zero, $t3
xor		 $t3, $t0, $t1

label_if_13:

beq		 $t3, $zero, label_else_14
la		 $t0, start
lw		 $t0, 0($t0)
sll		 $t0, $t0, 2
addi		 $t0,$t0, 4
la		 $t1, arr
lw		 $t1, 0($t1)
add		 $t1, $t0, $t1

lw $t3, 0($t1)

la		 $t1, temp
sw		 $t3, 0($t1)
la		 $t1, start
lw		 $t1, 0($t1)
sll		 $t1, $t1, 2
addi		 $t1,$t1, 4
la		 $t3, arr
lw		 $t3, 0($t3)
add		 $t3, $t1, $t3

la		 $t1, pos
lw		 $t1, 0($t1)
sll		 $t1, $t1, 2
addi		 $t1,$t1, 4
la		 $t4, arr
lw		 $t4, 0($t4)
add		 $t4, $t1, $t4

lw $t5, 0($t4)

sw		 $t5, 0($t3)

la		 $t0, pos
lw		 $t0, 0($t0)
sll		 $t0, $t0, 2
addi		 $t0,$t0, 4
la		 $t3, arr
lw		 $t3, 0($t3)
add		 $t3, $t0, $t3

la		 $t0, temp
lw		 $t0, 0($t0)
sw		 $t0, 0($t3)

j		 label_end_if_15

label_else_14:

label_end_if_15:

la		 $t0, arr
lw		 $t0, 0($t0)
move		 $a0, $t0
la		 $t0, start
lw		 $t0, 0($t0)
li		 $t3, 1
add		 $t4, $t0, $t3
move		 $a1, $t4
la		 $t0, end
lw		 $t0, 0($t0)
move		 $a2, $t0
sw		 $ra, 0($sp)
jal		 label_selectionSort_9

lw		 $ra, 0($sp)
move		 $t0, $v0

j		 label_end_if_12

label_else_11:

label_end_if_12:

addi		 $sp, $sp, 4
jr		 $ra


main:
addi		 $sp, $sp, -4
addi		 $sp, $sp, -40

li		 $t0, 100
sw		 $t0, 4($sp)
li		 $t0, 2
sw		 $t0, 8($sp)
li		 $t0, 67
sw		 $t0, 12($sp)
li		 $t0, 38
sw		 $t0, 16($sp)
li		 $t0, 76
sw		 $t0, 20($sp)
li		 $t0, 12
sw		 $t0, 24($sp)
li		 $t0, 50
sw		 $t0, 28($sp)
li		 $t0, 62
sw		 $t0, 32($sp)
li		 $t0, 14
sw		 $t0, 36($sp)
li		 $t0, 60
sw		 $t0, 40($sp)
la $t0, arr
sw $sp, 0($t0)

la		 $t0, arr
lw		 $t0, 0($t0)
move		 $a0, $t0
li		 $t0, 0
move		 $a1, $t0
li		 $t0, 10
li		 $t3, 1
sub		 $t4, $t0, $t3
move		 $a2, $t4
sw		 $ra, 0($sp)
jal		 label_selectionSort_9

lw		 $ra, 0($sp)
move		 $t0, $v0

la		 $t0, arr
lw		 $t0, 0($t0)
move		 $a0, $t0
sw		 $ra, 0($sp)
jal		 label_printArray_6

lw		 $ra, 0($sp)
move		 $t0, $v0

addi		 $sp, $sp, 4
jr		 $ra
