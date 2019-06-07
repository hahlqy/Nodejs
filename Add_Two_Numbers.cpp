#include<iostream>
using namespace std; 
/**
 Definition for singly-linked list.*/
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        int val = l1->val+l2->val;
        add = val / 10;
        val = val % 10;
        ListNode* LN = new ListNode(val);
		ListNode* p = LN; 
        ListNode* p1=l1->next;
        ListNode* p2=l2->next;
        if(p1==NULL&&p2==NULL&&add){
            ListNode *ps = new ListNode(add);
			p->next = ps;
            return LN;
        }
        while(p1||p2){
        	if(p1!=NULL && p2!=NULL){
        		val = p1->val + p2->val + add;
				add = val / 10;
				val = val % 10;
				ListNode *pnew = new ListNode(val);
				p->next = pnew;
				p = pnew; 
				p1 = p1->next;
				p2 = p2->next;
				if(p1==NULL&&p2==NULL&&add){
                    ListNode *ps = new ListNode(1);
					p->next = ps;
					break;
                }
			}
			else if(p1!=NULL){
				val = p1->val + add;
				add = val / 10;
				val = val % 10;
				ListNode *pnew = new ListNode(val);
				p->next = pnew;
				p = pnew;
				p1 = p1->next;
				if(p1==NULL){
					ListNode *ps = new ListNode(1);
					p->next = ps;
					break;
				}
			}
			else if(p2!=NULL){
				val = p2->val + add;
				add = val / 10;
				val = val % 10;
				ListNode *pnew = new ListNode(val);
				p->next = pnew;
				p = pnew;
				p2 = p2->next;
				if(p2==NULL){
					ListNode *ps = new ListNode(1);
					p->next = ps;
					break;
				}
			}
		}
		return LN;
    }
    ListNode* Creat(int val[],int len){
    	ListNode* LN = new ListNode(val[len-1]);
    	ListNode* p = LN;
		for(int i=len-2;i>=0;i--){
			ListNode* pnew = new ListNode(val[i]);
			p->next = pnew;
			p = pnew;
		} 
		return LN;
	}
	void showList(ListNode* l){
		ListNode* p = l;
		while(p!=NULL){
			cout<<p->val;
			p = p->next;
		} 
		cout<<endl;
	}
};

int main(){
	int a1[] = {6};
	int a2[] = {4};
	Solution su = Solution();
	ListNode* l1=su.Creat(a1,1);
	ListNode* l2=su.Creat(a2,1);
	ListNode* l3=su.addTwoNumbers(l1,l2);
	su.showList(l3);
	return 0;
}
