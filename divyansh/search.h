void searchBook() {
    struct book {
    char bookname[50];
    char genre[50];
    char author[50];
	char publication[50];
    char id[10];
    char date[50];
};
 char search[50];

    printf("\nEnter Book Name to search:\t");
    fgets(search, sizeof(search), stdin);

    size_t len = strlen(search);
    if (len > 0 && search[len - 1] == '\n') {
        search[len - 1] = '\0';  
    }

    FILE *fb = fopen("book.dat", "rb");
    if (fb == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct book searchBook;

    int found = 0;

    while (fread(&searchBook, sizeof(struct book), 1, fb) == 1) {
        if (strcmp(searchBook.bookname, search) == 0) {
            found = 1;
            printf("\nBook found:\n");
            printf("Book Name: %s\n", searchBook.bookname);
            printf("Genre: %s\n", searchBook.genre);
            printf("Author: %s\n", searchBook.author);
            printf("Publication: %s\n", searchBook.publication);
            printf("Date of Entry: %s\n", searchBook.date);
            printf("Book ID: %s\n", searchBook.id);
            
        }
    }

    fclose(fb);

    if (!found) {
        printf("Book not found!\n");
    }
}

