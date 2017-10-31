int p_abs(int n)
{
	int t = (unsigned int)n >> (sizeof(int)* 8 -1);
	return ( -t) ^ (n-t);
}
