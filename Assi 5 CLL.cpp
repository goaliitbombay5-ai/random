#include <iostream>
using namespace std;

class node
{
	public:
		int orderNo;
		string sizeOfPizz;
		int quantity;
		float price;
		float TotalPrice;
		node *next;
};

class CLL
{
	public:
		node *head;
		CLL()
		{
			head =NULL;
		}
		void create();
		void display();
		void insert();
		void deleteCLL();
		void update();
};

void CLL::create()
{
	char ch;
	node *temp, *p;
	do{
	temp=new node;
	cout<<"Enter Order No.: ";
	cin>>temp->orderNo;
	cout<<"Enter Size of pizza (Small/Medium/big): ";
	cin>>temp->sizeOfPizz;
	cout<<"Enter Quantity: ";
	cin>>temp->quantity;
	cout<<"Enter Price of one Pizza: ";
	cin>>temp->price;
	temp->next=temp;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		p=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=head;
		
	}
	cout<<"Do you want to continue(y/n): ";
	cin>>ch;
	cout<<"-------------------------------"<<endl;
	}while(ch=='y'|| ch=='Y');
	
	
}
void CLL::display()
{
	node *p=head;
	if(head==NULL)
	{
		cout<<"No Order!!"<<endl;
		
	}
	else
	{
		do{
			cout<<"Order No: ";
			cout<<p->orderNo<<endl;
			cout<<"Size Of Pizza: ";
			cout<<p->sizeOfPizz<<endl;
			cout<<"Quantity Of Pizza: ";
			cout<<p->quantity<<endl;
			cout<<"Price Of one Pizza: ";
			cout<<p->price<<endl;
			cout<<"Total Price: ";
			cout<<p->price*p->quantity<<endl;
			p=p->next;
		}while(p!=head);
	}
}
void CLL::insert()
{
	 int ch, pos;
    cout << "\nInsert Menu:\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "Enter your choice: ";
    cin >> ch;

    node *temp = new node;
    cout << "Enter Order No.: ";
    cin >> temp->orderNo;
    cout << "Enter Size of pizza (Small/Medium/Big): ";
    cin >> temp->sizeOfPizz;
    cout << "Enter Quantity: ";
    cin >> temp->quantity;
    cout << "Enter Price of one Pizza: ";
    cin >> temp->price;
    
    if (head == NULL) {
        temp->next = temp;
        head = temp;
        cout << "Inserted as first order.\n";
        return;
    }

    if (ch == 1) {  
        node *p = head;
        while (p->next != head)
            p = p->next;
        p->next = temp;
        temp->next = head;
        head = temp;
        cout << "Inserted at beginning.\n";
    }
    else if (ch == 2) {  
        node *p = head;
        while (p->next != head)
            p = p->next;
        p->next = temp;
        temp->next = head;
        cout << "Inserted at end.\n";
    }
    
}
void CLL::deleteCLL()
{
	node *curr=head;
	node *prev=NULL;
	int ordid;
	cout<<"Enter a order No which want to delete: ";
	cin>>ordid;
	
	do
	{
		if(curr->orderNo==ordid)
		{
		
			if(curr==head)
			{
				node *temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				temp->next=head->next;
				head=head->next;
				delete curr;
				break;
			}
			else if(curr->next==head)
			{
				prev->next=head;
				delete curr;
				break;
			}
			else
			{
				prev->next=curr->next;
				delete curr;
				break;
			}
			
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	} while(curr!=head);
}
void CLL::update()
{
	 if (head == NULL) {
        cout << "No orders to update." << endl;
        return;
    }

    int ordid;
    cout << "Enter the Order No. you want to update: ";
    cin >> ordid;

    node* curr = head;
    bool found = false;

    do {
        if (curr->orderNo == ordid) {
            found = true;
            cout << "Order found. Enter new details:" << endl;

            cout << "Enter new Size of pizza (Small/Medium/Big): ";
            cin >> curr->sizeOfPizz;
            cout << "Enter new Quantity: ";
            cin >> curr->quantity;
            cout << "Enter new Price of one Pizza: ";
            cin >> curr->price;
            curr->TotalPrice = curr->price * curr->quantity;

            cout << "Order updated successfully.\n";
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (!found) {
        cout << "Order not found with Order No. " << ordid << endl;
    }
}

int main() {
		 CLL c1;
    int choice;

    cout << "\t!!Welcome to Pizza Parlor!!" << endl;
    cout << "\t-------------------------------" << endl;

    do {
        cout << "\n====== Pizza Order Menu ======\n";
        cout << "1. Create Orders\n";
        cout << "2. Display Orders\n";
        cout << "3. Insert Order (Beginning/End)\n";
        cout << "4. Delete Order\n";
        cout << "5. Update Order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                c1.create();
                break;

            case 2:
                cout << "\n\t!!Your Bill!!" << endl;
                cout << "\t--------------" << endl;
                c1.display();
                break;

            case 3:
                c1.insert();
                break;

            case 4:
                c1.deleteCLL();
                break;
                
            case 5:
            	c1.update();
            	break;

            case 6:
                cout << "Thank you for visiting Pizza Parlor!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
