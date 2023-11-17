int power(int base, unsigned int exp)
{
	if (exp == 0) return 1;
	if (exp == 1) return base;
	if (exp == 2) return base * base;

	int tmp = power(base, exp / 2);
	if (exp % 2 == 0)
		return tmp * tmp;
	else
		return base * tmp * tmp;
}