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
	cout<<"Cycle loopback Node -"<<curr->data<<endl;
	curr = head;

	while(m>0)
	{
		curr=curr->next;
		m--;
	}
	cout<<"Cycle Start Node -"<<curr->data<<endl;
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
			cout<<"Cycle detected at Node - "<<slow->data<<endl;
			slow = head;
			while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
				cout<<"Slow - "<<slow->data<<", Fast - "<<fast->data<<endl;
			}
			return slow;
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
				temp = head ; 
				head = head->next ; 
				delete temp ;  
		}
		step=head;

		while (step!=NULL)
		{
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
        cout<<"temp - "<<temp->data<<",subList_iter - "<<subList_iter->data;
        cout<<",subList_head - "<<subList_head->data<<endl;
        Print(head);
    }
    return dummy;
    
}

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

void remove_dups(Node *head){
    unordered_set<int> unique_map;
    Node *prev=NULL;
    while(head) {
        if(unique_map.find(head->data) != unique_map.end()) {
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

int main()
{
    Node *head = NULL;

    cout<<"Test program on linked list"<<endl;
    head = Insert(head,1);
    head = Insert(head,2);
    head = Insert(head,3);
    head = Insert(head,4);
    head = Insert(head,5);
    head = Insert(head,6);
    head = Insert(head,7);
    head = Insert(head,8);
    Insert(head,9);

    Print(head);
 
    //head = RemoveDuplicates(head);
    //head = InsertNth(head,9,8);
    //Node *node = findKthLastNode(head, 2);
    //cout<<node->data<<endl;
    //Node *node = deleteKNodeFromLast(head,3);
    //Node *node  = DeleteNode(head, 6);
    //Node *node = DeleteKthNode(head,5);
    //Print(node);
    
    //Node *L = head;
    //int k = 3;
    //while(k--){
    //    L = L->next;
    //    cout<<"Value of k - "<<k<<", Node - "<<L->data<<endl;
    //}
    
        //head = ReverseSubList(head, 3, 5);
		head = deleteOdd(head);
		Print(head);
		//head = createCycle(head);
		//Node *cyclePtr = HasCycle(head);
		//cout<<"Cycle Start at Node - "<<cyclePtr->data<<endl;
		
    //head = deleteKNode(head,2);
		return 0;
}
