#include "contact.h"
#include "file.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

// Initialize address book and load data from file
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
   
    load_data_from_file(addressBook);
    
}

// Display all contacts with sorting option
void listContacts(AddressBook *addressBook)
{
    int choice;

    if (addressBook->contactCount == 0)
    {
        printf("Address book is empty.\n");
        return;
    }

    printf("\nSort by:\n");
    printf("1. Name \t2. Phone\t3. Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    bubbleSort(addressBook, choice);

    printf("\n--------------------------------------------------------------------------\n");
    printf("%-25s %-15s %-35s\n", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-25s %-15s %-35s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("--------------------------------------------------------------------------\n");
}

void bubbleSort(AddressBook *addressBook, int choice)
{
    int i, j;
    Contact temp;
    int n = addressBook->contactCount;

    if (n <= 1)
        return;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            int result = 0;

            if (choice == 1) 
                result = strcasecmp(addressBook->contacts[j].name,
                                    addressBook->contacts[j + 1].name);

            else if (choice == 2) 
                result = strcmp(addressBook->contacts[j].phone,
                                addressBook->contacts[j + 1].phone);

            else if (choice == 3) 
                result = strcasecmp(addressBook->contacts[j].email,
                                    addressBook->contacts[j + 1].email);
            else
            {
                printf("Invalid sorting choice.\n");
                return;
            }

            if (result > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
}

// Check if phone number already exists in address book
int check_duplicate_phone(AddressBook *addressBook, char *phone)
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            return 1; 
        }
    }
    return 0; 
}

void createContact(AddressBook *addressBook)
{
    int flag;
      Contact new;

   // Name validation loop
    do
    {
        flag = 0;
        printf("Name: ");
        scanf("%[^\n]", new.name);
        getchar();
        flag = validate_name(new.name);
    } while (flag == 0);

  // Phone validation and duplicate check loop
   do
{
    flag = 0;

    printf("Phone Number: ");
    scanf("%[^\n]", new.phone);
    getchar();

    if(validate_number(new.phone) == 0)
    {
        continue;   
    }

  // Check duplicate phone number
    if(check_duplicate_phone(addressBook, new.phone))
    {
        printf("This number already exists. Please enter a different one.\n");
        continue;   
    }

    flag = 1;

} while (flag == 0);
  
// Email validation loop
    do
    {
        flag = 0;
        printf("E-mail: ");
        scanf("%[^\n]", new.email);
        getchar();
        flag = validate_email(new.email);
    } while (flag == 0);

    // Store contact in address book
    addressBook->contacts[addressBook->contactCount] = new; 
    addressBook->contactCount++; 

    printf("Contact added successfully!\n"); 
    printf("No. of contacts present in Address Book: %d",addressBook->contactCount);
}


int validate_name(char *name)
{
    if(name[0] == '\0')
    {
        printf("Name can not be empty");
        return 0;
    }
    int i=0;
    while(name[i]!='\0')
    {
        if(islower(name[i]) || isupper(name[i]) || isspace(name[i]))
        {
            i++;
        }
        else
        {
            printf("Invalid name!\nName should only contain alphabets\n");
            return 0;
        }
        
    }
    printf("Name accepted\n");
    return 1;
    
}

int validate_number(char *num)
{
    int i=0;
    if(strlen(num)!=10)
    {
        printf("Phone number should contain only 10 digits\n");
        return 0;
    }
    else
    {
        while(num[i]!='\0')
        {
            if(isdigit(num[i]))
            i++;
            else
            {
                printf("Phone number should contain only digits\n");
                return 0;
            }
           
        }
    }
    printf("Phone number added\n");
    return 1;

}

// Validate email format
int validate_email(char *mail)
{
    int i=0, at_pos = 0, dot_pos = 0, count = 0;
    if(mail[0] =='\0')
    {
        printf("Email field can not be empty\n");
        return 0;
    }
    while(mail[i] !='\0')
    {
        if(isupper(mail[i]))
        {
            printf("Mail ID should not contain Upper case letters!\n");
            return 0;
        }
        if(mail[i] =='@')
        {
            count ++;
            at_pos = i;
        }
        if(mail[i] =='.')
        {
            dot_pos = i;
        }
        i++;
    }

    if(count != 1)
    {
        printf("Email should contain only one @\n");
        return 0;
    }
    if (at_pos == 0)
    {
        printf("'@' cannot be first character\n");
        return 0;
    }
    if(dot_pos-at_pos<5)
    {
        printf("Enter valid domain\n");
        return 0;
    }
   if (!(strstr(mail, ".com") || strstr(mail, ".in")))
   {
        printf("Invalid extention!\n");
        return 0;
   }

    printf("Email accepted\n");
    return 1;
}

// Search contact by name, phone, or email 
void searchContact(AddressBook *addressBook)
{
    char buffer[50];
    int ch;

    printf("How do you want to search: \n");
    printf("1. Name \t2. Phone\t3. Email\n");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
        {
            int found = 0;

            printf("Enter the name you want to search: ");
            scanf(" %[^\n]", buffer);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasestr(addressBook->contacts[i].name, buffer))
                {
                    printf("Contact Found\n");
                    printf("%20s%15s%20s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);

                    found = 1;
                }
            }

            if(found == 0)
                printf("Name not found!\n");

            break;
        }

        case 2:
        {
            int found = 0;

            printf("Enter the phone number you want to search: ");
            scanf(" %[^\n]", buffer);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasestr(addressBook->contacts[i].phone, buffer))
                {
                    printf("Contact Found\n");
                    printf("%20s%15s%20s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);

                    found = 1;
                }
            }

            if(found == 0)
                printf("Phone number not found!\n");

            break;
        }

        case 3:
        {
            int found = 0;

            printf("Enter the email you want to search: ");
            scanf(" %[^\n]", buffer);

            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasestr(addressBook->contacts[i].email, buffer))
                {
                    printf("Contact Found\n");
                    printf("%20s%15s%20s\n",
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);

                    found = 1;
                }
            }

            if(found == 0)
                printf("Email not found!\n");

            break;
        }

        default:
            printf("Enter correct choice!\n");
    }
}
 
// Edit existing contact details by searching name 
void editContact(AddressBook *addressBook)
{
    char buffer[50];

    printf("Enter the contact you want to edit : ");
    scanf(" %[^\n]", buffer);

    // Search contact to update
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].name, buffer))
        {
            printf("Editing contact : %s\n", buffer);

            printf("Enter new name : ");
            scanf(" %[^\n]", addressBook->contacts[i].name);

            printf("Enter new phone number : ");
            scanf(" %[^\n]", addressBook->contacts[i].phone);

            printf("Enter new email : ");
            scanf(" %[^\n]", addressBook->contacts[i].email);

            printf("Contact successfully edited\n");
            return;
        }
    }

    printf("Contact does not found\n");
}

void deleteContact(AddressBook *addressBook)
{
    char buffer[50];

    printf("Enter what you want to delete : ");
    scanf(" %[^\n]", buffer);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcasestr(addressBook->contacts[i].name, buffer))
        {
            for (int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;
            printf("Contact deleted successfully\n");
            return;
        }
    }

    printf("Contact does not found\n");
}

void exitProgram()
{
    char choice;

    printf("\nYou are about to exit the Address Book.\n");
    printf("Have you saved your contacts? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Exiting the program!\n");
        exit(0);
    }
    else
    {
        printf("Warning: Your unsaved contacts will be lost if you exit now\n");
        printf("Press 'y' to exit without saving, or any other key to return to the main menu: ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y')
        {
            printf("Exiting without saving \n");
            exit(0);
        }
        else
        {
            printf("Returning to the main menu\n");
            return;
        }
    }
}




