Convert character '0','1','2' etc to numbers easily : digit in character - zero in character i.e '9' - '0' = 9.
Operate on a string to put a new number in a string position :

//string s = "124";
  s[0] = 9 - (s[0] - '0') + '0';
  cout << s;
// prints 824

shifting x many characters : generally done by 'character' - 'a'/'A' + new shift like if we want to go to the 'z' - 'a' + 'something
new'

http://www.c4learn.com/c-programming/c-arithmetic-operations-on-character/

Way 1: Displays ASCII value[ Note that %d in Printf ]

char x = 'a';
printf("%d",x); // Display Result = 97
Way 2 : Displays Character value[ Note that %c in Printf ]

char x = 'a';
printf("%c",x); // Display Result = a
Way 3 : Displays Next ASCII value[ Note that %d in Printf ]

char x = 'a' + 1 ;
printf("%d",x);
// Display Result = 98 ( ascii of 'b' )
Way 4 Displays Next Character value[Note that %c in Printf ]

char x = 'a' + 1;
printf("%c",x); // Display Result = 'b'
Way 5 : Displays Difference between 2 ASCII in Integer[Note %d in Printf ]

char x = 'z' - 'a';
printf("%d",x);
/* Display Result = 25 
    (difference between ASCII of z and a ) */
    
Way 5 : Displays Difference between 2 ASCII in Integer[Note %d in Printf ]

char x = 'z' - 'a';
printf("%d",x);
/* Display Result = 25 
    (difference between ASCII of z and a ) */
Way 6 : Displays Difference between 2 ASCII in Char [Note that %c in Printf ]

char x = 'z' - 'a';
printf("%c",x);
/* Display Result = ↓ 
      ( difference between ASCII of z and a ) */
      
