//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring Structure
struct blood
{
    char name[50];
    char bg[10];
    char sex[10];
    char add[150];
    int age;
    int weight;
};

//function prototype
void insert(struct blood *, int);
void display(struct blood *, int);
void search_blood_type(struct blood *, int);

static int count=0; //Static Global Variable
int i; //Global Variable

//Main function
int main()
{
    struct blood *b;
    int n, o;

    printf("Enter the number of donors for today's donation: ");
    scanf("%d", &n);
    b=(struct blood *)malloc(n*sizeof(struct blood)); //malloc function to allocate memory at runtime
    if(b==NULL)
    {
        printf("\nMEMORY ALLOCATION UNSUCCESSFUL\n");
        exit(0);
    }
    while (1)
    {
        printf("---------------------------------------------\n");
        printf("\t  Blood Donation System\n");
        printf("---------------------------------------------");    
        printf("\n1. Add a donor");
        printf("\n2. Display all donors");
        printf("\n3. Display info on specific blood type");
        printf("\n4. Press 4 to exit");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-4) : ");
        fflush(stdin);
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            insert(b, n);
            break;
        case 2:
            display(b, count); //Replace n with count variale as it contains valid doner records
            break;
        case 3:
            search_blood_type(b, count);
            break;
        case 4:
            printf("\nThank you for using this Application\n\n");
            exit(0);
        default:
            printf("Enter value from 1 to 3\n\n");
            break;
        }
    }
    free(b); //Release the memory blocks which are previously allocated by malloc()
    b=NULL;
    return 0;
}
//Function definition for donor input
void insert(struct blood *b, int n)
{ 
    int age, weight;
    for(i=0;i<n;i++)      
    {
    printf("\n---------------------------------------------");
    printf("\nEnter Donor details for eligibility criteria:");
    printf("\n---------------------------------------------");
    printf("\nEnter your age \t  : ");
    fflush(stdin);
    scanf("%d", &age);
    printf("Enter your Weight : ");
    fflush(stdin);
    scanf("%d", &weight);    
    if (((age < 18) || (age > 65)) || weight < 45) //Eligibility Criteria
    {
        printf("Donor not Eligible");
        i--; // Decrement the value of i from the array if donor not eligible
    }
    else
    {
    printf("\n---------------------------------------------");
    printf("\n\tEnter details of donor-%d",i+1);
    printf("\n---------------------------------------------");
    printf("\nEnter your name\t\t: ");
    fflush(stdin);
    gets(b[i].name);
    printf("Enter your age\t\t: ");
    fflush(stdin);
    scanf("%d", &b[i].age);
    printf("Enter you.r Weight\t: ");
    fflush(stdin);
    scanf("%d", &b[i].weight);
    printf("Enter your blood group  : ");
    fflush(stdin);
    gets(b[i].bg);
    printf("Enter your sex\t\t: ");
    fflush(stdin);
    gets(b[i].sex);
    printf("Enter your address\t: ");
    fflush(stdin);
    gets(b[i].add);
    count++; //Increments the donor count in the array
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
}
//Function definition to search for specific blood type
void search_blood_type(struct blood *b, int n)
{
    char bg[10];
    int c=0;
    int found=0;
    printf("\nEnter Blood type: ");
    fflush(stdin);
    scanf("%s", bg);
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
        found=1; //Desired blood type details found
        }
    }
        printf("\nTotal number of blood type: %d\n",c);
        if(found==0) //Desired blood type details was not found
        {
            printf("\n\aRECORD DOES NOT EXIST.\n");
        }   
}