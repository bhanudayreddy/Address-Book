#include "contact.h"

void scancontacts(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.txt", "r");

  addressBook->contactCount = 0;

    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fp);

}



void listContacts(AddressBook *addressBook) 
{
    printf(BLUE"==============================================\n "RESET);
    printf(YELLOW"   Name            Phone             Email    \n "RESET);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\t %s\t %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf(BLUE"==============================================\n "RESET);


}



void createContact(AddressBook *addressBook) 
{
    while(1)
    {
    printf("Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    if(validname(addressBook->contacts[addressBook->contactCount].name,addressBook))
    {
        break;
    }
    }
    while(1)
    {
        printf("Enter mobile number: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
        if(validphone(addressBook->contacts[addressBook->contactCount].phone,addressBook))
        {
            break;
        }
    }
    while(1)
    {
        printf("Enter email: ");
        scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
        if(validemail(addressBook->contacts[addressBook->contactCount].email,addressBook))
        break;
    }

    printf(GREEN"Contact created successfully!!!\n"RESET); 
    addressBook->contactCount++;
    
}

int searchContact(AddressBook *addressBook) 
{
    int n;
    printf(CYAN"Enter the option to search by: \n"RESET);
    printf("1.Search by Name\n");
    printf("2.Search by Phone number\n");
    printf("3.Search by email address\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            searchbyname(addressBook);
            break;
        }
        case 2:
        {
            searchbyphone(addressBook);
            break;
        }
    
        case 3:
        {
            searchbyemail(addressBook);
            break;   
        }
        default: 
        {
            printf(RED"Search Unsucsessful\n"RESET);
            return 0;
        }
    } 
    return 0;      
}

void editContact(AddressBook *addressBook) 
{
    int index = -1;  
    int option;
    char namee[50], phonee[20], emaill[50]; 
    int newindex[100];  
    int newindexcount = 0;

    printf(CYAN"What do you want to edit by? \n"RESET);
    printf("1. Name\n2. Phone\n3. Email\n");
    printf("Enter the option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]", namee);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].name, namee)) {
                    newindex[newindexcount++] = i;
                    printf("%d. %s \t %s \t %s \n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        case 2:
            printf("Enter phone number: ");
            scanf(" %[^\n]", phonee);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].phone, phonee)) {
                    newindex[newindexcount++] = i;
                    printf("%d. %s \t %s \t %s \n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        case 3:
            printf("Enter email address: ");
            scanf(" %[^\n]", emaill);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].email, emaill)) {
                    newindex[newindexcount++] = i;
                    printf("%d. %s\t %s\t %s\n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        default: 
            printf(RED"Invalid Option... Please try again!!\n"RESET);
            return;
    }

    if (newindexcount == 0) {
        printf(RED"Contact not found\n"RESET);
        return;
    } 

    if (newindexcount > 1) {
        int choice;
        printf("Select the contact to edit : %d", newindexcount);
        scanf("%d", &choice);  
        
        if (choice >= 1 && choice <= newindexcount) {
            index = newindex[choice - 1];
        } else {
            printf(RED"Invalid selection.\n"RESET);
            return;
        }
    } else {
        index = newindex[0];  
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", namee);
    if (!validname(namee, addressBook)) {
        printf(RED"Invalid name\n"RESET);
        return;
    }

    printf("Enter new phone: ");
    scanf(" %[^\n]", phonee);  
    if (!validphone(phonee, addressBook)) {
        printf(RED"Invalid phone number\n"RESET);
        return;
    }

    printf("Enter new email: ");
    scanf(" %[^\n]", emaill);
    if (!validemail(emaill, addressBook)) {
        printf(RED"Invalid email\n"RESET);
        return;
    }

    strcpy(addressBook->contacts[index].name, namee);
    strcpy(addressBook->contacts[index].phone, phonee);
    strcpy(addressBook->contacts[index].email, emaill);

    printf(GREEN"Contact updated successfully\n"RESET);
}


void deleteContact(AddressBook *addressBook) 
{
    int index = -1;  
    int option;
    char namee[50], phonee[20], emaill[50]; 
    int newindex[100];  
    int newindexcount = 0;

    printf(CYAN"What do you want to delete by? \n"RESET);
    printf("1. Name\n2. Phone\n3. Email\n");
    printf("Enter the option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter name: ");
            scanf(" %[^\n]", namee);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].name, namee)) {
                    newindex[newindexcount++] = i;
                    printf("%d. %s\t %s\t %s\n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        case 2:
            printf("Enter phone number: ");
            scanf(" %[^\n]", phonee);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].phone, phonee)) {
                    newindex[newindexcount++] = i;
                    printf("%d.%s\t %s\t %s\n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        case 3:
            printf("Enter email address: ");
            scanf(" %[^\n]", emaill);
            for(int i = 0; i < addressBook->contactCount; i++) {
                if(strstr(addressBook->contacts[i].email, emaill)) {
                    newindex[newindexcount++] = i;
                    printf("%d.%s\t %s\t %s\n", newindexcount, 
                        addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,
                        addressBook->contacts[i].email);
                }
            }
            break;
        default: 
            printf(RED"Invalid Option. Please try again!!\n"RESET);
            return;
    }

    if (newindexcount == 0) {
        printf(RED"Contact not found\n"RESET);
        return;
    } 

    if (newindexcount > 1) {
        int choice;
        printf(CYAN"Select the contact to delete:"RESET);
        scanf("%d", &choice);  
        
        if (choice >= 1 && choice <= newindexcount) {
            index = newindex[choice - 1];
        } else {
            printf(RED"Invalid selection.\n"RESET);
            return;
        }
    } else {
        index = newindex[0];  
    }
    printf(CYAN"Do you want to delete the contact? \n"RESET);
    printf("1.Yes\n");
    printf("2.No\n");
    printf("Select the option: \n");
    scanf("%d",&option);

    switch(option)
    {
    case 1:
    {
        
    for (int i = index; i < addressBook->contactCount - 1; i++) {
        addressBook->contacts[i] = addressBook->contacts[i + 1]; 
    }
    
    addressBook->contactCount--;

    printf(GREEN"Contact deleted successfully\n"RESET);
    break;
    }

    case 2:
        printf(CYAN"Returning to main menu!!!\n"RESET);
        return;
        break;
    default:
    printf(RED"Invalid option\n"RESET);             
    }
}
void savecontacts(AddressBook *addressBook)
{
    FILE * fp = fopen("Contacts.txt","w");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
}

 