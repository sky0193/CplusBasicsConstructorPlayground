#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class MyString
{
private:
    char* str;      // pointer to a char[] that holds a C-style string
public:
    MyString();                                          // No-args constructor
    MyString(const char* s);                             // Overloaded constructor
    MyString(const MyString& source);                    // Copy constructor
    MyString(MyString&& source);
    ~MyString();                                         // Destructor

    MyString& operator=(const MyString& rhs);       // Copy assignment
    MyString& operator=(MyString&& rhs);       // Move assignment

    MyString operator+(const MyString& rhs) const;
    bool operator==(const MyString& rhs) const;

    void display() const;

    int get_length() const;
    const char* get_str() const;
};

#endif 
