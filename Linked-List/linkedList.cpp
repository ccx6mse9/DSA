#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void display(Node* n){
	while(n != NULL){
		cout<<n->data<<"->";
		n= n->next;
	}
	cout<<"NULL"<<endl;
}

void insertBefore(Node** temp,int nData){
	Node* newNode = new Node();
	newNode->data = nData;
	newNode->next = (*temp);
	(*temp) = newNode;
}
void insertAfter(Node* preNode,int nData){
	if(preNode == NULL){
		cout<<"List is empty "; return;
	}
	Node* newNode = new Node();
	newNode->data = nData;
	newNode->next = preNode->next;
	preNode->next = newNode;
}
void append(Node** temp,int nData){
	Node* newNode = new Node();
	newNode->data = nData;
	newNode->next = NULL;

	if((*temp) == NULL){
		(*temp) = newNode; return;
	}
	Node* lNode = (*temp);
	while(lNode->next != NULL){
		lNode = lNode->next;
	}
	lNode->next = newNode;
	return ;
}
void deleteNode(Node** head,int val){
	Node* temp = *head;
	Node* prev = NULL;
	
	if(temp != NULL && temp->data == val){
		*head = temp->next;
		delete temp;
		return;
	}else{
	while(temp != NULL && temp->data != val){
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL)  return;
	prev->next = temp->next;
	delete temp;
}
}

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* four = new Node();

	// // assiging data to nodes

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = four;
	four->data = 4;
	four->next = NULL;

	// Pass (pointer to pointer) as argument
	// (double Pointer) in insertBefore func();
	display(head);
	deleteNode(&head,4);
	display(head);
	
	return 0;
}