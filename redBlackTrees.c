#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int color; // 1 is red 0 is black
    struct node *p;
    struct node *r;
    struct node *l;
};
struct node *root =NULL;
struct node *ins(struct node *head,struct node *temp)
{
    if(head==NULL)
    {
        return temp;
    }
    if(temp->data < head->data)
    {
        head->l=ins(head->l,temp);
        head->l->p=head;
    }
    else if(temp->data > head->data)
    {
        head->r=ins(head->r,temp);
        head->r->p=head;
    }
    return head;
}
void rightrotate(struct node* temp)
{
    struct node* left = temp->l;
    temp->l = left->r;
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p)
        root = left;
    else if (temp == temp->p->l)
        temp->p->l = left;
    else
        temp->p->r = left;
    left->r = temp;
    temp->p = left;
}
void leftrotate(struct node* temp)
{
    struct node* right = temp->r;
    temp->r = right->l;
    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    if (!temp->p)
        root = right;
    else if (temp == temp->p->l)
        temp->p->l = right;
    else
        temp->p->r = right;
    right->l = temp;
    temp->p = right;
}
void fixup(struct node *root,struct node *temp)
{
    struct node *parent=NULL;
    struct node *grandparent=NULL;
    while(temp!=root && temp->color!=0 && temp->p->color==1)
    {
        parent=temp->p;
        grandparent=temp->p->p;
        if(parent == grandparent->l)
        {
            struct node *uncle= grandparent->r;
            if(uncle && uncle->color==1) //recolor
            {
                grandparent->color=1;
                parent->color=0;
                uncle->color=0;
                temp=grandparent;
            }
            else
            {
                if(temp==parent->r)
                {
                    leftrotate(parent);
                    temp=parent;
                    parent=temp->p;
                }
                rightrotate(grandparent);
                int t=parent->color;
                parent->color=grandparent->color;
                grandparent->color=t;
                temp=parent;
            }
        }
        else 
        {
            struct node *uncle=grandparent->l;
            if(uncle && uncle->color==1) //recolor
            {
                grandparent->color=1;
                parent->color=0;
                uncle->color=0;
                temp=grandparent;
            }
            else
            {
                if(temp==parent->l)
                {
                    rightrotate(parent);
                    temp=parent;
                    parent=temp->p;
                }
                leftrotate(grandparent);
                 int t=parent->color;
                parent->color=grandparent->color;
                grandparent->color=t;
                temp=parent;
            }
        }
    }
}
void postorder(struct node *trav)
{
     if (trav == NULL)
        return;
    postorder(trav->l);
    postorder(trav->r);
    printf("%d ", trav->data);
}
int blackHeight(struct node *root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    int leftBlackHeight = blackHeight(root->l);
    int rightBlackHeight = blackHeight(root->r);
    if (leftBlackHeight == -1 || rightBlackHeight == -1) 
    {
        return -1;
    }
    if (root->color == 0) 
    {
        return leftBlackHeight + 1;
    } 
    else 
    {
        if (leftBlackHeight == rightBlackHeight) 
        {
            return leftBlackHeight;
        } 
        else 
        {
            return -1;
        }
    }
}
int main()
{
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        struct node temp=(struct node)malloc(sizeof(struct node));
        temp->r=NULL;
        temp->l=NULL;
        temp->p=NULL;
        temp->data=a[i];
        temp->color=1;
        root=ins(root,temp);
        fixup(root,temp);
        root->color=0;
    }
    postorder(root);
    int cnt=blackHeight(root);
    printf("\n%d",cnt);
    return 0;
}
