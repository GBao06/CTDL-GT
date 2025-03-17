#include<bits/stdc++.h>

using namespace std;

struct node{
	int x;
	node* next;
};

node* createNode(int x){
	node* newNode = new node;
	newNode->x = x;
	newNode->next = NULL;
	return newNode;
}

void insertFirst(node*& head, int x ){
	node* newNode = createNode(x);
	if( head == NULL){
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}

void insertLast(node*& head, int x){
	node* newNode = createNode(x);
	if ( head == NULL){
		head = newNode;
		return;
	}
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	
}

void display(node* head){
	node* temp = head;
	if(head == NULL){
		cout<<"Danh sach rong!"<<endl;
		return;
	}
	while(temp!=NULL){
		cout<<temp->x<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insertBefore(node*& head, int x, int pos){
	node* newNode= createNode(x);
	if(head == NULL || pos == 1){
		newNode->next = head;
		head = newNode;
		return;
	}
	node* temp = head;
	int count = 1;
	while( temp->next != NULL && count < pos-1){
		temp = temp->next;
		count++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void insertSorted(node *&head, int x){
	node* newNode = createNode(x);
	if(head == NULL || x <= head->x){
		newNode->next = head;
		head = newNode;
		return;		
	}
	node* temp = head;
	while(temp->next && temp->next->x < x){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void deletee(node *&head, int pos){
	if(head == NULL ) return;
	if(pos == 1){
		node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	int count = 1;
	node* temp = head;
	while(temp->next != NULL && count < pos - 1){
		temp = temp->next;
		count++;
	}
	if(temp->next == NULL) return ;
	node* prev = temp->next;
	temp->next = prev->next;
	delete prev;
	
}

node* Sorted(node* head){
	node *temp = head;
	for(node *i = temp; i!=NULL; i = i->next){
		for( node *j = i->next; j!= NULL; j = j->next){
			if(i->x > j->x){
				int tam = i->x;
				i->x = j->x;
				j->x = tam;
			}
		}
	}
	return temp;
}

void update(node*& head,int x, int pos){
	if( head == NULL || pos == 1){
		head->x = x;
		cout<<"Da cap nhat" << x <<"tai vi tri "<<pos<<endl;
		return;
	}
	node* temp = head;
	int count = 1;
	while(temp->next!=NULL && count < pos){
		temp = temp->next;
		count++;
	}
	cout<<"Da cap nhat " << x <<" tai vi tri "<<pos<<endl;
	temp->x = x;
}

void search(node* head, int pos){
	if( head == NULL || pos == 1){
	cout<<"Vi tri "<< pos <<" la: "<<head->x<<endl;
		return;
	}
	node* temp = head;
	int count = 1;
	while(temp->next != NULL && count < pos ){
		temp = temp->next;
		count++;
	}
	cout<<"Vi tri "<< pos <<" la: "<<temp->x<<endl;
}

node* tachNode(node*& head, int pos){
	if(head == NULL || pos <= 0){
		cout<<"Khong tach duoc! "<<endl;
		return NULL;
	}
	if(pos == 1){
		node* newHead = head;
		head = NULL;
		return newHead;
	}
	node* temp = head;
	int count = 1;
	while(temp->next != NULL && count < pos - 1){
		temp = temp->next;
		count++;
	}
	if(temp->next == NULL){
		cout<<"Khong tach duoc! "<<endl;
		return NULL;
	}
	node* l = temp->next;
	temp->next = NULL;
	return l;
}

node* noiNode(node*& l, node*& r){
	if( r == NULL && l == NULL){
		cout<<"Khong the noi!"<<endl;
		return NULL;
	}
	if(l == NULL) return r;
	if(r == NULL) return l;
	node* temp = l;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = r;
	r = NULL;
	return l;
}

void freeList(node*& head) {
    while (head != NULL) {
        node* temp = head; 
        head = head->next;  
        delete temp;    
    }
}


int main(){
  	node* head = NULL;
  	node* newList = NULL;
    int choice, value, pos;
	do {
        cout << "\nMENU CHUC NANG\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them vao danh sach\n";
        cout << "3. Xoa phan tu\n";
        cout <<	"4. Cap nhat danh sach tai vi tri\n";
        cout << "5. Tim kiem\n";
        cout << "6. Tach danh sach\n";
        cout << "7. Noi danh sach\n";
        cout << "8. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Danh sach hien tai: ";
                display(head);
                break;
            case 2:
                cout << "Nhap gia tri: ";
                cin >> value;
                insertLast(head, value);
                break;
            case 3:
            	cout<<"Nhap vi tri de xoa: "; cin>>pos;
                deletee(head,pos);
                break;
			case 4:
				cout<<"Nhap gia tri cap nhat: "; cin>>value;
				cout<<"Nhap vi tri cap nhat: "; cin>>pos;
				update(head,value,pos);
				break;
			case 5:
				cout<<"Nhap vi tri tim kiem "; cin>>pos;
				search(head,pos);
				break;
            case 6:
                cout << "Nhap vi tri tach: ";
                cin >> pos;
                newList = tachNode(head, pos);
                cout << "Danh sach sau khi tach:\n";
                cout << "Phan 1: "; display(head);
                cout << "Phan 2: "; display(newList);
                break;
            case 7:
                head = noiNode(head, newList);
                cout << "Danh sach sau khi noi: ";
                display(head);
                break;
            case 8:
                cout << "Thoat chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le! Moi nhap lai.\n";
                break;
        }
    } while (choice != 8);
    return 0;
    freeList(head);
    freeList(newList);
}
