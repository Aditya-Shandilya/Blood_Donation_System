#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring Structure
struct blood
{
    char name[50];
    char bg[11];
    char sex[10];
    char add[150];
    int age;
    int weight;
};

void mainmenu(struct blood *, int);
void insert(struct blood *, int);
void display(struct blood *, int);
void search(struct blood *, int);
void search_blood_type(struct blood *, int);
void search_name(struct blood *, int);
void search_sex(struct blood *, int);
void search_sex(struct blood *, int);
void clr_file();

static int count=0; 
int i; 

int main()
{
    struct blood *b;
    int n;

    printf("Enter the number of donors for today's donation: ");
    scanf("%d", &n);
    b=(struct blood *)malloc(n*sizeof(struct blood)); //malloc function to allocate memory at runtime
    if(b==NULL)
    {
        printf("\nMEMORY ALLOCATION UNSUCCESSFUL\n");
        exit(0);
    }
    mainmenu(b,n);
    free(b); //Release the memory blocks which are previously allocated by malloc()
    b=NULL;
    return 0;
}

//Main menu
void mainmenu(struct blood *b, int n)
{
    int o;
    while (1)
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("\t  Blood Donation System\n");
        printf("---------------------------------------------");    
        printf("\n1. Add a donor");
        printf("\n2. Display all donors");
        printf("\n3. Search a donor");
        printf("\n4. RESET");
        printf("\n5. Press 5 to exit");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-4) : ");
        scanf("%d", &o);
        system("cls");
        switch (o)
        {
            case 1:
                insert(b, n);
                break;
            case 2:
                display(b, count); //count variale contains valid doner records
                break;          
            case 3:
                search(b, n);
                break;
            case 4:
                clr_file();
                break;
            case 5:
                printf("\nThank you for using this Application\n\n");
                exit(0);
            default:
                printf("Enter value from 1 to 5\n\n");
                break;   
        }
    }
}

//Search menu
void search(struct blood *b, int n)
{
    int a;
    while (1)
    {
        system("cls");   
        printf("---------------------------------------------\n");
        printf("\t\tSearch Menu\n");
        printf("---------------------------------------------");    
        printf("\n1. Search by blood type");
        printf("\n2. Search by name");
        printf("\n3. Search by sex");
        printf("\n4. Press 4 to return to main menu");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-4) : ");
        scanf("%d", &a);
        system("cls");
        switch (a)
        {
            case 1:
                search_blood_type(b, count);
                break;
            case 2:
                search_name(b, count); //Replace n with count variale as it contains valid doner records
                break;
            case 3:
                search_sex(b, count);
                break;
            case 4:
                mainmenu(b,n);
                exit(0);
            default:
                printf("Enter value from 1 to 4\n\n");
                break;
        } 
    }
}

//Donor input
void insert(struct blood *b, int n)
{
    FILE *fp = fopen("bloodrecords.txt", "a+"); 
    for(i=0;i<n;i++)      
    {
        printf("\n---------------------------------------------");
        printf("\nEnter Donor blood for eligibility criteria:");
        printf("\n---------------------------------------------");
        printf("\nEnter your age \t  : ");
        scanf("%d", &b[i].age);
        printf("Enter your Weight : ");
        scanf("%d", &b[i].weight);    
        if (((b[i].age < 18) || (b[i].age > 65)) || b[i].weight < 45) //Eligibility Criteria
        {
            printf("Donor not Eligible");
            i--; 
        }
        else
        {
            printf("\n---------------------------------------------");
            printf("\n\tEnter blood of donor-%d",i+1);
            printf("\n---------------------------------------------");
            printf("\nEnter your name\t\t: ");
            scanf(" %[^\n]s",b[i].name);
            printf("Enter your blood group  : ");
            scanf(" %[^\n]s",b[i].bg);
            printf("Enter your sex\t\t: ");
            scanf(" %[^\n]s",b[i].sex);
            printf("Enter your address\t: ");
            scanf(" %[^\n]s",b[i].add);
            count++; //Increments the donor count in the array
        }
        fwrite(&b[i],sizeof(struct blood),1,fp);
    }
    fclose(fp);
    getchar();
    getchar();
    system("cls");
}

//Donor Records
void display(struct blood *b, int n)
{
    FILE *fp = fopen("bloodrecords.txt", "r");
    printf("\nRecord of all donors:\n");
	printf("---------------------------------------------\n");
    while(fread(&b[i],sizeof(struct blood),1,fp))
    {   
        printf("\nName: %s\n",b[i].name);
        printf("Age: %d\n", b[i].age);
        printf("Blood group: %s\n", b[i].bg );
        printf("Weight: %d\n", b[i].weight);
        printf("Sex: %s\n",b[i].sex);
        printf("Address: %s\n",b[i].add);
        printf("\n");       
    }
    fclose(fp);
    printf("\nPress ENTER to continue");
    getchar();
    getchar();
    return;    
}

//Search for specific blood type
void search_blood_type(struct blood *b, int n)
{
    char bg[10];
    int c=0;
    int found=0;
    FILE *fp = fopen("bloodrecords.txt", "r");
    printf("\nEnter Blood type: ");
    scanf(" %[^\n]s", bg);
    printf("---------------------------------------------\n");
    while(fread(&b[i],sizeof(struct blood),1,fp))
    {
        if(strcmpi(b[i].bg,bg)==0) 
        {
        c=c+1;
        }

        if(strcmpi(b[i].bg,bg)==0) //=0 (string1 identical to string2)
        {
            printf("\nName: %s\n",b[i].name);
            printf("Age: %d\n", b[i].age);
            printf("Blood group: %s\n", b[i].bg );
            printf("Weight: %d\n", b[i].weight);
            printf("Sex: %s\n",b[i].sex);
            printf("Address: %s\n",b[i].add);
            printf("\n");
            found=1; //Desired blood type blood found
        }
    }
        printf("\nTotal number of blood type: %d\n",c);
        if(found==0) //Desired blood type blood was not found
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }
        fclose(fp);
        getchar();
        getchar();           
}

//Search by name
void search_name(struct blood *b, int n)
{
    char name[50];
    int found=0;
    FILE *fp = fopen("bloodrecords.txt", "r");
    printf("\nEnter Name: ");
    scanf(" %[^\n]s", name);
    printf("---------------------------------------------\n");
    while(fread(&b[i],sizeof(struct blood),1,fp))
    {
        if(strcmpi(b[i].name,name)==0) 
        {
            printf("\nName: %s\n",b[i].name);
            printf("Age: %d\n", b[i].age);
            printf("Blood group: %s\n", b[i].bg );
            printf("Weight: %d\n", b[i].weight);
            printf("Sex: %s\n",b[i].sex);
            printf("Address: %s\n",b[i].add);
            printf("\n");
            found=1; 
        }
    }
        if(found==0) 
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }
        fclose(fp);
        getchar();
        getchar();       
}

//Search by sex
void search_sex(struct blood *b, int n)
{
    char sex[10];
    int found=0;
    FILE *fp = fopen("bloodrecords.txt", "r");
    printf("\nEnter Sex: ");
    fflush(stdin);
    scanf("%[^\n]s", sex);
    printf("---------------------------------------------\n");
    while(fread(&b[i],sizeof(struct blood),1,fp))
    {
        if(strcmpi(b[i].sex,sex)==0) 
        {
            printf("\nName: %s\n",b[i].name);
            printf("Age: %d\n", b[i].age);
            printf("Blood group: %s\n", b[i].bg );
            printf("Weight: %d\n", b[i].weight);
            printf("Sex: %s\n",b[i].sex);
            printf("Address: %s\n",b[i].add);
            printf("\n");
            found=1; 
        }
    }
        if(found==0) 
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }
        fclose(fp);
        getchar();
        getchar();   
}
void clr_file()
{
    FILE *fp = fopen("bloodrecords.txt", "w");
    FILE *fp1 = fopen("temp.txt", "w");
    fclose(fp1);
    fclose(fp);
}