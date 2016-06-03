#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];

typedef int bool;
enum{false, true};

typedef struct LLTag
{
	String name;
	struct LLTag *NextNode;
	struct LLTag *BestFriend;
} Node;

typedef Node *NodePointer;

bool addName(NodePointer head, NodePointer newNode)
{
	String input;
	printf("Enter nation name : ");
	scanf("%s", input);

	if(!strcmp(input, "exit"))
	{
		free(newNode);
		return false;
	}

	strcpy(newNode -> name, input);
	newNode -> NextNode = head -> NextNode;
	head -> NextNode = newNode;

	return true;
}

NodePointer getFriends(NodePointer head, String name)
{
	NodePointer dummy = head;

	while(dummy -> NextNode != NULL)
	{
		if(!strcmp(name, dummy -> name))
		{
			return dummy;
		}

		else
		{
			dummy = dummy -> NextNode;
		}
	}

	return NULL;
}

void addFriends(NodePointer head)
{
	String input;
	NodePointer dummy = head;
	NodePointer friend = NULL;

	do
	{
		dummy = dummy -> NextNode;

		printf("Enter best ally name for %s : ", dummy -> name);
		scanf("%s", input);

		if((friend = getFriends(head, input)) == NULL)
		{
			perror("ERROR: Not a valid nation!");
			continue;
		}

		else
		{
			dummy -> BestFriend = friend;
		}
	}

	while(dummy -> NextNode != NULL);
}

int main(void)
{
	NodePointer head;
	head = malloc(sizeof(Node));
	head -> NextNode = NULL;
	NodePointer dummy;
	bool inputStatus = true;

	printf("Note: Please enter \"exit\" to cease nation name input.\n");

	do
	{
		inputStatus = addName(head, malloc(sizeof(Node)));
	}

	while(inputStatus);

	addFriends(head);

	do
	{
		
		dummy = head -> NextNode;
		free(head);
		head = dummy;

		printf("The best ally of %s is %s\n", head -> name, head -> BestFriend -> name);
	}

	while(head -> NextNode != NULL);

	free(head);

	return(EXIT_SUCCESS);
}