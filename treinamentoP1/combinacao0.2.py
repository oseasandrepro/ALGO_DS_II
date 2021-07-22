# Solução teoricamente possivel Mas,
# inviavel na pratica


def comb(n,k):
	if(k==0):
		return 1
	else:
		return comb(n-1,k-1) * (n / (k * (n-k) * (n-k-1)) )
		
print( comb(10,3) )
