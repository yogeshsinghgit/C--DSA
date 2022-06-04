// github.com/yogeshsinghgit

#include <stdio.h>
#include <stdlib.h>

// creating a node structure...
struct node {
  int data; // store the data 
// The pointer will store the address of next the node and the node is of type struct thats why we create a struct node pointer variabel.
  struct node  *link;
};

struct node* add_at_end(struct node *ptr, int data);
struct node* add_at_beg(struct node **head, int data);
struct node* del_node(struct node *head, int pos);
struct node* createLL(struct node *head, int data);


void countNodes(struct node *head);
void printNodes(struct node *head);

int main(void) {
 
  struct node *head = malloc(sizeof(struct node));
  head = createLL(head, 12);
  
  struct node *ptr = head;
  ptr = add_at_end(ptr, 98);
  ptr = add_at_end(ptr, 3);
  ptr = add_at_end(ptr, 67);
  // Use a While Loop with switch statement for better structure of the code...
  
  countNodes(head);
  printf("\n");
  printNodes(head);
  
  return 0;
}


struct node* createLL(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    
    temp->data = data;
    temp->link= NULL;
    
    return temp;
}


struct node* add_at_end(struct node *ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link= NULL;
    
    ptr->link = temp;
    return temp;
}
  
// Insert Node at beginning....
struct node* add_at_beg(struct node **head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link= NULL;
    
    temp->link = *head;
    *head = temp;
}

struct node* del_node(struct node *head, int pos){
    struct node *ptr, *prev_ptr=NULL;
    ptr = head;
    // pos--;
    while(pos!=1){
        prev_ptr = ptr;
        ptr = ptr->link;

        pos--;
    }
    prev_ptr->link = ptr->link;
    ptr->link = NULL;
    
}
void countNodes(struct node *head){
  int count = 0;
  if(head ==NULL)
    printf("Linked List is Empty");

  struct node *ptr = NULL;
  ptr = head;
  while(ptr != NULL){
    count++;
    ptr = ptr->link;
  }
  printf("Total Numbers of Nodes  are %d",count);
}


void printNodes(struct node *head){
  if(head ==NULL)
    printf("Linked List is Empty");

  struct node *ptr = NULL;
  ptr = head;
  while(ptr != NULL){
    printf("->%d", ptr->data);
    ptr = ptr->link;
    
  }
}
