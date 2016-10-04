/**Running time :3ms beats 11.89%
**很简单的题目，但是眼注意检查边界。if语句先检查是否超出边界，在判断值
**/
int lengthOfLastWord(string s) {
        int len = 0, i = 0;
	    while (s[i] != '\0')
		    i++;
	    --i;
	    while (i >= 0 && s[i] == ' ')
		    i--;
	    while (i >= 0 && s[i--] != ' ')
		    len++;
	    return len;
    }