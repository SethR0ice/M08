#include <iostream>
#include <string>
 
 using namespace std;
 
    enum MenuItem {
    veg_Burger = 35,
    hamburger = 45,
    FCS = 38,
    HS = 38,
    vegSliders = 38,
    haddock_sandwich = 38,
    BLT = 42,
    faux_blt = 42,
    chicken_burrito = 42,
    falafel_wrap = 42,
    cheese_pizza = 59,
    pepperoni_pizza = 59,
    faux_meat_and_chips = 77,
    fish_and_chips = 77



    }item;
    
    struct Reservation {
        string time;
        string amORpm;
        string firstName;
        string lastName;
        int reservationSize;
        bool checkedIn = false;
    }reservation;
    
    struct Table {
        int tableNumber;        
        int size;
        int numberOfPeople;
        bool available = true;
    }table;

    struct Order {
        Reservation reservation;        
        Table table;
        MenuItem items[10];
        int numItems;
        bool complete = false;
        bool paid = false;
    }order;   


    Reservation reservations[50];
    Table tables[20];
    Order orders[50];
    Order items[10];

    int numReservations = 0;
    int numTables = 20;
    int numOrders = 50;

    void welcomeMessage()
    {
        cout << "\nWelcome to Messijoes!\n"
            << "1. Make Reservation\n"
            << "2. Check-In Reservation\n"
            << "3. Enter Order\n"
            << "4. Complete Order\n"
            << "5. Calculate and Pay Bill\n"
            << "6. Close the restraunt.\n";
    }
    void createReservation(){

        if (numReservations >= 50)
        {
            cout << "You are at the maximum reservations!" << endl;
        }
        cout << "Enter a name for the reservation: "; cin >> reservation.firstName >> reservation.lastName;
        cout << "\n Enter the number of people in party: "; cin >> reservation.reservationSize;
        cout << "\n Enter the time for the reservation in HH:MM AM/PM: "; cin >> reservation.time >> reservation.amORpm;
        reservation.checkedIn = false;
    }

    void confirmReservation()
    {
        int response = 0;
        char choice = 0;
        do {
            cout << "\nPlease confirm the reservation:";
            cout << "\nReservation Name:" << reservation.firstName << " " << reservation.lastName;
            cout << "\nReservation Time:" << reservation.time << " " << reservation.amORpm;
            cout << "\nNumber in Party:" << reservation.reservationSize;
            cout << "\nIs this information correct [Y]es, [N]o, [C]ancel?";
            cin >> choice;
            if(choice == 'Y')
            {
                reservations[numReservations] = reservation;
                numReservations++;
            }
            else if (choice == 'N')
            {
                cout << "\nWhat would you like to change?\n"
                << "1. Name\n"
                << "2. Time\n"
                << "3. Number of people\n";
                cin >> response;
                switch (response)
                {
                case 1:
                cout << "Enter a name for your reservation: ";
                cin >> reservation.firstName >> reservation.lastName;
                break;
                case 2:
                cout << "Enter a time for your reservation: ";
                cin >> reservation.time >> reservation.amORpm;
                break;
                case 3:
                cout << "Enter how the size of your reservation: ";
                cin >> reservation.reservationSize;    
            }

        }
        else if (choice == 'C')
        {
            cout << "Reservation successfully canceled! Good bye!";
        }
        else {
            cout<< "Invalid choice. You must enter Y or N or C.";
        }
   }  while (choice == 'N');

}

void checkInReservation()
{
    int chosenReservation = 0;
    int selectedTable = 0;

    if (numReservations > 0){
        cout << "Select the reservation you would like to check in:\n";
        for (int i = 0; i < numReservations; i ++)
        {
            if(!reservations[i].checkedIn)
            {
                cout << i + 1 << ". "
                << reservations[i].firstName << " "
                << reservations[i].lastName << " "
                << reservations[i].time << " "
                << reservations[i].amORpm << " "
                << reservations[i].reservationSize << "people\n ";
            }
        }
        cin >> chosenReservation;
        reservations[chosenReservation - 1].checkedIn = true;
        cout << "Reservation checked in successfully!\n ";
        cout << "Choose a table to be seated!\n ";
        for (int j = 0; j <= numTables; j++)
        {
            if(tables[j].available && tables[j].size >= reservations[chosenReservation - 1].reservationSize)
            {
                cout << tables[j].tableNumber << ". " << tables[j].size << "people\n";
            }
        }
        cin >> selectedTable;
        tables[selectedTable - 1].available = false;
        tables[selectedTable - 1].numberOfPeople = reservations[chosenReservation - 1].reservationSize;
    }
    else {
        cout << "You must make a reservation first. " << endl;}
}
void createOrder()
{
    int entreSelection;
    int tableToOrder;
    cout << "Please select the table that is ready to order: \n";
    for (int i = 0; i < numTables; i++)
    {
        if((!tables[i].available) && (orders[i].complete))
        {
            cout << tables[i].tableNumber <<".Table for" << tables[i].numberOfPeople << "people.\n";
        }
    }
    cin >> tableToOrder;

    // adding table number and number of people inside the table array to the order object inside the orders struct
    order.table.tableNumber = tables[tableToOrder -1].tableNumber;
    order.table.numberOfPeople = tables[tableToOrder -1].numberOfPeople;
    if (numOrders < 51)
    {
        for (int j = 0; j < order.table.numberOfPeople; j ++)
        {
            cout << "Please choose for entre number" << j + 1 << ":\n";
            cout << "1: Veggie Burger\n"
                << "2: Hamburger\n"
                << "3: Fired Chicken Sliders\n"
                << "4: Hamburger Slider\n"
                << "5: Veggie Sliders\n"
                << "6: Haddock Sandwhich\n"
                << "7: BLT\n"
                << "8: Faux BLT\n"
                << "9: Chicken Burrito\n"
                << "10: Falafel Wrap\n"
                << "11: Cheese Pizza\n"
                << "12: Pepperoni Pizza\n"
                << "13: Faux Meat and chips\n"
                << "14: Fish and Chips\n";
            cin >> entreSelection;
            switch (entreSelection)
            {
            case 1:
                entreSelection= veg_Burger;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 2:
                entreSelection= hamburger;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 3:
                entreSelection= FCS;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 4:
                entreSelection= HS;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 5:
                entreSelection= vegSliders;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 6:
                entreSelection= haddock_sandwich;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 7:
                entreSelection= BLT;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 8:
                entreSelection= faux_blt;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 9:
                entreSelection= chicken_burrito;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 10:
                entreSelection= falafel_wrap;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 11:
                entreSelection= cheese_pizza;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 12:
                entreSelection= pepperoni_pizza;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 13:
                entreSelection= faux_meat_and_chips;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            case 14:
                entreSelection= fish_and_chips;
                order.items[j] = static_cast<MenuItem>(entreSelection);
                numOrders++;
                break;
            }
            for (int z = 0; z < order.table.numberOfPeople; z ++)
            {
                cout << "You selected: " << entreSelection << " " << order.items[z] << "\n";
            }
        }
        orders[tableToOrder] = order;
    }
}

void completeOrder()
{
    int chosenTable;
    for(int i = 0; i < 20; i ++)
    {
        cout << orders[i].table.tableNumber << " Table for" << orders[i].table.numberOfPeople << "\n";
    }
    cin >> chosenTable;
    orders[chosenTable - 1].complete = true;
}

int main() 
{
    int i;
    int response;

   for(int i = 0; i <numTables; i++)
   {


        //tables[i] = {i + 1,2,0 true}
    

        if(i <= 8)
        {
        table.tableNumber = i + 1;
        table.size = 2;
        table.numberOfPeople = 0;
        table.available = true;
        tables[i] = table;
        } 
        else if(i <=  14)
        {
        table.tableNumber = i + 1;
        table.size = 4;
        table.numberOfPeople = 0;
        table.available = true;
        tables[i] = table;
        }
        else if(i <= 18)
        {
        table.tableNumber = i + 1;
        table.size = 6;
        table.numberOfPeople = 0;
        table.available = true;
        tables[i] = table;
        }
        else  {
   
        table.tableNumber = i + 1;
        table.size = 10;
        table.numberOfPeople = 0;
        table.available = true;
        tables[i] = table;
    }
    do {
        welcomeMessage();
        cin >> response;

        switch (response)
        {
        case 1:
            createReservation();
            confirmReservation();
            break;
        case 2:
            checkInReservation();
            break;
        case 3:
            createOrder();
            break;
        case 4:
            completeOrder();
            break;
        case 5:
            //calculateBil();
            //payBill()
            break;
        case 6:
            cout << "Store is now closed. Good Bye!";
        }
    }while (response !=6);
}
}

     