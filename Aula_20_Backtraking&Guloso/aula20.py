import random

def EscreverSol(R, N):

	for i in range(1, N+1):
		for j in range(1, N+1):
			print("|", end="")
			if R[i] == j:
				print("D", end="")
			else:
				print(" ", end="")
		print("|")

def DamasPacificas(N, d, R): 
	#N = tabuleiro NxN
	#até a d-ésima decisão já feita
	#a d-ésima decisão é decidir em que coluna vai a dama da linha d
	#retorna V se encontrou uma solução, e F caso contrário 
		
	if d==N:
		EscreverSol(R, N)
		return True
	else:
		for i in range(1, N+1):
			pode = True
			for x in range(d):
				#...
				#		 i-(x+1)  i	 i+(x+1)
				#d-x     	 X    X    X
				#...			....
				#d-1			X X X	
				#d-0			 XXX
				#d+1           	  	  X
				c1 = i-(x+1)
				c2 = i+(x+1)
				pode = pode and \
					(c1 <= 0 or R[d-x] != c1) and \
					R[d-x] != i and \
					(c2 > N or R[d-x] != c2)
			if pode:
				R[d+1] = i
				if DamasPacificas(N, d+1, R):
					return True
		return False

def Ex08Backtracking():
	N = 4
	R = [None]*(N+1)
	if DamasPacificas(N, 0, R):
		print("Encontrei a solução (veja acima)!")
	else:
		print("Não encontrei nenhuma solução (e olha que tentei)!")

def DamasPacificasGuloso(N, d, R): 
	if d==N:
		EscreverSol(R, N)
	else:
		for i in range(1, N+1):
			pode = True
			for x in range(d):
				#...
				#		 i-(x+1)  i	 i+(x+1)
				#d-x     	 X    X    X
				#...			....
				#d-1			X X X	
				#d-0			 XXX
				#d+1           	  X
				c1 = i-(x+1)
				c2 = i+(x+1)
				pode = pode and \
					(c1 <= 0 or R[d-x] != c1) and \
					R[d-x] != i and \
					(c2 > N or R[d-x] != c2)
			if pode:
				R[d+1] = i
				DamasPacificasGuloso(N, d+1, R)
				break

def Ex08Guloso():
	#a d-ésima decisão é decidir em que coluna vai a dama da linha d, sendo que
	#há uma escolha gulosa: colocar a dama na primeira coluna da linha d que não 
	#conflite com as anteriores
	
	N = 7
	R = [None]*(N+1)
	DamasPacificasGuloso(N, 0, R)


def DamasPacificasRandomizado(N, d, R): 
	if d==N:
		EscreverSol(R, N)
	else:
		Lpode = []
		for i in range(1, N+1):
			pode = True
			for x in range(d):
				#...
				#		 i-(x+1)  i	 i+(x+1)
				#d-x     	 X    X    X
				#...			....
				#d-1			X X X	
				#d-0			 XXX
				#d+1           	  X
				c1 = i-(x+1)
				c2 = i+(x+1)
				pode = pode and \
					(c1 <= 0 or R[d-x] != c1) and \
					R[d-x] != i and \
					(c2 > N or R[d-x] != c2)
			if pode:
				Lpode.append(i)
		
		i = Lpode[random.randint(0,len(Lpode)-1)]
				
		R[d+1] = i
		DamasPacificasGuloso(N, d+1, R)

def Ex08Randomizado():
	
	N = 7
	R = [None]*(N+1)
	DamasPacificasRandomizado(N, 0, R)


Ex08Randomizado()
