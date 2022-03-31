#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void display();

int main()
{
    int n, choice;

    head = NULL;
    last = NULL;
    
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n); // Create list of n nodes

    display();

    return 0;
}
 //Create a doubly linked list of n nodes.
 void createList(int n)
{
    int i, data;
    struct node *newNode;

   head = (struct node *)malloc(sizeof(struct node));

        if(head==NULL)
        {
            printf("unable to allocate memory");
        }
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;
           // Create rest of the n-1 nodes
             for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode==NULL)
                {
                    printf("unable to allocate memory");
                    break;
                }
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;          // Make new node as last/previous node
                }
               
}
 // Displays the content of the list from beginning to end
void display()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            
            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}
