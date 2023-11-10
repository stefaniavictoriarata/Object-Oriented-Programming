#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include <fstream>
#include <istream>
#include "MyCLass.h"
using namespace std;






int main()
{
	char command[200];
	
	ALLTables database;
	

	database.readDataBase();
	database.deleteDataBase();
	//THESE ARE COMMANDS VERIFIED THAT WORK
	
	
	//create table tabelnou ((masini,text,20,logan),(clienti,text,10,marcel),(venit_lunar,text,10,pensie))
	
	//delete from tabelnou where column_name = clienti
	
	//insert into tabelnou (mercedes,danut,salariu)
	
	//insert into tabelnou (toyota,ion,bitcoin)
	
	//display table tabelnou
	
	//update tabelnou set column_name = masini_sport where column_name = masini
	
	//create index coloana_cool on tabelnou (masini)
	
	//drop index coloana_cool
	
	//select masini_sport from tabelnou where id = 1
	
	//select all from tabelnou where id = 2

	//PHASE 2
	//command file - a file which contains the commands

	//each table will have a separate file ( named after the table name ) 

	//an additional file that stores all the table names

	//here is a loop where we can introduce commands an modify the database
	while (strcmp(command, "quit") != 0)
	{
		cin.getline(command, 200);
		if(strcmp(command, "quit") != 0)
		findMyCommand(command, database);
	
	}
	

	if (database.nrOfTables != 0)
	{
		database.writeDataBase();
	}

	

	
	//HOW IT WORKS
	//I created 4 classes that stores all the tables(with all their values) in the AllTables class(database)
	//ALl classes:
	//ALLTables
	//TABLE
	//COLLUMN
	//ELEMENTE
	//by compiling the program there is a loop where u insert commands 1 by 1 an therefore modyfy the database variable

	//MENTIONS
	//The project works just fine for commands that are written correctly( I couldn't manage to create 
	//a function that verify if the input between paranthesis is correct) 
	//there is still a lot of work to do,but we are working on it
	//sorry for not being able to complete phase 1 entirely by the deadline

} 