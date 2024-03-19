#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA{
	int nAge;
	char szName[16];
	char szPhone[16];
} userdata;

typedef struct NODE{
	userdata data;
	struct NODE* pNext;
} node;

node *CreateNode(userdata *user){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = *user;
	newNode->pNext = NULL;
	
	return newNode;
}
void AppendNode(node** head, node* newNode){
	if(head == NULL){
		*head = newNode;
	}
	else{
		node* Tail = *head;
		while(Tail->pNext != NULL){
			Tail = Tail->pNext;
		}
		Tail->pNext = newNode;
	}

}

void DeleteNodeLast(node** head){
	node* temp = *head;
	while(temp != NULL && temp->pNext->pNext != NULL){
		temp = temp->pNext;
	}
	if(temp->pNext != NULL){
		free(temp->pNext);
		temp->pNext = NULL;
	}

}

int main(){
	node* userList = NULL;
	userdata user[3] = {
		{28, "David", "010-4xxx-xxx0"},
		{26, "Daniel", "010-xxxx-xxx0"},
		{24, "Alice", "010-xxxx-xxx1"},
	};
	node* newNode = CreateNode(&user[0]);
	AppendNode(&newNode, CreateNode(&user[1]));
	AppendNode(&newNode, CreateNode(&user[2]));
	DeleteNodeLast(&newNode);

	node* temp = newNode;
	while(temp != NULL){
		printf("%s, %d, %s\n", temp->data.szName, temp->data.nAge, temp->data.szPhone);
		temp = temp->pNext;
	}

	return 1;
}
