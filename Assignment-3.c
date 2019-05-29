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
#define MAX_QUES_LEN 100
#define MAX_ANS_LEN 50
#define MIN_USERNAME_LEN 5
#define MIN_PASS_LEN 8
#define MAX_ENTRY 500
#define MAX_USERINFO_LEN 25
#define MAX_REC_QUES 3
#define INVALID_USERNAME_CHAR "`~!@#$%^&*()_-+=[]\\{}|;\':\",./<>? "

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
user_t create_user(void);
void change_password(void);
void reset(void);
void main_menu(void);
int ran_prime (char* given);
char* get_message(char* filename);
void encrypt(char* filename);
void save_encryption(char* filename, char* message);
void decrypt(char* filename);
void search(char* filename);
void main_menu_select(char* filename);
int gcd(int a, int b);


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

	FILE *fp1, *fp2;
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

	FILE *fp1, *fp2;
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


/********************************************************************************
 *	createuser
 *
 *
********************************************************************************/

user_t create_user (void)
{
	while ((getchar()) != '\n');
	char TempName[MAX_ENTRY], TempPass[MAX_ENTRY];
	char Ques[MAX_REC_QUES + 1][MAX_ENTRY], Ans[MAX_REC_QUES + 1][MAX_ENTRY];
	int i = 0, l = 0, a = 0, b = 0;
	FILE * Userfile;

	/* Entering "*" canceles user creation */
	printf("Enter * at any time to cancel.\n");

	/* Username entry */
	for (i = 0; i < 1; i++)
	{
		printf("Enter a username that is between 5 to 25 characters long using only letters, underscores and/or numbers.\n");
		fgets(TempName, MAX_ENTRY, stdin);

		/* Checking for cancel */
		if (strcmp(TempName, "*\n") == 0)
		{
			printf("Cancelling.\n");
			main();
		}

		/* Checking for previous used usernames */
		Userfile = fopen(TempName, "r");
		if (Userfile != NULL)
		{
			printf("Your username is the same as another user, please try a different username or add numbers e.g. Username1\n");
			i--;
		}

		/* Username valid?, + 1 to account for newline character appended by fgets */
		if ((strlen(TempName)) > MAX_USERINFO_LEN + 1 || (strlen(TempName)) < MIN_USERNAME_LEN + 1 || (strpbrk(TempName, INVALID_USERNAME_CHAR)) > 0)
		{
			printf("Your username is too long, too short or contains invalid characters, please try using a different username.\n");
			i--;
		}
	}

	/* Password Entry */
	for (i = 0; i < 1; i++)
	{
		printf("Enter a password that is between 8 to 25 characters long.\n");
		fgets(TempPass, MAX_ENTRY, stdin);

		/* Checking for cancel */
		if (strcmp(TempPass, "*\n") == 0)
		{
			printf("Cancelling.\n");
			main();
		}

		/* Password Valid? */
		if ((strlen(TempPass)) > MAX_USERINFO_LEN + 1 || (strlen(TempPass)) < MIN_PASS_LEN + 1)
		{
			printf("Your password is too short or too long, please try a different password.\n");
			i--;
		}
	}
	
	/* Recovery questions */
	for (i = 0; i < 1; i++)
	{
		printf("Add recovery questions to your account.\n");

		for (l = 1; l < MAX_REC_QUES + 1; l++)
		{
			for (i = 0; i < 1; i++)
			{
				/* Entering their question */
				printf("Enter recovery question %d (Maximum 100 characters)\n", l);
				fgets(Ques[l], MAX_ENTRY, stdin);

				/* Checking for cancel */
				if ((strcmp(Ques[l], "*\n")) == 0)
				{
					printf("Cancelling.\n");
					main();
				}

				/* Valid input? */
				else if (strlen(Ques[l]) > MAX_QUES_LEN + 1 || strlen(Ques[l]) < 1)
				{
					printf("Invalid input, too long or no input.\n");
					i--;
				}
			}

			for (i = 0; i < 1; i++)
			{
				/* Entering their answer */
				printf("Enter the answer to: %s", Ques[l]);
				fgets(Ans[l], MAX_ENTRY, stdin);

				/* Checking for cancel */
				if ( (strcmp(Ans[l], "*\n")) == 0)
				{
					printf("Cancelling.\n");
					main();
				}

				/* Valid input? */
				else if (strlen(Ans[l]) > MAX_ANS_LEN + 1 || strlen(Ans[l]) < 1)
				{
					printf("Invalid input, too long or no input.\n");
					i--;
				}
			}
		}
	}

	printf("Creating user, please wait...\n");

	/* Getting random prime numbers */

	a = ran_prime(TempName);
	b = ran_prime(TempPass);

	if (a == 0 || b == 0)
	{
		printf("Something went wrong, cancelling."
			   "DEBUG:"
			   "a = %d"
			   "b = %d", a, b);
		main();
	}

	/* Saving Username & Password */
	
	Userfile = fopen(TempName, "w");

	/* File creation successful? */
    if (Userfile == NULL) {
        printf("Something went wrong, you may not have permission to create files, cancelling.\n");
        main();
    }

    /* Saving username, password */
	fprintf(Userfile, "Username: %s\nPassword: %s\n", TempName, TempPass);

	/* Saving security questions */
	for (i = 1; i < MAX_REC_QUES + 1; i++)
	{
		fprintf(Userfile, "Q%d: %sA%d: %s\n", i, Ques[i], i, Ans[i]);
	}

	/* Holding Keys ***TEMPORARY*** */

	fprintf(Userfile, "a = %i\nb = %i\n", a, b);

	/* Closing file */
	fclose(Userfile);

	/* Success (if fail, returned to manu earlier) */
	printf("\nSuccess, Welcome %s", TempName);

	/* Returning struct */

	user_t user = {TempName, TempPass, a, b};

	return user;
}


/********************************************************************************
 *	ran_prime
 *
 *
********************************************************************************/

int ran_prime (char* given)
{
	int i = 0, ran_num = 0, primed = 0, l = 0, prime = 0;
	long seed = 0;
	char entry[MAX_ENTRY];

	strcpy(entry, given);

	/* To get consistant primes (will still be different as usernames cannot be the same)
	   change MAX_ENTRY to strlen(entry) */
	for (i = 0; i < MAX_ENTRY; i++)
	{
		int Temp = entry[i];
		seed = fabs(seed + Temp);
	}

	srand(seed);

	/* printf("Seed: %ld\n", seed); */

	for (i = 0; i < 1; i++)
	{
		ran_num = rand();

		for (l = 2; l < ran_num/2; l++)
		{
			if (ran_num%l == 0)
			{
				primed = 1;
				break;
			}
		}

		if (primed == 0)
		{
			prime = ran_num;
			break;
		}
		else
		{
			i--;
		}

		primed = 0;
	}

	/* printf("The prime: %d\n", prime); */

	return prime;
}
