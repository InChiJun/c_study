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

node* FindNode(node** head, char* name){
	if(*head == NULL){
		return NULL;
	}
	node* temp = *head;
	while(temp != NULL){
		if(strcmp(temp->data.szName, name) == 0){
			return temp;
		}
		temp = temp->pNext;
	}

	return NULL;
}

int main(){
	node* userList = NULL;
	node* userHead = NULL;
	userdata user[3] = {
		{28, "David", "010-4xxx-xxx0"},
		{26, "Daniel", "010-xxxx-xxx0"},
		{24, "Alice", "010-xxxx-xxx1"},
	};
	node* newNode = CreateNode(&user[0]);
	AppendNode(&userList, newNode);
	AppendNode(&userList, CreateNode(&user[1]));
	AppendNode(&userList, CreateNode(&user[2]));
	userHead = userList;
	while(userList != NULL){
		printf("%s, %d, %s\n", userList->data.szName, userList->data.nAge, userList->data.szPhone);
		userList = userList->pNext;
	}

	userList = userHead;
	DeleteNodeLast(&userList);
	userList = userHead; // 삭제 가능여부 확인
	while(userList != NULL){
		printf("%s, %d, %s\n", userList->data.szName, userList->data.nAge, userList->data.szPhone);
		userList = userList->pNext;
	}

	userList = userHead;
	node* find = FindNode(&userList, "David");
	printf("find David is %d, %s\n", find->data.nAge, find->data.szPhone);

	return 1;
}
