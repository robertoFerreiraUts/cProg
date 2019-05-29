#include<stdio.h>
#include<stdlib.h>

int encrypt(void);
int decrypt(void);
int encrypt_view(void);
int decrypt_view(void);

FILE *fp1, *fp2;
char ch;

int main()
{
    int choice;
    while(1)
    {
        printf("Select One of the Following:\n");
        printf("\n1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. View The Encypted File\n");
        printf("4. Exit\n");
        printf("\nEnter Your Choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: encrypt();
                break;
            case 2: decrypt();
                break;
            case 3: encrypt_view();
                break;
            case 4: exit(1);
        }
    }
    printf("\n");
    return 0;
}

int encrypt()
{
    printf("\n");
    fp1 = fopen("source.txt","r");
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
		remove("source.txt");
    return 0;
}

int decrypt()
{
    printf("\n");
    fp1 = fopen("encrypted.txt","r");
    if(fp1 == NULL)
    {
        printf("Source File Could Not Be Found\n");
    }
    fp2 = fopen("source.txt","w");
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
    return 0;
}

int encrypt_view()
{
    printf("\n");
    fp1 = fopen("encrypted.txt","r");
    if(fp1 == NULL)
    {
        printf("No File Found\n");
        exit(1);
    }
    else
    {
        while(1)
        {
            ch = fgetc(fp1);
            if(ch == EOF)
            {
                break;
            }
            else
            {
                printf("%c", ch);
            }
        }
        printf("\n");
        fclose(fp1);
    }
    printf("\n");
    return 0;
}
