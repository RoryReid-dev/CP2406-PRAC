#pragma once

#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	Person(string firstName, string lastName)
		: Person{firstName, lastName,
				 firstName.substr(0, 1) + lastName.substr(0, 1)}
	{
	}

	Person() = default;

	Person(string firstName, string lastName, string initials)
		: m_firstName{move(firstName)}, m_lastName{move(lastName)}, m_initials{move(initials)}
	{
	}

	virtual ~Person() = default; // A virtual destructor!

	virtual const string &getFirstName() const { return m_firstName; }
	virtual void setFirstName(string firstName) { m_firstName = move(firstName); }

	virtual const string &getLastName() const { return m_lastName; }
	virtual void setLastName(string lastName) { m_lastName = move(lastName); }

	virtual const string &getInitials() const { return m_initials; }
	virtual void setInitials(string initials) { m_initials = move(initials); }

	virtual string toString() const
	{
		return "Person's name is: " + getFirstName() + " " + getLastName();
	}

	void output(ostream &output) const
	{
		output << getFirstName() << " " << getLastName() << " " << getInitials() << endl;
	}

private:
	string m_firstName;
	string m_lastName;
	string m_initials;
};
