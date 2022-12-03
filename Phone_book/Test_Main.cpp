#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "phone.h"

using namespace Art_Space;
int main()
{
    phoneBook rec;
    int choice;

    while(1)
    {
        char nm[20];
        std::cout << "\n*****Phone Book -Developed by Arthur  Berberyan for Pixart lab *****\n";
        std::cout << "1) Add New Record\n";
        std::cout << "2) Display All Records\n";
        std::cout << "3) Search Telephone No.\n";
        std::cout << "4) Search Person Name\n";
        std::cout << "5) Update Telephone No.\n";
        std::cout << "6) Delete a record \n";
        std::cout << "7) Exit\n";
        std::cout << "Choose your choice : ";
        std::cin >> choice;
        switch(choice)
        {
            case 1 : rec.newrecord();
                 break;

            case 2 :  rec.display();
              break;

            case 3 :rec.searchpname();
                    break;
                    

            case 4 :
                    std::cout << "\n\nEnter Name : ";
                    std::cin >> nm;
                    rec.display(nm);
            break;

            case 5 :rec.updatetelno();
                 break;

           case 6:   rec.deleterec();
                    break;

           case 7:  exit(1);

           default:
                    std::cout << "Invalid Option!!" << std::endl;

        }

    }


return 0;
}
