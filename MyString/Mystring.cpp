#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Mystring.h"

MyString::MyString()
    : str{ nullptr } {
    std::cout << "No-args  constructor called" << std::endl;
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char* s)
    : str{ nullptr } {
    std::cout << "Overloaded constructor called" << std::endl;

    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);

    }
}

MyString::MyString(const MyString& source)
    : str{ nullptr } {
    std::cout << "Copy constructor called" << std::endl;

    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

MyString::MyString(MyString&& source):str(source.str)
{
    std::cout << "Move constructor" << std::endl;
    source.str = nullptr;
}


MyString& MyString::operator=(const MyString& rhs) {
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

MyString& MyString::operator=(MyString&& rhs)
{
    std::cout << "move assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

MyString MyString::operator+(const MyString& rhs) const
{
    char* temp = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(temp, str);
    std::strcat(temp, rhs.str);
    MyString result{ temp };
    delete[] temp;
    return result;
}

bool MyString::operator==(const MyString& rhs) const
{
    return std::strcmp(str, rhs.str) == 0;
}

// Display method
void MyString::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int MyString::get_length() const { return strlen(str); }
const char* MyString::get_str() const { return str; }

MyString::~MyString() {
    std::cout << "Destructor called"<< std::endl;
    delete[] str;
}




