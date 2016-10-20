int myAtoi(string str) {
	int i, len = str.length(), inword = 0, postive = 1, count = 0;
	long long integer = 0;//intmax = INT_MAX, intmin = INT_MIN;
	if (len == 0)
		return 0;
	
	for (i = 0; i < len; i++) {
		if (!inword) {
			if (str[i] == '-') {
				postive = -1;
				inword = 1;
				continue;
			}
			if (str[i] == '+') {
				inword = 1;
				continue;
			}
			if (str[i] == '0' || str[i] == ' ')
				continue;
			if (str[i] >= '1' && str[i] <= '9') {
				inword = 1;
				integer = integer * 10 + (str[i] - '0');
				
				continue;
			}
			else
				return 0;
		}
		else {
			if (str[i] >= '0' && str[i] <= '9') {
				integer = integer * 10 + (str[i] - '0');
				count++;
				if (count > 10)
					break;
			}
			else
				break;
		}
	}
	integer *= postive;
	if (count > 10 && postive == 1)
		return INT_MAX;
	if (count > 10 && postive == -1)
		return INT_MIN;
	if ((integer >= INT_MAX || integer <= INT_MIN) && postive == 1)
		return INT_MAX;
	else if ((integer <= INT_MIN || integer >= INT_MAX) && postive == -1)
		return INT_MIN;
	else
		return integer;
}