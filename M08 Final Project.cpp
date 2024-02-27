#include <iostream>
#include <string>
 
 using namespace std;
 
 enum menu {
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
    };
    
 struct {
        std::string name;
        std::string time;
        int num_people;
        int max_size = 10;
    } reservation[50];
 struct {
        int table_number;        
        int max_size;
        int size;
        std::string isReservedBy;
    } table[20];   


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