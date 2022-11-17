#include "useful.h"

int main()
{
	struct ListNode list4(32,NULL),
					list3(4,&list4),
					list2(2,&list3),
					list1(1,&list2);
	
	struct ListNode list6(98,NULL),
					list7(4,&list6),
					list8(3,&list7),
					list9(1,&list8);
	
	struct ListNode *list;
	pro_21 so;
	list=so.mergeTwoLists(&list1,&list9);
	list=list->nextnode;
	while(list!=NULL)
	{
		cout<<list->val<<endl;
		list=list->nextnode;
	}
	return 0;
}
