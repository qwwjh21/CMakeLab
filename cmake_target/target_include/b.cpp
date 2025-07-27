#include <iostream>
void A();
void B(){
    A();
    std::cout << "In B" << A_VAR << std::endl;
}
