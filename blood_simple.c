#include <stdio.h>
#include <string.h>

#define name_len 11
#define bg_len 4
#define sex_len 7
#define max_donor 100

char name_[max_donor][name_len];
char bg_[max_donor][bg_len];
char sex_[max_donor][sex_len];
char a_[max_donor];
char w_[max_donor];

int insert(int *index);
int display(int *index);
int search_blood_type(int *count);

int main()
{
    int o,count=0;
    while (1)
    {
        printf("\n1. Add a donor\n\n");
        printf("2. Display all donors\n\n");
        printf("3. Display info on specific blood type\n\n");
        printf("4. Press 4 to exit\n\n");
        printf("Select your option (1-3)\n\n");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            insert(&count);
            break;
        case 2:
            display(&count);
            break;
        case 3:
            search_blood_type(&count);
            break;
        case 4:
            printf("Thank you for using this Application\n\n");
            return 0;
        default:
            printf("Enter value from 1 to 3\n\n");
        }
    }
}

int insert(int *count)
{
    char local_name[10];
    int age,weight;
    printf("\nEnter your name:\n\n");
    scanf("%s",local_name);

    printf("\nEnter your age:\n\n");
    scanf("%d", &age);
    printf("\nEnter your Weight:\n\n");
    scanf("%d", &weight);
    if (((age < 18) & (age > 65)) & weight < 45)
    {
        printf("Donor not Eligible");
        return -1;
    }
    w_[*count]=weight;
    a_[*count]=age;
    strcpy(name_[*count],local_name);

    printf("\nEnter your blood group:\n\n");
    scanf("%s", bg_[*count]);
    printf("\nEnter your sex:\n\n");
    scanf("%s", sex_[*count]);
    (*count)+=1;
    return 0;
}

int display(int *count)
{

    for (int i = 0; i <*count; i++)
    {   
        printf("Name:");
        puts(name_[i]);
        printf("Age: %d\n", a_[i]);
        printf("Blood group:");
        puts(bg_[i]);
        printf("Weight: %d\n", w_[i]);
        printf("Sex:");
        puts(sex_[i]);
        printf("\n");
    }
    
    return 0;
}

int search_blood_type(int *count)
{
    char sample_bg[3];
    printf("Enter Blood type:");
    scanf("%s", sample_bg);

    int counter=0;
    int indexes[*count+1],j=0;
    for(int i=0;i<*count;i++)
    {
        if(sample_bg[0]!=bg_[i][0]) continue;
        if(sample_bg[1]!=bg_[i][1]) continue;
        if((sample_bg[1]=='B') && (bg_[i][1]=='B') && (sample_bg[2]!=bg_[i][2])) continue;
        counter++;
        indexes[j++]=i;
    }
    printf("\nTotal such donor: %d\n",counter);
    for(int k=0;k<j;k++)
    {
        int fi = indexes[k];
        puts(name_[fi]);
        printf("%d\n", a_[fi]);
        puts(bg_[fi]);
        printf("%d\n", w_[fi]);
        puts(sex_[fi]);
        printf("\n");
    }
    return 0;
}