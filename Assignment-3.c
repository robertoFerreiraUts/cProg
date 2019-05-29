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

char* get_message(char* filename)
{
	int c;
	FILE *file;
	char buffer[1000];
	char* message;
	int counter = 0;
	file = fopen(filename, "r");
	if (file)
	{
		while ((c = getc(file)) != EOF) {
			buffer[counter] = c;
			counter++;
		}
		fclose(file);
	}
	buffer[counter+1] = '\0';
	message = (char*)malloc(counter * sizeof(char));
	strcpy(message, buffer);
	return message;
}

void encrypt(char* filename)
{
	char* message = get_message(filename);
/*	char encrypted_message[sizeof(message)+1];*/ 
	double p = 3;
	double q = 7;

	double publicKey1 = p * q;

	int encrypt = 2;
	double phi = (p-1)*(q-1);

	while (encrypt < phi)
	{
		if (gcd(encrypt, phi) == 1)	break;
		else encrypt++;
	}

	int k = 2;
	double decrypt = (1 + (k*phi))/encrypt;

		char mssg = message[0];
		double msg = 20;
		printf("message data = %c", mssg);
		printf("ascii data = %lf", msg);

		double encrypted = pow(msg, encrypt);
		encrypted = fmod(encrypted, publicKey1);
		char encrypted_msg = (char)(encrypted);
		printf("\nEncypted data = %lf", encrypted);
		printf("\nEncypted ascii= %c", encrypted_msg);

		double decrypted = pow(encrypted, decrypt);
		decrypted = fmod(decrypted, publicKey1);
		char decrypted_message =(char)decrypted;
		printf("\n DEcrypted data = %f", decrypted);
		printf("\n DEcrypted ascii = %c", decrypted_message);
/*
	int i;
	for (i=0; i<=sizeof(message)+1; i++)
	{
		double msg = (double)message[i];
		printf("message data = %c", (char)msg);

		double encrypted = pow(msg, encrypt);
		encrypted = fmod(encrypted, publicKey1);
		encrypted_message[i] = (char)encrypted+constant;
		printf("\nEncypted data = %lf", encrypted);

		double decrypted = pow(encrypted, decrypt);
		decrypted = fmod(decrypted, publicKey1);
		printf("\n DEcrypted data = %c", (char)decrypted);
	}

	encrypted_message[i+1] = '\0';	
	save_encryption(filename, encrypted_message);
*/
	return;
}

void save_encryption(char* filename, char* message) 
{
	FILE *fp = fopen(filename, "w");
    if (fp != NULL)
	{
		fputs(message, fp);
		fclose(fp);
	}
}

int gcd(int a, int b)
{
	int temporary;
	while (b != 0)
	{
		temporary = a % b;
		a = b;
		b = temporary;
	}
	return a;
}

/********************************************************************************
 *	Decrypt
 *
 *
********************************************************************************/

void decrypt (char* filename)
{
	char* message = get_message(filename);
	char decrypted_message[sizeof(message)+1];
	double constant = 100;
	double p = 3;
	double q = 7;

	double publicKey1 = p * q;

	int encrypt = 2;
	double phi = (p-1)*(q-1);

	while (encrypt < phi)
	{
		if (gcd(encrypt, phi) == 1)	break;
		else encrypt++;
	}

	int k = 2;
	double decrypt = (1 + (k*phi))/encrypt;
		
	int i;
	for (i=0; i<=sizeof(message)+1; i++)
	{
		double msg = (double)(message[i]-constant);

		double decrypted = pow(msg, decrypt);
		decrypted = fmod(decrypted, publicKey1);
		
		printf("asci: %lf", decrypted);
		decrypted_message[i] = (char)decrypted;
		printf("\ndecypted data = %c", decrypted_message[i]);
	}
	decrypted_message[i+1] = '\0';	

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
