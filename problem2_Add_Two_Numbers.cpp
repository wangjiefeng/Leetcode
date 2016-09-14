/**仍然是又臭又长，自己再看一遍都有问题                 Runtime:26ms
**1、计算出较短链表的长度（后面的for循环以此为循环次数）
**2、先计算出第一位的结果，创建head，为结果链表的第一个链表
**3、循环相加
**Editorial Solution十分简洁！！然后还体会到三目运算符的强大
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0, len = 0, carry = 0;
	ListNode *lp1 = l1, *lp2 = l2, *head = NULL, *lp = NULL;
	while (lp1->next)
	{
		len1++;
		lp1 = lp1->next;
	}
	while (lp2->next)
	{
		len2++;
		lp2 = lp2->next;
	}
	len = (len1>len2) ? len2 : len1;
	lp1 = l1;
	lp2 = l2;
	head = new ListNode(carry);
	lp = head;
	head->val = lp1->val + lp2->val;
	lp1 = lp1->next;
	lp2 = lp2->next;
	for (int i = 0; i < len; i++)
	{
		if (lp->val >= 10)
		{
			lp->val -= 10;
			carry = 1;
		}
		lp->next = new ListNode(carry);
		lp = lp->next;
		lp->val += lp1->val + lp2->val;
		carry = 0;
		lp1 = lp1->next;
		lp2 = lp2->next;
	}
	if (!lp1 && ! lp2)
	{
	    if(lp->val >= 10)
	    {
		    lp->next = new ListNode(1);
		    lp->val -= 10;
		    lp = lp->next;
	    }
	}
	else
	{
        //取较长的链表的剩余部分
		ListNode *last = (lp1 == NULL) ? lp2 : lp1;
		while (last)
		{
			if (lp->val >= 10)
			{
				lp->val -= 10;
				carry = 1;
			}
			lp->next = new ListNode(carry);
			lp = lp->next;
			lp->val += last->val;
			carry = 0;
			last = last->next;
		}
	}
    //最后一位，检查是否大于9
	if (lp->val >= 10)
	{
		lp->val -= 10;
		lp->next = new ListNode(1);
		lp = lp->next;
	}
	lp->next = NULL;
	return head;
    }
};