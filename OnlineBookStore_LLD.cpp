
/*
 * Requirements:
 * 1 - User should be able to read books
 * 2 - Admin User should be able to add books
 * 3 - Books Searching would be based on book title and author name
 * 4 - User should be able to resume book reading, for a selected book from active book list. 
 * 5 - User can have max of 2 active books, if wants to read more, first has to close the existing books
 * 6 - Admin User should be able to delete books
 * 7 - User authentication based on email/phone Number
 * 8 - Book Searching based on genre
 *	------
 * 9  - DB interaction to store information in DB and create interface for it
 * 10 - DB Table Structure
 * 11 - Analytics on book - likes, comments, users reading it... 
 */

class BookStore{
	private:
		vector<Book> books;
	
	public:
		AddBook(Book b);
		DeleteBook(Book b);
		DeleteBook(long long Id);
		vector<Book> SearchBook(long long Id);
	        vector<Book> SearchBook(string AuthorName_title);	
		vector<Book> SearchBook(Genre genre);
}

// Implements actual BookStore in Cache without DB
class AmazonBookStore: public BookStore{
	public: 
		AddBook(Book b);
		DeleteBook(Book b);
		DeleteBook(long long Id);
		vector<Book> SearchBook(long long Id);
	        vector<Book> SearchBook(string AuthorName_title);	
}

// All DB related implementations are here
class AmazonBookStorewithDB: public BookStore{
	public: 
		AddBook(Book b);
		DeleteBook(Book b);
		DeleteBook(long long Id);
		vector<Book> SearchBook(long long Id);
	        vector<Book> SearchBook(string AuthorName_title);	
}

class Book{
	private:
	        static long long book_count;	
		string Title;
		long long Id;
		string Author;
		long Year_of_Publication;
		long page_count;
		long price;
		Genre genre;
		long current_page;
	public:
		Book(string Title, string Author, long year, long page_count, long price, Genre g):
		       Title(Title), Author(Author), Year_of_Publication(year), page_count(page_count), price(price), genre(g){
				Id = ++book_count;
				current_page = 0;
		       }
		Read();
		Close();
};

long long Book::book_count = 0;

enum Genre{
	SCIFI = 0,
	ADVENTURE,
	HORROR,
	LIFE
}

class Users{
	private:
		//map<uname, User*> map;
		map<string, User*> map;
	public:
		AddUser(User* u);
		DeleteUser(User* u);
		GetUser(string uname, string password); // Validator
}

// In Cache 
Class UsersCache: public Users{
	public:
		AddUser(User* u);
		DeleteUser(User* u);
		GetUser(string uname, string password); // Validator
}

// In DB
Class UsersDB: public Users{
	public:
		AddUser(User* u);
		DeleteUser(User* u);
		GetUser(string uname, string password); // Validator
}

class User{
	private:
		string UName;
		string Name;
		string email;
		long phone_no;
		string password;
		Utype utype;
	public:
		User(string Uname, string Name, string email, long ph, string password):
			UName(Uname), Name(Name), email(email), phone_no(ph), password(password){}
		string GetPassword();
};

class PublicUser: public User{
	private:
		long active_book_count;
		PublicUserCategory p;
		vector<Book> active_list;
		BookStore* Store;
	public:
		PublicUser(string Uname, string Name, string email, long ph, p, BookStore* Store):
			User(Uname, Name, email, ph), Store(Store), utype(PublicUser)
	{
		switch(p)
		{
			case FREE:
				active_book_count = 2;
				break;
			case PRO:
				active_book_count = 10;
				break;
			case PRO+:
				active_book_count = 20;
				break;
			case PREMIUM:
				active_book_count = 100;
				break;
			default:
				active_book_count = 0;
				break;
		}

	}
		GetBookCopy(Book b); // Gives a copy of Actual Book
		Book SearchBook(long long Id);
		vector<Book> SearchBook(Genre genre);
		ReadBook(Book b); // All reading validation active_list check and resume from particular page in book, store same back in active_list

};

enum PublicUserCategory { FREE, PRO, PRO+, PREMIUM }

class AdminUser: public User{
	private:
		BookStore* Store;
	public:
		AdminUser(string Uname, string Name, string email, long ph, BookStore* Store):
			User(Uname, Name, email, ph), Store(Store), utype(AdminUser) {}
		AddBook(Book b);	
		DeleteBook(Book b);
		DeleteBook(long long Id);
};

enum Utype{ PublicUser, AdminUser };
