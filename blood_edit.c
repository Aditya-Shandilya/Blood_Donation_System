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
void delete(struct blood *, int);
void delete_fn(struct blood *b, int n);
void search(struct blood *, int);
void search_blood_type(struct blood *, int);
void search_name(struct blood *, int);
void search_sex(struct blood *, int);
void search_sex(struct blood *, int);

static int count=0; //Static Global Variable
int i; //Global Variable

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
        printf("\n3. Delete a donor");
        printf("\n4. Search a donor");
        printf("\n5. Press 5 to exit");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-5) : ");
        scanf("%d", &o);
        system("cls");
        switch (o)
        {
            case 1:
                insert(b, n);
                break;
            case 2:
                display(b, count); //Replace n with count variale as it contains valid doner records
                break;
            case 3:
                delete(b, n);
                break;            
            case 4:
                search(b, n);
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

void delete(struct blood *b, int n)
{
    int del;
    while (1)
    {
        system("cls");
        printf("---------------------------------------------\n");
        printf("\t\tDelete Menu\n");
        printf("---------------------------------------------");    
        printf("\n1. Delete by name");
        printf("\n2. Delete by blood type");
        printf("\n3. Delete by sex");
        printf("\n4. Press 4 to return to main menu");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-4) : ");
        scanf("%d", &del);
        system("cls");
        switch (del)
        {
        case 1:
            delete_fn(b, count);
            break;
        case 2:
            delete_fn(b, count); 
            break;
        case 3:
            delete_fn(b, count);
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

//Function definition for donor input
void insert(struct blood *b, int n)
{ 
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
            getchar();
            getchar();
            system("cls");
        }
    }
}
//Function definition for donor input
void display(struct blood *b, int n)
{
    printf("\nRecord of all donors:\n");
	printf("---------------------------------------------\n");
    for (i = 0; i <n; i++)
    {   
        printf("\nName: %s\n",b[i].name);
        printf("Age: %d\n", b[i].age);
        printf("Blood group: %s\n", b[i].bg );
        printf("Weight: %d\n", b[i].weight);
        printf("Sex: %s\n",b[i].sex);
        printf("Address: %s\n",b[i].add);
        printf("\n");              
    }
    printf("\nPress ENTER to continue"); 
    getchar();
    getchar();    
}

void delete_fn(struct blood *b, int n)
{
    int j;
    char name[50];
    char nullStr[]= {"\0"};
    printf("Enter donor name you wan't to delete:");
    scanf("%[^\n]s", name);
    for(i=0; i<n; i++)
    {
        if(strcmpi(b[i].name,name)==0)
        {
            for(j=i;j<n-2;j++)
            {
                b[j]=b[j+1]; // copy elements at the end, one pos to the left 

            }
            strcpy(b[n-1].name,nullStr);
            return;
        }

    }
    getchar();
    getchar();
    
        
}



//Function definition to search for specific blood type
void search_blood_type(struct blood *b, int n)
{
    char bg[10];
    int c=0;
    int found=0;
    printf("\nEnter Blood type: ");
    scanf(" %[^\n]s", bg);
    printf("---------------------------------------------\n");
    for(i=0;i<n;i++)
    {
         if(strcmpi(b[i].bg,bg)==0) //Compares the entered blood type with the blood types in the array
                                    //Ignore Case
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
        getchar();
        getchar();           
}

//Function to search by name
void search_name(struct blood *b, int n)
{
    char name[50];
    int found=0;
    printf("\nEnter Name: ");
    scanf(" %[^\n]s", name);
    printf("---------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        if(strcmpi(b[i].name,name)==0) //=0 (string1 identical to string2)
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
        if(found==0) //Desired name blood was not found
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }
        getchar();
        getchar();       
}

void search_sex(struct blood *b, int n)
{
    char sex[10];
    int found=0;
    printf("\nEnter Sex: ");
    scanf("%[^\n]s", sex);
    printf("---------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        if(strcmpi(b[i].sex,sex)==0) //=0 (string1 identical to string2)
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
        if(found==0) //Desired blood type blood was not found
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }
        getchar();
        getchar();   
}