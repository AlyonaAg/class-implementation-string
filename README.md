# class-implementation-string
Сlass for representation a character string in C++.

The basic class MyString follow next requirements:
1) Constructor

        Constructor()                           // default constructor
        Constructor(MyString)                   //copy constructor
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
	      Opearator[](int)            // index operator, Mystring(“012345”)[5] ->‘5’

