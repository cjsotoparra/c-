#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main(){

	List *list = create_list();

	//insert
	insert(list, 0, 1);
	insert(list, 1, 2);
	insert(list, 2, 2);

	print_list(list);

	printf("Insert new process\n");

	insert(list, 3, 1);
	insert(list, 4, 5);
	insert(list, 5, 4);
	print_list(list);

	Node node_peek = *peek(list);
	printf("Node pid: %d\t Node Priority: %d\t\n", node_peek.pid, node_peek.priority);

	remove_process(list, 0);
	print_list(list);

	remove_process(list,4);

	print_list(list);

	remove_process(list,1);
	print_list(list);

	remove_process(list, 1);
	print_list(list);
	return 0;
}
