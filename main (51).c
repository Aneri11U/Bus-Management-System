#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void UserName();
void Admin();
void NewUser();


struct node{
    struct node*prev;
    char station[50];
    float distance;
    // char timing[20];
    // int busid;
    struct node*next;
}*head[5],*end[5];

char chEmpty[]="Empty";
struct node * temp1[5] = {NULL};
struct node * temp2[5] = {NULL};
// struct node * p[5] = {NULL};
// struct node*end = NULL;

struct node* createnode(char sta[],float dis){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> next = NULL;
    strcpy(temp->station,sta);
    // printf("%s",temp->station);
    temp->distance = dis;
    // temp->busid = t;
    // strcpy(temp->timing,tim);
    return temp;
}

void insert(){
    FILE *fp1;
    
    for(int i=0;i<5;i++){
        if(head[i] == NULL && fp1 != NULL){
            
            switch(i){
                case 0: head[i] = createnode("Patan",0);
                        // printf("1\n");
                        end[i] = head[i];
                        // printf("%s",head[i]->station);
                        printf("                                                    The first station Patan is created as head of path from Patan linked list.\n ");
                        // fprintf(fp1," %s ",head[i] -> station);
                        // fprintf(fp1,"%.2f ",head[i] -> distance);
                        // fprintf(fp1,"\n");
                        break;
                case 1: head[i] = createnode("Vadodara",0);
                        end[i] = head[i];
                        printf("                                                    The first station Vadodara is created as head of path from Vadodara linked list.\n ");
                        // fprintf(fp1," %s ",head[i] -> station);
                        // fprintf(fp1,"%.2f ",head[i] -> distance);
                        // fprintf(fp1,"\n");
                        // printf("1\n");
                        break;
                case 2: head[i] = createnode("Ahemadabad",0);
                        end[i] = head[i];
                        printf("                                                    The first station Ahemadabad is created as head of path from Ahemadabad linked list.\n ");
                        // fprintf(fp1," %s ",head[i] -> station);
                        // fprintf(fp1,"%.2f ",head[i] -> distance);
                        // fprintf(fp1,"\n");
                        // printf("1\n");
                        break;
                case 3: head[i] = createnode("Surat",0);
                        end[i] = head[i];
                        printf("                                                    The first station Surat is created as head of path from Surat linked list.\n ");
                        // fprintf(fp1," %s ",head[i] -> station);
                        // fprintf(fp1,"%.2f ",head[i] -> distance);
                        // fprintf(fp1,"\n");
                        // printf("1\n");
                        break;
                case 4: head[i] = createnode("Bhuj",0);
                        end[i] = head[i];
                        printf("                                                    The first station Bhuj is created as head of path from Bhuj linked list.\n ");
                        break;
            }
            
        }
        // printf("Here you can enter rotes for these 5 source stations: Patan, Vadodara, Ahemadabad, Surat, Bhuj\n");
        else{
            int flag ;
            switch(i){
                label : case 0: 
                        printf("                                                    Do you want to add a station? Yes(1)/No(0) to %s source: ",head[i]->station);
                        scanf("%d",&flag);
                        if(flag==0) {
                            fp1 = fopen("busroute.txt", "a+");
                            temp2[i] = head[i];
                        do{
                            // fprintf(fp1,"%d ",temp2[i]->busid);
                            fprintf(fp1," %s ",temp2[i] -> station);
                            fprintf(fp1,"%f ",temp2[i] -> distance);
                            // fprintf(fp1,"%s ",temp2[i] -> timing);
                            // printf("%s ",temp2[i] -> station);
                            temp2[i] = temp2[i] -> next;
                            }while(temp2[i] != NULL);
                            fprintf(fp1,"\n");
                            fclose(fp1);
                        continue;
                        }
                        else{
                            temp1[i] = (struct node*)malloc(sizeof(struct node));
                            char sta[50];
                            float dis;
                            // char tim[20];
                            int id;
                            printf("                                                    Enter the next station and its distance from previous station: ");
                            scanf("%s",sta);
                            scanf("%f",&dis);
                            // scanf("%s",tim);
                            strcpy(temp1[i]->station,sta);
                            temp1[i]->distance = dis;
                            // temp1[i]->busid = i + 1;
                            // strcpy(temp1[i]->timing,tim);
                            // printf("%s",temp1[i]->station);
                            // temp1[i] = end[i] -> next;
                            end[i]->next = temp1[i];
                            temp1[i] -> prev = end[i];
                            temp1[i] -> next = NULL;
                            end[i] = temp1[i];
                            // printf("1\n");
                            // break;
                        }
                        goto label;
                        break;
                label1 : case 1: 
                        printf("                                                    Do you want to add a station? Yes(1)/No(0) to %s source: ",head[i]->station);
                        scanf("%d",&flag);
                        if(flag==0) {
                            fp1 = fopen("busroute.txt", "a+");
                            temp2[i] = head[i];
                        do{
                            fprintf(fp1," %s ",temp2[i] -> station);
                            fprintf(fp1,"%f ",temp2[i] -> distance);
                            temp2[i] = temp2[i] -> next;
                            }while(temp2[i] != NULL);
                            fprintf(fp1,"\n");
                            fclose(fp1);
                        continue;
                        }
                        else{
                            temp1[i] = (struct node*)malloc(sizeof(struct node));
                            char sta[50];
                            float dis;
                            printf("                                                    Enter the next station and its distance from previous station: ");
                            scanf("%s",sta);
                            scanf("%f",&dis);
                            strcpy(temp1[i]->station,sta);
                            temp1[i]->distance = dis;
                            end[i]->next = temp1[i];
                            temp1[i] -> prev = end[i];
                            temp1[i] -> next = NULL;
                            end[i] = temp1[i];
                        }
                        goto label1;
                        break;
                label2 : case 2: 
                        printf("                                                    Do you want to add a station? Yes(1)/No(0) to %s source: ",head[i]->station);
                        scanf("%d",&flag);
                        if(flag==0) {
                            fp1 = fopen("busroute.txt", "a+");
                            temp2[i] = head[i];
                        do{
                            fprintf(fp1," %s ",temp2[i] -> station);
                            fprintf(fp1,"%f ",temp2[i] -> distance);
                            temp2[i] = temp2[i] -> next;
                            }while(temp2[i] != NULL);
                            fprintf(fp1,"\n");
                            fclose(fp1);
                        continue;
                        }
                        else{
                            temp1[i] = (struct node*)malloc(sizeof(struct node));
                            char sta[50];
                            float dis;
                            printf("                                                    Enter the next station and its distance from previous station: ");
                            scanf("%s",sta);
                            scanf("%f",&dis);
                            strcpy(temp1[i]->station,sta);
                            temp1[i]->distance = dis;
                            end[i]->next = temp1[i];
                            temp1[i] -> prev = end[i];
                            temp1[i] -> next = NULL;
                            end[i] = temp1[i];
                        }
                        goto label2;
                        break;
                label3 : case 3: 
                        printf("                                                    Do you want to add a station? Yes(1)/No(0) to %s source: ",head[i]->station);
                        scanf("%d",&flag);
                        if(flag==0) {
                            fp1 = fopen("busroute.txt", "a+");
                            temp2[i] = head[i];
                        do{
                            fprintf(fp1," %s ",temp2[i] -> station);
                            temp2[i] = temp2[i] -> next;
                            }while(temp2[i] != NULL);
                            fprintf(fp1,"\n");
                            fclose(fp1);
                        continue;
                        }
                        else{
                            temp1[i] = (struct node*)malloc(sizeof(struct node));
                            char sta[50];
                            float dis;
                            printf("                                                    Enter the next station and its distance from previous station: ");
                            scanf("%s",sta);
                            scanf("%f",&dis);
                            strcpy(temp1[i]->station,sta);
                            temp1[i]->distance = dis;
                            end[i]->next = temp1[i];
                            temp1[i] -> prev = end[i];
                            temp1[i] -> next = NULL;
                            end[i] = temp1[i];
                        }
                        goto label3;
                        break;
                label4 : case 4: 
                        printf("                                                    Do you want to add a station? Yes(1)/No(0) to %s source: ",head[i]->station);
                        scanf("%d",&flag);
                        if(flag==0) {
                            fp1 = fopen("busroute.txt", "a+");
                            temp2[i] = head[i];
                        do{
                            fprintf(fp1," %s ",temp2[i] -> station);
                            fprintf(fp1,"%f ",temp2[i] -> distance);
                            temp2[i] = temp2[i] -> next;
                            }while(temp2[i] != NULL);
                            fprintf(fp1,"\n");
                            fclose(fp1);
                        continue;
                        }
                        else{
                            temp1[i] = (struct node*)malloc(sizeof(struct node));
                            char sta[50]; 
                            float dis;
                            printf("                                                    Enter the next station and its distance from previous station: ");
                            scanf("%s",sta);
                            scanf("%f",&dis);
                            strcpy(temp1[i]->station,sta);
                            temp1[i]->distance = dis;
                            end[i]->next = temp1[i];
                            temp1[i] -> prev = end[i];
                            temp1[i] -> next = NULL;
                            end[i] = temp1[i];
                        }
                        goto label4;
                        break;
            }
        
            
        }
    }
}

void UserName()
{
    FILE *fp;
    fp = fopen("test.txt", "a+");
    char username[50];
    char pswd[50];
    printf("                                                    Username: ");
    scanf("%s,", username);
    printf("                                                    Password: ");
    scanf("%s", pswd);
    fp = fopen("test.txt","r");
    char ch;
    int i=0, x=0;
    while ((ch=getc(fp))!=EOF)
    {
        if(fp)
        {  
            char word[20];
            while(fscanf(fp,"%s",word)!=EOF)
            {
                if(strcmp(username, word)==0)
                {
                    x=i;
                    i++;
                    continue;
                }
                if(i==x+1 && i!=1)
                {
                    if(strcmp(pswd, word)==0)
                    {
                        printf("                                                    Welcome!\n");
                    }
                    else
                    {
                        printf("                                                    Wrong username and password!\n");
                        UserName();
                    }
                    
                }
                i++;
            }
        }  
        if(x==0)
        {
            printf("                                                    No such account exist\n");
            printf("                                                    Do you want to create a new account(1/0)? ");
            int x;
            scanf("%d", &x);
            if(x==1)
                NewUser();
            else
                return;
        }
        fclose(fp);
    }
}
  
void NewUser()
{
    FILE *fp;
    fp = fopen("test.txt", "a+");
    char username[50];
    char pswd[50];
    printf("                                                    Username: ");
    scanf("%s,", username);
    printf("                                                    Password: ");
    scanf("%s", pswd);
    fprintf(fp, " %s ", username);
    fprintf(fp, "%s \n", pswd);
    fclose(fp);
    printf("                                                    You have been registered successfully.\n\n\n\n");
    printf("                                                    Now you can log in\n\n");
    UserName();
}

float printsedule(char from[], char to[], int i){
    // char from[20], to[20];
    // int i;
    float price;
    // printf("From: ");
    // scanf("%s",from);
    // printf("\nTo: ");
    // scanf("%s",to);
    struct node*p = (struct node*)malloc(sizeof(struct node));
    // if(strcmp(from,"Patan")==0) i =0;
    // else if(strcmp(from,"Vadodara")==0) i =1;
    // else if(strcmp(from,"Ahmedabad")==0) i =2;
    // else if(strcmp(from,"Surat")==0) i =3;
    // else if(strcmp(from,"Bhuj")==0) i =4;
           
                switch(i){
                    // printf("1");
                    case 0: p = head[i];
                            // printf("1");
                            do{
                                // printf("1");
                                printf("                                                    %s-> ",p -> station);
                                p = p -> next;
                            }while(strcmp(p->station,to)!=0);
                            printf("                                                    %s \n",p->station);
                            price = p->distance;
                            break;
                    case 1: p = head[i];
                            do{
                                printf("                                                    %s-> ",p -> station);
                                p = p -> next;
                            }while(strcmp(p->station,to)!=0);
                            printf("                                                    %s \n",p->station);
                            price = p->distance;
                            break;
                    case 2: p = head[i];
                            do{
                                printf("%s-> ",p -> station);
                                p = p -> next;
                            }while(strcmp(p->station,to)!=0);
                            printf("                                                    %s \n",p->station);
                            price = p->distance;
                            break;
                    case 3: p = head[i];
                            do{
                                printf("                                                    %s-> ",p -> station);
                                p = p -> next;
                            }while(strcmp(p->station,to)!=0);
                            printf("                                                    %s \n",p->station);
                            price = p->distance;
                            break;
                    case 4: p = head[i];
                            do{
                                printf("                                                    %s-> ",p -> station);
                                p = p -> next;
                            }while(strcmp(p->station,to)!=0);
                            printf("                                                    %s \n",p->station);
                            price = p->distance;
                            break;
                            
                    
                    
                }
                return price;
}

int Booking(){
    FILE *fp; 
    int n;       
    int num;
    printf("                                                    Enter the number of tickets you want to book: ");
    scanf("%d", &n);
    int a[32]={0};
    // for(int i=0; i<32; i++)
    //     printf("%d ", a[i]);
    fp=fopen("Booking.txt","r");
    if (fp==NULL)
    {
        // printf("0 \n");
        fp = fopen("Booking.txt", "w+");
        for(int i=0; i<32; i++)
        {
            
            fprintf(fp, "%d\n", a[i]);
            // printf("%d\n",a[i]);
        }
        fclose(fp);
    }
    else{
    fclose(fp);
    }

    
    
    fp = fopen("Booking.txt", "r+");// AIYA KHALI READ KARVANU CHE PACHI THAI JASE MOSTPROBABLY
    int j=0;
    char ch;
      while (!feof (fp) && j<32)
        {  
         ch = getc(fp);
         num = atoi(&ch);
        //  printf("%d %d\n",j,num);
         a[j] = num;
          j++;  
        }
      fclose (fp);
        // for(int i=0; i<32; i++)
        // printf("%d ", a[i]);
        /*for(int i=0;i<32;i++){
            if(i%4!=0 || i==0){
            printf("\t\t\t%d. ",i+1);
            if(a[i]==0)
            printf("Empty ");
            else
            printf("Occupied ");
            }
            printf("\n");
        }*/
        
        
    

    int ct =0;
    for(int i=0; i<n; i++)
    {
        int seat;
        
        label: printf("                                                    Seat-%d: ", i+1);
        scanf("%d", &seat);
        int c=0;
        if(a[seat-1]==1){
        printf("                                                    Seat not available\nChoose again\n");
        goto label;
        }
        else
        a[seat-1]=1;
        ct++;
        
    }

    // for(int i=0; i<32; i++)
    //     printf("%d ", a[i]);
    
    fp = fopen("Booking.txt", "w+");
    for(int i=0; i<32; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp) ;
    // for(int i=0; i<32; i++)
    //     printf("%d ", a[i]);
        
    return ct;

}

void Admin(){
    int var;
    printf("                                                    LOGIN\n");
    char pass[20]="WrongPassword@123";
    char entered[20];
    printf("                                                    Enter valid password: ");
    scanf("%s",entered);
    if(strcmp(pass,entered)==0){
        printf("                                                    Logged in successfully!!\n\n\n");
        printf("                                                    Here you can enter routes for these 5 source stations: Patan, Vadodara, Ahemadabad, Surat, Bhuj\n");
        // insert();
        // insert();
        int t =1;
        while(t){
            printf("                                                    Enter 1 to insert path and 0 to exit: ");
        scanf("%d",&var);
        switch(var){
            case 1: insert();
                    // display();
                    break;
            case 0: t =0;
                    break;
        }
        }
        
        
       
        
    }
    else{
        printf("                                                    Try again.\n");
    }
}

int main()
{
    int a;
    int t =1;
    while(t>0){
    printf("\n                                                    Login\n");
    printf("                                                    (i) Admin\n");
    printf("                                                    (ii) Existing User\n");
    printf("                                                    (iii) New User\n");
    printf("                                                    Enter 0 to Exit\n");
    printf("                                                    Enter your choice: ");
    int login_choice;
    scanf("%d", &login_choice);
    switch(login_choice)
    {
        case 1:
            Admin();
            break;
        case 2:
            UserName();
            float dis;
            float baseprice = 3;
            int v = 0;
            int num;
            char from[20], to[20];
            int flag =0;
            int i;
            while(v ==0){
                int choice;
                printf("                                                    Enter 0 to exit.\n");
                printf("                                                    Enter 1 to get the bus route information.\n");
                printf("                                                    Enter 2 to book a bus.\n");
                scanf("%d",&choice);
                switch(choice){
                    case 1: 
                            printf("                                                    From: ");
                            scanf("%s",from);
                            printf("                                                    \nTo: ");
                            scanf("%s",to);
                            if(strcmp(from,"Patan")==0) i =0;
                            else if(strcmp(from,"Vadodara")==0) i =1;
                            else if(strcmp(from,"Ahmedabad")==0) i =2;
                            else if(strcmp(from,"Surat")==0) i =3;
                            else if(strcmp(from,"Bhuj")==0) i =4;
                            struct node*ptr = (struct node*)malloc(sizeof(struct node));
                            switch(i){
                                case 0: ptr = head[i];
                                        while(ptr != NULL){
                                            if(strcmp(to,ptr->station)==0){
                                                flag =1;
                                                break;
                                            }
                                            ptr = ptr->next;
                                        }
                                        if(flag == 1){
                                            printf("                                                    Bus Number: %d\n",i+1);
                                            dis = printsedule(from,to,i);
                                        }
                                        else{
                                            printf("                                                    No such bus is available!\n");
                                        }
                                        break;
                                case 1: ptr = head[i];
                                        while(ptr != NULL){
                                            if(strcmp(to,ptr->station)==0){
                                                flag =1;
                                                break;
                                            }
                                            ptr = ptr->next;
                                        }
                                        if(flag == 1){
                                            printf("                                                    Bus Number: %d\n",i+1);
                                            dis = printsedule(from,to,i);
                                        }
                                        else{
                                            printf("                                                    No such bus is available!\n");
                                        }
                                        break;
                                case 2: ptr = head[i];
                                        while(ptr != NULL){
                                            if(strcmp(to,ptr->station)==0){
                                                flag =1;
                                                break;
                                            }
                                            ptr = ptr->next;
                                        }
                                        if(flag == 1){
                                            printf("                                                    Bus Number: %d\n",i+1);
                                            dis = printsedule(from,to,i);
                                        }
                                        else{
                                            printf("                                                    No such bus is available!\n");
                                        }
                                        break;
                                case 3: ptr = head[i];
                                        while(ptr != NULL){
                                            if(strcmp(to,ptr->station)==0){
                                                flag =1;
                                                break;
                                            }
                                            ptr = ptr->next;
                                        }
                                        if(flag == 1){
                                            printf("                                                    Bus Number: %d\n",i+1);
                                            dis = printsedule(from,to,i);
                                        }
                                        else{
                                            printf("                                                    No such bus is available!\n");
                                        }
                                        break;
                                case 4: ptr = head[i];
                                        while(ptr != NULL){
                                            if(strcmp(to,ptr->station)==0){
                                                flag =1;
                                                break;
                                            }
                                            ptr = ptr->next;
                                        }
                                        if(flag == 1){
                                            printf("                                                    Bus Number: %d\n",i+1);
                                            dis = printsedule(from,to,i);
                                        }
                                        else{
                                            printf("                                                    No such bus is available!\n");
                                        }
                                        break;
                            }
                            break;
                    case 2: printf("                                                    Enter the bus number:\n");
                            scanf("%d",&num);
                            int tickets;
                            tickets = Booking();
                            printf("                                                    ticket fees: %.2f\n",(tickets*baseprice*dis));
                            break;
                    case 0: v =1;
                            break;
                }
                
            }
            // dis = printsedule();
            // printf("Price of one ticket is: %.2f",(dis*baseprice));
            break;
        case 3:
            NewUser();
            break;
        case 0:
            // exit(0);
            t =0;
            break;
        default: printf("                                                    Please enter valid input!\n");
    }
    }
    
}