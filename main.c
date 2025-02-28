#include "contact.h"

int main()
{
    int option;
    AddressBook addressbook;
    initialize(&addressbook);

    while(1)
    {
        printf(YELLOW"========ADDRESS BOOK========\n"RESET);
        printf(BLUE"Menu:\n"RESET);
        printf("1.Contacts List\n");
        printf("2.Add Contact\n");
        printf("3.Search Contact\n");
        printf("4.Edit Contacts\n");
        printf("5.Delete Contact\n");
        printf("6.Save Contacts\n");
        printf("7.Exit\n");
        printf(YELLOW"============================\n"RESET);
        printf("Choose any one option from the menu\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            listContacts(&addressbook);
            break;

        case 2:

            createContact(&addressbook);
            break;

        case 3:

            searchContact(&addressbook);
            break;

        case 4:

            editContact(&addressbook);
            break;

        case 5:
            deleteContact(&addressbook);
            break;

        case 6:
            savecontacts(&addressbook);
            printf(GREEN"Saving the contacts!\n"RESET);
            sleep(1);
            printf(GREEN"Contacts saved succesfully!!!\n");
            break;    

        case 7:
            printf(GREEN"Program terminated. Thank YOU"RESET);
             exit(0);    

        default:

            printf(RED"\nInvalid Option, Please try again\n"RESET);
            break;
        }
    }
}
