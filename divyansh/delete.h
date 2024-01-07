 void deletebook(){
struct book {
    char bookname[50];
    char genre[50];
    char author[50];
	char publication[50];
    char id[10];
    char date[50];
};
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
	}
