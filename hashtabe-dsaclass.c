// #include<stdio.h>
// #include<stdlib.h>
// #define SIZE 10
// typedef struct node
// {
//     int data;
//     struct node *next;
// }node;
// typedef struct hash
// {
//     int count;
//     struct node *head;
// }HashTable;

// node* create(int key)
// {
//     node nn=(node)malloc(sizeof(node));
//     nn->data=key;
//     nn->next=NULL;
//     return nn;
// }

// void insert(int key,HashTable *hashtable)
// {
//     int hash;
//     hash=key%SIZE;
//     node *nn,*t;
//     nn=create(key);
//     if(hashtable[hash].count==0)
//     {
//         hashtable[hash].head=nn;
//         hashtable[hash].count++;
//     }
//     else 
//     {
//         t=hashtable[hash].head;
//         while(t->next!=NULL)
//         {
//             t=t->next;
//         }
//         t->next=nn;
//         hashtable[hash].count++;
//     }
// }

// void display(HashTable *hashtable)
// {
//     for(int i=0;i<SIZE;i++)
//     {
//         node *t=hashtable[i].head;
//         printf("\n[%d]C=%d=>",i,hashtable[i].count);
//         while(t!=NULL)
//         {
//             printf("%d->",t->data);
//             t=t->next;
//         }
//     }
// }

// void search(int key,HashTable *hashtable)
// {
//     int hash,pos=1;
//     node *t;
//     hash=key%SIZE;
//     t=hashtable[hash].head;
//     // if(hashtable[hash].count==0)
//     // {
//     //     printf("\nData not found");
//     //     return;
//     // }
//     while(t!=NULL)
//     {
//         pos++;
//         if(t->data==key)
//         {
//             printf("\nData found at index %d in position %d",hash,pos);
//             return;
//         }
//         t=t->next;
//     }
//     printf("\nData not found");
// }

// void delete(int key,HashTable *hashtable)
// {
//     int hash= key%SIZE;
//     int pos=0;
//     node *t,*prev;
//     t=hashtable[hash].head;
//     while(t!=NULL)
//     {
//         pos++;
//         if(t->data==key)
//         {
//            if(pos==1)
//             hashtable[hash].head=t->next;
//             else 
//             {
//                 prev=hashtable[hash].head;
//                 while(prev->next!=t)
//                     prev=prev->next;
//                 prev->next=t->next;
//             }
//             free(t);
//             hashtable[hash].count--;
//             return;
//         }
//         t=t->next;
//     }
//     printf("\nData not found");
// }

// void main()
// {
//     int key,ch;
//     HashTable hashtable[SIZE]={};
//     do{
//          printf("Enter the key to be inserted");
//     scanf("%d",&key);
//     insert(key,hashtable);
//     printf("\n To exit press 0:");
//     scanf("%d",&ch);
//     }while(ch);
//     display(hashtable);
//     do 
//     {
//         printf("\nEnter the key to be searched");
//         scanf("%d",&key);
//         search(key,hashtable);
//         display(hashtable);
//         printf("\nTo exit press 0:");
//         scanf("%d",&ch);
//     }while(ch);
//      do 
//     {
//         printf("\nEnter the key to be deleted");
//         scanf("%d",&key);
//         delete(key,hashtable);
//         printf("\nTo exit press 0:");
//         scanf("%d",&ch);
//     }while(ch);
//    display(hashtable);
// // }



#include<stdio.h>
#define SIZE 10
typedef struct node 
{
    int data;
    int flag;
}node;

void insert(int key,node *hashtable)
{
    int hash,i=0;
    hash=((key%SIZE)+i)%SIZE;
    while(hashtable[hash].flag && i<SIZE)
    {
        i++;
        hash=((key%SIZE)+i)%SIZE;
    }
    if(hashtable[hash].flag==0)
    {
        hashtable[hash].data=key;
        hashtable[hash].flag=1;
    }
    else 
    {
        printf("\nData cannot be inserted");
    }
}

void display(node* HashTable){
     for(int i =0; i<SIZE;i++){
          if(HashTable[i].flag==1)
               printf("\n[%d] %d", i, HashTable[i].flag );
     }
}

void search(node* HashTable){
     int hash, i=0;
     
}

void main()
{
    int key;
    node HashTable[SIZE]={};
    printf("\nEnter the data to be inserted");
    scanf("%d",&key);
    insert(key,HashTable);
}