def comb(n,k):
	if(n==k):
		return 1
	else:
		return comb(n-1, k) * (n/(n-k))

print( comb(6,4) )
