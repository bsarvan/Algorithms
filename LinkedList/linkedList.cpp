#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;
typedef struct node {
		int data;
		struct node *next;
} Node;

Node* Insert(Node *head,int data)
{
		if (head == NULL){
				Node *node = new Node;
				node->data = data;
				node->next = NULL;
				head= node;
				return head;
		
		}
		Node *curr = head;

		while(curr->next!=NULL)
			curr=curr->next;

		Node *node = new Node;
		node->data = data;
		node->next = NULL;
		curr->next = node;
		return head;
}

Node * createCycle(Node *head)
{
	Node *curr = head;
	int n=3,m=6;

	int count = 0;
	while(n>0){
		n--;
		cout<<"Iteration - "<<++count<<" ";
		curr = curr->next;
		cout<<curr->data<<" "<<endl;
	}
	cout<<endl;
	Node *prev = curr;
	cout<<"Cycle loopback Node - "<<curr->data<<endl;
	curr = head;

	while(m>0)
	{
		curr=curr->next;
		m--;
	}
	cout<<"Cycle Start Node - "<<curr->data<<endl;
	curr->next = prev;

	return head;
}

void Print(Node *head)
{
		Node *curr = head;
		while (curr != NULL)
		{
				cout<<curr->data<<" ";
				curr = curr->next;
		}
		cout<<endl;
		return;
}

Node *HasCycle(Node *head)
{
	Node *slow, *fast;
	slow = head;
	fast = head;
	int cycle = 0;

	while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
		cout<<"Cycle - "<<cycle<<",Slow - "<<slow->data<<",Fast - "<<fast->data<<endl;
		if (slow == fast){
			cout<<"Loop point at Node - "<<slow->data<<endl;
            
            // To fix the loop, iterate together from head and loop point
            // until both the iterators point to the same node.
            Node *firstPointer = head;
			Node *secondPointer = slow;
			while(firstPointer->next!=secondPointer->next){
                firstPointer = firstPointer->next;
                secondPointer = secondPointer->next;
				cout<<"FirstPointer - "<<firstPointer->data<<", SecondPointer - "<<secondPointer->data<<endl;
			}
            
            // Fix the loop in the list by setting the next of fast iterator to nullptr
            secondPointer->next = NULL;
			return firstPointer;
		}
		cycle++;
	}	
	return NULL;

}


Node *deleteKNodeFromLast(Node *head, int k)
{
	Node *first = head->next;
	while(k--)
	{	cout<<"K - "<<k<<", Node - "<<first->data<<endl;
		first = first->next;
	}
	cout<<"First Node is at  - "<<first->data<<endl;

	Node *second = head;
	while(first != NULL){
		cout<<"Second - "<<second->data<<",First - "<<first->data<<endl;
		second = second->next, first = first->next;
		cout<<"Second - "<<second->data<<endl;
	}

	second->next = second->next->next;
	return head;

}

Node* DeleteKthNode(Node *head, int position)
{
    Node *curr = head;
    Node *prev;
    int count = 0;
    
    if (position == 0){
        return head->next;
    }
    
    while(count<position-1 && curr->next!=NULL){
        curr=curr->next;
        cout<<curr->data<<endl;
        count++;
    }
    curr->next = curr->next->next;
    return head;
    
}


Node* InsertNth(Node *head, int data, int position)
{
    Node *node = new Node();
    int count = 0;
    node->data = data;
    
    if (head == NULL)
        return node;
    
    
    if(position == 0){
        node->next = head;
        return node;
    }
    
    Node *curr = head;
    
    while(count<position - 1 && curr->next!=NULL)
    {
        curr = curr->next;
        count++;
    }
    
    if (curr->next != NULL) {
        node->next = curr->next;
        curr->next = node;
    } else {
        curr->next = node;
    }
    
    return head;
}

Node *deleteOdd(Node *head)
{
	Node *prev;

	if (head == NULL)
		return NULL;

    Node *curr = head;
	while(curr != NULL) {
		
		if (curr->data % 2 == 0) {
			
			if (curr == head)
				head = curr->next;
			else	
				prev->next = curr->next;
		}
		prev = curr;
		curr=curr->next;
	}
	return head;

}


Node* delete_evens(Node *head)
{ 
		Node *temp,*step,*prev ; 
		if (head==NULL)
				return NULL;
		
        while(head!=NULL && head->data%2==0)
		{
            cout<<"Executing first"<<endl;
            temp = head ;
            head = head->next ;
            delete temp ;
		}
		step=head;

		while (step!=NULL)
		{
            cout<<"Executing second"<<endl;
            if (step->data %2==0)
            {
                    temp = step ;
                    step = step->next ;
                    prev->next=step;
                    delete temp ;
            }
            else
            {
                    prev=step;
                    step = step->next ;
            }
		}
		step=NULL;
		return head;
}

Node *ReverseSubList(Node *head, int start, int finish){
    if (start == finish)
        return head;
    
    Node *dummy = head;
    Node *subList_head = dummy;
    int k = 1;
    
    while(k++<start){
        subList_head = subList_head->next;
    }
    cout<<"SubList head is - "<<subList_head->data<<endl;
    
    Node *subList_iter = subList_head->next;
    while(start++ < finish){
        Node *temp = subList_iter->next;
        
        subList_iter->next = temp->next;
        temp->next = subList_head->next;
        subList_head->next = temp;
        
        Print(head);
    }
    return dummy->next;
    
}

/* Function to delete duplicates from a sorted list */
Node *RemoveDuplicates(Node *head){
    auto iter = head;
    while(iter) {
        auto next_distinct = iter->next;
        while(next_distinct && next_distinct->data == iter->data) {
            next_distinct = next_distinct->next;
        }
        iter->next = next_distinct;
        iter = next_distinct;
    }
    return head;
}

Node *RemoveDuplicates_v2(Node *head) {
    Node* curr = head;
    while (curr) {
        if (curr->next!= nullptr && curr->next->data == curr->data) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}

/* Remove all duplicates from a sorted linked list */
Node *RemoveAllDuplicates (Node* A) {
        
        if (A == NULL) {
            return NULL;
        }
        
        Node* dummy = new Node();
        dummy->next = A;
        Node* pre = dummy;
        Node* cur = A;
        while (cur != NULL) {
            while (cur->next != NULL && cur->data == cur->next->data) {
                cur = cur->next;
            }
            if (pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
}

/* Function to remove duplicates from unsorted list */
void remove_dups(Node *head){
    unordered_set<int> unique_map;
    Node *prev=NULL;
    while(head) {
        if(unique_map.find(head->data) != unique_map.end()){
            cout<<"Duplicate - "<<head->data<<endl;
            prev->next = head->next;
        } else  {
            unique_map.emplace(head->data);
            prev = head;
        }
        head = head->next;
    }
}

Node *findKthLastNodeHelper(Node *head, int k, int &i){
    if (head == NULL)
        return NULL;
    
    Node *node =findKthLastNodeHelper(head->next,k,i);
    i++;
    if(i == k)
        return head;
    
    return node;
}

Node* findKthLastNode(Node *head, int k) {
    int i = 0;
    return findKthLastNodeHelper(head, k, i);
}


Node* deleteNode(Node *head, int d){
    Node *curr = NULL;
    
    if(head->data == d){
        return (head->next);
    }
    curr = head;
    while(curr->next != NULL) {
        if(curr->next->data == d){
            curr->next = curr->next->next;
            return head;
        }
        curr = curr->next;
    }
    return NULL;
}


Node *Reverse(Node *head){
    Node *p = NULL;
    Node *q = NULL;
    Node *curr = head;
    while(curr!= NULL) {
        q = p;
        p = curr;
        curr = curr->next;
        p->next = q;
    }
    return p;
}

Node *ReverseKNodes(Node *head, int K){
    Node *p = NULL;
    Node *q = NULL;
    Node *curr = head;
    
    Node *t = NULL;
    for(int i=0;i<K;i++) {
        q = p;
        p = curr;
        curr = curr->next;
        p->next = q;
        
        if (!t) {
            t = p;
        }
    }
    cout<<t->data<<endl;
    return p;
}


Node *DeleteNode(Node *head, int data) {
    Node *curr = head;
    Node *prev=NULL;
    
    while(curr){
        if(curr->data == data) {
            if(curr == head) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}




Node* reverseAndClone(Node *A) {
    Node *node = A;
    Node *head = NULL;
    
    while (node != NULL) {
        Node *n = new Node;
        cout<<node->data<<" ";
        n->data = node->data;
        n->next = head;
        head = n;
        node = node->next;
    }
    cout<<endl;
    return head;
}

int lPalin(Node* A) {

    Node *X = A;

    Node *Y = reverseAndClone(A);
    
    while(X != NULL && Y != NULL) {
        cout<<"X - "<<X->data<<", Y - "<<Y->data<<endl;
        if (X->data != Y->data) {
            cout<<"REturning 0"<<endl;
            return 0;
        }
        X=X->next;
        Y=Y->next;
    }
    
    return (X==NULL && Y==NULL);
}


void ListTraverse(Node *A) {
    int k = 3;
    Node *curr = A;
    while(k > 0) {
        k--;
        curr = curr->next;
        cout<<"k = "<<k<<", node = "<<curr->data<<endl;
    }
    cout<<"Current pointing to Node - "<<curr->data<<endl;
    
    k = 0;
    curr = A;
    while(k < 3) {
        k++;
        curr = curr->next;
        cout<<"k = "<<k<<", node = "<<curr->data<<endl;
    }
    cout<<"Current pointing to Node - "<<curr->data<<endl;
    
    return ;
}


/*
 Given a linked list, remove all consecutive nodes that sum to zero. Print out the remaining nodes.

 For example, suppose you are given the input 3 -> 4 -> -7 -> 5 -> -6 -> 6.
 
 In this case, you should first remove 3 -> 4 -> -7, then -6 -> 6, leaving only 5.
 */
#if 0
Node * removeSumZero(Node *head) {
    Node *curr = head;
    Node *fakehead = new Node();
    fakehead->next = curr;
    
    Node *pre = fakehead;
    
    int sum = 0;
    
    Node *p = curr;
    Node *q = curr;
    
    while(curr) {
        int sum=sum + curr->data;
        Node *tmp = curr->next;
        while(tmp && sum >0) {
            sum += tmp->data;
            tmp = tmp->next;
        }
        
        if (pre->next != tmp) {
            pre->next = tmp->next;
        } else {
            pre = pre->next;
        }
        
        curr = tmp->next;
    }
}
#endif


int main()
{
    Node *head = NULL;

    cout<<"Test program on linked list"<<endl;
    
    head = Insert(head,1);
    Insert(head,2);
    Insert(head,3);
    Insert(head,4);
    Insert(head,5);
    Insert(head,6);
    Insert(head,7);
    Insert(head,8);
    Insert(head,9);
    Insert(head,10);
#if 0
    head = Insert(head,5);
    head = Insert(head,6);
    head = Insert(head,7);
    head = Insert(head,8);
    Insert(head,9);
#endif
    
    Print(head);
    
    head = createCycle(head);
    Node *cyclePtr = HasCycle(head);
    cout<<"Cycle Start at Node - "<<cyclePtr->data<<endl;
    Print(head);
    
    //Node *h = deleteOdd(head);
    //Node *node = deleteKNodeFromLast(head,3);
//    Node *node = RemoveDuplicates_v2(head);
//
//    Print(node);
    //ListTraverse(head);
    
 
    //head = RemoveAllDuplicates(head);
    //head = ReverseKNodes(head,2);
    //Print(head);
   // int result = lPalin(head);
    //cout<<"Is Palindrome - "<<result<<endl;
    
    //remove_dups(head);
    //head = RemoveDuplicates(head);
    //head = InsertNth(head,9,8);
    //Node *node = findKthLastNode(head, 2);
    //cout<<node->data<<endl;
    //Node *node = deleteKNodeFromLast(head,3);
    //Node *node  = DeleteNode(head, 5);
    //Node *node = DeleteKthNode(head,5);
    //Print(node);
    
    //Node *L = head;
    //int k = 3;
    //while(k--){
    //    L = L->next;
    //    cout<<"Value of k - "<<k<<", Node - "<<L->data<<endl;
    //}
    
    //head = ReverseSubList(head, 1, 5);
		//head = deleteOdd(head);
	//Print(head);
		//head = createCycle(head);
		//Node *cyclePtr = HasCycle(head);
		//cout<<"Cycle Start at Node - "<<cyclePtr->data<<endl;
		
    //head = deleteKNode(head,2);
		return 0;
}
