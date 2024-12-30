#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book {
	int id;
	char name[40];
	char author[20];
	char category[20];
	float price;
	float rating;
} book;

void displayMenu();
void addBook(book*, int*, int*);
void displayAllBook(book*, int);
int searchBook(book*, int);
void author(book*, int);
void category(book*, int);
void updateBook(book*, int);
void sort(book*,int);
void sortPrice(book*,int);
void sortRating(book*,int);
void swap(book*, book*);
void removeBook(book*,int*,int*);
void notify(int, char*);
void closing();
void dummyData(book*);

void main()
{
    
    int size=20;
    int count=20;
    int Newsize=0;
	
	printf("\n---------------------------------------------------- DigiBookShelf ----------------------------------------------------\n\n");

    book* brr;
    brr=(book*)malloc(size * sizeof(book));
    	
    dummyData(brr);

	do
	{
		int ch;
		displayMenu();
		scanf("%d", &ch);
	
		switch(ch) 
		{
			case 1:
				printf("\nHow many books you want to add?\n= ");
				scanf("%d",&Newsize);
				
				size=size+Newsize;
    			brr = (book*)realloc(brr, size * sizeof(book));
    			
				addBook(brr,&size,&count);
				
				if(Newsize>1)
					printf("Books have been successfully added!\n");
				else
					printf("A book has been successfully added!\n");
					
				break;
			case 2:
				displayAllBook(brr, count);
				break;
			case 3:
				printf("\n------------- Search books -------------");
				searchBook(brr, count);
				break;
	    	case 4:
	    		if(count>0)
	    			author(brr, count);
				else
					printf("\nThe system is empty right now. Kindly add books to the system.\n\n");
				break;
	    	case 5:
	    		category(brr, count);
	    		break;
	    	case 6:
	    		updateBook(brr, count);
	    		break;
	    	case 7:
	    		sort(brr, count);
	    		break;
	    	case 8:
	    		removeBook(brr, &size, &count);
	    		
	    		size--;
	    		count--;
	    		brr = (book*)realloc(brr, count * sizeof(book));
	    		break;
			case 9:
				closing();
			default:
				printf("\nPlease check your input and try again.\n");
		}
	}
	while(1);
}

void displayMenu()
{
	printf("\n---------------   MENU   ---------------\n");
	printf("1. Add books\n");
	printf("2. Display books\n");
	printf("3. Search books\n");
	printf("4. Search author\n");
	printf("5. Search category\n");
	printf("6. Update book\n");
	printf("7. Sort books\n");
	printf("8. Remove book\n");
	printf("9. Exit\n\n");
	printf("Enter your choice: ");
}

void addBook(book* brr, int* size, int* count)
{

    printf("\n-------------- Add books ---------------\n");

	int i=*count;
	
    while(i<*size)
    {
    	fflush(stdin);
	
		do {
            printf("Book id   : ");
            scanf("%d", &brr[i].id);
            if (brr[i].id <= 0) {
                printf("Invalid input! Id must be a positive number.\n");
                fflush(stdin);
            }
        } while (brr[i].id <= 0);
        
		fflush(stdin);
		printf("Book name : ");
		scanf("%[^\n]s",&brr[i].name);
		fflush(stdin);        
		printf("Author    : ");
		scanf("%[^\n]s",&brr[i].author);
		fflush(stdin);
		printf("Category  : ");
		scanf("%[^\n]s",&brr[i].category);
		fflush(stdin);
		
		do {
            printf("Price     : ");
            scanf("%f", &brr[i].price);
            if (brr[i].price <= 0) {
                printf("Invalid input! Price must be a positive number.\n");
                fflush(stdin);
            }
        } while (brr[i].price <= 0);
        
		do {
            printf("Rating    : ");
            scanf("%f", &brr[i].rating);
            if (brr[i].rating <= 0) {
                printf("Invalid input! Rating must be a positive number.\n");
                fflush(stdin);}
            else if (brr[i].rating > 5) {
                printf("Invalid input! Rating must be out of 5.\n");
                fflush(stdin);
            }
        } while (brr[i].rating <= 0 || brr[i].rating > 5);
        
		printf("\n");
        (*count)++;
        i++;
	}
}

void displayAllBook(book* brr, int size) 
{
	printf("\n------------ Display books -------------\n");
	
	if(size > 0)
	{
		printf("\n---------------------------------------------------------------------------------------------\n");
		printf("%-5s %-30s %-20s %-15s %-10s %-10s\n", "ID", "Name", "Author", "Category", "Price", "Rating");
    	printf("---------------------------------------------------------------------------------------------\n");

		for(int i=0; i<size; i++) 
		{
			printf("%-5d %-30s %-20s %-15s %-10.2f %-10.1f\n",
               brr[i].id,
               brr[i].name,
               brr[i].author,
               brr[i].category,
               brr[i].price,
               brr[i].rating);
		}
	}
	else
		printf("\nThe system is empty right now. Kindly add books to the system.\n\n");

}

int searchBook(book* brr, int size) 
{
	char Sname[20];
	int Sid;
	int counter=0;
	
	fflush(stdin);
	printf("\nEnter the id of book to search : ");
	scanf("%d",&Sid);
	fflush(stdin);
	printf("Enter the name of book to search : ");
	scanf("%[^\n]s",&Sname);

	for(int i=0; i<size; i++) 
	{
		if(strcmp(brr[i].name, Sname) == 0 && brr[i].id == Sid) 
		{
			printf("\nBook id       : %d\nBook name     : %s\nBook author   : %s\nBook category : %s\nBook price    : %.2f\nBook rating   : %.1f\n",brr[i].id,brr[i].name,brr[i].author,brr[i].category,brr[i].price,brr[i].rating);
			counter++;
			notify(counter,"ID and name");
			return i;
		}
	}
	notify(counter,"ID and name");
	return -1;
}

void author(book* brr, int size)
{
	char Aname[20];
	int counter=0;
	
	printf("\n------------ Search author -------------");
	fflush(stdin);
	printf("\nEnter the name of author to search : ");
	scanf("%[^\n]s",&Aname);

	printf("\n---------------------------------------------------------------------------------------------\n");
	printf("%-5s %-30s %-20s %-15s %-10s %-10s\n", "ID", "Name", "Author", "Category", "Price", "Rating");
    printf("---------------------------------------------------------------------------------------------\n");

	for(int i=0; i<size; i++) 
	{
		if(strcmp(brr[i].author, Aname) == 0) 
		{
			printf("%-5d %-30s %-20s %-15s %-10.2f %-10.1f\n",
               brr[i].id,
               brr[i].name,
               brr[i].author,
               brr[i].category,
               brr[i].price,
               brr[i].rating);
			counter++;
		}
	}

	notify(counter,"author");
}

void category(book* brr, int size)
{
	char Cname[20];
	int counter=0;
	
	printf("\n------------ Search category -----------");
	fflush(stdin);
	printf("\nEnter the category to search : ");
	scanf("%[^\n]s",&Cname);

	printf("\n---------------------------------------------------------------------------------------------\n");
	printf("%-5s %-30s %-20s %-15s %-10s %-10s\n", "ID", "Name", "Author", "Category", "Price", "Rating");
    printf("---------------------------------------------------------------------------------------------\n");

	for(int i=0; i<size; i++) 
	{
		if(strcmp(brr[i].category, Cname) == 0) 
		{
			printf("%-5d %-30s %-20s %-15s %-10.2f %-10.1f\n",
               brr[i].id,
               brr[i].name,
               brr[i].author,
               brr[i].category,
               brr[i].price,
               brr[i].rating);
			   counter++;
		}
	}
	
	notify(counter,"category");
}

void updateBook(book* brr, int size)
{
	char Sname[20];
	int Sid;
	int counter=0;
	
	printf("\n------------- Update book -------------");
	fflush(stdin);
	printf("\n\nPlease provide the details of the book you'd like to update.\n");
	
	int i=searchBook(brr,size);
	
	if(i>=0)
	{
		int ch;
		printf("What would you like to update?\n1. Update price.\n2. Update rating.\n3. Update price and rating.\n\nPlease enter your choice = ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				{
					printf("\nCurrent price    = %.2f",brr[i].price);
					
					do {
				        printf("\nEnter new price  = ");
				        scanf("%f", &brr[i].price);
				        if (brr[i].price <= 0) 
						{
				            printf("Invalid input! Price must be a positive number.\n");
				            fflush(stdin);
				    	}
				    } while (brr[i].price <= 0);
				    
					printf("\nPrice updated successfully..!\n\n");
				}
				break;
			case 2:
				{
					printf("\nCurrent rating    = %.1f",brr[i].rating);
					
					do {
			            printf("\nEnter new rating  = ");
			            scanf("%f", &brr[i].rating);
			            if (brr[i].rating <= 0) 
						{
			                printf("Invalid input! Rating must be a positive number.\n");
			                fflush(stdin);
						}
			            else if (brr[i].rating > 5)
						{
			                printf("Invalid input! Rating must be out of 5.\n");
			                fflush(stdin);
			            }
			        } while (brr[i].rating <= 0 || brr[i].rating > 5);

					printf("\nRating updated successfully!\n\n");
				}
				break;
			case 3:
				{
					printf("\nCurrent price     = %.2f\nCurrent rating    = %.1f",brr[i].price,brr[i].rating);
					
					do 
					{
				        printf("\n\nEnter new price = ");
				        scanf("%f", &brr[i].price);
				        if (brr[i].price <= 0) 
						{
				            printf("Invalid input! Price must be a positive number.\n");
				            fflush(stdin);
				    	}
				    }while (brr[i].price <= 0);
					
					do 
					{
			            printf("Enter new rating = ");
			            scanf("%f", &brr[i].rating);
			            if (brr[i].rating <= 0) 
						{
			                printf("Invalid input! Rating must be a positive number.\n");
			                fflush(stdin);
						}
			            else if (brr[i].rating > 5)
						{
			                printf("Invalid input! Rating must be out of 5.\n");
			                fflush(stdin);
			            }
			        } while (brr[i].rating <= 0 || brr[i].rating > 5);

					printf("\nSuccessfully updated the Price and Rating..!\n\n");
				}
				break;
			default:
				printf("\nPlease check your input and try again.\n");
				break;
		}
	}
}

void sort(book* brr, int size)
{
	book sortedArray[size];
	
	//copy original array to new empty array.
	for(int i=0; i<size; i++)
	{
		sortedArray[i]=brr[i];
	}
	
	int ch;
	printf("\nHow would you like to sort the books?\n1: By price.\n2: By ratings.\n\nPlease enter your choice = ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			sortPrice(sortedArray, size);
			break;
		case 2:
			sortRating(sortedArray, size);
			break;
		default:
			printf("Invalid choice..!");
			break;
	}
}

void sortPrice(book* sortedArray, int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(sortedArray[j].price < sortedArray[j+1].price)
			{
				swap(&sortedArray[j], &sortedArray[j+1]);
			}
		}
	}
	
	int topThree=3;
	displayAllBook(sortedArray,topThree);
}

void sortRating(book* sortedArray, int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(sortedArray[j].rating < sortedArray[j+1].rating)
			{
				swap(&sortedArray[j], &sortedArray[j+1]);
			}
		}
	}
	
	int topThree=3;
	displayAllBook(sortedArray,topThree);
}

void swap(book* a, book* b)
{
    book temp = *a;
    *a = *b;
    *b = temp;
}

void removeBook(book* brr, int* size,int* count)
{
	printf("\n------------- Remove book --------------");
	int index=searchBook(brr, *size);
	
	if(index >= 0)
	{
		char confirmation;
		printf("This action will permanently remove the book. Are you sure?\n(y/n) = ");
		scanf(" %c", &confirmation);
		
		if(confirmation == 'y')
		{	
			for(int i=index; i<*size-1; i++)
			{
				brr[i] = brr[i+1];
			}
			printf("\nBook successfully removed!\n\n");
		}
		else
		{
			printf("\nBook removal process has been cancelled.\n\n");
		}
	}
	
}

void notify(int counter,char* msg)
{
	if(counter==0)
		printf("\nSorry..!\nWe couldn't find a book matching this %s in our system.\n\n",msg);
	else if(counter==1)
		printf("\nWe've found the book you were looking for %s..!\n\n",msg);
	else if(counter>1)
		printf("\nWe've found the books you were looking for %s..!\n\n",msg);
}

void closing()
{
	printf("\nThe book management system is now closing. We thank you for your cooperation..!\n");
	exit(1);
}

void dummyData(book* brr)
{
	brr[0] = (book){1, "The Hidden Fortress", "Anna Bright", "Adventure", 499.99, 4.3};
    brr[1] = (book){2, "The Coder's Journey", "Samuel Grant", "Technology", 799.99, 4.7};
    brr[2] = (book){3, "The Silent Whisper", "Maya Roberts", "Thriller", 399.99, 4.1};
    brr[3] = (book){4, "The Wonders of the Cosmos", "John Milton", "Science", 899.50, 4.6};
    brr[4] = (book){5, "The Lost Kingdom", "Samuel Grant", "Fantasy", 749.00, 4.8};
    brr[5] = (book){6, "In Search of Time", "Anna Bright", "Fiction", 549.99, 4.5};
    brr[6] = (book){7, "Python Programming", "Maya Roberts", "Technology", 1499.95, 4.9};
    brr[7] = (book){8, "City of Shadows", "John Milton", "Mystery", 699.00, 4.2};
    brr[8] = (book){9, "Understanding Physics", "Samuel Grant", "Science", 1200.00, 4.7};
    brr[9] = (book){10, "History of Civilizations", "Maya Roberts", "History", 1299.00, 4.3};
    brr[10] = (book){11, "Mastering Data Science", "Anna Bright", "Education", 1799.50, 4.6};
    brr[11] = (book){12, "The Art of Painting", "John Milton", "Art", 1599.00, 4.8};
    brr[12] = (book){13, "The Mindful Path", "Samuel Grant", "Self-Help", 799.00, 4.2};
    brr[13] = (book){14, "Deep Ocean Mysteries", "Anna Bright", "Documentary", 1199.00, 4.5};
    brr[14] = (book){15, "Shakespeare Revisited", "Maya Roberts", "Drama", 999.99, 4.7};
    brr[15] = (book){16, "The Power of AI", "John Milton", "Technology", 1999.99, 4.3};
    brr[16] = (book){17, "The Hidden Truth", "Samuel Grant", "Fiction", 899.00, 4.0};
    brr[17] = (book){18, "The New Era of AI", "Anna Bright", "Technology", 1499.00, 4.9};
    brr[18] = (book){19, "The Digital Revolution", "John Milton", "Business", 2499.99, 4.8};
    brr[19] = (book){20, "Art of War", "Samuel Grant", "History", 1299.99, 4.6};
}
