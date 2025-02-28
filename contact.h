
#ifndef CONTACT_H
#define CONTACT_H

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"


#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;


typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void savecontacts(AddressBook *addressBook);
void scancontacts(AddressBook *addressBook);
int validname(char *name, AddressBook *addressBook);
int validphone(char *phone, AddressBook *addressBook);
int validemail(char *email, AddressBook *addressBook);
int searchbyname(AddressBook *addressBook);
int searchbyphone(AddressBook *addressBook);
int searchbyemail(AddressBook *addressBook);
#endif
