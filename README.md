# class-implementation-string
Сlass for representation a character string in C++.

The functionality of the Python interpreter has also been extended with an implemented class (***./for python***)

## Functionality
The basic class MyString follow next requirements:
1) Constructor

        Constructor()                           // default constructor
        Constructor(MyString)                   // copy constructor
        Constructor(“char string”)              // char array constructor
        Constructor({‘s’,’t’,’r’,’i’,’n’,‘g’})  // initializer list constructor 
        Constructor(std::string)                // std::string constructor
        Constructor(“char string”, count)       // init class with count characters of  “char string”,Constructor(“hello”, 4) -> “hell”
        Constructor( count, char)               // init class with count of characters
        
2) Destructor()
3) Operator +
        
		Operator +(Mystring)        // concatenate with Mystring
		Operator +(“char string”)   // concatenate with char array
		Operator +(std::string)     // concatenate with std::string
        
4) Operator +=

        Operator +=(“char string”)  // assignment concatenate with char array
        Operator +=(std::string)    // assignment concatenate with std::string

5) Operator =

        Operator=(“char string”)    // char string assignment
		Operator=(std::string)      // std::string assignment
		Operator=(‘char’)           // char assignment
	      
6) Opearator[]
	    
	    Opearator[](int)            // index operator, Mystring(“012345”)[5] ->‘5’
	  
7) Operator>(), Operator<(), Operator>=(), Operator<=(), Operator!=(), Operator==() // lexicographically comparing
8) Operator<<(std::basic_ostream), Operator>>(std::basic_istream) 	// like operator<<,>>(std::basic_string)
9) c_str()			// return a pointer to null-terminated character array
10) data()			// return a pointer to array data that not required to be null-terminated
11) length() 			// same as size 
12) size() 			// return the number of char elements in string
13) empty() 			// true if string is empty
14) capacity() 			// return the current amount of allocated memory for array
15) shrink_to_fit() 		// reduce the capacity to size
16) clear() 			// remove all char element in string
17) insert()

		insert(index, count, char) 		// insert count of char in index position
		s = “aaaaa”
		s.insert(0,1,’!’) -> “!aaaaa”
		s.insert(3,2,’@’) -> “!aa@@aaa”

		insert(index, “string”) 		// insert null-terminated char string at index position
		s = “aaaaa”
		s.insert(1,”@@@@@”) -> “a@@@@@aaaa”

		insert(index, “string”, count) 		// insert count of null-terminated char string at index position
		s = “aaaaa”
		s.insert(1,”@@@@@”, 2) -> “a@@aaaa”

		insert(index, std::string) 		// insert std::string at index position
		s = “aaaaa”
		string = “@@@@@”
		s.insert(1, std::string(“@@@@@”)) -> “a@@@@@aaaa”

		insert(index, std::string, count) 	// insert count of std::string at index position
		s = “aaaaa”
		s.insert(1, std::string(“@@@@@”)), 2) -> “a@@aaaa”

18) erase()

		erase(index, count) 			// erase count of char at index position
		s = “aa@@@@@aaa”
		s.erase(2, 3) -> “a@@aaaa”

19) append()

		append(count, char) 			// append count of char
		str.clear() -> “”
		str.append(3,’!’) -> “!!!”
		str.append(3,’@’) -> “!!!@@@”

		append(“string”) 			// append null-terminated char string
		str.clear() -> “”
		str.append(“hello ”) -> “hello ”
		str.append(“world”) -> “hello world”

		append(“string”, index, count) 		// append a count of null-terminated char string by index position
		str.clear() -> “”
		str.append(“hello world”,0, 6) -> “hello ”
		str.append(“hello world”,6, 5) -> “hello world”

		append(std::string) 			// append std:: string
		str.clear() -> “”
		str.append(std::string(“hello ”)) -> “hello ”
		str.append(std::string(“world”)) -> “hello world”

		append(std::string, index, count) 	// append a count of std:: string by index position
		str.clear() -> “”
		str.append(std::string(“hello world”),0, 6) -> “hello ”
		str.append(std::string(“hello world”),6, 5) -> “hello world”

20) replace()

		replace(index, count, “string”)	 	// replace a count of char at index by “string”
		s = “hello amazing world”
		s.replace(6,7,”wonderful”) -> “hello wonderful world”

		replace(index, count, std::string) 	// replace a count of char at index by std::string
		s = “hello amazing world”
		s.replace(6,7,std::string(”wonderful”)) -> “hello wonderful world”

21) substr()

		substr(index) 		//return a substring starts with index position
		s = “hello amazing world”
		s.substr(6) -> “amazing world”

		substr(index,count)	// return a count of substring’s char starts with index position
		s = “hello amazing world”
		s.substr(6, 7) -> “amazing”

22) find()

		find(“string”) 			// if founded return the index of substring
		find(“string”, index) 		// same as find(“string”) but search starts from index position
		find(std::string) 		// if founded return the index of substring
		find(std::string, index) 	// same as find(“string”) but search starts from index position
