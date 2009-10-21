int fibo(int n)
{
	int z1 = 0, z2 = 1, tmp, i;

	if(n == 0)
		return 0;

	if(n == 1)
		return 1;

	if(n < 0)
		return -1;

	for(i = 2; i <= n; i++)
	{
		tmp = z2;
		z2 += z1;
		z1 = tmp;
	}
	return z2;
}