#include <stdio.h>
#include <iostream>
#include "my_class.h"

MyString::MyString()
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	a_string_[0] = '\0';
}

MyString::MyString(const MyString &point)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	reallocation_of_memory(point.c_str(), point.size());
}

MyString::MyString(char *string)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	size_t len_string = 0;
	for (; string[len_string]; len_string++);
	reallocation_of_memory(string, len_string);
}

MyString::MyString(char *string, size_t count)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	a_string_[0] = '\0';
	append(string, 0, count);
}

MyString::MyString(size_t count, char symbol)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	a_string_[0] = '\0';
	insert(0, count, symbol);
}

MyString::MyString(std::initializer_list<char> list)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	a_string_[0] = '\0';

	char* temp_string=new char [list.size()+1];
	temp_string[list.size()] = '\0';
	size_t i = 0;
	for (auto &element : list)
	{
		temp_string[i] = element;		
		++i;
	}
	append(temp_string);
}

MyString::MyString(std::string &string)
{
	a_len_string_ = 0;
	a_capacity_ = cCapacityBlock;
	a_string_ = new char[a_capacity_];
	reallocation_of_memory(string.c_str(), string.size());
}


void MyString::reallocation_of_memory(const char *string, size_t count)
{
	size_t len_string = 0, offset = 0;
	for (; string[len_string]; len_string++);
	len_string = count < len_string ? count : len_string;

	while (len_string >(a_capacity_ - a_len_string_))
			a_capacity_ += cCapacityBlock;

	char* temp_string = a_string_;
	a_string_ = new char[a_capacity_];
	std::copy(temp_string, temp_string + a_len_string_, a_string_);
	delete[] temp_string;

	std::copy(string, string + len_string, a_string_ + a_len_string_);		//copy input string
	a_len_string_ += len_string;
	a_string_[a_len_string_] = '\0';
}


const char MyString::operator[] (size_t index) const
{
		return a_string_[index];
}

void MyStringPython::__setitem__(size_t index, char symbol)
{
	a_string_[index] = symbol;
}

const char MyStringPython::__getitem__(size_t index)
{
	return a_string_[index];
}

const char* MyStringPython::__str__()
{
	return a_string_;
}


void MyString::operator =(const char* string)
{
	clear();
	append(string);
}

void MyString::operator =(const MyString &point)
{
	clear();
	append(point.a_string_);
}

void MyString::operator =(const std::string &string)
{
	clear();
	append(string);
}

void MyString::operator =(const char symbol)
{
	a_len_string_ = 1;
	a_string_[0] = symbol;
	a_string_[1] = '\0';
}


MyString MyString::operator +(const char* string) const
{
	MyString temp;
	temp.append(a_string_);
	temp.append(string);
	return temp;
}

MyString MyString::operator +(const MyString &point) const
{
	return this->operator+(point.c_str());
}

MyString operator +(const char* string, const MyString &point)
{
	MyString temp;
	temp.append(string);
	temp.append(point.a_string_);
	return temp;
}

MyString MyString::operator +(const std::string &string) const
{
	return this->operator+(string.c_str());
}

MyString operator +(const std::string &string, const MyString &point)
{
	MyString temp;
	temp.append(string);
	temp.append(point.a_string_);
	return temp;
}


void MyString::operator +=(const char* string)
{
	append(string);
}

void MyString::operator +=(const MyString &point)
{
	append(point.a_string_);
}

void MyString::operator +=(const std::string &string)
{
	append(string);
}

MyStringPython MyStringPython::operator += (const char* string)
{
	append(string);
	MyStringPython temp;
	temp.a_string_ = this->a_string_;
	temp.a_capacity_ = this->a_capacity_;
	temp.a_len_string_ = this->a_len_string_;
	return temp;
}

MyStringPython MyStringPython::operator += (const MyStringPython& point)
{
	append(point.c_str());
	MyStringPython temp;
	temp.a_string_ = this->a_string_;
	temp.a_capacity_ = this->a_capacity_;
	temp.a_len_string_ = this->a_len_string_;
	return temp;
}

MyStringPython MyStringPython::operator += (const std::string& string)
{
	append(string);
	MyStringPython temp;
	temp.a_string_ = this->a_string_;
	temp.a_capacity_ = this->a_capacity_;
	temp.a_len_string_ = this->a_len_string_;
	return temp;
}


bool MyString::operator ==(const char* string) const
{
	size_t string_len = 0;
	for (; string[string_len]; string_len++);
	if (string_len != a_len_string_)
		return false;

	size_t i = 0;
	while (string[i] && string[i] == a_string_[i])
		++i;

	if (i == a_len_string_)
		return true;
	else
		return false;
}

bool MyString::operator ==(const std::string &string) const
{
	return this->operator==(string.c_str());
}

bool MyString::operator ==(const MyString &point) const
{
	return this->operator==(point.c_str());
}

bool operator ==(const char* string, const MyString &point)
{
	return point.operator==(string);
}

bool operator ==(const std::string &string, const MyString &point)
{
	return point.operator==(string.c_str());
}


bool MyString::operator !=(const char* string) const
{
	return !(this->operator==(string));
}

bool MyString::operator !=(const std::string &string) const
{
	return !(this->operator==(string.c_str()));
}

bool MyString::operator !=(const MyString &point) const
{
	return !(this->operator==(point.c_str()));
}

bool operator !=(const char* string, const MyString &point)
{
	return !(point.operator==(string));
}

bool operator !=(const std::string &string, const MyString &point)
{
	return !(point.operator==(string.c_str()));
}


bool MyString::operator >(const char* string) const
{
	size_t i = 0;
	while (string[i] && a_string_[i])
	{
		if (string[i] < a_string_[i])
			return true;
		if (string[i] > a_string_[i])
			return false;
		++i;
	}
	if (!string[i] && a_string_[i])
		return true;
	else
		return false;
}

bool MyString::operator >(const std::string &string) const
{
	return this->operator>(string.c_str());
}

bool MyString::operator >(const MyString &point) const
{
	return this->operator>(point.c_str());
}

bool operator >(const char* string, const MyString &point)
{
	return !(point.operator>(string) || point.operator==(string));
}

bool operator >(const std::string &string, const MyString &point)
{
	return !(point.operator>(string.c_str()) || point.operator>(string.c_str()));
}


bool MyString::operator <(const char* string) const
{
	return !(this->operator>(string) || this->operator==(string));
}

bool MyString::operator <(const std::string &string) const
{
	return !(this->operator>(string.c_str()) || this->operator==(string.c_str()));
}

bool MyString::operator <(const MyString &point) const
{
	return !(this->operator>(point.c_str()) || this->operator==(point.c_str()));
}

bool operator <(const char* string, const MyString &point)
{
	return point.operator>(string);
}

bool operator <(const std::string &string, const MyString &point)
{
	return point.operator>(string.c_str());
}


bool MyString::operator >=(const char* string) const
{
	return !(this->operator<(string));
}

bool MyString::operator >=(const std::string &string) const
{
	return !(this->operator<(string.c_str()));
}

bool MyString::operator >=(const MyString &point) const
{
	return !(this->operator<(point.c_str()));
}

bool operator >=(const char* string, const MyString &point)
{
	return !(point.operator>(string));
}

bool operator >=(const std::string &string, const MyString &point)
{
	return !(point.operator>(string.c_str()));
}


bool MyString::operator <=(const char* string) const
{
	return !(this->operator>(string));
}

bool MyString::operator <=(const std::string &string) const
{
	return !(this->operator>(string.c_str()));
}

bool MyString::operator <=(const MyString &point) const
{
	return !(this->operator>(point.c_str()));
}

bool operator <=(const char* string, const MyString &point)
{
	return !(point.operator<(string));
}

bool operator <=(const std::string &string, const MyString &point)
{
	return !(point.operator<(string.c_str()));
}


std::ostream& operator << (std::ostream &out, const MyString &point)
{
	out << point.a_string_;
	return out;
}

std::istream& operator >> (std::istream &in, MyString &point)
{
	point.clear();
	char* temp_string = new char[point.cMaxCinLength];
	in.getline(temp_string, point.cMaxCinLength);
	int temp_strlen = 0;
	for (; temp_string[temp_strlen]; temp_strlen++);
	point.reallocation_of_memory(temp_string, temp_strlen);
	delete[] temp_string;
	return in;
}


const char* MyString::c_str() const
{
	return a_string_;
}

const char* MyString::data() const
{
	return a_string_;
}

size_t MyString::size() const
{
	return a_len_string_;
}

size_t MyString::length() const
{
	return a_len_string_;
}

bool MyString::empty() const
{
	if (!a_len_string_)
		return true;
	else
		return false;
}

void MyString::clear()
{
	a_string_[0] = '\0';
	a_len_string_ = 0;
}

size_t MyString::capacity() const
{
	return a_capacity_;
}

void MyString::shrink_to_fit()
{
	char* temp_string = new char [a_len_string_];
	size_t temp_length = a_len_string_;
	std::copy(a_string_, a_string_+a_len_string_, temp_string);
	a_len_string_=0;
	a_capacity_ = 15;
	reallocation_of_memory(temp_string, temp_length);
	delete[] temp_string;
}


void MyString::insert(size_t index, size_t count, const char symbol)
{
	char* temp_string = new char[count+1];
	for (int i = 0; i < count; temp_string[i] = symbol, ++i);
	temp_string[count] = '\0';
	insert(index, temp_string);
	delete[] temp_string;
}

void MyString::insert(size_t index, const char* string)
{
	size_t i = 0;
	for (; string[i]; i++);
	insert(index, string, i);
}

void MyString::insert(size_t index, const std::string &string)
{
	insert(index, string.c_str());
}

void MyString::insert(size_t index, const char* string, size_t count)
{
	if (index < 0 || count < 0)
		return;
	char* temp_string = new char [a_len_string_+1];
	size_t temp_length = a_len_string_;
	std::copy(a_string_, a_string_ + a_len_string_, temp_string);

	a_string_[index] = '\0';
	a_len_string_ = index;
	reallocation_of_memory(string, count);
	reallocation_of_memory(temp_string+index, temp_length-index);
	delete[] temp_string;
}

void MyString::insert(size_t index, const std::string &string, size_t count)
{
	insert(index, string.c_str(), count);
}


void MyString::erase(size_t index, size_t count)
{
	if (index < 0 || count <= 0 || index>a_len_string_)
		return;
	a_string_[index] = 0;
	if (index + count < a_len_string_)
	{
		a_len_string_ = index;
		append(a_string_ + index + count);
	}
	else
		a_len_string_ = index;
}


void MyString::append(size_t count, const char symbol)
{
	char* temp_string = new char[count + 1];
	for (int i = 0; i < count; temp_string[i] = symbol, ++i);
	temp_string[count] = '\0';
	append(temp_string);
	delete[] temp_string;
}

void MyString::append(const char* string)
{
	insert(length(), string);
}

void MyString::append(const std::string &string)
{
	insert(length(), string.c_str());
}

void MyString::append(const char* string, size_t index, size_t count)
{
	size_t i = 0;
	for (; string[i]; i++);
	if (index > i)
		return;
	insert(length(), string + index, count);
}

void MyString::append(const std::string &string, size_t index, size_t count)
{
	insert(length(), string.c_str() + index, count);
}

void MyString::append(const MyString &point)
{
	insert(length(), point.c_str());
}


void MyString::replace(size_t index, size_t count, const char* string)
{
	if (index < 0 || count < 0 || index>a_len_string_)
		return;
	erase(index, count);
	insert(index, string);
}

void MyString::replace(size_t index, size_t count, const std::string &string)
{
	replace(index, count, string.c_str());
}


MyString MyString::substr(size_t index) const
{
	return substr(index, length()-index);
}

MyString MyString::substr(size_t index, size_t count) const
{
	if (index < 0 || count<0 || index>a_len_string_)
		return "";

	char* temp_string = new char[a_len_string_ + 1];

	size_t i = 0;
	while (a_string_[i + index] && i < count)
	{
		temp_string[i] = a_string_[i + index];
		++i;
	}
	temp_string[i] = '\0';
	MyString return_MyString(temp_string);
	delete[] temp_string;
	return return_MyString;
}


size_t MyString::find(const char* string) const
{
	return find(string, 0);
}

size_t MyString::find(const std::string &string) const
{
	return find(string.c_str(), 0);
}

size_t MyString::find(const std::string &string, size_t index) const
{
	return find(string.c_str(), index);
}

size_t MyString::find(const char* string, size_t index) const
{
	if (index < 0)
		return -1;
	
	size_t len_new_string = 0, i;
	for (; string[len_new_string]; ++len_new_string);

	i = index - 1;
	while (a_string_[++i] && (i + len_new_string) <= a_len_string_)
		if (std::equal(string, string + len_new_string, a_string_ + i))
			return i;
	return -1;
}