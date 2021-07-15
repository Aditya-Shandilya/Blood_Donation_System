#include <stdio.h>
#include <stdlib.h>

struct blood
{
    char name[50];
    char bg[10];
    char sex[10];
    char add[150];
    int age;
    int weight;
};

void insert(struct blood *, int);
void display(struct blood *, int);

static int count=0; 
int i; 

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
        system("cls");
        printf("---------------------------------------------\n");
        printf("\t  Blood Donation System\n");
        printf("---------------------------------------------");    
        printf("\n1. Add a donor");
        printf("\n2. Display all donors");
        printf("\n3. Press 3 to exit");
        printf("\n---------------------------------------------\n");        
        printf("\nEnter your choice (1-3) : ");
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
void insert(struct blood *b, int n)
{ 
    for(i=0;i<n;i++) 
    {
        printf("\n---------------------------------------------");
        printf("\nEnter Donor details for eligibility criteria:");
        printf("\n---------------------------------------------");
        printf("\nEnter your age \t  : ");
        scanf("%d", &b[i].age);
        printf("Enter your Weight : ");
        scanf("%d", &b[i].weight);
        if (((b[i].age < 18) || (b[i].age > 65)) || b[i].weight < 45) 
        {
            printf("Donor not Eligible");
            i--; 
        }
        else
        {
        printf("\n---------------------------------------------");
        printf("\n\tEnter details of donor-%d",i+1);
        printf("\n---------------------------------------------");
        printf("\nEnter your name\t\t: ");
        scanf(" %[^\n]s",b[i].name);
        printf("Enter your blood group  : ");
        scanf(" %[^\n]s",b[i].bg);
        printf("Enter your sex\t\t: ");
        scanf(" %[^\n]s",b[i].sex);
        printf("Enter your address\t: ");
        scanf(" %[^\n]s",b[i].add);
        count++;
        }
        getchar();
        getchar();
        system("cls");
    }
}
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
    getchar();
    getchar();
}