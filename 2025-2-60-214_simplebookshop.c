/* ID- 2025-2-60-214
   Name:Mohammad Shahriar Kabir  */


#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 500

// Structure to store the book details
struct Book {
    char title[51];
    char author[31];
    float price;
    int copies;
};

// Global array of books
struct Book books[MAX_BOOKS];
int bookCount = 0;

// Function declarations at begining
void showWelcomeMessage();
void showGoodByeMessage();
void showMenuOptions();
void showBooks();
void addBook();
void searchBook();
void showNumberOfBooks();

// This is the main function
int main() {
    int choice;

    showWelcomeMessage();
    showMenuOptions();

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();     /*this clears newline from buffer */

        switch (choice) {
            case 1:
                showMenuOptions();
                break;
            case 2:
                showBooks();
                break;
            case 3:
                addBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                showNumberOfBooks();
                break;
            case 6:
                showGoodByeMessage();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function definitions

void showWelcomeMessage() {  // shows a welcome message
    printf("*********************************\n");
    printf(" Welcome to our Bookshop!\n");
    printf("*********************************\n");
}

void showGoodByeMessage() {  // shows a goodbye message
    printf("*********************************\n");
    printf("Thanks for using our services. See you next time!\n");
    printf("*********************************\n");
}
// The following function shows menu options
void showMenuOptions() {
    printf("\nPlease select a menu option number:\n");
    printf("1) Display this menu\n");
    printf("2) Show all available books\n");
    printf("3) Add a book to the book shop\n");
    printf("4) Search a book by title\n");
    printf("5) Display the total number of books\n");
    printf("6) Exit from this book shop system\n");
}
// This function shows available books
void showBooks() {
    if (bookCount == 0) {
        printf("No books available\n");
        return;
    }

    printf("\nList of books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book title: %s\n", books[i].title);
        printf("Book author: %s\n", books[i].author);
        printf("Book price: %.2f\n", books[i].price);
        printf("Number of copies: %d\n\n", books[i].copies);
    }
}
// you can add books using this function
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Book limit reached. Cannot add more books\n");
        return;
    }

    printf("Enter book title: ");
    gets(books[bookCount].title);

    printf("Enter book author: ");
    gets(books[bookCount].author);

    printf("Enter book price: ");
    scanf("%f", &books[bookCount].price);

    printf("Enter number of copies: ");
    scanf("%d", &books[bookCount].copies);
    getchar(); // Clear newline

    bookCount++;
    printf(" Book added successfully!\n");
}


// this function is used for searching books

void searchBook() {
    char searchTitle[51];
    int found = 0;

    printf("Enter book title to search: ");
    gets(searchTitle);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {  // compare strings
            printf("Book title: %s\n", books[i].title);
            printf("Book author: %s\n", books[i].author);
            printf("Book price: %.2f\n", books[i].price);
            printf("Number of copies: %d\n", books[i].copies);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// this function shows total number of books
void showNumberOfBooks() {
    int totalCopies = 0;
    for (int i = 0; i < bookCount; i++) {
        totalCopies += books[i].copies;
    }
    printf(" Total number of books in the shop: %d\n", totalCopies);
}
