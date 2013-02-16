//#include "stdafx.h"
#include <iostream>
//#include "Database.h"
#include "gtest/gtest.h"




TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 2);
}
TEST(my_test_case, sample_test)
{
	int a = 0;
	int b = 0;
    EXPECT_EQ(a, b);
}
/*----------------------Database Class-----------------------*/
//----------------------Kira
//Database()
TEST(database_constructor, database_eq)
{
	Database b = new Database();
	Database a = b;
	EXPECT_TRUE(a==b);
}
//---int deleteRows(string fromTable, string whereClause)
TEST(database_deleteRows, invalid_where)
{
	Table t = new Table();
	Database d(t);
	string table = "t";
	string where_input = "I don't exist";
	int a = d.deleteRows(table, where_input)
	EXPECT_EQ(1,a); //Return a 1 for failure
}
TEST(database_deleteRows, invalid_table)
{
	Database d;
	string table = "t";
	string where_input = "I don't exist";
	int a = d.deleteRows(table, where_input)
	EXPECT_EQ(1,a); //Return a 1 for failure
}
TEST(database_deleteRows, invalid_table)
{
	Table t = new Table();
	Type type = INTEGER;
	Attribute a(type, "10");
	t.addColumn(a);
	Database d(t);
	string table = "t";
	string where_input = "type > 5";
	int a = d.deleteRows(table, where_input);
	EXPECT_EQ(0,a); 
}

//---int merge(const Database &d)
TEST(database_merge, merge_success)
{
	Database d;
	int a = merge(d);
	EXPECT_EQ(0,a); 
}

//---int addTable(const Table &t, string name)
TEST(database_addTable, valid_table_name)
{
	Database d;
	Table t = new Table();
	int a = d.addTable(t, "Table 1");
	EXPECT_EQ(0,a); 
}
TEST(database_addTable, duplicate_table_name)
{
	Database d;
	Table t = new Table();
	Table d = new Table();
	int a = d.addTable(t, "Table 1");
	int b = d.addTable(d, "Table 1");
	EXPECT_EQ(1,a); 
}


//--------------------Grant
TEST(database_load, invalidfilename)
{
	Database d;
	int a = d.load("wrong.txt");
	ASSERT_EQ(0, a);
}

TEST(database_load, validfilename)
{
	Database d;
	int a = d.load("correctfilename.txt");
	ASSERT_EQ(1,a);
}

TEST(database_copy, successfulcopy)
{
	Table t;
	Attribute a(INTEGER, "INT");
	t.addColumn(a);
	Database d;
	int a = d.addTable(t, "table1");
	ASSERT_EQ(1,a);
}
TEST(database_copy, file_copy)
{
	Database d;
	int a = d.copy("thisfile.txt");
	ASSERT_EQ(1,a);
}

TEST(database_tableconstruct, createfromtable)
{
	Table t;
	Attribute a("2000/05/03", "bday");
	t.addColumn(a);
	Database(t);
}

TEST(database_tableconstruct, createfrombigtable)
{
	Table t;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	Database(t);
}

//api doesn't specify how to give a table a name if it is created through the Database(const Table &t)
//this test brings that issue to light
TEST(tablequerry, test1)
{
	Table t;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	Database d(t);
	Table c = d.querryTable(*,"",ALL);
}

TEST(tablequerry, test2)
{
	Table t;
	Database d;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	d.addTable(t, "table1")
	Table c = d.querryTable(*,"table1","thisnum"="TIMETIME");
}

TEST(tablequerry, test3)
{
	Table t;
	Database d;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	d.addTable(t, "table1")
	Table c = d.querryTable(*,"table1","thisnum"="TIMETIME");
}

TEST(tablequerry, test4)
{
	Table t;
	Database d;
	Attribute a(2200, "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	d.addTable(t, "table1")
	Table c = d.querryTable(*,"table1","bday"<"thisnum");
}

TEST(tablequerry, test5)
{
	Table t;
	Database d;
	Attribute a(12.67, "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	d.addTable(t, "table1")
	Table c = d.querryTable(*,"table1","bday"<"thisnum");
}

TEST(tablequerry, test6)
{
	Table t;
	Database d;
	Attribute a(12, "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	d.addTable(t, "table1")
	Table c = d.querryTable(*,"table1","bday"<"thisnum");
}
//----------------------Khoa
TEST(database_droptable,dropfail)//1
{
	Database d;
	string a= "table does not exist";
	int a=d.dropTable(a);
	EXPECT_EQ(0, a);


}

TEST(database_droptable,invalidetable)//2
{
	Database d;
	int a=1;
	table invalid;
	vector<Table> tables= d.getTables();
	for(int i =0; i<tabeles.size;i++)
	{
		if(tables[i]==invalid)
			a=0;// table doesn't exist
	}
	EXPECT_EQ(1, a);


}

TEST(database_droptable,tabledropsucess)//1
{
	Database d;
	string a= "real table";
	d(a);
	int a=d.dropTable(a);
	EXPECT_EQ(1, a);


}

TEST(database_droptable,dropfails)//3
{
	Database d;
	int a=d.dropTable("badtable");
	EXPECT_EQ(0, a);


}
TEST(database_droptable,dropsucess)//4
{
	Database d;

	int a=d.dropTable("goodtable");
	EXPECT_EQ(1, a);


}

TEST(string_merge,mergefail)///6
{
	Database d;
	Database c;
	int a=d.merge(c);
	EXPECT_EQ(0, a);


}
TEST(string_merge,mergesucess)
{
	Database d;
	Database c;
	int a=d.merge(c);
	EXPECT_EQ(1, a);


}
TEST(database_updatetable,updatefail)//7
{
	Table t;
	string a="tablename";
	string b="setclause";
	string c= "whereclause";
	int d=t.updateTable(a,b,c);
	EXPECT_EQ(0, d);


}

TEST(database_updatetable,invalidetable)//9
{
	Table t;
	string a="badtable name";
	string b="setclause";
	string c= "whereclause";
	int d=t.updateTable(a,b,c);
	EXPECT_EQ(0, d);


}
TEST(database_updatetable,sucess)
{
	Table t;
	string a="goodtable name";
	string b="setclause";
	string c= "whereclause";
	int d=t.updateTable(a,b,c);
	EXPECT_EQ(1, d);


}
TEST(database_database,invaldatabase)//10
{
	Database d;
	int a= d.Database("invalid data base ");
	EXPECT_EQ(0, d);


}

/*----------------------Table Class-----------------------*/
//----------------------Khoa
TEST(table_renamecolum,sucess)//12
{
	Table t;
	string a="goodtable name";
	string b="new name";
	 
	int d=t.renameColumn(a,b);
	EXPECT_EQ(1, d);


}
TEST(table_renamecolum,invalidcolum)
{
	Table t;
	string a="invalid colum name";
	string b="new name";
	 
	int d=t.renameColumn(a,b);
	EXPECT_EQ(0, d);


}
TEST(table_renamecolum,samecolum)
{
	Table t;
	string a="same";
	string b="same";
	 
	int d=t.renameColumn(a,b);
	EXPECT_EQ(0, d);


}
TEST(table_renamecolum,renamegood)
{
	Table t;
	Attribute a(string,"bob");
	int d = 1;
	 
	t.renameColumn("bob","jim");
	vector<Attribute> A=t.getColumns();
	for(int i=0;i<A.size();i++)
		if(A[0]=="jim")
			d=0;
	EXPECT_EQ(0, d);


}
TEST(table_renamecolum,renamegood)
{
	Table t;
	Attribute a(string,"asdfaesdfsdgf");
	int d = 1;
	 
	t.renameColumn("asdfaesdfsdgf","jim");
	vector<Attribute> A=t.getColumns();
	for(int i=0;i<A.size();i++)
		if(A[0]=="jim")
			d=0;
	EXPECT_EQ(0, d);


}
TEST(table_crossjoin,sucess)//17
{
	Table t;
	Table googd;
	 
	int d=t.crossJoin(t,bad);
	EXPECT_EQ(1, d);


}
TEST(table_crossjoin,invalidtable)
{
	database a;
	table notreal;
	int d=0;
	vector<Table> tablelist=a.getTables();
	for(int i=0;i<tablelist.size();i++)
	{
		
		if(tablelist[i]==notreal)
			d=1;// search the table
	} 
	EXPECT_EQ(0, d);


}
TEST(table_min,realtable)
{
	database a;
	table  t;
	vector<Attribute> columns;
	int min=columns[0];

	for(int i=0; i<columns.size(); i++)
	{
		if(min>columns[i])
			min=columns[i];
	}
	EXPECT_EQ(1, d);


}

TEST(table_vector, invalidinput)
{
	database a;
	table  t;
	vector<int> A;
	t(A);
	EXPECT_EQ(1, d);


}
TEST(table_vector, invalidinput2)//21
{
	database a;
	table  t;
	vector<float> A;
	t(A);
	EXPECT_EQ(1, d);


}  

//----------------------Kira
//---int deleteColumn(string attributeName)
TEST(table_deleteColumn, valid_attribute)
{
	Table t;
	Attribute a(INTEGER, "20");
	string att = "a";
	t.addColumn(a);
	int a = t.deleteColumn(att);
	ASSERT_EQ(0,a);
}
TEST(table_deleteColumn, attribute_not_in_table)
{
	Table t;
	Attribute a(INTEGER, "20");
	string att = "a";
	int a = t.deleteColumn(att);
	ASSERT_EQ(1,a);
}
TEST(table_deleteColumn, two_attribute_in_table)
{
	Table t;
	Attribute a(INTEGER, "20");
	Attribute b(INTEGER, "10");
	string att = "a";
	t.addColumn(a);
	t.addColumn(b);
	int a = t.deleteColumn(att);
	ASSERT_EQ(1,a);
}
TEST(table_deleteColumn, invalid_attribute)
{
	Table t;
	string att = "b";
	int a = t.deleteColumn(att);
	ASSERT_EQ(1,a);
}
//---int setKey(vector<string> attributes)
TEST(table_setKey, valid_attributes)
{
	Table t;
	Attribute a(INTEGER, "20");
	Attribute b(INTEGER, "10");
	Attribute c(INTEGER, "5");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	vector<string> att;
	att.push_back("a");
	att.push_back("b");
	att.push_back("c");
	int a = t.setKey(att);
	ASSERT_EQ(0,a);
}
TEST(table_setKey, invalid_attributes)
{
	Table t;
	vector<string> att;
	att.push_back("a");
	att.push_back("b");
	att.push_back("c");
	int a = t.setKey(att);
	ASSERT_EQ(1,a);
}
//---string sum(string column)
TEST(table_sum, one_attribute)
{
	Table t;
	Attribute a(INTEGER, "20");
	t.addColumn(a);
	int a = t.sum("INTEGER");
	ASSERT_EQ(20,a);
}
TEST(table_sum, two_attribute)
{
	Table t;
	Attribute a(INTEGER, "20");
	Attribute b(INTEGER, "10");
	t.addColumn(a);
	t.addColumn(b);
	int a = t.sum("INTEGER");
	ASSERT_EQ(10,a);
}
TEST(table_sum, two_attribute)
{
	Table t;
	Attribute a(INTEGER, "20");
	Attribute b(INTEGER, "10");
	t.addColumn(a);
	t.addColumn(b);
	int a = t.sum("INTEGER");
	ASSERT_EQ(10,a);
}
TEST(table_sum, three_attribute)
{
	Table t;
	Attribute a(INTEGER, "20");
	Attribute b(INTEGER, "10");
	Attribute b(INTEGER, "30");
	t.addColumn(a);
	t.addColumn(b);
	int a = t.sum("INTEGER");
	ASSERT_EQ(10,a);
}
TEST(table_sum, no_attribute)
{
	Table t;
	int a = t.sum("INTEGER");
	ASSERT_EQ(0,a);
}
TEST(table_sum, null_attribute)
{
	Table t;
	Attribute b(INTEGER, "NULL");
	int a = t.sum("INTEGER");
	ASSERT_EQ(0,a);
}
//---Table()
TEST(table_constructor, table )
{
	Table t;
	Table d = t;
	ASSERT_TRUE(t==d);
}
//---Record& rowAt(int index)
TEST(table_rowAt, valid_record)
{
	Table t;
	string entry = "Weee!";
	vector<string> entries;
	entries.push_back(entry);
	Record r(entries);
	Record w = t.insertRow("Weee!");
	ASSERT_TRUE(r==w);
}
//----------------------Grant
TEST(deleteColumn, deletemanycolumns)
{
	Table t;
	int a;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn(a);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(a);
	ASSERT_EQ(0, a);
	a = t.deleteColumn(a);
	ASSERT_EQ(0, a);
	a = t.deleteColumn(a);
	ASSERT_EQ(0, a);
	a = t.deleteColumn(c);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(b);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(a);
	ASSERT_EQ(0, a);
	a = t.deleteColumn(d);
	ASSERT_EQ(1, a);
}

TEST(deleteColumn, deletegoodcolumns)
{
	Table t;
	int a;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn(a);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(b);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(c);
	ASSERT_EQ(1, a);
	a = t.deleteColumn(d);
	ASSERT_EQ(1, a);
}

TEST(deleteColumn, deletegoodcolumns)
{
	Table t;
	int a;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn(a);
	ASSERT_EQ(1, a);
	a = t.deleteColumn("bday");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("TIMETIME");
	ASSERT_EQ(1, a);
	a = t.deleteColumn(d);
	ASSERT_EQ(1, a);
}

TEST(deleteColumn, deleteMOREcolumns)
{
	Table t;
	int a;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn(a);
	ASSERT_EQ(1, a);
	a = t.deleteColumn("thisstring");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("thisnum");
	ASSERT_EQ(1, a);
	a = t.deleteColumn(d);
	ASSERT_EQ(1, a);
}

TEST(deleteColumn, deletemoreStringcolumns)
{
	Table t;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	Attribute e("2110/06/12", "lanparty");
	Attribute f(90485.44, "double");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn(e);
	ASSERT_EQ(1, a);
	a = t.deleteColumn("bday");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("TIMETIME");
	ASSERT_EQ(1, a);
	a = t.deleteColumn(f);
	ASSERT_EQ(1, a);
}

TEST(deleteColumn, deletegoodcolumns)
{
	Table t;
	int a;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	Attribute e("2110/06/12", "lanparty");
	Attribute f(90485.44, "double");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	a = t.deleteColumn("thisnum");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("bday");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("double");
	ASSERT_EQ(1, a);
	a = t.deleteColumn("thisnum");
	ASSERT_EQ(0, a);
}

TEST(setkey, setgoodkey)
{
	Table t;
	int a;
	vector<Attribute> v;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	Attribute e("2110/06/12", "lanparty");
	Attribute f(90485.44, "double");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	v.push_Back(a);
	v.push_Back(b);
	v.push_Back(c);
	v.push_Back(d);
	a = t.setKey(v);
	ASSERT_EQ(1, a);
}

TEST(setkey, setbadkey)
{
	Table t;
	vector<Attribute> v;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	Attribute e("2110/06/12", "lanparty");
	Attribute f(90485.44, "double");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(d);
	v.push_Back(a);
	v.push_Back(b);
	v.push_Back(c);
	v.push_Back(d);
	int c = t.setKey(v);
	ASSERT_EQ(0, a);
	
}

TEST(setkey, setgoodandbadkey)
{
	Table t;
	int a;
	vector<Attribute> v;
	Attribute a("2000/05/03", "bday");
	Attribute b(2000, "thisnum");
	Attribute c("asldfa;sdlfas;dlfjhasd;fljahsdgadsfljasdf;jadsfweald", "thisstring");
	Attribute d("05:01:33", "TIMETIME");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	t.addColumn(d);
	v.push_Back(a);
	v.push_Back(b);
	v.push_Back(c);
	v.push_Back(d);
	a = t.setKey(v);
	ASSERT_EQ(1, a);
	Attribute e("2110/06/12", "lanparty");
	Attribute f(90485.44, "double");
	vector<Attribute> x;
	x.push_back(e);
	x.push_back(f);
	a = t.setKey(x);
	ASSERT_EQ(0, a);
}

TEST(checkcount, goodinput)
{
	Table t;
	Attribute a(2000, "thisnum");
	Attribute b(100, "hey");
	Attribute c(200, "as;dlfjgahsdgf");
	t.addColumn(a);
	t.addColumn(b);
	t.addColumn(c);
	int a = t.count("thisnum");
	ASSERT_EQ(1, a);
}

TEST(checkRow, row1)
{
	Table t;
	t.insertRow("val1");
	t.insertRow("val2");
	t.insertRow("val3");
	int a = t.getNumberOfRows();
	ASSERT_EQ(3,a);
}

TEST(checkRow, row2)
{
	Table t;
	t.insertRow("val1");
	t.insertRow("val2");
	t.insertRow("val3");
	t.insertRow("val4");
	t.insertRow("val5");
	t.insertRow("val6");
	int a = t.getNumberOfRows();
	ASSERT_EQ(6,a);
}

TEST(checkRow, row2)
{
	Table t;
	t.insertRow("val1");
	t.insertRow("val2");
	t.insertRow("val3");
	t.insertRow("val4");
	t.insertRow("val5");
	t.insertRow("val6");
	t.insertRow("val7");
	t.insertRow("val8");
	t.insertRow("val9");
	int a = t.getNumberOfRows();
	ASSERT_EQ(9,a);
}

/*----------------------Record Class-----------------------*/
//----------------------Khoa
TEST(record, invalidinput)
{
	vector<int> entries;
	Record(entries);
	EXPECT_EQ(1, d);


}
TEST(record, invalidinput)
{
	vector<float> entries;
	Record(entries);
	EXPECT_EQ(1, d);


}

TEST(record, invalidinput)
{
	vector<vector<char>> entries;
	Record(entries);
	EXPECT_EQ(1, d);


}
TEST(record, invalidinput)
{
	vector<vector<int>> entries;
	Record(entries);
	EXPECT_EQ(1, d);


}

//----------------------Kira
//---string& elementAt(int index)
TEST(record_elementAt, valid_index)
{
	vector<string> entries;
	entries.push_back("Hey");
	entries.push_back("Wow");
	Record r(entries);
	ASSERT_STREQ("Hey", 0);
}
TEST(record_elementAt, valid_index)
{
	vector<string> entries;
	entries.push_back("Hey");
	entries.push_back("Wow");
	Record r(entries);
	ASSERT_STREQ("Wow", 1);
}
TEST(record_elementAt, invalid_index)
{
	vector<string> entries;
	entries.push_back("Hey");
	entries.push_back("Wow");
	Record r(entries);
	ASSERT_STRNE("Wow", 3);
}
TEST(record_elementAt, wrong_return)
{
	vector<string> entries;
	entries.push_back("Hey");
	entries.push_back("Wow");
	Record r(entries);
	ASSERT_STRNE("Hey", 1);
}


int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
}

//-------------------Cullen (not ordered!)
TEST(attribute_constructor, saves_name)		//1
{
	string a = "fish";
	Attribute b = Attribute(INTEGER, a);
	EXPECT_EQ(a, b.name);
}

TEST(attribute_constructor, saves_wrong_name)	//2
{
	string a = "fish";
	string c = "dog";
	Attribute b = Attribute(INTEGER, c);
	EXPECT_EQ(a, b.name);
}

TEST(attribute_constructor, valid_type_int)	//3
{
	INTEGER A;
	string c = "dog";
	Attribute b = Attribute(INTEGER, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(attribute_constructor, valid_type_float)	//4
{
	FLOAT A;
	string c = "dog";
	Attribute b = Attribute(FLOAT, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(attribute_constructor, valid_type_varstring)	//5
{
	VARSTRING A;
	string c = "dog";
	Attribute b = Attribute(VARSTRING, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(attribute_constructor, valid_type_date)	//6
{
	DATE A;
	string c = "dog";
	Attribute b = Attribute(DATE, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(attribute_constructor, valid_type_time)	//7
{
	TIME A;
	string c = "dog";
	Attribute b = Attribute(TIME, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(attribute_constructor, invalid_type_bool)	//8
{
	bool A;
	string c = "dog";
	Attribute b = Attribute(INTEGER, c);
	EXPECT_EQ(typeid(A), typeid(b.type));
}

TEST(table_naturaljoin, does_not_contain_table_a)	//9
{
	int truth = 1;
	Table A;
	A.addColumn(INTEGER, "blue");
	Table B;
	B.addColumn(INTEGER, "green");

	Table C = naturalJoin(A,B);
	vector<Attribute> v = C.getColumns();
	vector<Attribute> w = A.getColumns();
	for (int i=0; i< w.size(); i++){
		Attribute at1 = w[i];
		for (int j = 0; j < v.size(); j++){
			Attribute at2 = v[j];
			if ((at1.type != at2.type)||(at1.name != at2.name)){
				truth = 0;
			}
		}
	}
	EXPECT_EQ(truth, 1);
}

TEST(table_naturaljoin, does_not_contain_table_b)	//10
{
	int truth = 1;
	Table A;
	A.addColumn(INTEGER, "blue");
	Table B;
	B.addColumn(INTEGER, "green");

	Table C = naturalJoin(A,B);
	vector<Attribute> v = C.getColumns();
	vector<Attribute> w = A.getColumns();
	for (int i=0; i< w.size(); i++){
		Attribute at1 = w[i];
		for (int j = 0; j < v.size(); j++){
			Attribute at2 = v[j];
			if ((at1.type != at2.type)||(at1.name != at2.name)){
				truth = 0;
			}
		}
	}
	EXPECT_EQ(truth, 1);
}

TEST(table_insertRow, row_insertion_error)	//11
{
	int truth = 1;
	Table A;
	string s = "blah blah blah ";
	string z = "";
	A.insertRow(s);

	vector<Attribute> w = A.getColumns();
	for (int i = 0; i < w.size(); i++){
		z += w[i].name;
	}

	if (s != z)
		truth = 0;

	EXPECT_EQ(truth, 1);
}

TEST(table_addcolumn, column_not_at_end_of_list)	//12
{
	int truth = 1;
	Table A;
	A.addColumn(INTEGER, "blue");
	A.addColumn(INTEGER, "green");

	vector<Attribute> w = A.getColumns();

	if (w[w.size()-1].name != "green")
		truth = 0;

	EXPECT_EQ(truth, 1);
}

TEST(table_addcolumn, column_not_added)	//13
{
	int truth = 1;
	Table A;
	truth = A.addColumn(INTEGER, "blue");

	EXPECT_EQ(truth, 1);
}

TEST(database_getTable, runs_successfully)	//14
{
	int truth = 1;
	Database A;
	Table B;

	A.addTable(B);
	vector<Table> t = A.getTables();

	if (t.size() < 1)
		truth = 0;

	EXPECT_EQ(truth, 1);
}

TEST(table_getColumns, attributes_correct)	//15
{
	int truth = 1;
	Table A;

	vector<Attributes> v;
	v.push_back(INTEGER, "blue");
	v.push_back(INTEGER, "green");
	v.push_back(INTEGER, "red");

	for (int i = 0; i < v.size(); i++){
		A.addColumn(v[i]);
	}

	vector<Attributes> w = A.getColumns();

	for (int j = 0; j < w.size(); j++){
		if ((v[j].name != w[j].name) || (v[j].type != w[j].type))
			truth = 0;
	}

	EXPECT_EQ(truth, 1);
}

TEST(table_getColumns, not_all_attributes_listed){	//16
{
	int truth = 1;
	Table A;

	vector<Attributes> v;
	v.push_back(INTEGER, "blue");
	v.push_back(INTEGER, "green");
	v.push_back(INTEGER, "red");

	for (int i = 0; i < v.size(); i++){
		A.addColumn(v[i]);
	}

	vector<Attributes> w = A.getColumns();

	if (w.size() != v.size())
		truth = 0;

	EXPECT_EQ(truth, 1);
}

TEST(database_getTable, incorrect_tables)	//17
{
	int truth = 1;
	Database A;
	Table B;
	Table C;

	vector<Table> g;
	g.push_back(B);
	g.push_back(C);

	A.addTable(B);
	A.addTable(C);

	vector<Table> t = A.getTables();

	for (int i = 0; i < t.size(); i++){
		if (g[i] != t[i])
			truth = 0;
	}

	EXPECT_EQ(truth, 1);
}

TEST(table_max, returns_max){		//18
	int truth = 1;
	Table A;

	vector<Attributes> v;

	Attribute b(VARSTRING, "blue");
	Attribute r(VARSTRING, "red");
	Attribute g(VARSTRING, "green");
	Attribute y(VARSTRING, "yellow");

	v.push_back(b);
	v.push_back(c);
	v.push_back(g);
	v.push_back(y);

	for (int i = 0; i < v.size(); i++){
		A.addColumn(v[i]);
	}

	//add values to column 3

	A[2].push_back(Attribute(VARSTRING, "mango");
	A[2].push_back(Attribute(VARSTRING, "plum");
	A[2].push_back(Attribute(VARSTRING, "purple");
	A[2].push_back(Attribute(VARSTRING, "I hate your api");

	string s = A.max("green");

	string z = A[2][1].name;

	for (int i = 1; i < A[2].size(); i++){
		if (A[2][i].name < z){
			z = A[2][i].name;
		}
	}

	if (z != s)
		truth = 0;

	EXPECT_EQ(truth, 1);
}

Test(database_copy, bad_string){	//19
	int truth = 1;
	
	Database D;
	D.copy("badfilename.txt");

	if (D.getTables().size == 0){
		truth = 0;
	}

	EXPECT_EQ(truth, 1);
}

Test(database_copy, good_string){	//20
	int truth = 1;
	
	Database D;
	D.copy("goodfilename.txt");

	if (D.getTables().size == 0){
		truth = 0;
	}

	EXPECT_EQ(truth, 1);
}

Test(database_save, bad_string){	//21
	int truth = 1;
	
	Database D;
	truth = D.save("badfilename.txt");

	EXPECT_EQ(truth, 1);
}

Test(database_save, good_string){	//22
	int truth = 1;
	
	Database D;
	truth = D.save("goodfilename.txt");

	EXPECT_EQ(truth, 1);
}

Test(database_fromstring, good_string){	//23
	int truth = 1;
	
	truth = Database D("goodfilename.txt");

	EXPECT_EQ(truth, 1);
}

Test(database_fromstring, bad_string){	//24
	int truth = 1;
	
	truth = Database D("badfilename.txt");

	EXPECT_EQ(truth, 1);
}

Test(table_insertrow, successful){	//25
	int truth = 1;
	
	Table t;
	truth = T.insertRow("test string");

	EXPECT_EQ(truth, 1);
}