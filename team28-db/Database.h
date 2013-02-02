/*
* Name        : Database.h
* Author      : Team 28
* Description : - header file for Department class
*/

#ifndef DATABASE_H_
#define DATABASE_H_

class Database
{
	public:
		Database() {};

		add_table(Table t, string name);
		drop_table(string name);

	private:

}

#endif //DATABASE_H_