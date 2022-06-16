#include<stdio.h>
#include<stdlib.h>
struct sll
{
	int data;
	struct sll *link;
};
struct sll *head = NULL;
void insert(int data);
void print();
void reverse();

int main()
{
	int data,i=0;
	while(i++<=5)
	{
		printf("Enter data : \n");
		scanf("%d", &data);
		insert(data);
	}
	print();
	reverse();
	print();
}

void reverse()
{
	struct sll *prev=NULL;
	struct sll *curr=head;
	struct sll *next=NULL;

	while(curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void insert(int data)
{
	struct sll *temp;
	struct sll *new = (struct sll *)malloc(sizeof(struct sll));
	if(new == NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		new->data = data;
		new->link = NULL;
		if(head == NULL)
		{
			head = new;
		}
		else
		{
			temp = head;
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = new;
		}
	}
}

void print()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct sll *temp = head;
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

