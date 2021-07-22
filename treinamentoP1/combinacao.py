# Solução teoricamente possivel Mas,
# inviavel na pratica


def comb(n,k):
	if(n==k):
		return 1
	else:
		return comb(n, k-1) * (1/k*(n-k))

print( comb(10,3) )
