#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* ================= STACK ================= */
int stack[SIZE], tos = -1;

void push(int item)
{
    if(tos == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++tos] = item;
}

int pop()
{
    if(tos == -1)
        return -999;
    return stack[tos--];
}

void stack_display()
{
    int i;
    if(tos == -1)
        printf("Stack Empty\n");
    else
        for(i = tos; i >= 0; i--)
            printf("%d\n", stack[i]);
}

/* ================= MULTIPLE STACK ================= */
int arr[SIZE], top1 = -1, top2 = SIZE;

void push1(int item)
{
    if(top1 + 1 == top2)
        printf("Overflow\n");
    else
        arr[++top1] = item;
}

void push2(int item)
{
    if(top1 + 1 == top2)
        printf("Overflow\n");
    else
        arr[--top2] = item;
}

void pop1()
{
    if(top1 == -1)
        printf("Underflow\n");
    else
        printf("Deleted: %d\n", arr[top1--]);
}

void pop2()
{
    if(top2 == SIZE)
        printf("Underflow\n");
    else
        printf("Deleted: %d\n", arr[top2++]);
}

/* ================= LINEAR QUEUE ================= */
int lq[SIZE], lf = -1, lr = -1;

void lq_enqueue(int item)
{
    if(lr == SIZE - 1)
        printf("Queue Overflow\n");
    else
    {
        if(lf == -1)
            lf = 0;
        lq[++lr] = item;
    }
}

void lq_dequeue()
{
    if(lf == -1 || lf > lr)
        printf("Queue Underflow\n");
    else
        printf("Deleted: %d\n", lq[lf++]);
}

void lq_display()
{
    int i;
    if(lf == -1 || lf > lr)
        printf("Queue Empty\n");
    else
    {
        for(i = lf; i <= lr; i++)
            printf("%d ", lq[i]);
        printf("\n");
    }
}

/* ================= CIRCULAR QUEUE ================= */
int cq[SIZE], f = -1, r = -1;

void cq_enqueue(int item)
{
    if((f == 0 && r == SIZE - 1) || (f == r + 1))
        printf("Queue Overflow\n");
    else
    {
        if(f == -1)
            f = r = 0;
        else if(r == SIZE - 1)
            r = 0;
        else
            r++;
        cq[r] = item;
    }
}

void cq_dequeue()
{
    if(f == -1)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted: %d\n", cq[f]);
        if(f == r)
            f = r = -1;
        else if(f == SIZE - 1)
            f = 0;
        else
            f++;
    }
}

void cq_display()
{
    int i;
    if(f == -1)
        printf("Queue Empty\n");
    else
    {
        i = f;
        while(i != r)
        {
            printf("%d ", cq[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", cq[r]);
    }
}

/* ================= DEQUE ================= */
int dq[SIZE], front = -1, rear = -1;

void renqueue(int item)
{
    if(rear == SIZE - 1)
        printf("Overflow\n");
    else
    {
        if(front == -1) front = 0;
        dq[++rear] = item;
    }
}

void fenqueue(int item)
{
    if(front == 0)
        printf("Overflow\n");
    else
    {
        if(front == -1)
            front = rear = 0;
        else
            front--;
        dq[front] = item;
    }
}

void rdequeue()
{
    if(front == -1)
        printf("Underflow\n");
    else
    {
        printf("Deleted: %d\n", dq[rear--]);
        if(front > rear)
            front = rear = -1;
    }
}

void fdequeue()
{
    if(front == -1)
        printf("Underflow\n");
    else
    {
        printf("Deleted: %d\n", dq[front++]);
        if(front > rear)
            front = rear = -1;
    }
}

void dq_display()
{
    int i;
    if(front == -1)
        printf("Deque Empty\n");
    else
    {
        for(i = front; i <= rear; i++)
            printf("%d ", dq[i]);
        printf("\n");
    }
}

/* ================= LINEAR LINKED LIST ================= */
struct lnode
{
    int data;
    struct lnode *next;
};

struct lnode *start = NULL;

void ll_insert()
{
    int item;
    struct lnode *temp, *ptr;
    temp = (struct lnode *)malloc(sizeof(struct lnode));
    scanf("%d", &item);
    temp->data = item;
    temp->next = NULL;

    if(start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void ll_delete()
{
    struct lnode *ptr;
    if(start == NULL)
        printf("Underflow\n");
    else
    {
        ptr = start;
        start = start->next;
        printf("Deleted: %d\n", ptr->data);
        free(ptr);
    }
}

void ll_display()
{
    struct lnode *ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/* ================= CIRCULAR LINKED LIST ================= */
struct cnode
{
    int data;
    struct cnode *next;
};

struct cnode *head = NULL;

int cll_count()
{
    int c = 0;
    struct cnode *cur = head;
    if(head == NULL) return 0;
    do
    {
        c++;
        cur = cur->next;
    } while(cur != head);
    return c;
}

void cll_display()
{
    struct cnode *cur = head;
    if(head == NULL)
    {
        printf("Empty\n");
        return;
    }
    do
    {
        printf("%d ", cur->data);
        cur = cur->next;
    } while(cur != head);
    printf("\n");
}

void cll_insertbeg(int num)
{
    struct cnode *newnode = (struct cnode *)malloc(sizeof(struct cnode));
    newnode->data = num;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    struct cnode *cur = head;
    while(cur->next != head)
        cur = cur->next;

    newnode->next = head;
    cur->next = newnode;
    head = newnode;
}

void cll_insertend(int num)
{
    struct cnode *newnode = (struct cnode *)malloc(sizeof(struct cnode));
    newnode->data = num;

    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }

    struct cnode *cur = head;
    while(cur->next != head)
        cur = cur->next;

    cur->next = newnode;
    newnode->next = head;
}

void cll_delete(int num)
{
    struct cnode *cur = head, *prv;

    if(head == NULL) return;

    if(head->data == num && head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    if(head->data == num)
    {
        while(cur->next != head)
            cur = cur->next;
        cur->next = head->next;
        free(head);
        head = cur->next;
        return;
    }

    prv = head;
    cur = head->next;
    while(cur != head)
    {
        if(cur->data == num)
        {
            prv->next = cur->next;
            free(cur);
            return;
        }
        prv = cur;
        cur = cur->next;
    }
}

/* ================= MAIN ================= */
void main()
{
    int ch, sub, item;

    do
    {
        printf("\n====== MAIN MENU ======\n");
        printf("1. Stack\n");
        printf("2. Multiple Stack\n");
        printf("3. Linear Queue\n");
        printf("4. Circular Queue\n");
        printf("5. Deque\n");
        printf("6. Linear Linked List\n");
        printf("7. Circular Linked List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("1.Push 2.Pop 3.Display\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); push(item); }
                else if(sub == 2) printf("%d\n", pop());
                else if(sub == 3) stack_display();
                break;

            case 2:
                printf("1.Push Stack1 2.Push Stack2 3.Pop Stack1 4.Pop Stack2\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); push1(item); }
                else if(sub == 2){ scanf("%d",&item); push2(item); }
                else if(sub == 3) pop1();
                else if(sub == 4) pop2();
                break;

            case 3:
                printf("1.Enqueue 2.Dequeue 3.Display\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); lq_enqueue(item); }
                else if(sub == 2) lq_dequeue();
                else if(sub == 3) lq_display();
                break;

            case 4:
                printf("1.Enqueue 2.Dequeue 3.Display\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); cq_enqueue(item); }
                else if(sub == 2) cq_dequeue();
                else if(sub == 3) cq_display();
                break;

            case 5:
                printf("1.Insert Rear 2.Insert Front 3.Delete Rear 4.Delete Front 5.Display\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); renqueue(item); }
                else if(sub == 2){ scanf("%d",&item); fenqueue(item); }
                else if(sub == 3) rdequeue();
                else if(sub == 4) fdequeue();
                else if(sub == 5) dq_display();
                break;

            case 6:
                printf("1.Insert 2.Delete 3.Display\n");
                scanf("%d",&sub);
                if(sub == 1) ll_insert();
                else if(sub == 2) ll_delete();
                else if(sub == 3) ll_display();
                break;

            case 7:
                printf("1.Insert Beg 2.Insert End 3.Delete 4.Display 5.Count\n");
                scanf("%d",&sub);
                if(sub == 1){ scanf("%d",&item); cll_insertbeg(item); }
                else if(sub == 2){ scanf("%d",&item); cll_insertend(item); }
                else if(sub == 3){ scanf("%d",&item); cll_delete(item); }
                else if(sub == 4) cll_display();
                else if(sub == 5) printf("Count = %d\n", cll_count());
                break;

            case 8:
                exit(0);
        }

    } while(ch != 8);

    return 0;
}

