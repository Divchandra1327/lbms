//#include"count.h"

void display(){
//int nbooks=countbook();	
struct book {
    char bookname[50];
    char genre[50];
    char author[50];
	char publication[50];
    char id[10];
    char date[50];
};
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
}
