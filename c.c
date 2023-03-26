#include<stdio.h> //standard input output functions
#include<conio.h> //the console input output library functions
#include<string.h> //using any string function
#include<stdlib.h> // standard library allocate memory
#include<time.h> //functions to get and manipulate date and time information
#include<math.h> //a set of functions to perform mathematical operations
void heading(); //no return & no parameters
void main_heading();
void menu();
void user_menu();
void insert();
void display();
void search();
void delete();
void arrival_time();
void user_login();
void login_user();
void main()
{
    char name[30];
    int id;
    int c;
    char username[20];
    char password[20];
     system("CLS");  //To clear the screen stdlib function
    heading();
    printf("\n\n\t\t\t\t\t1) Login as Admin");
    printf("\n\t\t\t\t\t2) Login as user");
    printf("\n\n\t\t\t\t\tEnter Option [1/2] : \t");
    scanf("%d",&c);
    system("CLS");

    switch(c)
    {
        case 1:system("CLS");
               heading();
               printf("\n\n\t\t\t\t\t\t=======================\t\t\t\t");
               printf("\n\n\t\t\t\t\t\t||    ADMIN LOGIN    ||\t\t\t\t"); //admin login menu
               printf("\n\n\t\t\t\t\t\t=======================\t\t\t\t");
               printf("\n\n\n\t\t\t\t\tEnter Username :");
               scanf("%s",&username);
               printf("\t\t\t\t\tEnter Password :");
               scanf("%s",&password);

               if(strcmp(username, "admin")==0) //This function takes two strings as arguments and compare these two strings
               {
                   if(strcmp(password ,"admin123")==0)
                   {
                       system("CLS");
                       main_heading();
                       printf("\n\n\t\t\t\t\tWELCOME!");
                       printf("\n\n\t\t\t\t\tAdmin Login Successfull !!!");
                       menu();
                   }
                   else
                   {
                       printf("\n\t\t\t\t\tIncorrect Password!!! Failed to Login");
                   }
               }
               else
               {
                    printf("\t\t\t\t\tUsername is Invalid!!! Failed to Login");
               }

                break;
        case 2:system("CLS");
               heading();
               int ch;
               printf("\n\n\t\t\t\t\t\t=======================\t\t\t\t");
               printf("\n\n\t\t\t\t\t\t||    USER LOGIN    ||\t\t\t\t"); //user login menu
               printf("\n\n\t\t\t\t\t\t=======================\t\t\t\t");
               printf("\n\n\t\t\t\t\t1.Login ");
               printf("\n\t\t\t\t\t2.New user? sign up ");
               printf("\n\t\t\t\t\tEnter Option: ");
               scanf("%d",&ch);

               switch(ch)
               {
                   case 1: printf("\n\n\t\t\t\t\t\t||   USER LOGIN    ||\t\t\t\t");
                           main_heading();
                           login_user();
                           break;

                    case 2: system("CLS");
                            main_heading();
                            user_login();
                            break;

                    default: printf("\n\t\t\t\t\tInvalid Choice!!!");
                             break;

               }
                           
    }
}   
void heading()
{
    printf("\n\t\t\t\t===================================================\t\t\t\t");
    printf("\n\t\t\t\t||       WELCOME TO CYBER MANAGEMENT SYSTEM       ||\t\t");
    printf("\n\t\t\t\t===================================================\t\t\t\t\n");
}

void main_heading()
{
    printf("\n\t\t\t\t==================================================\t\t\t\t");
    printf("\n\t\t\t\t||              CYBER MANAGEMENT SYSTEM          ||\t\t");
    printf("\n\t\t\t\t==================================================\t\t\t\t");
}

void menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t  ||==MENU==||"); //admin menu for record manipulation
    printf("\n\n\t\t\t\t\t\t1.Insert a Record.");
    printf("\n\t\t\t\t\t\t2.Display Records.");
    printf("\n\t\t\t\t\t\t3.Search a Record.");
    printf("\n\t\t\t\t\t\t4.Delete a Record.");
    printf("\n\t\t\t\t\t\t5.Exit");
    printf("\n\n\t\t\t\t\t\tEnter Option :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("CLS");
                insert();
                break;

        case 2: system("CLS");
                main_heading();
                display();
                printf("\n\n\t\t\t\t\tTo continue, Press any key");
                fflush(stdin); //used to flush the output buffer of the stream
                getchar(); // input single character
                menu();

        case 3: system("CLS");
                search();
                printf("\n\n\t\t\t\t\tTo continue, Press any key ");
                fflush(stdin);
                getchar();
                menu();
                break;

        case 4: system("CLS");
                delete();
                break;

        case 5: system("CLS");
                exit(0);
                break;

        default: printf("INVALID CHOICE !!!");
    }
}

void user_menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t  ||==MENU==||");
    printf("\n\n\t\t\t\t\t\t1.View a Record");
    printf("\n\t\t\t\t\t\t2.Exit");
    printf("\n\n\t\t\t\t\t\tEnter choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("CLS");
                search();
                break;

        case 2: system("CLS");
                exit(0);
                break;
    }
}

void insert()
{
    time_t mytime;
    struct tm* current_time; //a way to group several related variables into one place
    mytime = time(NULL);
    current_time = localtime(&mytime);

    FILE *fp; //create file pointer
    char name[30];
    int id;
    char choice='y';
    system("CLS");
    fp = fopen("cyber.txt","ab+"); //Open a binary file in append mode for writing at the end of the file. The fopen() function creates the file if it does not exist

    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    fflush(stdin);
    while(choice=='y')
    {
        main_heading();
        printf("\n\n\t\t\t\t\t\tENTER NEW USER DATA :");
        printf("\n\n\t\t\t\t\tEnter User_ID in Numbers : ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\n\n\t\t\t\t\tEnter name of the user : ");
        scanf("%s",&name);
        fflush(stdin);
        fprintf(fp,"%d %s\t",id,name); //used to write data in a file using a stream object, not in the stdout console.
        fprintf(fp,"%02d/%02d/%d %02d:%02d",current_time->tm_mday,current_time->tm_mon+1,current_time->tm_year+1900,current_time->tm_hour,current_time->tm_min);
        fprintf(fp,"\n");
        arrival_time();
        printf("\n\n\t\t\t\t     INSERTED USER RECORD SUCCESSFULLY !!!");
        
        printf("\n\n\t\t\t\t     Add another record ? (y/n) : ");
        scanf("%c",&choice);
        fflush(stdin);
        system("CLS");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t     To continue, Press any key ");
    getchar();
    menu();
}

void display()
{
    
    int duration,tothr;
    int totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    fp = fopen("cyber.txt","rb"); //Open a binary file for reading. The file must exist.
    
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    printf("\n\n\t\t\t\t\tUSER DETAILS ARE AS FOLLOWS :");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tDate\t\tTime\t Duration");
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        printf("\n\n\t\t\t    %d \t\t\t%s \t\t\t%02d/%02d/%d \t%02d:%02d",id,name,mday,mmon,myear,mhour,mmin);
        tothr =(((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
        duration = tothr/60;
        totmin = tothr-(duration*60);
        printf("\t %dHr:%dMin",duration,totmin);
    }
    fclose(fp);
}
void search()
{
    system("CLS");
    main_heading();
    int my_id,flag=0;
    int duration,tothr,totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\n\t\t\t\t\tEnter user_ID to fetch information :");
    scanf("%d",&my_id);
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id == id)
        {
            flag=1;
            printf("\n\t\t\t\t\tRECORD FOUND SUCCESSFULLY !!!");
            printf("\n\n\t\t\t\t\tUser_ID : %d",id);
            printf("\n\t\t\t\t\tName of User : %s",name);
            printf("\n\t\t\t\t\tLogin Date And Time : %02d/%02d/%d   %02d:%02d",mday,mmon,myear,mhour,mmin);
            tothr =(((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
            duration = tothr/60;
            totmin = tothr-(duration*60);
            printf("\n\t\t\t\t\tDuration : %dHr:%dMin",duration,totmin);
            if(tothr>300)
            {
                printf("\n\t\t\t\t\tALERT!!! MALICIOUS ACTIVITY");
            }
            break;
        }
    }    
        fclose(fp);
        if(flag==0)
        {
            printf("\n\t\t\t\t\tRecord not found !!!");
        }
    
}

void delete()

{
    system("CLS");
    main_heading();
    FILE *fp,*ft;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    int my_id;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    unsigned flag=0;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\t\t\t\t\t|======== PREVIOUS ENTERED DATA ========|");
    display();
    printf("\n\n\n\t\t\t\tEnter ID of the user which you want to delete : ");
    scanf("%d",&my_id);

    ft = fopen("cyber1.txt","wb"); //Create an empty binary file for writing. If the file exists, its contents are cleared unless it is a logical file.
    if(ft==NULL)
    {
        printf("\n\t\t\t\tERROR OPENING NEW FILE !!!");
    }
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF) //reads data from the current position of the specified stream into the locations that are given by the entries in argument-list
    {
        if(my_id!=id)
        {
            flag=1;
            fprintf(ft,"%d %s\t",id,name);
            fprintf(ft,"%02d/%02d/%d %02d:%02d",mday,mmon,myear,mhour,mmin);
            fprintf(ft,"\n");
        }
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tNo Such Record Found!!!");
    }
    fclose(fp);
    fclose(ft);
    remove("cyber.txt");
    rename("cyber1.txt","cyber.txt");
    printf("\n\n\t\t\t\tRecord Deleted Successfully!!!");
    printf("\n\n\t\t\t\t\t|===== Updated Records =====| ");
    display();
    printf("\n\n\t\t\t\t\tTo continue, Press any key");
    fflush(stdin);
    getchar();
    system("CLS");
    main_heading();
    menu();
}

void arrival_time()
{
    time_t rawtime; //returns the time 
    struct tm* timeinfo;
    struct tm* dateinfo;
    char buf[80];
    char buffer[80];
    FILE *fp;

    fp = fopen("cyber.txt", "ab+");

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    dateinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M:%S", timeinfo); //I=Hour in 12h format (01-12) M=Month as a decimal number (01-12) S=Second (00-61)
    strftime(buf, 80, "%b %d, %Y", dateinfo); //b=Abbreviated month name d= day of month Y=year 2013
    printf("\n\n\t\t\t\tArrival Time : %s",buffer);
    printf("\t\tDate : %s",buf);
}

void user_login()
{
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","ab+");
    printf("\n\t\t\t\t\tSIGN IN USER");
    printf("\n\t\t\t\t\tEnter Username :");
    scanf("%s",&usern);
    printf("\n\t\t\t\t\tEnter Password : ");
    scanf("%s",&pass);
    fprintf(fp,"%s %s",usern,pass);
    fprintf(fp,"\n");
    system("CLS");
    printf("\n\t\t\t\t\tSuccessfully Signed in ");
    user_menu();
    
}

void login_user()
{
    char u_id[20],p[20];
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","rb");
    printf("\n\t\t\t\t\tUsername : ");
    scanf("%s",u_id);
    while(fscanf(fp,"%s %s",&usern,&pass)!=EOF)
    {
        if(strcmp(u_id,usern)==0)
        {
            printf("\n\t\t\t\t\tPassword : ");
            scanf("%s",&p);
            if(strcmp(p,pass)==0)
            {
                system("CLS");
                main_heading();
                printf("\n\n\t\t\t\t\tWELCOME USER!!! LOGIN SUCCESSFULL");
                printf("\n\n");
                user_menu();
                printf("\n\n\t\t\t\t\tTo continue, Press any key ");
                fflush(stdin);
                getchar();
                user_menu();
            }
            else
            {
                printf("\n\t\t\t\t\tIncorrect username or password");
                printf("\n\t\t\t\t\tTRY AGAIN");
                login_user();
            }
        }
        printf("\nIncorrect Username!!! try again");
        user_login();
    }
}