/**Running time:9ms beats 19.72%...
**这道题很多坑
**/
int reverse(int x) {
    int reverse(int x) {
    if (x >-10 && x < 10)
		return x;
	double t = 0.1, num = 0;
	int i;
	vector<double> digit;
	while (x != 0)
	{
		t *= 10;
		digit.push_back(x % 10);
		x /= 10;
	}
	int len = digit.size();
	for (i = 0; i < len; i++)
	{
		num += t*digit[i];
		t /= 10;
	}
	if (num > INT_MAX || num < INT_MIN)
		    return 0;
	return (int)num;
    }
    }