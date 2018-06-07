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
		cout << "Введите данные: " << endl;
		cin >> newNode->key;
		cout << "Введите ключ: " << endl;
		cin >> newNode->value;
	
		newNode->next = NULL;
		newNode->prev = NULL;
	
		return newNode;
	}
			
	void createEmptyList() {
		
		system("cls");
		
		if(emptyList) {
			cout << "\tСписок уже создан." << endl;
		}
		else {
			head = NULL;
			system("cls");
			cout << "\tПустой список создан." << endl;
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
			cout << "Список еще не создан. Невозможно выполнить операцию." << endl;
		}
		else if(head == NULL) {
			cout << "Список пуст. Невозможно выполнить операцию."<< endl;
		}
		else if(confirmation("\tВы уверены, что хотите удалить элемент из начала списка?")) {
			head->prev->next = head->next;
			head->next->prev = head->prev;
			PNode tmp = head;
			head = head->next;
			delete(tmp);
		}
	}

	void deleteFromEnd() {
	
		if(!emptyList) {
			cout << "Список еще не создан. Невозможно выполнить операцию." << endl;
		}
		else if(head == NULL) {
			cout << "Список пуст. Невозможно выполнить операцию."<< endl;
		}
		else if(confirmation("\tВы уверены, что хотите удалить элемент из конца списка?")) {
			PNode tmp = head->prev;
			tmp->prev->next = head;
			head->prev = tmp->prev;
			delete(tmp);
		}
	}

	void deleteAll() {
	
		if(head == NULL) {
			cout << "\tСписок пуст. Невозможно выполнить операцию." << endl;
			return;
		}
		else if(confirmation("\tВы уверены, что хотите уничтожить список с освобождением памяти?")) {
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
    		cout << "\tВведите i: ";
    		cin >> i;
		
		int x = numberOfNodes();
		
		if(i > x) {
			cout << "Число элементов в списке меньше i. Невозможно выполнить операцию." << endl;	
		}
		else {
			PNode p = head;
			for(int k = 1; k < i; k++) p = p->next;
			if(confirmation("\tВы уверены, что хотите удалить этот элемент?")) {
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
			cout << "\tСписок еще не создан. Невозможно выполнить операцию." << endl;
		}
		else if(head == NULL) {
			cout << "\tСписок пуст." << endl;
		}
		else {
			int x = numberOfNodes();
			p = head;
			cout << left << setw(8) << setfill(' ') << "№ п/п"
             	 << left << setw(8) << setfill(' ') << "Ключ"
            	 << left << setw(8) << setfill(' ') << "Информация" << endl;
			for(int i = 0; i < x; i++) {
				cout << left << setw(8) << setfill(' ') << i
                	 << left << setw(8) << setfill(' ') << p->key
                	 << left << setw(8) << setfill(' ') << p->value << endl;
            	p = p->next;
			}
			cout << "В списке " << x << " элементов." << endl;
		}
	}
	
	void insert() {
		do {
			system("cls");

           	cout << "            МЕНЮ > ВСТАВКА ЭЛЕМЕНТА В СПИСОК" << endl
            	 << endl
            	 << "    1. Вставить элемент в начало списка." << endl
           		 << "    2. Вставить элемент в конец списка." << endl
           		 << "    3. Вернуться к главному меню." << endl
           		 << endl;
        		
       		int i;
    		cout << "    Выберите действие: ";
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
    				cout << "\tТакого действия не существует." << endl;
    				goBack();
			}

    		
		}while(true);
	}
	
	void del() {
		do {
			system("cls");

           	cout << "            МЕНЮ > УДАЛЕНИЕ ЭЛЕМЕНТА В СПИСКЕ" << endl
            	 << endl
            	 << "    1. Удалить элемент из начала списка." << endl
            	 << "    2. Удалить элемент из конца списка." << endl
            	 << "    3. Исключить  элемент перед i-ым по номеру элементом." << endl
            	 << "    4. Вернуться к меню." << endl
            	 << endl;
        		
       		int i;
    		cout << "    Выберите действие: ";
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
						cout << "Список еще не создан. Невозможно выполнить операцию." << endl;
					}
					else if(head == NULL) {
						cout << "Список пуст. Невозможно выполнить операцию."<< endl;
					}
					else deleteBeforeI();
					goBack();
    				break;
    			case 4:
    				return;
    			default:
    				system("cls");
    				cout << "\tТакого действия не существует." << endl;
    				goBack();
			}

    		
		}while(true);
	}
	
	void goBack() {
	
    	cout << "\tНажмите любую клавишу, чтобы вернуться назад.";
    	cin.get();
    	cin.get();
	}
	
	bool confirmation(string str) {
		
		system("cls");
		cout << str << endl
         << "    Да - y, нет - n: " << endl;
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
  			cout 	<< "            МЕНЮ ВЫБОРА ДЕЙСТВИЙ" << endl
        	 	<< endl
        	 	<< "    1. Создание пустого списка." << endl
         	 	<< "    2. Вывод на экран содержимого списка." << endl
        	 	<< "    3. Подсчет количества элементов списка." << endl
        	 	<< "    4. Вставка элемента в список." << endl
        	 	<< "    5. Удаление элемента из списка." << endl
        	 	<< "    6. Уничтожение списка с освобождением памяти." << endl
        	 	<< "    7. Выйти из программы." << endl
        	 	<< endl;

    		int i;
    		cout << "    Выберите действие: ";
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
    					cout << "\tСписок еще не создан. Невозможно выполнить операцию." << endl;
    					goBack();
					}
					else {
						system("cls");
						cout << "В списке " << numberOfNodes() << "элементов" << endl;
						goBack();
						break;
					}
					
    			case 4:
    				if(!emptyList){
    					system("cls");
    					cout << "\tСписок еще не создан. Невозможно выполнить операцию." << endl;
    					goBack();
					}
    				else insert();
    				break;
    			case 5:
    				if(!emptyList){
    					system("cls");
    					cout << "\tСписок еще не создан. Невозможно выполнить операцию." << endl;
    					goBack();
					}
    				else del();
    				break;
    			case 6:
    				system("cls");
    				if(!emptyList){
    					cout << "\tСписок еще не создан. Невозможно выполнить операцию." << endl;
					}
    				else deleteAll();
    				goBack();
    				break;
    			case 7:
    				if(confirmation("\tВы уыерены, что хотите выйти из программы?")) exit(0);
    				break;
    			default:
    				system("cls");
    				cout << "\tТакого действия не существует." << endl;
    				goBack();
			}
		} while(true);
	}
	
};




int main() {
	
	setlocale(LC_ALL, "Russian");
	
	cout << endl
         << endl
		 << "                              Министерство образования и науки Российской Федерации" << endl
         << "                                     Федеральное государственное бюджетное " << endl
         << "                                 образовательное учреждение высшего образования" << endl
         << "                           \"Российский экономический университет имени Г.В. Плеханова\"" << endl
         << endl
         << "                            Факультет математической экономики, статистики и информатики" << endl
         << endl
         << "                          Кафедра управления информационными системами и программирования" << endl
         << endl
         << endl
         << "                                                  ЛАБОРАТОРНАЯ РАБОТА" << endl
         << endl
         << "                                по дисциплине \"Информатика и программирование\"" << endl
         << endl
         << "                           на тему \"Динамические структуры данных. Работа с симметричным" << endl
         << "                                       циклическим списком без головного элемента.\"" << endl
         << endl
         << endl
         << endl
         << endl
         << "                                                                    Выполнил" << endl
         << "                                                                    студент группы 415" << endl
         << "                                                                    очной формы обучения" << endl
         << "                                                                    факультета математической экономики," << endl
         << "                                                                    статистики и информатики" << endl
         << "                                                                    Рыжов В.А." << endl
         << "                                                                    Научный руководитель:" << endl
         << "                                                                    _____________________" << endl
         << endl
         << endl
         << endl
         << endl
         << "                                                   Москва - 2018" << endl
         << endl
         << endl
         << endl;

    cout << "                          Нажмите ENTER для открытия меню.";
    cin.get();
    List a;
    a.menu();
	
	return 0;
}

