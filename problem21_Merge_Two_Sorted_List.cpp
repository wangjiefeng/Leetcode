/**Running time:6ms
**就是归并排序的一部分啊，可是不够简洁
**/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        ListNode *lp1 = l1, *lp2 = l2;
	    int val;
    	ListNode *lHead = new ListNode(0);
    	ListNode *lEnd = lHead;
    	while (lp1 != nullptr && lp2 != nullptr) {
	       	lEnd->next = new ListNode(0);
	    	if (lp1->val < lp2->val) {
		    	val = lp1->val;
		    	lp1 = lp1->next;
	    	}
	    	else {
		    	val = lp2->val;
		    	lp2 = lp2->next;
	    	}
	        lEnd->val = val;
		    lEnd = lEnd->next;
    	}
	    if (lp1 == nullptr && lp2 != nullptr) {
	    	while (lp2 != nullptr) {
		    	lEnd->next = new ListNode(0);
		    	lEnd->val = lp2->val;
		    	lEnd = lEnd->next;
		    	lp2 = lp2->next;
	    	}
    	}
	    if (lp2 == nullptr &&lp1 != nullptr) {
	    	while (lp1 != nullptr) {
		    	lEnd->next = new ListNode(0);
		    	lEnd->val = lp1->val;
			    lEnd = lEnd->next;
		    	lp1 = lp1->next;
		    }
    	}
	    lEnd = lHead;
    	while (lEnd->next->next != nullptr)
	    	lEnd = lEnd->next;
	    delete lEnd->next;
    	lEnd->next = nullptr;
	    return lHead;
        }