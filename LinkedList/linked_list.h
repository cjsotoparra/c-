typedef struct node {
	unsigned int pid;
	int priority;
	struct node *next;
}Node;

typedef struct list{
	Node *first;
} List;

List *create_list(){

	List *new_list = malloc(sizeof(List));
	Node *first = (Node*) malloc(sizeof(Node));
	new_list->first = NULL;
	return new_list;
}

void delete_node(Node *node){
        free(node);
}

void delete_list(List *list){
	Node *node = list->first;
	Node *next;

	while(node != NULL){
		next = node->next;
		delete_node(node);
		node = next;
	}

	free(list);
}

void remove_process(List *list, unsigned int pid){
	Node *node = list->first;

	//check if pid is at the begining of the list
	if(node->pid == pid){
		list->first = node->next;
		free(node);
		return;
	}

	//else, search for the pid
	while(node !=  NULL){
		if(node->next == NULL){
			break;
		}

		if(node->next->pid == pid){
			Node *temp = node->next;
			node->next = node->next->next;
			free(temp);
			return;
		}

		node = node->next;
	}//while loop
}

/*void append_list(List *list, unsigned int pid, int priority){
	Node *node = list->first;

	//get to the last node in list
	while(node->next != NULL){
		node = node->next;
	}

	node->pid = pid;
	node->priority = priority;
	node->next = (Node*) malloc(sizeof(Node));
}*/

/*Node *pop(List *list){
	Node *temp = list->first;
	if(temp->next == NULL){
		Node *new_first = (Node*) malloc(sizeof(Node));
		list->first = new_first;
	} else {
		Node *new_first = temp->next;
		list->first = new_first;
	}

	return temp;
}*/

void insert(List *list, unsigned int pid, int priority){

	//allocate new node
	Node *new_node = (Node*) malloc(sizeof(Node));

	//put date in new_node
	new_node->pid = pid;
	new_node->priority = priority;

	//reference the next node as NULL
	new_node->next = NULL;

	//if list is empty then insert at the begining of the list
	if(list->first == NULL){
		list->first = new_node;
		return;
	}

	//check if frist has a lower prioirty than new_node
	if(priority < list->first->priority){

		new_node->next = list->first;
		list->first = new_node;
		return;
	}

	//create temp node and iterate through process list and
	//insert at appropiate place based on priority or at the end of the list
	Node *prev = list->first;
	Node *temp = list->first->next;
	while(temp != NULL){

		if(priority < temp->priority){

			prev->next = new_node;
			new_node->next = temp;
			return;
		}

		prev = temp;
		temp = temp->next;
	}

	prev->next = new_node;
	return;

}//insert

Node *peek(List *list){
	return list->first;
}//peek

Node *get_element(List *list, int element){

	Node *node = list->first;
	int i = 0;

	while(i < element && node != NULL){

		node = node->next;
		i++;

	}//while

	return node;

}//get_element

Node *find_pid(List *list, unsigned int pid){

	Node *node = list->first;

	while(node->next != NULL){

		if(node->pid == pid){

			return node;

		}//if

		node = node->next;

	}//while

	return NULL;

}//find_pid

void print_list(List *list){

	Node *node = list->first;

	while(node != NULL){

		printf("PID: %d\t Priority: %d\n", node->pid, node->priority);
		node = node->next;

	}//while

	printf("\n");

}//print_list
