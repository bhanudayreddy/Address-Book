#include "contact.h"
// Dummy contact data
// static Contact dummyContacts[] = {
//     {"John Doe", "1234567890", "john@example.com"},
//     {"Alice Smith", "0987654321", "alice@example.com"},
//     {"Bob Johnson", "1112223333", "bob@company.com"},
//     {"Carol White", "4445556666", "carol@company.com"},
//     {"David Brown", "7778889999", "david@example.com"},
//     {"Eve Davis", "6665554444", "eve@example.com"},
//     {"Frank Miller", "3334445555", "frank@example.com"},    
//     {"Grace Wilson", "2223334444", "grace@example.com"},
//     {"Hannah Clark", "5556667777", "hannah@example.com"},
//     {"Ian Lewis", "8889990000", "ian@example.com"}
// };

void initialize(AddressBook *addressBook) 
{
     scancontacts(addressBook);

    // addressBook->contactCount=0;
    // int size =  sizeof(dummyContacts)/sizeof(dummyContacts[0]);
    // for(int i=0;i<size;i++)
    // {
    //     addressBook->contacts[addressBook->contactCount++]=dummyContacts[i];

    // }
    // assign 0 to addressBook->contactCount
   // cal size of dummyContacts (10)
   //run a loop for size of dummyContacts (10 time)
        //1. copy dummyContacts[index] to addressbook->contacts[index]
        //2. inc (addressBook->contactCount)++                          
    
}
int validname(char *name, AddressBook *addressBook)
{
    if(strlen(name)== 0)
    {
        printf(RED"\nName cannot be empty! Please try again.\n"RESET);
        return 0;
    }
    for(int i=0;i<strlen(name);i++)
    {
        if(!((name[i]>= 'A') && (name[i]<='Z') || (name[i]>='a' && name[i]<='z') || name[i]== ' '))
        {
            printf(RED"Name cannot contain other characters! Please try again."RESET);
            return 0;
        }
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].name,name)==0)
        {
            printf(RED"Contact already exists."RESET);
            return 0;
        }
    }
    return 1;
}

int validphone( char *phone, AddressBook *addressBook)
{
    if(strlen(phone)!=10)
    {
        printf(RED"Invalid Phone number,Digits must be 10\n"RESET);
        return 0;
    }

    for(int i=0;i<strlen(phone);i++)
    {
        if(phone[i]<'0'||phone[i]>'9')
        {
            printf(RED"Phone number should contain only digits.\n"RESET);
            return 0;
        }
    }
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,phone)==0)
        {
            printf(RED"Contact already exists."RESET);
            return 0;
        }
    }
    return 1;
}
int validemail(char *email, AddressBook *addressBook) {
    int len = strlen(email);
    int atCount = 0, dotCount = 0;
    
    if (email[0] == '.' || email[0] == '@') {
        printf(RED "Invalid email: cannot start with '.' or '@'.\n"RESET);
        return 0;
    }
    
    for (int i = 0; i < len; i++) {
        if (email[i] == ' ') {
            printf(RED"Invalid email: cannot contain spaces.\n"RESET);
            return 0;
        }
        if (email[i] == '@') atCount++;
        if (email[i] == '.') dotCount++;
    }
    
    if (atCount != 1 || dotCount != 1) {
        printf(RED"Invalid email: must contain exactly one '@' and one '.'.\n"RESET);
        return 0;
    }
    
    char *at = strchr(email, '@');
    char *dotcom = strstr(email, ".com");
    
    if (!at || !dotcom) {
        printf(RED"Invalid email: must contain '@' and end with '.com'.\n"RESET);
        return 0;
    }
    
    if (at == email || at == email + len - 1) {
        printf(RED"Invalid email: '@' must have characters before and after it.\n"RESET);
        return 0;
    }
    
    if (dotcom + 4 != email + len) {
        printf(RED"Invalid email: must end with '.com'.\n"RESET);
        return 0;
    }
    
    if (at > dotcom) {
        printf(RED"Invalid email: '@' must be before '.com'.\n"RESET);
        return 0;
    }
    
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].email, email) == 0) {
            printf(RED"Email already exists.\n"RESET);
            return 0;
        }
    }
    
    return 1;
}



int searchbyname( AddressBook *addressBook)
{
     char namee[50];
     int index=-1;
            int flag=0;
            printf("Enter name: ");
            scanf(" %[^\n]",namee);

            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strstr(addressBook->contacts[i].name,namee))
                {
                    printf("%d. %s \t %s \t %s \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                     flag=1;
                     index=i; 

                }
            }
            if(flag == 0)
            {
                printf(RED"No contact found\n"RESET);
                return -1;
            }
            return index;
}

int searchbyphone(AddressBook *addressBook)
{
    char phonee[20];
    int index=-1;
            int flag=0;
            printf("Enter the phone number: ");
            scanf(" %[^\n]",phonee);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strstr(addressBook->contacts[i].phone,phonee))
                {
                    printf("%d %s \t %s \t %s \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag=1;
                    index=i;

                }
                if(flag == 0)
                {
                    printf(RED"No contact found\n"RESET);
                    return -1;
                }

            }
                return index;;

}

int searchbyemail(AddressBook *addressBook)
{
    char emaill[50];
            int flag=0;
            int index=-1;
            printf("Enter email address: ");
            scanf(" %[^\n]",emaill);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strstr(addressBook->contacts[i].email,emaill))
                {
                    printf("%d %s \t %s \t %s \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag=1;
                    index=i;

                }
                if(flag==0)
            {
                printf(RED"No contact found"RESET);
                return -1;
            }
            }
            return index;
}