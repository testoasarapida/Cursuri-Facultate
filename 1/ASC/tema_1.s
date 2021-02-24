.data
	p:.space 4  #p citit de la tastatura
	generatorul:.space 4  #in aceasta variabila am salvat generatorul
	v:.space 40  #vectorul de incriptare
	copiev:.space 40  #copia lui v, folosita la sortare
	clar:.space 40  #sirul de incriptat
	criptat:.space 40  #sirul de decriptat
	neprim:.asciiz "numarul nu este prim"  #text de afisat daca p nu e prim
.text
main:
	li $v0,5
	syscall
	move $t0,$v0
	sw $t0,p  #citire p

	li $v0,8
	la $a0,clar
	li $a1,64
	syscall  #citire sir criptat
	
	li $v0,8
	la $a0,criptat
	li $a1,64
	syscall  #citire sir pentru incriptare

	li $t1,0  #variabila ok pentru testare numar prim se initializeaza cu 0
	li $t2,2	
	li $t3,0  #t2 si t3 sunt pentru verificarea diferitelor conditii de nr. prim
	li $t9,0  #t9 = 0 pentru majoritatea programului, aka 0 universal
	rem $t4,$t0,$t2  #pentru verificarea paritatii, t4=p%2
	
	
	bne $t0,$t2,elseif1  #if(p==2)
		li $t1,0  #ok=0
		j continua
	elseif1: 
		bge $t0,$t2,elseif2  #if(p<2)
			li $t1,1  #ok=1
			j continua
		elseif2: 
			bne $t4,$t3,elseif3  #if(p%2==0)
				li $t1,1  #ok=1
				j continua
			elseif3:
				div $t3,$t0,$t2 #t3 este incarcat cu jumatatea numarului care trebuie verificat
				li $t2,3  #t2 este contorul si incepe cu 3
				li $t4,0
				loop1: 
					bge $t2,$t3,continua  #for(d=3;d<=p/2;d=d+2)
					rem $t5,$t0,$t2  #se calculeaza restul impartirii
					bne $t5,$t4,maideparte #se verifica
						li $t1,1  #daca contorul se imparte la 0, testul pica, iar ok devine 1
					maideparte: 
						addi $t2,$t2,2  #saltul se face din cifra impara in cifra impara
						j loop1
		
	continua:
		beq $t1,$t9,else  #daca ok=1, atunci numarul nu e prim
			la $a0,neprim 
			li $v0,4
			syscall  #se afiseaza mesajul ca nu e prim
			j exit2
		else:  #daca ok=0, p e prim, si programul incepe sa calculeze generatorul
			li $t1,2  #t1 este contorul forului cu elementele grupului
			move $t2,$t0  #t2 contine conditia de iesire din for, anume primeste valoarea lui p
			generator:
				bge $t1,$t2,decriptare  #for(i=2;i<p;i++)

					li $t3,1  #contorul de zi cu zi al vectorului
					li $t4,4  #contorul de adresa

					sw $t3,v($t9)  #v[0]=1; pentru economia de registri, folosesc t3 si pentru acest pas
					sw $t3,copiev($t9)  #copiev[0]=1;

					move $t5,$t0
					addi $t5,$t5,-1  #t5 contine conditia de iesire din for, anume t5=p-1
					li $t6,1  #in t6 se va retine produsul de puteri

					calculareputere:  #se calculeaza puterea si restul ei si se memoreaza in vector
						bge $t3,$t5,sortare  #for(j=1;j<p-1;j++)

							mul $t6,$t6,$t1  #putere=putere*i
							move $t7,$t6
							rem $t7,$t7,$t0  #dupa ce s-a calculat puterea, se calculeaza restul in t7

							sw $t7,v($t4)  #se retin valorile in vector
							sw $t7,copiev($t4)  #si in copie se retin valorile

							addi $t3,$t3,1  #se creste contorul
							addi $t4,$t4,4  #si adresa se creste

							j calculareputere


					sortare:
						li $t3,0  #in t3 se retine 0, el fiind contor
						li $t4,0  #t4 e contorul de adresa
						move $t5,$t0  #in t5 se retine conditia de iesire din for
						addi $t5,$t5,-2  #t5=p-2
						
						primulfor:  #am folosit selection sort, cu cele doua foruri clasice
							bge $t3,$t5,verificare  #for(j=0;j<p-2;j++)
							
								move $t6,$t3  #t6 e contorul pentru al doilea for
								addi $t6,$t6,1  #t6=j+1
								move $t7,$t4  #asemenea si pentru adresa
								addi $t7,$t7,4  #t7=t4+4
								move $t8,$t0  #conditia de iesire din for
								addi $t8,$t8,-1  #t8=p-1
								
									aldoileafor:
										bge $t6,$t8,repeta  #for(k=j+1;k<p-1;k++)
									
											lw $s0,copiev($t7)  #s0=v[j]
											lw $s1,copiev($t4)  #s1=v[k]
											bge $s0,$s1,iesi  #se compara

												sw $s1,copiev($t7)
												sw $s0,copiev($t4)  #daca v[j]>v[k], atunci le interschimba
										
											iesi:
												addi $t6,$t6,1  #se creste contorul pentru al doilea for
												addi $t7,$t7,4  #si adresa se creste
												j aldoileafor

								repeta:
									addi $t3,$t3,1  #se creste contorul pentru primul for
									addi $t4,$t4,4  #si adresa se creste
									j primulfor
		
	
					verificare:
						li $t3,1  #contorul este initializat cu 1
						li $t4,4  #si contorul de adresa este initializat, cu 4
						move $t5,$t0  #in t5 se retine conditia de iesire din for
						addi $t5,$t5,-1  #t5=p-1
						li $t6,0  #t6 va fi o variabila de tip ok, initializata cu 0
						loop2:
							bge $t3,$t5,incearca  #for(j=1;j<p-1;j++)
								lw $t7,copiev($t4)  #t7=v[t3]
								move $t9,$t4
								addi $t9,$t9,-4
								lw $t8,copiev($t9)  #t8=v[t3-1]
								addi $t8,$t8,1  #t8++
								
								beq $t7,$t8,aici  #if(t7 != t8)
									li $t6,1  #t6=1, variabila devine 1
								
								aici:
									addi $t3,$t3,1  #creste contorul
									addi $t4,$t4,4  #creste si adresa
									j loop2                                                        


					incearca:
						li $t3,0  #t3=0
						bne $t3,$t6,abort  #daca variabila t6 a ramas 0, s-a descoperit generatorul si va fi memorat
							sw $t1,generatorul  #generatorul este de fapt variabila i
							move $t4,$t0
							addi $t4,$t4,1					
							move $t1,$t4  #din moment ce s-a descoperit generatorul, variabila i creste acum la p+1 pentru a se iesi din for

						abort:  #in caz ca t6 a devenit 1, se creste variabila i si forul o ia de la capat
							addi $t1,$t1,1 #i++
							j generator


									
	decriptare:
		li $t1,0  #se initializeaza contorul, t1=0
		li $t2,4  #se initializeaza conditia de iesire, t2=4
		loop3:  #se parcurge sirul clar
			bge $t1,$t2,afisare1  #for(i=0;i<4;i++)
				lb $t3,clar($t1)  #t3 primeste caracterul de pe pozitia i
				addi $t3,$t3,-65 #se scade 65 pentru a putea fi corelat cu vectorul de criptare
				li $t4,4  #t4 este initializat cu 4
				mul $t3,$t3,$t4 #se inmulteste t3 cu 4 pentru a se obtine adresa din vector
			 	lw $t3,v($t3)  #t3 primeste noua valoare din vector
				addi $t3,$t3,65  #t3+=65 pentru a se ajunge la valoarea din tabelul ASCII
				sb $t3,clar($t1)  #se retine in sirul original, tot pe pozitia i
				addi $t1,$t1,1  #creste contorul, i++
				j loop3
	afisare1:
		la $a0,clar
		li $v0,4
		syscall  #primul sir se afiseaza in noua forma, cea criptata
		
		criptare:
			li $t1,0  #se initializeaza contorul pentru al doilea string
			li $t2,4  #se initializeaza conditia de iesire
			loop4:
				bge $t1,$t2,afisare2  #for(i=0;i<4;i++)
					li $t3,0  #t3 e contor, va fi initializat cu 0
					li $t4,0  #t4 e contor de adresa
					move $t5,$t0  #t5 e conditia de iesire
					addi $t5,$t5,-1  #t5=p-1
					loop5:
						bge $t3,$t5,maiincearca  #for(j=0;j<p-1;j++)
							lw $t6,v($t4)  #in t6 se retine valoarea de la adresa t4 din vector
							lb $t7,criptat($t1)  #in t7 se retine caracterul de pe poztia criptat[i]
							addi $t7,$t7,-65  #se scade 65 din t7 pentru a putea fi corelat cu vectorul
							bne $t6,$t7,goaway  #if(t6==t7)
								addi $t8,$t3,65  #t8=j+65
								sb $t8,criptat($t1)  #se retine t8 in string pe aceeasi pozitie
							goaway:
								addi $t3,$t3,1  #se creste contorul vectorului
								addi $t4,$t4,4  #si se creste adresa
								j loop5
					maiincearca:
						addi $t1,$t1,1  #se creste si contorul stringului
						j loop4

			afisare2:
				la $a0,criptat
				li $v0,4
				syscall  #se afiseaza stringul in forma decriptata
						

	
	exit2:
		li $v0,10
		syscall  #gata
