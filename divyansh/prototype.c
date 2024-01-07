#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "user.h"
#include "input.h"
#include "addbook.h"
#include "display.h"
#include "delete.h"
#include "search.h"
struct book {
    char bookname[50];
    char genre[50];
    char author[50];
	char publication[50];
    char id[10];
    char date[50];
    
};

struct user{
	char fullname[50];
	char email[50];
    char pass[50];
    char username[50];
    int role;
	char phone[50];
};



/*void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch)-1]=0;
	
}*/

/*char genrateusername(char email[50],char username[50]){
	int i;
	for(i=0;i<strlen(email);i++){
		if(email[i]=='@'){
		    break;
		} 
		else {
		   username[i]=email[i];
		}
	}
}
*/
void addbook();
void display();
void deletebook();
void searchBook();
int main(){
	
	
	system ("color 0b");
	
	FILE *fp;
	FILE *fb;
	int opt,usrfound=0,choice;
	struct user user;
	char username[50],pword[50];
    struct user usr;
	do{
	printf("\n================================================WELCOME TO LIBRARY=====================================================");
	printf("\n\t\t\t\t\t\tenter your choice");
	printf("\n\t\t\t\t\t\t1.Singup");
	printf("\n\t\t\t\t\t\t2.Login");
	printf("\n\t\t\t\t\t\t3.Exit");
    printf("\n\t\t\t\t\t\tyour choice :");
    scanf("%d",&opt);
    fgetc(stdin);
		switch(opt){
    	case 1:
    		printf("\nEnter your fullName :\t");
    		takeinput(user.fullname);
    		printf("\nEnter your email:\t");
    		takeinput(user.email);
    		printf("\nEnter your phone numer:\t");
    		takeinput(user.phone);
    		printf("\nEnter your password:\t");
    		takeinput(user.pass);
    		printf("\nEnter your role(1.for librarian 2.Students):\t");
    		scanf("%d",&user.role);
    		genrateusername(user.email,user.username);
    		fp=fopen("user.dat","a+");
    		fwrite(&user,sizeof(struct user),1,fp);
    		if (fwrite(&user, sizeof(struct user), 1, fp) != 0) {

    			printf("\n\n Regstration succesfull,user name:%s",user.username);
			}
    		else{
    			printf("something went worng....!");
    			
			}
			fclose(fp);
			break;
			
			
			case 2:
				   
				 
				 printf("\nEnter your Username :\t");
				 takeinput(username);
				 printf("\nEnter your password :\t");
				 takeinput(pword);
				 system("cls");
				 fp=fopen("user.dat","r");
				 while(fread(&usr,sizeof(struct user),1,fp)){
				    if(!strcmp(usr.username,username)){
					    if(!strcmp(usr.pass,pword)){
						 if(usr.role==1){
						  do{
						      system("cls");
						      printf("Logged in as %s(Role:%d)\n", usr.username,usr.role);
                              printf("1. Add Book\n");
                              printf("2. Delete Book\n");
                              printf("3. Display Books List\n");
                              printf("4. Search Books List\n");
                              printf("5. Logout\n");
							  printf("enter your choice:\t");
							  scanf("%d", &choice);
                              fgetc(stdin);
                              system("cls");
							  switch(choice){
                              	case 1:
                              		addbook();
									break;
                              	case 2:
                              		deletebook();
                              		 break;
                              	case 3:
								    display();
									 break;	 
								case 4:
								     searchBook();
									 break; 
								case 5:
									printf("Loging out....");
									  return;
								default:
								    printf("invalid choice");	    	 
							  }
					       }while(choice!=5);
					      }
					      else{
					      	 do{
						         system("cls");
						         printf("Logged in as %s(Role:%d)\n", usr.username,usr.role);
                                 printf("1. Display Books List\n");
                                 printf("2. Display borrowed books\n");
                                 printf("3. Search Book\n");
                                 printf("4. Logout\n");
							     printf("enter your choice:\t");
							     scanf("%d", &choice);
                                 fgetc(stdin);
                                 system("cls");
							     switch(choice){
                              	        case 1:
                              		          addbook();
									         break;
                              	        case 2:
                              		         deletebook();
                              		         break;
                              	        case 3:
								             display();
									         break;	  
								        case 4:
									         printf("Loging out....");
									          return;
								        default:
								            printf("invalid choice");	    	 
							        }
					         }while(choice!=5);
						   }
					   }
						else{
						printf("\n\ninvalid password");
					      }
					   usrfound=1;
					}
				}
				if(!usrfound){
					printf("\n\nUser is not registered ");
				}
				fclose(fp);
				break;
				case 3:
					printf("\t\t\t\t THANKYOU");
					return 0;
	 }
	}while(opt!=3);
	return 0;
}
/*void addbook(){
	FILE *fb;
	struct book book;
	printf("\nEnter Bookname:\t");
	fgets(book.bookname,50,stdin);
	fgetc(stdin);
	printf("\nEnter genre:\t");
	fgets(book.genre,50,stdin);
	fgetc(stdin);
	printf("\nEnter Author:\t");
	fgets(book.author,50,stdin);
	fgetc(stdin);
	printf("\nEnter Publication:\t");
	fgets(book.publication,50,stdin);
	fgetc(stdin);
	printf("\nEnter Date of Entry:\t");
	fgets(book.date,50,stdin);
	fgetc(stdin);
	printf("\nEnter BookId:\t");
	fgets(book.id,10,stdin);
	fgetc(stdin);
	fb=fopen("book.dat","a+");
	fwrite(&book,sizeof(struct book),1,fb);
	if (fwrite(&book, sizeof(struct book), 1, fb) != 0) {
    		printf("\n\n book added  succesfully , book name:%s",book.bookname);
			}
    else{
    		printf("something went worng....!");
		}
	fclose(fb);
   
}*/
/*void display(){

    FILE *fb;
    struct book book;
    fb=fopen("book.dat","r+");
    while(fread(&book,sizeof(book),1,fb)){
    	printf("BookName:\t%s\n",book.bookname);
    	printf("genre:\t%s\n",book.genre);
    	printf("Author Name:\t%s\n",book.author);
    	printf("Publication:\t%s\n",book.publication);
    	printf("BookId:\t%s\n",book.id);
    	printf("Date:\t%s\n",book.date);
		printf("\n");    	
	}
	if(fb==NULL){
		printf("something went wrong.....");
	}
    fclose(fb);
    getch();
}*/

/*void deletebook(){
 FILE *fb, *temp;
    struct book tempBook, book;
    char deleteId[50];

    printf("\nEnter BookId to delete:\t");
    fgets(deleteId, 50, stdin);
    fgetc(stdin);

    fb = fopen("book.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fb == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
     while (fread(&tempBook, sizeof(struct book), 1, fb) != 0) {
        if ((tempBook.id && deleteId) != 0) {
            fwrite(&tempBook, sizeof(struct book), 1, temp);
        }
    }

    fclose(fb);
    fclose(temp);

    remove("book.dat");
    rename("temp.dat", "book.dat");

    printf("Book deleted successfully!\n");
}*/

/*void searchBook() {
     char searchName[50];

    printf("\nEnter Book Name to search:\t");
    fgets(searchName, sizeof(searchName), stdin);

    size_t len = strlen(searchName);
    if (len > 0 && searchName[len - 1] == '\n') {
        searchName[len - 1] = '\0';  
    }

    FILE *fb = fopen("book.dat", "rb");
    if (fb == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct book searchBook;

    int found = 0;

    while (fread(&searchBook, sizeof(struct book), 1, fb) == 1) {
        if (strcmp(searchBook.bookname, searchName) == 0) {
            found = 1;
            printf("\nBook found:\n");
            printf("Book Name: %s\n", searchBook.bookname);
            printf("Genre: %s\n", searchBook.genre);
            printf("Author: %s\n", searchBook.author);
            printf("Publication: %s\n", searchBook.publication);
            printf("Date of Entry: %s\n", searchBook.date);
            printf("Book ID: %s\n", searchBook.id);
            // You can add more details to print if needed
        }
    }

    fclose(fb);

    if (!found) {
        printf("Book not found!\n");
    }
}*/
