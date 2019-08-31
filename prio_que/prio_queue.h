 #ifndef __BIN_HEAP_H__
 
 struct heap_struct;
 typedef struct heap_struct *prio_queue;
 
 prio_queue initialize(int max_ele);
 void destory(prio_queue q);
 void make_empty(prio_queue q);
 void insert(ele_type ele, prio_queue q);
 ele_type del_min(prio_queue q);
 ele_type find_min(prio_queue q);
 
 int is_empty(prio_queue q);
 int is_full(prio_queue q);
 
 #endif


 struct heap_struct {
     int capacity;
     int size;
     ele_type *ele;
 };


/* init */

prio_queue initialize(int max_ele)
{
    prio_queue head;

    if(max_ele < min_req)
    {
        error("prio queue size is too small");
    }

    head = malloc(sizeof(struct heap_struct));
    if(!head) fataerror("out of space");

    head->ele = malloc((max_ele + 1)*sizeof(ele_type));
    if(!head->ele) fataerror("out of space");

    h->capacity = max_ele;
    h->size = 0;
    h->ele[0] = min_data;

    return head;
}

/* head->ele[0] is a sentinel */
void insert(ele_type x, prio_queue h)
{
    int i ;

    if(isfull)
    {
        error("prio queue is full");
        return;
    }

    for(i = ++h->size; h->ele[i/2] > x; i /= 2)
    {
        /* slide down the parent */
        h->ele[i] = h->ele[i/2];
    }

    /* place the cur node */
    h->ele[i] = x;
}

/* function to perform del_min in a binary heap */
ele_type del_min(prio_queue h)
{
    int i, child;
    ele_type min_ele, last_ele;

    if(is_empty(h))
    {
        error("prio queue is empty");
        return h->ele[0];
    }

    min_ele = h->ele[1];
    last_ele = h->ele[h->size--];

    for(i = 1; i*2 <= h->size; i = child)
    {
        /* find smaller child */
        child = i*2;
        /* right child is smaller */
        if(child != h->size && h->ele[child + 1] < h->ele[child])
            child++;

        /* percolate one level */
        if(last_ele > h->ele[child])
        {
            h->ele[i] = h->ele[child];
        }
        else
            break;
    }

    h->ele[i] = last_ele;

    return min_ele;
}
