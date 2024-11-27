#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
  printf("Address book menu:\n");
  printf("------------------------------------------------------------------------\n");
  printf("Name\t\t\tPhone\t\t\tE-mail\n");
  printf("------------------------------------------------------------------------\n");
    for(int i=0; i < addressBook->contactCount; i++){
        printf("%s\t\t%s\t\t%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) 
{
    populate_contacts(addressBook);
}

void createContact(AddressBook *addressBook) 
{
  char name[50];
  char phone[20];
  char email[50];
  printf("Enter new contact name: ");
  scanf(" %[^\n]", name);
  printf("Enter new contact phone: ");
  scanf(" %s", phone);
  for(int i=0; i < addressBook->contactCount; i++){
    if(strcmp(addressBook->contacts[i].phone, phone) == 0){
      printf("Contact phone already exists\n");
      return;
    }
  }

  printf("Enter new contact email: ");
  scanf(" %s", email);
  for(int i=0; i < addressBook->contactCount; i++){
    if(strcmp(addressBook->contacts[i].email, email) == 0){
      printf("Contact email already exists\n");
      return;
    }
  }
  strcpy(addressBook->contacts[addressBook->contactCount].name, name);
  strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
  strcpy(addressBook->contacts[addressBook->contactCount].email, email);
  addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
  char name[50];
  char phone[20];
  char email[50];
  int choice;
  printf("Search contact by: 1.Name 2.Phone  3.Email ");
  scanf("%d", &choice);
  int flag = 0;
  switch(choice){
    case 1:
      printf("Enter contact name: ");
      scanf(" %[^\n]", name);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].name, name) == 0){
          printf("Contact found: %s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          return;
        }
      }
      flag = 1;
      break;

    case 2:
      printf("Enter contact phone: ");
      scanf(" %s", phone);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].phone, phone) == 0){
          printf("Contact found: %s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          return;
        }
      }
      flag = 1;
      break;

    case 3:
      printf("Enter contact email: ");
      scanf(" %s", email);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].email, email) == 0){
          printf("Contact found: %s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
          return;
        }
      }
      flag = 1;
      break;
  }
  if(flag==1){
    printf("Contact not found\n");
  }
}

void editContact(AddressBook *addressBook) 
{
  char name[50];
  char phone[20];
  char email[50];
  char name1[50];
  char phone1[20];
  char email1[50];
  int choice;
  printf("Edit contact by:   1. Name   2. Phone   3. Email\n");
  scanf("%d", &choice);
  int flag = 0;
  switch(choice){
    case 1:
      printf("Enter contact name you want to edit: ");
      scanf(" %[^\n]", name);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].name, name) == 0){
          printf("Enter edited name: ");
          scanf(" %[^\n]", name1);
          strcpy(addressBook->contacts[i].name, name1);
          return;
        }
      }
      flag = 1;
      break;

    case 2:
      printf("Enter phone number you want to edit: ");
      scanf(" %s", phone);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].phone, phone) == 0){
          printf("Enter edited phone number: ");
          scanf(" %s", phone1);
          strcpy(addressBook->contacts[i].phone, phone1);
          return;
        }
      }
      flag = 1;
      break;

    case 3:
      printf("Enter email you want to edit: ");
      scanf(" %s", email);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].email, email) == 0){
          printf("Enter edited email: ");
          scanf(" %s", email1);
          strcpy(addressBook->contacts[i].email, email1);
          return;
        }
      }
      flag = 1;
      break;
  }
  if(flag==1){
    printf("Contact not found\n");
  }
}

void deleteContact(AddressBook *addressBook) 
{
  char name[50];
  char phone[20];
  char email[50];
  int choice;
  printf("Delete contact by: 1.Name 2.Phone  3.Email ");
  scanf("%d", &choice);
  int flag = 0;
  switch(choice){
    case 1:
      printf("Enter contact name you want to delete: ");
      scanf(" %[^\n]", name);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].name, name) == 0){
          strcpy(addressBook->contacts[i].name, addressBook->contacts[i+1].name);
          strcpy(addressBook->contacts[i].phone, addressBook->contacts[i+1].phone);
          strcpy(addressBook->contacts[i].email, addressBook->contacts[i+1].email);
          addressBook->contactCount--;
          return;
        }
      }
      flag = 1;
      break;

    case 2:
      printf("Enter phone number you want to delete: ");
      scanf(" %s", phone);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].phone, phone) == 0){
          strcpy(addressBook->contacts[i].name, addressBook->contacts[i+1].name);
          strcpy(addressBook->contacts[i].phone, addressBook->contacts[i+1].phone);
          strcpy(addressBook->contacts[i].email, addressBook->contacts[i+1].email);
          addressBook->contactCount--;
          return;
        }
      }
      flag = 1;
      break;

    case 3:
      printf("Enter contact email: ");
      scanf(" %s", email);
      for(int i=0; i < addressBook->contactCount; i++){
        if(strcmp(addressBook->contacts[i].email, email) == 0){
          strcpy(addressBook->contacts[i].name, addressBook->contacts[i+1].name);
          strcpy(addressBook->contacts[i].phone, addressBook->contacts[i+1].phone);
          strcpy(addressBook->contacts[i].email, addressBook->contacts[i+1].email);
          addressBook->contactCount--;
          return;
        }
      }
      flag = 1;
      break;
  }
  if(flag==1){
    printf("Contact not found\n");
  }
}
