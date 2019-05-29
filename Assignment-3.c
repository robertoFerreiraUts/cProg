/********************************************************************************
 *	48430 Fundamentals of C Programming - Assignment 3 (Group Project)
 *	File Encryption
 *	Names:
 *	Jackie Leong	(Team Leader)
 *	Alan Kocharians
 *	Nick Iacono
 *	Roberto Ferreira
 *	Date: 08/05/2019
 *
********************************************************************************/

/********************************************************************************
 *	Included Libraries
 *
 *
********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/********************************************************************************
 *	List preprocessing directives (#define)
 *
 *
********************************************************************************/

/********************************************************************************
 *	Structs
 *
 *
********************************************************************************/
struct user
{
	char* name;
	char* password;
	int public_key;
	int private_key;
};
typedef struct user user_t;

/********************************************************************************
 *	Function Prototypes
 *
 *
********************************************************************************/
void pre_menu(void);
user_t login(void);
void create_user(void);
void change_password(void);
void reset(void);
void main_menu(void);
char* get_message(char* filename);
void encrypt(char* filename);
void save_encryption(char* filename, char* message);
void decrypt(char* filename);
void search(char* filename);
void main_menu_select(char* filename);
int gcd(int a, int b);

FILE *fp1, *fp2;
char ch;
/********************************************************************************
 *	MAIN
 *
 *
********************************************************************************/

int main (void)
{
	char* filename;
	filename = "hello";
	encrypt(filename);
	/* CODE */
	main_menu_select(filename);

	return 0;
}

/********************************************************************************
 *	PasswordEntry
 *
 *
********************************************************************************/

user_t login (void)
{
	user_t user;
	/* CODE */
	return user;
}

/********************************************************************************
 *	ChangePassword
 *
 *
********************************************************************************/

void changePassword (void)
{
	/* CODE */return;
}

/********************************************************************************
 *	RESET
 *
 *
********************************************************************************/

void reset (void)
{
	/* CODE */return;
}

/********************************************************************************
 *	Start_Menu
 *
 *
********************************************************************************/

void start_menu (void)
{
	/* CODE */return;
}

/********************************************************************************
 *	Main_Menu
 *
 *
********************************************************************************/

void main_menu (void)
{
	printf("\n"
	"1. Encrypt File\n"
	"2. Decrypt File\n"
	"3. Search File\n"
	"4. Exit the program\n"
	"Enter choice (Number between 1-4)>\n");
}

/********************************************************************************
 *	Encrypt
 *
 *
********************************************************************************/

void main_menu_select (char* filename)
{
	int i = 0;
	while (i != 4)
	{
		main_menu();
		scanf(" %d", &i);

		switch (i)
		{

		case 1: encrypt(filename);
				break;
		case 2: decrypt(filename);
				break;
		case 3: search(filename);
				break;
		case 4: exit(0);
				break;
		default:
			printf("Invalid choice\n");
		}
	}
}



void encrypt(char* filename)
{
	printf("\n");
	fp1 = fopen(filename,"r");
	if(fp1 == NULL)
	{
			printf("Source File Could Not Be Found\n");
	}
	fp2 = fopen("encrypted.txt","w");
	if(fp2 == NULL)
	{
			printf("Target File Could Not Be Found\n");
	}
	while(1)
	{
			ch = fgetc(fp1);
			if(ch == EOF)
			{
					printf("\nEnd Of File\n");
					break;
			}
			else
			{
					ch = ch - (8 * 5 - 3);
					fputc(ch, fp2);
			}
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	remove(filename);
	return;
}

/********************************************************************************
 *	Decrypt
 *
 *
********************************************************************************/

void decrypt (char* filename)
{
	printf("\n");
	fp1 = fopen("encrypted.txt","r");
	if(fp1 == NULL)
	{
			printf("Source File Could Not Be Found\n");
	}
	fp2 = fopen(filename,"w");
	if(fp2 == NULL)
	{
			printf("Target File Could Not Be Found\n");
	}
	while(1)
	{
			ch = fgetc(fp1);
			if(ch == EOF)
			{
					printf("\nEnd Of File\n");
					break;
			}
			else
			{
					ch = ch + (8 * 5 - 3);
					fputc(ch, fp2);
			}
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	return;
}

/********************************************************************************
 *	Search
 *
 *
********************************************************************************/

void search (char* filename)
{
	return;
}
