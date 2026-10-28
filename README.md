# **Address Book Management System in C**

## **Project Description**

The Address Book Management System is a menu-driven console application developed using C programming. It allows users to manage contact information, including names, phone numbers, and email addresses. The application supports adding, searching, editing, deleting, displaying, sorting, and saving contacts. It uses structures to organize contact data and file handling to store contact details in a CSV file for future use.

## **Features**

- **Add Contact:** Add a new contact with name, phone number, and email address.
- **Input Validation:** Validate names, phone numbers, and email addresses during contact creation.
- **Duplicate Phone Check:** Prevent adding a contact with a phone number that already exists.
- **Search Contact:** Search contacts by name, phone number, or email address.
- **Edit Contact:** Update the details of an existing contact.
- **Delete Contact:** Remove an existing contact from the address book.
- **Display Contacts:** Display all stored contacts in a formatted table.
- **Sort Contacts:** Sort contacts by name, phone number, or email address using Bubble Sort.
- **File Handling:** Save contacts to a CSV file and load previously saved contacts when the program starts.

## **Technologies Used**

- **Programming Language:** C
- **Data Organization:** Structures and arrays
- **Storage:** CSV file
- **Core Concepts:** Functions, pointers, string manipulation, searching, sorting, and file handling

## **Project Structure**

```text
Addressbook/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
└── README.md
```

## **File Description**

| **File** | **Description** |
|---|---|
| `main.c` | Contains the main function, menu, and operation selection. |
| `contact.c` | Implements contact creation, validation, searching, editing, deletion, listing, and sorting. |
| `contact.h` | Defines the Contact and AddressBook structures, constants, and function declarations. |
| `file.c` | Implements loading contacts from and saving contacts to the CSV file. |
| `file.h` | Contains declarations for file-handling functions. |
| `contacts.csv` | Stores contact records in comma-separated format. |
