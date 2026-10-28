/* Project Title : Address Book
   
Project Description :
   This project is a simple Address Book application in C that allows users to manage their personal contacts.
   It provides options to:  → Add new contact
                            → Search contact (by name, phone, or email)
                            → Edit existing contact
                            → Delete contact
                            → List all contacts 
                            → Save contacts to file
                            → Exit program
 
  When the program is executed again, the previously saved contact list is loaded automatically.
  This project demonstrates the use of structures, file handling, string manipulation, functions,
  and menu-driven programming in C. 

Name   : Pragati Subhash Todakar.
course : ECEP

*/


#include <stdio.h>
#include "contact.h"
#include"file.h"

int main()
 {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. save contact\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                listContacts(&addressBook);
                break;
            case 6:
                saveContactsToFile(&addressBook);
                break;
            case 7:
                    exitProgram();
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    
       return 0;
}
