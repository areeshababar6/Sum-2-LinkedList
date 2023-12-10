#include<iostream>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *add_node(node *head, int val)
{
	node *pnew = (node *)malloc(sizeof(node));
	pnew->data = val;
	pnew->link = NULL;

	pnew->link = head;
	head = pnew;
	return head;
}

node *create_list(node*head, int n)
{
	while (n != 0)
	{
		head = add_node(head, n % 10);
		n = n / 10;
	}
	return head;
}

node *reverse_list(node *head)
{
	if (head == NULL)
		return head;

	node *cur = NULL;
	node *next = head->link;
	head->link = NULL;

	while (next != NULL)
	{
		cur = next;
		next = next->link;
		cur->link = head;
		head = cur;
	}
	return head;
}

node *push(node *head, int val)
{
	node *pnew = (node *)malloc(sizeof(node));
	pnew->data = val;
	pnew->link = head;
	head = pnew;
	return head;
}

node *add_list(node *head1, node *head2)
{
	if (head1->data == 0)
		return head2;
	if (head2->data == 0)
		return head1;

	node *ptr1 = head1;
	node *ptr2 = head2;
	node *head3 = NULL;

	int carry = 0, sum;

	while (ptr1 || ptr2)
	{
		sum = 0;
		if (ptr1)
			sum += ptr1->data;
		if (ptr2)
			sum += ptr2->data;
		sum += carry;

		carry = sum / 10;
		sum = sum % 10;

		head3 = push(head3, sum);

		if (ptr1)
			ptr1 = ptr1->link;
		if (ptr2)
			ptr2 = ptr2->link;
	}
	if (carry)
		head3 = push(head1, carry);
	return head3;
}

node *back_to_num(node *head)
{
	node *temp = head;
	cout << endl;
	cout << "Result  " << endl << endl;
	
	while (temp)
	{
		cout << temp->data << " -> ";
		temp = temp->link;
	}
	return head;
}


void print(node *head)
{
	node *temp = head;
	if (head == NULL)
	{
		cout << "No Number !" << endl;
	}
	else
	{
		while (temp->link != NULL)
		{
			cout << temp->data << "  ->  ";
			temp = temp->link;
		}
		cout << temp->data;
	}
}


int main()
{
	int a, b;
	cout << "-------------------!    Enter any two numbers !------------------ " << endl;
	cout << "Enter 1st numbers : " << endl;
	cin >> a;
	cout << "Enter 2nd numbers : " << endl;
	cin >> b;
	cout << endl << endl;

	node *head1 = NULL;
	cout << "Linked list representation of first number : " << endl;
	head1 = create_list(head1, a);
	print(head1);
	cout << endl << endl;
	
	node *head2 = NULL;
	cout << "Linked list representation of Second number : " << endl;
	head2 = create_list(head2, b);
	print(head2);
	cout << endl << endl;

	head1 = reverse_list(head1);
	head2 = reverse_list(head2);

	cout << "Reversed Linked list ! " <<endl;
	print(head1);
	cout << endl << endl;
	print(head2);

	node *head3 = NULL;
	head3 = add_list(head1, head2);
	cout << endl << endl;
	cout << "Resultant Linked List after Addition ! " << endl;
	print(head3);

	back_to_num(head3);

	return 0;
}