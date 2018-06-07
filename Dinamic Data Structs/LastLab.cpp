#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class List {
	 
	 typedef struct Node {
	
		char key[40];
		char value[40];
		struct Node *next;
		struct Node *prev;
	}*PNode;
	
	private:
		
	PNode head, p;
	bool emptyList = false;
	
	PNode createNode() {
		
		system("cls");
		
		PNode newNode = new Node;
		cout << "������� ������: " << endl;
		cin >> newNode->key;
		cout << "������� ����: " << endl;
		cin >> newNode->value;
	
		newNode->next = NULL;
		newNode->prev = NULL;
	
		return newNode;
	}
			
	void createEmptyList() {
		
		system("cls");
		
		if(emptyList) {
			cout << "\t������ ��� ������." << endl;
		}
		else {
			head = NULL;
			system("cls");
			cout << "\t������ ������ ������." << endl;
			emptyList = true;
		}
	} 

	void addToEnd(PNode newNode) {
			
		if(head == NULL){
			head = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		}
		else {
			head->prev->next = newNode;
			newNode->prev = head->prev;
			newNode->next = head;
			head->prev = newNode;
		}
	}

	void addToBeginning(PNode newNode) {
		
		if(head == NULL){
			head = newNode;
			newNode->next = newNode;
			newNode->prev = newNode;
		}
		else {
			newNode->next = head;
			head->prev->next = newNode;
			newNode->prev = head->prev;
			head->prev = newNode;
			head = newNode;
		}		
	}

	void deleteFromBeginnig() {
		
		if(!emptyList) {
			cout << "������ ��� �� ������. ���������� ��������� ��������." << endl;
		}
		else if(head == NULL) {
			cout << "������ ����. ���������� ��������� ��������."<< endl;
		}
		else if(confirmation("\t�� �������, ��� ������ ������� ������� �� ������ ������?")) {
			head->prev->next = head->next;
			head->next->prev = head->prev;
			PNode tmp = head;
			head = head->next;
			delete(tmp);
		}
	}

	void deleteFromEnd() {
	
		if(!emptyList) {
			cout << "������ ��� �� ������. ���������� ��������� ��������." << endl;
		}
		else if(head == NULL) {
			cout << "������ ����. ���������� ��������� ��������."<< endl;
		}
		else if(confirmation("\t�� �������, ��� ������ ������� ������� �� ����� ������?")) {
			PNode tmp = head->prev;
			tmp->prev->next = head;
			head->prev = tmp->prev;
			delete(tmp);
		}
	}

	void deleteAll() {
	
		if(head == NULL) {
			cout << "\t������ ����. ���������� ��������� ��������." << endl;
			return;
		}
		else if(confirmation("\t�� �������, ��� ������ ���������� ������ � ������������� ������?")) {
			int x = numberOfNodes();
			for(int i = 0; i < x; i++) {
				head = head->next;
				delete(head->prev);
			}
			head = NULL;
		}
	}
	
	void deleteBeforeI(){
		
		system("cls");
		
		int i;
    		cout << "\t������� i: ";
    		cin >> i;
		
		int x = numberOfNodes();
		
		if(i > x) {
			cout << "����� ��������� � ������ ������ i. ���������� ��������� ��������." << endl;	
		}
		else {
			PNode p = head;
			for(int k = 1; k < i; k++) p = p->next;
			if(confirmation("\t�� �������, ��� ������ ������� ���� �������?")) {
				PNode tmp = p->prev;
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				if(i == 2) {
					head = head->next;
				}
				else delete(tmp);
			}
		}		
	}

	int numberOfNodes() {
	
		int i = 1;
	
		if(head != NULL) {
			PNode tmp = head;
			while(tmp->next != head) {
				i++;
				tmp = tmp->next;
			}
		}
		else return 0;
	
		return i;
	}
	
	void show() {
		
		system("cls");
		
		if(!emptyList) {
			cout << "\t������ ��� �� ������. ���������� ��������� ��������." << endl;
		}
		else if(head == NULL) {
			cout << "\t������ ����." << endl;
		}
		else {
			int x = numberOfNodes();
			p = head;
			cout << left << setw(8) << setfill(' ') << "� �/�"
             	 << left << setw(8) << setfill(' ') << "����"
            	 << left << setw(8) << setfill(' ') << "����������" << endl;
			for(int i = 0; i < x; i++) {
				cout << left << setw(8) << setfill(' ') << i
                	 << left << setw(8) << setfill(' ') << p->key
                	 << left << setw(8) << setfill(' ') << p->value << endl;
            	p = p->next;
			}
			cout << "� ������ " << x << " ���������." << endl;
		}
	}
	
	void insert() {
		do {
			system("cls");

           	cout << "            ���� > ������� �������� � ������" << endl
            	 << endl
            	 << "    1. �������� ������� � ������ ������." << endl
           		 << "    2. �������� ������� � ����� ������." << endl
           		 << "    3. ��������� � �������� ����." << endl
           		 << endl;
        		
       		int i;
    		cout << "    �������� ��������: ";
    		cin >> i;
    		
    		switch(i) {
    			case 1:
    				addToBeginning(createNode());
    				break;
    			case 2:
    				addToEnd(createNode());
    				break;
    			case 3:
    				return;
    			default:
    				system("cls");
    				cout << "\t������ �������� �� ����������." << endl;
    				goBack();
			}

    		
		}while(true);
	}
	
	void del() {
		do {
			system("cls");

           	cout << "            ���� > �������� �������� � ������" << endl
            	 << endl
            	 << "    1. ������� ������� �� ������ ������." << endl
            	 << "    2. ������� ������� �� ����� ������." << endl
            	 << "    3. ���������  ������� ����� i-�� �� ������ ���������." << endl
            	 << "    4. ��������� � ����." << endl
            	 << endl;
        		
       		int i;
    		cout << "    �������� ��������: ";
    		cin >> i;
    		
    		switch(i) {
    			case 1:
    				system("cls");
    				deleteFromBeginnig();
    				goBack();
    				break;
    			case 2:
    				system("cls");
    				deleteFromEnd();
    				goBack();
    				break;
    			case 3:
    				system("cls");   				
    				if(!emptyList) {
						cout << "������ ��� �� ������. ���������� ��������� ��������." << endl;
					}
					else if(head == NULL) {
						cout << "������ ����. ���������� ��������� ��������."<< endl;
					}
					else deleteBeforeI();
					goBack();
    				break;
    			case 4:
    				return;
    			default:
    				system("cls");
    				cout << "\t������ �������� �� ����������." << endl;
    				goBack();
			}

    		
		}while(true);
	}
	
	void goBack() {
	
    	cout << "\t������� ����� �������, ����� ��������� �����.";
    	cin.get();
    	cin.get();
	}
	
	bool confirmation(string str) {
		
		system("cls");
		cout << str << endl
         << "    �� - y, ��� - n: " << endl;
   		string answer;
    	cin >> answer;
    	if (answer == "y") {
	
        	return true;
    	}
    	else
        	return false;
		
	}
	
	public:
		
	void menu() {
		
		do {
			
			system("cls");
  			cout 	<< "            ���� ������ ��������" << endl
        	 	<< endl
        	 	<< "    1. �������� ������� ������." << endl
         	 	<< "    2. ����� �� ����� ����������� ������." << endl
        	 	<< "    3. ������� ���������� ��������� ������." << endl
        	 	<< "    4. ������� �������� � ������." << endl
        	 	<< "    5. �������� �������� �� ������." << endl
        	 	<< "    6. ����������� ������ � ������������� ������." << endl
        	 	<< "    7. ����� �� ���������." << endl
        	 	<< endl;

    		int i;
    		cout << "    �������� ��������: ";
    		cin >> i;
    
    		switch(i) {
    			case 1:
    				createEmptyList();
    				goBack();
					break;
    			case 2:
    				show();
    				goBack();
    				break;
    			case 3:
    				if(!emptyList){
    					system("cls");
    					cout << "\t������ ��� �� ������. ���������� ��������� ��������." << endl;
    					goBack();
					}
					else {
						system("cls");
						cout << "� ������ " << numberOfNodes() << "���������" << endl;
						goBack();
						break;
					}
					
    			case 4:
    				if(!emptyList){
    					system("cls");
    					cout << "\t������ ��� �� ������. ���������� ��������� ��������." << endl;
    					goBack();
					}
    				else insert();
    				break;
    			case 5:
    				if(!emptyList){
    					system("cls");
    					cout << "\t������ ��� �� ������. ���������� ��������� ��������." << endl;
    					goBack();
					}
    				else del();
    				break;
    			case 6:
    				system("cls");
    				if(!emptyList){
    					cout << "\t������ ��� �� ������. ���������� ��������� ��������." << endl;
					}
    				else deleteAll();
    				goBack();
    				break;
    			case 7:
    				if(confirmation("\t�� �������, ��� ������ ����� �� ���������?")) exit(0);
    				break;
    			default:
    				system("cls");
    				cout << "\t������ �������� �� ����������." << endl;
    				goBack();
			}
		} while(true);
	}
	
};




int main() {
	
	setlocale(LC_ALL, "Russian");
	
	cout << endl
         << endl
		 << "                              ������������ ����������� � ����� ���������� ���������" << endl
         << "                                     ����������� ��������������� ��������� " << endl
         << "                                 ��������������� ���������� ������� �����������" << endl
         << "                           \"���������� ������������� ����������� ����� �.�. ���������\"" << endl
         << endl
         << "                            ��������� �������������� ���������, ���������� � �����������" << endl
         << endl
         << "                          ������� ���������� ��������������� ��������� � ����������������" << endl
         << endl
         << endl
         << "                                                  ������������ ������" << endl
         << endl
         << "                                �� ���������� \"����������� � ����������������\"" << endl
         << endl
         << "                           �� ���� \"������������ ��������� ������. ������ � ������������" << endl
         << "                                       ����������� ������� ��� ��������� ��������.\"" << endl
         << endl
         << endl
         << endl
         << endl
         << "                                                                    ��������" << endl
         << "                                                                    ������� ������ 415" << endl
         << "                                                                    ����� ����� ��������" << endl
         << "                                                                    ���������� �������������� ���������," << endl
         << "                                                                    ���������� � �����������" << endl
         << "                                                                    ����� �.�." << endl
         << "                                                                    ������� ������������:" << endl
         << "                                                                    _____________________" << endl
         << endl
         << endl
         << endl
         << endl
         << "                                                   ������ - 2018" << endl
         << endl
         << endl
         << endl;

    cout << "                          ������� ENTER ��� �������� ����.";
    cin.get();
    List a;
    a.menu();
	
	return 0;
}

