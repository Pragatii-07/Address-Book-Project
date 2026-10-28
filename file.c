#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.csv", "w");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Data saved successfully\n");
}

void load_data_from_file(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.csv", "r");

    if (fp == NULL)
    {
        perror("File is not present\n");
        return;
    }

    for (int i = 0; ; i++)
    {
        int res = fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                         addressBook->contacts[i].name,
                         addressBook->contacts[i].phone,
                         addressBook->contacts[i].email);
    

        if (res == 3)
            addressBook->contactCount++;
        else
            break;
    }

    fclose(fp);
}