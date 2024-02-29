#include <iostream>
#include <string>
 
 using namespace std;
 
    enum MenuItem {
    heg_Burger = 35,
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
    if ()
    {
        for (int j = 0; j < order,table.numberOfPeople; j ++)
    }
}
}





    int main() {
   for(int i = 0; i <20; i++) {

    if(i <= 7) {
        table[i].max_size = 2;
    }
    else if((i>=8)&&(i<10)) {
        table[i].max_size = 10;
    }
    else if((i>=10)&&(i<14)) {
        table[i].max_size = 6;
    }
    else {
        table[i].max_size = 4;
    }
    table[i].table_number = i;
    std::cout << table[i].max_size << "\n";
   }
    
    return 0;
}