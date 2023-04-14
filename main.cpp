#include <iostream>
#include <data_structures/data_structures.h>
int main(){
    std::cout << "Main loding\n" ;
    Person peris{"Peris", 21};
    std::cout << "Name: " << peris.getname() << "\n";
    return 0;
}