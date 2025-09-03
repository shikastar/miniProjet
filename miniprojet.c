#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_BOOKS 10000

struct Book {
    char title[MAX_SIZE];
    char author[MAX_SIZE];
    double price;
    int quantity;
};

struct Library {
    struct Book Books[MAX_BOOKS];
    int numberOfBooks;
    int booksQuantity;
};


// Book functions 

void    setTitle(struct Book *book) {
    printf("Enter Book title please:\n");
    scanf("%s", book->title);
}

void    setAuthor(struct Book *book) {
    printf("Enter author name please:\n");
    scanf("%s", book->author);
}
void    setPrice(struct Book *book) {
    printf("Enter Book price please: \n");
    scanf("%lf", &book->price);
}
void    setQuantity(struct Book *book) {
    do {
        printf("Enter Book quantity please: \n");
        scanf("%d", &book->quantity);
    } while (book->quantity < 0);
}

void    showInfos(struct Book *book) {
    printf("Book info:\n");
    printf("    Title: %s\n", book->title);
    printf("    Author: %s\n", book->author);
    printf("    Price: %lf\n", book->price);
    printf("    Quantity: %d\n", book->quantity);
}

bool    isSameBookName(char *s, char *t) {
    if (!s || !t) return 0;
    int i = 0;
    while (s[i] && t[i]) {
        if (s[i] != t[i]) return 0;
        i++;
    }
    return (s[i] == t[i]);
}

bool    isDeleted(struct Book *book) {
    return (book->quantity == -1);
}

// library functions

void    AddBook(struct Library *library) {
    struct Book newBook;
    setTitle(&newBook);
    setAuthor(&newBook);
    setPrice(&newBook);
    setQuantity(&newBook);

    library->Books[library->numberOfBooks] = newBook;
    library->numberOfBooks++;
    library->booksQuantity += newBook.quantity;
}

void    showBooksInfo(struct Library *library) {
    printf("---------------------\n");
    printf("Here is all the books in library.\n");
    for (int i = 0; i < library->numberOfBooks; i++) {
        if (isDeleted(&library->Books[i])) continue;
        showInfos(&library->Books[i]);
    }
    printf("---------------------\n");
}



void    changeBookQuantity(struct Library *library) {
    printf("---------------------\n");
    char title[MAX_SIZE];
    int newQuantity;
    
    printf("Enter book title that you want to change it's quantity: \n");
    scanf("%s", title);
    do {
        printf("Enter new book quantity: \n");
        scanf("%d", &newQuantity);
    } while (newQuantity < 0);
    
    printf("---------------------\n");
    for (int i = 0; i < library->numberOfBooks; i++) {
        if (isDeleted(&library->Books[i])) continue;
        if (isSameBookName(library->Books[i].title, title)) {
            library->booksQuantity -= library->Books[i].quantity;
            library->Books[i].quantity = newQuantity;
            library->booksQuantity += library->Books[i].quantity;
            printf("the new quantity of book title %s new is :%d\n", title, newQuantity);
            printf("---------------------\n");
            return ;
        }
    }

    printf("No book with title: \'%s\' exist\n", title);
    printf("---------------------\n");
}

void    deleteBook(struct Library *library) {
    printf("Enter book title that you want to delete: \n");
    char title[MAX_SIZE];
    scanf("%s", title);

    for (int i = 0; i < library->numberOfBooks; i++) {
        if (isDeleted(&library->Books[i])) continue;
        if (isSameBookName(library->Books[i].title, title)) {
            library->booksQuantity -= library->Books[i].quantity;
            library->Books[i].quantity = -1;
            break;
        }
    }
}

void    showBooksQuantity(struct Library *library) {
    printf("---------------------\n");
    printf("total books quantities is : %d\n", library->booksQuantity);
}


// Menu functions 

void    checkOption(struct Library *library, int option) {
    
    switch (option) {
        case 1:
        AddBook(library);
        break;
        case 2 :
            showBooksInfo(library);
            break;
        case 3 :
            changeBookQuantity(library);
            break;
        case 4 :
            deleteBook(library);
            break;
        case 5 :
            showBooksQuantity(library);
            break;
        default :
            printf("Enter a valid option please.\n");
    }
}
    
void    DisplayMenu() {
    printf("\n===============MENU=============================\n");
    printf("1- Add a book.\n");
    printf("2- Show all books informations.\n");
    printf("3- Change book quantity.\n");
    printf("4- Delete a book.\n");
    printf("5- show quantitiy of all books.\n");
    printf("Enter an option from the menu please:\n");
}

int main() {
    struct Library library;
    library.booksQuantity = 0;
    library.numberOfBooks = 0;
    while (true) {
        DisplayMenu();
        int option;
        scanf("%d", &option);
        checkOption(&library, option);
    }
}
