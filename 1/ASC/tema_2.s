.data
	n:.word 6
	v:.space 24
	spatiu:.asciiz " "
.text
suma_patrate:
	addi $sp,$sp,-8
	
	sw $ra,0($sp)
	sw $s2,4($sp)

	addi $s2,$a2,-1

	beq $s2,$zero,else

		move $a2,$s2
		jal suma_patrate

		mul $t6,$s2,$s2
		add $v0,$v0,$t6

	iesire:
		lw $ra,0($sp)
		lw $s2,4($sp)
		addi $sp,$sp,8
		jr $ra 
	else:
		li $v0,0
		j iesire

modifica:
	addi $sp,$sp,-12
	sw $ra,0($sp)
	sw $s0,4($sp)
	sw $s1,8($sp)

	addi $s1,$a1,-1
	move $s0,$a0
	li $t7,-2
	beq $s1,$t7,altelse
		
		move $a1,$s1
		addi $a0,$a0,-4
		jal modifica
		
		lw $a2, 0($s0)
		jal suma_patrate
		sw $v0, 0($s0)
	
	altiesire:
		lw $ra,0($sp)
		lw $s0,4($sp)
		lw $s1,8($sp)
		addi $sp,$sp,12
		jr $ra
	altelse:
		li $v0,0
		j altiesire
		
main:
	lw $t0,n
	li $t1,0
	li $t2,0
	li $t3,0
	li $t4,0


citire:
	bge $t1,$t0,alterare

	li $v0,5
	syscall
	sw $v0,v($t2)

	addi $t1,$t1,1
	addi $t2,$t2,4
	j citire



alterare:
	lw $a1,n
	la $a0,v     
	lw $t5,n
	add $t5,$t5,$t5
	add $t5,$t5,$t5
	add $a0,$a0,$t5
	jal modifica

afisare:
	bge $t3,$t0,exit

	lw $a0,v($t4)
	li $v0,1
	syscall
	
	la $a0,spatiu
	li $v0,4
	syscall

	addi $t3,$t3,1
	addi $t4,$t4,4

	j afisare
exit:
	li $v0,10
	syscall 