
#include<stdio.h>
#include<stdlib.h>
struct node{
	float coef;
	int expo;
	struct node*next;
};
typedef struct node NODE;
NODE* insert_a_term(NODE* head,float co,int ex){
	NODE *new_term = (NODE *)malloc(sizeof(NODE));
	new_term->coef=co;
	new_term->expo=ex;
	new_term->next=NULL;
	if(head==NULL || ex > head->expo)
	{
		new_term->next=head;
		head=new_term;
	}
	else{
		NODE *temp=head;
		while(temp->next!=NULL && temp -> next -> expo >ex)
		{
			temp=temp->next;
		}
		new_term->next= temp->next;
		temp->next=new_term;
		
	}
	return head;
}
NODE* create_polynomial(){
	NODE *head=NULL;
	int n;
	printf("enter no of terms: ");
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		float co;
		int ex;
		printf("Enter coeff of term %d: ",i);
		scanf("%f",&co);
		printf("Enter expo of term %d: ",i);
		scanf("%d",&ex);
		head= insert_a_term(head,co,ex);
		
	}
	return head;
}
void display_polynomial(NODE* head)
{
	NODE *temp = head;
	while(temp != NULL){
		printf("(%.1fx^%d)",temp->coef,temp->expo);
		if (temp->next!=NULL){
			printf(" + ");
		}
		else{
			printf("\n");
		}
		temp=temp->next;
	}
}
NODE* poly_addition(NODE *poly1,NODE *poly2)
{
	NODE *t1=poly1;
	NODE *t2=poly2;
	NODE *head=NULL;  //for resultant polynomial
	while(t1!=NULL && t2!=NULL){
		if(t1->expo == t2->expo){
			head=insert_a_term(head,t1->coef+t2->coef,t1->expo);
			t1=t1->next;
			t2=t2->next;
		}
		else if (t1 -> expo > t2 -> expo)
		{
			head=insert_a_term(head,t1->coef,t1->expo);
			t1=t1->next;
		}
		else{
				head=insert_a_term(head,t2->coef,t2->expo);
			t2=t2->next;
		}
	}
	while(t1!=NULL){
		head= insert_a_term(head,t1->coef,t1->expo);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
			head=insert_a_term(head,t2->coef,t2->expo);
			t2=t2->next;
	}
	return head;
	 
}
int main()
{
	printf("polynomial1: \n");
	NODE *poly1= create_polynomial();
	printf("polynomial2: \n");
    NODE *poly2= create_polynomial();
    NODE *sum =poly_addition(poly1,poly2);
	display_polynomial(poly1);
	display_polynomial(poly2);
	display_polynomial(sum);
	
}
