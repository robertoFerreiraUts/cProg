/********************************************************************************
 *	48430 Fundamentals of C Programming - Assignment 3 (Group Project)
 *	File Encryption
 *	Names:
 *	Jackie Leong	(Team Leader)(neehowdy)(LOOKHEREIFITCHANGED)
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
void decrypt(char* filename);
void search(char* filename);
void main_menu_select(char* filename);
int Questions_to_verify(char *Question,char *Correct_Answer,int counter,char *input);

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
 *	Login (Jackie)
 *
 *
********************************************************************************/

user_t login (void)
{
	user_t user;
	user.name = username;
	user.password=password;
	user.public_key = a;                    /*a and b are interchangeable values depending on which is public*/
	user.private_key= b;                    /*and whichever is private*/
	char file_name[MAX_ENTRY];              /*file_name and username are the same however to access the file*/
    char username[MAX_ENTRY];               /*and that values inside, i have used two variables*/
    char entered_password[MAX_ENTRY];		/*user input password*/
    char password[MAX_ENTRY];				/*genuine password for the acc*/
	int i=0;                                /*Counter for loop*/
    while (i!=1)
    {
        fflush(stdin);                      /*Clears the stdin to remove overflow*/
        printf("Enter your username or enter * to exit the program.\n");
	    fgets(file_name,MAX_ENTRY,stdin);
	    FILE*fp=NULL;
        fp = fopen(file_name,"r");
        if (strcmp(file_name,"*\n")==0)
        {
            printf("Byebye\n");
            return 0;
        }
                                                                    /*This line authetnticates whether the entered username is valid*/
                                                                    /*it verifies this by checking the length, invalid chars, etc.  */
        if ((fp == NULL && strcmp(file_name,"*\n")!=0) || (strlen(file_name)) > MAX_USERINFO_LEN + 1 || (strlen(file_name)) < MIN_USERNAME_LEN + 1 || (strpbrk(file_name, INVALID_USERNAME_CHAR)) > 0 )
        {
            printf("Username is invalid\n");
            i=0;
        }
	    else
	    {
	        fscanf(fp,"Username: %s\n\nPassword: %s\n",username,password);
            fclose(fp);
	        i =1;
	    }
	}
    
    int count=0;                                                    /*Counter for the while loop below*/    
    
    while (count !=10)
    {
        fflush(stdin);                                              /*Used to clear the stdin so that overflow does not occur*/
    	printf("Enter your password or enter * to exit the program\n");
        fgets(entered_password,MAX_ENTRY,stdin);
        char *pos;                                                  /*pos used to remove the /n character and replace it with*/
        if ((pos=strchr(entered_password,'\n'))!=NULL)              /*the \0 character so that strcmp will work successfully */
        *pos ='\0';
        else 
        {
            printf("Password is too long\n");
            count=1;
        }       
        if (strcmp (entered_password,password)==0)                  /*If password is correct, this condition will occur*/
        {	
        	printf("Correct, Welcome back\n");
        	count = 10;
       	}
        else if (strcmp(entered_password,"*")==0)                   /*Exit the password section. Essentially a quit key*/
        {
        	printf("bye");
        	return 0;
        }
        else 
        {
        	printf("Incorrect password, try again\n");
        	count = 1;
        }
        
    }
    printf("Congratulations, you've entered the correct password!");    /*This line is to ensure login is successful (Optional) */
   	                                                                    /*From this line onwards, it will jump to the main menu.*/
	return main();
}

/********************************************************************************
 *	ChangePassword
 *
 *
********************************************************************************/

void changePassword (void)
{
	char file_name[MAX_ENTRY];              /*file_name is the file where the user's personal details are stored*/
    char user_ans[MAX_ENTRY];               /*user_ans refers to the user's input/answers throughout the function*/
    char file_details_1[MAX_ANS_LEN];       /*file_details_x where x is a number from 1-3 is the answers to the questions*/
    char file_details_2[MAX_ANS_LEN];    
    char file_details_3[MAX_ANS_LEN];
    char file_quest_1[MAX_QUES_LEN];        /*file_quest_x where x is a number from 1-3 is the questions made by the user*/
    char file_quest_2[MAX_QUES_LEN];
    char file_quest_3[MAX_QUES_LEN];
    char a[1000];                            /*These represent the private and public keys a and b*/
    char b[1000];
    char username[MAX_ENTRY];               /*username is the same string as file_name however is used as a string rather*/
                                            /*than as a file*/
    char password[MAX_ENTRY];               /*password associated with the file.*/
    int count = 0;  

    while (count!=1)
    {
        fflush(stdin);                      /*Clears the stdin to remove overflow*/
        printf("Enter your username or enter * to exit the program.\n");
	    fgets(file_name,MAX_ENTRY,stdin);
	    FILE*fp=NULL;
        fp = fopen(file_name,"r");
        if (strcmp(file_name,"*\n")==0)
        {
            printf("Bye\n");
            return 0;
        }
/*This line authetnticates whether the entered username is valid it verifies this by checking the length, invalid chars, etc.*/
        if ((fp == NULL && strcmp(file_name,"*\n")!=0) || (strlen(file_name)) > MAX_USERINFO_LEN + 1 || (strlen(file_name)) < MIN_USERNAME_LEN + 1 || (strpbrk(file_name, INVALID_USERNAME_CHAR)) > 0 )
        {
            printf("Username is invalid\n");
            count=0;
        }
        /*If user_ans is correct, this condition occurs where data from the user's file is accessed.*/
        else
        {
            fscanf(fp,"Username: %s\n\nPassword: %s\n\nQ1: %s\nA1: %s\n\nQ2: %s\nA2: %s\n\nQ3:%s\nA3: %s\n\na: %s\nb: %s",username, password, file_quest_1, file_details_1, file_quest_2, file_details_2, file_quest_3, file_details_3, a, b);
            fclose(fp);
            count =1;
        }
    }
    
    Questions_to_verify(file_quest_1,file_details_1,count,user_ans);
    Questions_to_verify(file_quest_2,file_details_2,count,user_ans);
    Questions_to_verify(file_quest_3,file_details_3,count,user_ans);
    count =0;
    /*If all questions are answered succssfully, then user can create a new password with function below.*/
    while (count!=1)
    {
        printf("Enter a new password that is between 8 to 25 characters long, enter * to cancel\n");                             /*Need to implement Alan's conditions for making the pw*/
        fgets(user_ans,MAX_ENTRY,stdin);
        if (strcmp(user_ans,"*\n")==0)
        {
            printf("Bye\n");
            return 0;
        }
        if ((strlen(user_ans)) > MAX_USERINFO_LEN + 1 || (strlen(user_ans)) < MIN_PASS_LEN + 1)
		{
			printf("Your password is too short or too long, please try a different password.\n");
			count = 0;
        }
        else
        {
            strcpy(password,user_ans);
            count=1;
        }
    }
    
    FILE*fpp=NULL;                                              /*fpp pointer is to point the user's file and reset the password*/
    fpp = fopen(file_name,"w");
    if (fpp == NULL)                                            /*if fpp does not exist, which it wont unless the files are */
                                                                /*externally edited outside the program*/
    {
        printf("file error\n");
        return 1;
    }
    
    fprintf(fpp,"Username: %s\n\nPassword: %s\n\nQ1: %s\nA1: %s\n\nQ2: %s\nA2: %s\n\nQ3: %s\nA3: %s\n\na: %s\nb:%s",username,password,file_quest_1,file_details_1,file_quest_2,file_details_2,file_quest_3,file_details_3,a,b);
    fclose(fpp);
    return 0;
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
/********************************************************************************
 *	Questions to verify changing password
 *
 *

********************************************************************************/
int Questions_to_verify(char *Question,char *Correct_Answer,int counter,char *input)                
/*input = user ans, correct ans = file_details_x,counter = count*/
{
    while (counter !=10)
    {
        fflush(stdin);
    	printf("Question:%s\n",Question);
        fgets(input,MAX_ENTRY,stdin);  
        char *pos;                                                  /*pos used to remove the /n character and replace it with*/
        if ((pos=strchr(input,'\n'))!=NULL)              /*the \0 character so that strcmp will work successfully */
        *pos ='\0';
        else 
        {
            printf("Password is too long\n");
            return 1;
        }
        /*Conditions underneath determine whether user_ans is valid input*/     
        if (strcmp (input,Correct_Answer)==0)                    /*This if statement is fulfilled if user_ans is same as */
                                                                    /*the answer recorded within the user's account*/
        {	
        	printf("Correct\n");
        	counter = 10;
       	}
        else if (strcmp (input,"*") == 0)                      /*This if statement is fulfilled if user wishes to exit.*/
        {
        	printf("bye\n");
        	return main();                                      /*Return to main, escape mech, */
        }
        else                                                        /*For all incorrect answers, this condition is applied */
                                                                    /*causing the program to loop. */
        {
        	printf("Incorrect\n");
        	counter = 1;
        }
    }
    counter=0;
    return 0;
}
