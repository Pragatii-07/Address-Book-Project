

#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100 //macro

typedef struct {
    char name[50];
    char phone[11];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void bubbleSort(AddressBook *addressBook, int choice);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);
int validate_name(char *name);
int validate_number(char *num);
int validate_email(char *mail);
void exitProgram();
#endif
