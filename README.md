# Book Management System in C

This project is a simple **Book Management System** developed in C. It allows users to perform various operations such as adding, searching, updating, sorting, and removing books from a collection. The program uses dynamic memory allocation to manage a flexible list of books and implements functionality for managing book details, including price, rating, author, and category.

## Features

1. **Add Books**: Add new books to the system with details like ID, name, author, category, price, and rating.
2. **Display All Books**: Display the list of all books in the system.
3. **Search Books**: Search for books by their ID and name.
4. **Search by Author**: Find books by a specific author.
5. **Search by Category**: Find books by category (e.g., Fiction, Technology, etc.).
6. **Update Book Details**: Update the price or rating of a book.
7. **Sort Books**: Sort books by price or rating in descending order.
8. **Remove Books**: Remove a book from the system by ID and name.
9. **Graceful Exit**: The system can be closed gracefully, preserving data integrity.

## Data Structure

The program uses a `struct` to represent a book with the following attributes:
- `id`: Unique identifier of the book.
- `name`: Title of the book.
- `author`: Author of the book.
- `category`: Category or genre of the book.
- `price`: Price of the book.
- `rating`: Rating of the book (out of 5).

## Memory Management

The system dynamically allocates memory for the list of books using `malloc()` and `realloc()`, allowing for flexible handling of book entries. A sample set of 20 books is pre-loaded into the system using the `dummyData()` function for initial testing.

## Key Functions

- **Add Book**: Allows users to input book details and adds them to the system.
- **Display All Books**: Prints all books in a tabular format.
- **Search Book**: Allows searching by book name and ID.
- **Sort Books**: Offers sorting options based on price or rating.
- **Remove Book**: Deletes a book from the system and shifts subsequent entries.

## How to Use

1. Compile and run the program.
2. Use the menu to navigate through options to manage the book collection.
3. The system provides feedback after each operation (e.g., successful addition/removal of books).
4. The program will continue running until the user chooses to exit.

## Sample Output

- The user will interact with a console menu for book operations.
- On selecting an operation, the system will provide prompts for necessary input and display results accordingly.

### Example Usage:
- **Adding a Book**: After choosing option 1, you can enter details for multiple books.
- **Searching for a Book**: Option 3 allows users to search for a book by name and ID.
- **Sorting**: You can sort books by price or rating to view the highest-rated or most expensive books.

## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/sankalp217/book-management-system.git
