/*
Name: Muhammed Salih YILDIZ
ID: 150180012 
*/

#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

// Structs that will be needed
struct IngNode {
    string data;
    IngNode* next;
};

struct drinkNode {
    string data;
    drinkNode* next;
};

//Pizza ingredients
const string chicken[] = { "mozarella", "chicken", "mushroom", "corn", "onion", "tomato" };
const string broccoli[] = { "mozarella", "broccoli", "pepperoni", "olive", "corn", "onion" };
const string sausage[] = { "mozarella", "sausage", "tomato", "olive", "mushroom", "corn" };
const string drinkArr [] = { "cola", "soda", "ice tea", "fruit juice"};

//Classes that was described in PDF

class Pizza {
private:
    string name;
    string size;
    IngNode* ingredients;
    string crust_type;
public:
    ~Pizza();
    Pizza();
    Pizza(string size, string crust_type, int pizza_type);
    Pizza(Pizza&);
    string getName();
    string getSize();
    IngNode* getIngs();
    string getCrust();
};
Pizza::~Pizza(){
    IngNode* temp;
    while(ingredients != NULL){
        temp = ingredients;
        ingredients = ingredients->next;
        delete temp;
    }
}

Pizza::Pizza() {
    IngNode* ingredients = new IngNode;
    ingredients->data = chicken[0];
    ingredients->next = NULL;
    size = "medium";
    crust_type = "normal";
}

Pizza::Pizza(string Size, string Crust_type, int Pizza_type) {
    size = Size;
    crust_type = Crust_type;
    //Adding ingredients to pizzas according to their types
    if (Pizza_type == 1) {
        name = "Chicken Pizza";
        IngNode* temp_ingredients = new IngNode;
        temp_ingredients->data = chicken[0];
        temp_ingredients->next = NULL;
        IngNode* traverse = temp_ingredients;
        int i = 1;
        while (i < 6) {
            IngNode* temp = new IngNode;
            temp->data = chicken[i];
            temp->next = NULL;
            traverse->next = temp;
            traverse = traverse->next;
            i++;
        }
        ingredients = temp_ingredients;
    }
    else if (Pizza_type == 2) {
        name = "Broccoli Pizza";
        IngNode* temp_ingredients = new IngNode;
        temp_ingredients->data = broccoli[0];
        temp_ingredients->next = NULL;
        IngNode* traverse = temp_ingredients;
        int i = 1;
        while (i < 6) {
            IngNode* temp = new IngNode;
            temp->data = broccoli[i];
            temp->next = NULL;
            traverse->next = temp;
            traverse = traverse->next;
            i++;
        }
        ingredients = temp_ingredients;
    }
    else if (Pizza_type == 3) {
        name = "Sausage Pizza";
        IngNode* temp_ingredients = new IngNode;
        temp_ingredients->data = sausage[0];
        temp_ingredients->next = NULL;
        IngNode* traverse = temp_ingredients;
        int i = 1;
        while (i < 6) {
            IngNode* temp = new IngNode;
            temp->data = sausage[i];
            temp->next = NULL;
            traverse->next = temp;
            traverse = traverse->next;
            i++;
        }
        ingredients = temp_ingredients;
    }

}

Pizza::Pizza(Pizza& pizza) {
    IngNode* head = new IngNode;
    head->data = pizza.ingredients->data;
    head->next = NULL;
    IngNode* traverser = pizza.ingredients;
    IngNode* copier = head;
    traverser = traverser->next;
    //Copying all ingredients to new pizza
    while (traverser != NULL) {
        IngNode* temp = new IngNode;
        temp->data = traverser->data;
        copier->next = temp;
        copier = copier->next;
        traverser = traverser->next;
    }
    copier->next = NULL;
    IngNode* traverse = head;
    IngNode* tail = NULL;
    int i = 1;
    cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
    while (traverse != NULL) {
        cout << i << ". " << traverse->data << endl;
        traverse = traverse->next;
        i++;
    }
    i--;
    cout << "Press 0 to save it." << endl;
    traverse = head;
    int temp = 0;
    int removedIngs[i];
    for(int j = 0 ; j < i ; j++){
        removedIngs[j] = 0;
    }
    int ing_number = 0;
    //Saving number of ingredients which will be removed
    while (true) {
        cin >> temp;
        ing_number++;
        if(ing_number >= i){
            cout<<"There must exist at least one ingredient in a pizza!"<<endl;
            break;
        }
        if (temp == 0) {
            break;
        }
        if (temp > i) {
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        removedIngs[temp-1] = 1;
    }
    int counter = 1;
    tail = traverse;
    traverse = traverse->next;
    //Removing ingredients which are unwanted
    while(traverse != NULL){
        if(removedIngs[counter]){
            tail->next = traverse->next;
            delete traverse ;
            traverse = tail->next;
        }else{
            tail = tail->next;
            traverse = traverse->next;
        }
        counter++;
    }
    if(removedIngs[0]){
        traverse = head;
        head = head->next;
        delete traverse;
    }

    ingredients = head;
    name = pizza.name;
    crust_type = pizza.crust_type;
    size = pizza.size;
}

string Pizza::getName() {
    return name;
}
string Pizza::getCrust() {
    return crust_type;
}
IngNode* Pizza::getIngs() {
    return ingredients;
}
string Pizza::getSize() {
    return size;
}

struct pizzaNode {
    Pizza* data;
    pizzaNode* next;

};


class Order {
private:
    string customer;
    pizzaNode* pizzas;
    drinkNode* drinks;
public:
    ~Order();
    Order();
    Order(string customer_name, pizzaNode* Pizzas);
    Order(string customer_name, pizzaNode* Pizzas, drinkNode* Drinks);
    double getPrice();
    void printOrder();
    string getCustomer();
    pizzaNode* getPizzas();
    drinkNode* getDrinks();
};

Order::~Order(){
    pizzaNode* temp1;
    drinkNode* temp2;
    while(pizzas != NULL){
        temp1 = pizzas;
        pizzas = pizzas->next;
        delete temp1;
    }
    while(drinks != NULL){
        temp2 = drinks;
        drinks = drinks->next;
        delete temp2;
    }
}

Order::Order() {
    customer = "";
    pizzas = NULL;
    drinks = NULL;
}

Order::Order(string customer_name, pizzaNode* Pizzas) {
    customer = customer_name;
    pizzas = Pizzas;
    drinks = NULL;
}

Order::Order(string customer_name, pizzaNode* Pizzas, drinkNode* Drinks) {
    customer = customer_name;
    pizzas = Pizzas;
    drinks = Drinks;
}

double Order::getPrice() {
    double total = 0;
    pizzaNode* traverse_pizzas = pizzas;
    drinkNode* traverse_drinks = drinks;
    //Traversing pizzas and calculating their cost
    while (traverse_pizzas != NULL) {
        if (traverse_pizzas->data->getSize() == "small") {
            total += 15;
        }else if (traverse_pizzas->data->getSize() == "medium") {
            total += 20;
        }else if (traverse_pizzas->data->getSize() == "big") {
            total += 25;
        }
        traverse_pizzas = traverse_pizzas->next;
    }
    //Traversing drinks and calculating their cost
    while (traverse_drinks != NULL) {
        if (traverse_drinks->data == "cola") {
            total += 4;
        }else if(traverse_drinks->data == "soda"){
            total += 2;
        }else if(traverse_drinks->data == "ice tea") {
            total += 3;
        }else if (traverse_drinks->data == "fruit juice") {
            total += 3.5;
        }
        traverse_drinks = traverse_drinks->next;
    }
    return total;
}

void Order::printOrder() {
    cout<<("------------\n");
    cout<<"Name: " << customer << endl << endl ;
    pizzaNode* traverse_pizzas = pizzas;
    drinkNode* traverse_drinks = drinks;
    while (traverse_pizzas != NULL) {
        cout << traverse_pizzas->data->getName() <<"(";
        IngNode* traverse_ing = traverse_pizzas->data->getIngs();
        while (traverse_ing != NULL) {
            cout << traverse_ing->data << ", ";
            traverse_ing = traverse_ing->next;
        }
        cout<< ")" << endl << "size: " << traverse_pizzas->data->getSize() << ", crust: " << traverse_pizzas->data->getCrust() << endl << endl;
        traverse_pizzas = traverse_pizzas->next;
    }
    int drinkArray[4];
    for (int i = 0; i < 4; i++) {
        drinkArray[i] = 0;
    }
    while (traverse_drinks != NULL) {
        if (traverse_drinks->data == "cola") {
            drinkArray[0] += 1;
        }
        else if (traverse_drinks->data == "soda") {
            drinkArray[1] += 1;
        }
        else if (traverse_drinks->data == "ice tea") {
            drinkArray[2] += 1;
        }
        else if (traverse_drinks->data == "fruit juice") {
            drinkArray[3] += 1;
        }
        traverse_drinks = traverse_drinks->next;
    }
    if (drinkArray[0] != 0) {
        cout << drinkArray[0] << " cola, ";
    }
    if (drinkArray[1] != 0) {
        cout << drinkArray[1] << " soda, ";
    }
    if (drinkArray[2] != 0) {
        cout << drinkArray[2] << " ice tea, ";
    }
    if (drinkArray[3] != 0) {
        cout << drinkArray[3] << " fruit juice, ";
    }
    cout<<("\n------------\n");

}

string Order::getCustomer() {
    return customer;
}
pizzaNode* Order::getPizzas() {
    return pizzas;
}
drinkNode* Order::getDrinks() {
    return drinks;
}

struct orderNode {
    Order* data;
    orderNode* next;
};

class OrderList {
private:
    int n;
    orderNode* head;
public:
    ~OrderList();
    OrderList();
    void takeOrder();
    void listOrders();
    void deliverOrders();
    int getN();
    void setN(int N);
    orderNode* getHead();
};

OrderList::~OrderList() {
    orderNode* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

OrderList::OrderList() {
    n = 0;
    head = NULL;
}

int OrderList::getN() {
    return n;
}
void OrderList::setN(int N) {
    n = N;
}
orderNode* OrderList::getHead() {
    return head;
}

void OrderList::takeOrder() {
    cout<<("Pizza Menu\n");
    cout<<("1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)\n");
    cout<<("2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)\n");
    cout<<("3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)\n");
    cout<<"0. Back to main menu"<<endl;
    int pizza_type;
    string pizza_size;
    string pizza_crust;
    int pizza_number;
    string name;
    while(true){
        scanf("%d", &pizza_type);
        if(pizza_type == 0){
            return;
        }
        if(pizza_type > 3 || pizza_type < 0){
            cout<<"Please enter a valid number!" <<endl;
            continue;
        }
        break;
    }
    cout<<("Select size: small (15TL), medium (20TL), big (25TL)\n");
    while(true){
        cin >> pizza_size;
        if(pizza_size != "small" && pizza_size != "medium" && pizza_size != "big" ){
            cout<< "Please enter a valid size!"<<endl;
        }else{
            break;
        }
    }
    cout <<"Select crust type: thin, normal, thick" << endl;
    while(true){
        cin >> pizza_crust;
        if(pizza_crust != "thin" && pizza_crust != "normal" && pizza_crust != "thick" ){
            cout<< "Please enter a valid crust type!"<<endl;
        }else{
            break;
        }
    }
    cout << "Enter the amount:" ;
    cin >> pizza_number;
    cout<<endl;
    Pizza* pizza1 = new Pizza(pizza_size, pizza_crust, pizza_type);
    pizzaNode* orderPizzas = new pizzaNode;
    orderPizzas->data = pizza1;
    orderPizzas->next = NULL;
    pizzaNode* traverse = orderPizzas;
    if (pizza_number > 1) {
        for (int i = 1; i < pizza_number; i++) {
            pizzaNode* temp = new pizzaNode;
            Pizza* newPizza = new Pizza(*pizza1);
            temp->data = newPizza;
            temp->next = NULL;
            traverse->next = temp;
            traverse = traverse->next;
        }
    }
    drinkNode* drinks = NULL;
    drinkNode* drink_traverse = drinks;
    int drink_number;
    cout << "Please choose a drink:" << endl;
    cout << "0. no drink" << endl;
    cout << "1. cola 4 TL" << endl;
    cout << "2. soda 2 TL" << endl;
    cout << "3. ice tea 3 TL" << endl;
    cout << "4. fruit juice 3.5 TL" << endl;
    cout << "Press -1 for save your order" << endl;
    while (true) {
        cin >> drink_number ;
        if (drink_number == 0 || drink_number == -1) {
            break;
        }
        else if (drink_number > 4 || drink_number < 0) {
            cout << "Please enter a valid number" << endl;
            continue;
        }
        else if (drink_number == 1) {
            drinkNode* temp = new drinkNode;
            temp->data = drinkArr[0];
            temp->next = NULL;
            if (drinks == NULL) {
                drinks = temp;
                drink_traverse = drinks;
            }
            else {
                drink_traverse->next = temp;
                drink_traverse = drink_traverse->next;
            }
        }
        else if (drink_number == 2) {
            drinkNode* temp = new drinkNode;
            temp->data = drinkArr[1];
            temp->next = NULL;
            if (drinks == NULL) {
                drinks = temp;
                drink_traverse = drinks;
            }
            else {
                drink_traverse->next = temp;
                drink_traverse = drink_traverse->next;
            }
        }
        else if (drink_number == 3) {
            drinkNode* temp = new drinkNode;
            temp->data = drinkArr[2];
            temp->next = NULL;
            if (drinks == NULL) {
                drinks = temp;
                drink_traverse = drinks;
            }
            else {
                drink_traverse->next = temp;
                drink_traverse = drink_traverse->next;
            }
        }
        else if (drink_number == 4) {
            drinkNode* temp = new drinkNode;
            temp->data = drinkArr[3];
            temp->next = NULL;
            if (drinks == NULL) {
                drinks = temp;
                drink_traverse = drinks;
            }
            else {
                drink_traverse->next = temp;
                drink_traverse = drink_traverse->next;
            }
        }
    }
    cout << "Please enter your name:" << endl;
    cin >> name ;
    orderNode* order_traverse = head;
    if (order_traverse != NULL) {
        while (order_traverse->next != NULL) {
            order_traverse = order_traverse->next;
        }
    }
    if (n == 0) {
        if (drinks != NULL) {
            orderNode* newOrder = new orderNode;
            newOrder->data = new Order(name, orderPizzas, drinks);
            newOrder->next = NULL;
            head = newOrder;
            order_traverse = head;
            n = 1;
        }
        else {
            orderNode* newOrder = new orderNode;
            newOrder->data = new Order(name, orderPizzas);
            newOrder->next = NULL;
            head = newOrder;
            order_traverse = head;
            n = 1;
        }
    }
    else {
        if (drinks != NULL) {
            orderNode* newOrder = new orderNode;
            newOrder->data = new Order(name, orderPizzas, drinks);
            newOrder->next = NULL;
            order_traverse->next = newOrder;
            order_traverse = order_traverse->next;
            n++;
        }
        else {
            orderNode* newOrder = new orderNode;
            newOrder->data = new Order(name, orderPizzas);
            newOrder->next = NULL;
            order_traverse->next = newOrder;
            order_traverse = order_traverse->next;
            n++;
        }
    }
}
void OrderList::listOrders() {
    if(head == NULL){
        cout<<endl;
        return;
    }
    orderNode* traverse = head;
    int num = 1;
    while (traverse != NULL) {
        cout << num << endl;
        traverse->data->printOrder();
        traverse = traverse->next;
        num++;
    }
}

void OrderList::deliverOrders() {
    orderNode* traverse = head;
    orderNode* tail = traverse;
    string name;
    listOrders();
    cout << "Please write the customer name inorder to deliver his/her order:"  ;
    cin >> name ;
    //Searching for customers order
    if (traverse->data->getCustomer() != name) {
        traverse = tail;
        traverse = traverse->next;
        while (traverse->data->getCustomer() != name){
            tail = tail->next;
            traverse = traverse->next;
            if (traverse == NULL) {
                cout << "Wrong name!" << endl;
                return;
            }
        }
    }else{
        head = head->next;
    }
    cout << "Following order is delivering..." << endl;
    traverse->data->printOrder();
    char promotion ;
    cout << "Total Price: " << traverse->data->getPrice() << endl;
    while (true) {
        cout << "Do you have promotion code? (y/n)" << endl;
        cin >> promotion ;
        string code;
        if(promotion == 'y'){
            cout << "Please enter your code: " ;
            cin.ignore();
            getline(cin,code) ;
            if (code == "I am a student") {
                cout << "Discounted price: " << traverse->data->getPrice() * 9 / 10 << endl;
                break;
            }else {
                cout << "Promotion code is not accepted." << endl;
                continue;
            }
        }
        else {
            break;
        }
    }
    tail->next = traverse->next;
    delete traverse;
    n--;
    cout << "The order is delivered succesfully!" << endl;
}


int main() {
    OrderList Orders;
    int choice = 0;
    while (true) {
        cout << "Welcome" << endl;
        cout << "1. Add an order" << endl;
        cout << "2. List orders" << endl;
        cout << "3. Deliver order" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose what to do: " ;
        cin >> choice ;
        if (choice == 1) {
            Orders.takeOrder();
        }else if (choice == 2) {
            Orders.listOrders();
        }else if(choice == 3){
            Orders.deliverOrders();
        }else if( choice == 4){
            cout << "Goodbye..." ;
            break;
        }else {
            cout << "Please enter a valid number!" << endl;
        }
    }
    return 0;
}