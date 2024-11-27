#include "contact.h"

int main(void)
{
	AddressBook A1;
    A1.contactCount = 0;
    initialize(&A1);
    int choice;
	do{
    printf("\n");
		printf("Address Book Menu:\n");
		printf("1. Create contact\n");
		printf("2. Search contact\n");
		printf("3. Edit contact\n");
		printf("4. Delete contact\n");
		printf("5. List all contact\n");
		printf("6. Save contact\n");
		printf("7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			createContact(&A1);
			break;
			case 2:
			searchContact(&A1);
			break;
			case 3:
			editContact(&A1);
			break;
			case 4:
			deleteContact(&A1);
			break;
			case 5:
			listContacts(&A1);
			break;
			case 6:
			printf("Your choice is 6\n");
			break;
      case 7:
      break;
      default:
      printf("Invalid choice!! Choose between 1 to 7 choices\n");
      break;
		}
	}while(choice != 7);
    if(choice==7){
        return 0;
    }
}
