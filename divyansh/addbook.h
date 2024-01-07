
void addbook(){
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
   
}

