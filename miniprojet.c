#include <stdio.h>
#include <stdbool.h>

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
};


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
    printf("Enter Book price please: \n");
    scanf("%d", &book->quantity);
}

void    showInfos(struct Book *book) {
    printf("    Title: %s\n", book->title);
    printf("    Author: %s\n", book->author);
    printf("    Price: %lf\n", book->price);
    printf("    Quantity: %d\n", book->quantity);
}

void    AddBook(struct Library *library) {
    struct Book newBook;
    setTitle(&newBook);
    setAuthor(&newBook);
    setPrice(&newBook);
    setQuantity(&newBook);

    library->Books[library->numberOfBooks] = newBook;
    library->numberOfBooks++;
}

void    showBooksInfo(struct Library *library) {
    printf("there is %d books.\n", library->numberOfBooks);
    for (int i = 0; i < library->numberOfBooks; i++) {
        printf("book number %d infos:\n", i);
        showInfos(&library->Books[i]);
    }
}

void    DisplayMenu() {
    printf("1- Add a book: \n");
    printf("2-Show all books informations.\n");
    printf("Enter an option from the menu please:\n");
}


int main() {

    while (true) {
        DisplayMenu();
        int option;
        scanf("%d", &option);
    }
}
