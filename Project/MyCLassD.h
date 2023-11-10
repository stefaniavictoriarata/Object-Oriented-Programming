#pragma once
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

//the class for the elements
class ELEMENTE {

public:
	string value;

	ELEMENTE()
	{
		this->value = "";
	}

	void addElemente(string e)
	{
		this->value = e;

	}

	ELEMENTE& operator=(const ELEMENTE& e)
	{
		if (this != &e)
		{
			this->value = e.value;
		}
		return *this;

	
	}
	

	~ELEMENTE()
	{

	}
};

//the class for the collumns
class COLLUMN: public ELEMENTE
{
public:
	string colName;
	int size;
	string type;
	ELEMENTE* elemente;
	int nr_elemente;
	string index;
	string defaultValue;
	COLLUMN()
	{
		this->size = 0;
		this->colName = "";
		this->type = "";
		this->elemente = new ELEMENTE[10];
		this->nr_elemente = 0;
		this->index = "";
		this->defaultValue = "";
	}

	COLLUMN(string colName, int size, string type)
	{

		this->colName = colName;
		this->type = type;
		this->size = size;
		
	}

	void setSize(int size)
	{
		this->size = size;
	}

	void setColName(string colName)
	{
		this->colName = colName;
		
	}

	void setType(string type)
	{
		this->type = type;
	}

	void addELEMENTE(ELEMENTE &element, int nr_elemente)
	{
		this->elemente[nr_elemente] = element;

	}

	void addNrElemente()
	{
		this->nr_elemente = nr_elemente + 1;
	}
	void addDefault(string s)
	{
		this->defaultValue = s;
	}
	COLLUMN& operator=(const COLLUMN& c)
	{
		if (this  != &c)
		{
			this->index = c.index;
			this->colName = c.colName;
            this->type = c.type;
			this->size = c.size;
			this->nr_elemente = c.nr_elemente;
			this->defaultValue = c.defaultValue;
			for (int i = 0; i < 10; i++)
			{
				this->elemente[i] = c.elemente[i];
			}
		
		}
		return *this;
	}



	~COLLUMN() {
		delete[] elemente;
	}

};

//the class for the table which inherits collumn
class TABLE : public COLLUMN
{
public:
	string tableName;
	COLLUMN* coloana;
	int nrofCollumns;

	TABLE()
	{
		this->tableName = "";
		this->nrofCollumns = 0;
		this->coloana = new COLLUMN[10];
		
	
		
	}
	

	void addCOLLUMNS(COLLUMN &coloana_noua,int nrofCollumns)
	{
		
			this->coloana[nrofCollumns]=coloana_noua;
			
		
	}

	TABLE(string tableName, int nrofCollumns)
	{
		this->tableName = tableName;
		

		this->nrofCollumns = nrofCollumns;
		
	}
	void setTabelName(string tableName)
	{
		this->tableName = tableName;
	}

	void addColoane()
	{
		this->nrofCollumns = nrofCollumns+1;

	}

	void delNrOfCollumns()
	{
		this->nrofCollumns = nrofCollumns - 1;
	}

 string getTableName()
	{
		return this->tableName;
	}
 

	~TABLE()
	{
		
		
	}
};

//the class that contains all tables created, which inherits table
class ALLTables:TABLE {
public:
	TABLE* tabele;
	int nrOfTables;

	ALLTables()
	{
		this->nrOfTables = 0;
		this->tabele = new TABLE[10];

	}

	bool tableVerification(string numeTabel)
	{
		int ok = 0;
		for (int i = 0; i < nrOfTables; i++)
		{
			if (tabele[i].tableName == numeTabel)
				ok++;

		}
		if (ok == 0)
			return true;
		else
			return false;
	}

	void addNewTable(TABLE &tabel1,int nrOfTables)
	{
		
		
			this->tabele[nrOfTables] = tabel1;
		
		
	}

	void delNrofTables()
	{
		this->nrOfTables= nrOfTables - 1;
	}

	TABLE getTable(int nrOfTables)
	{
		return tabele[nrOfTables];
	}
	void addTables()
	{
		this->nrOfTables = nrOfTables + 1;
	}

	void writeDataBase()
	{
		ofstream fwrite("listOfTables.txt");
		
		for (int j = 0; j < nrOfTables; j++)
		{
			ofstream fout(this->tabele[j].tableName);

			fout << this->tabele[j].tableName << endl;

			fout << this->tabele[j].nrofCollumns << endl;

			for (int i = 0; i < this->tabele[j].nrofCollumns; i++)
			{
				fout << this->tabele[j].coloana[i].type << " ";
			}
			fout << endl;


			for (int i = 0; i < this->tabele[j].nrofCollumns; i++)
			{
				fout << this->tabele[j].coloana[i].size << " ";
			}
			fout << endl;

			for (int i = 0; i < this->tabele[j].nrofCollumns; i++)
			{
				fout << this->tabele[j].coloana[i].colName << " ";
			}
			fout << endl;

			
			
				fout << this->tabele[j].coloana[0].nr_elemente << endl;
			
			

			for (int z = 0; z < this->tabele[j].coloana[0].nr_elemente; z++)
			{

				for (int n = 0; n < this->tabele[j].nrofCollumns; n++)
				{

					fout << this->tabele[j].coloana[n].elemente[z].value << " ";

				}
				fout << endl;
			}
			
			for (int i = 0; i < this->tabele[j].nrofCollumns; i++)
			{
				fout << this->tabele[j].coloana[i].defaultValue << " ";
			}
			fout << endl;
			fwrite << tabele[j].tableName << endl;

			fout.close();
		}
		fwrite.close();
	}

	void copyExistingTable(string fileName,int numberOfTabel)
	{
		ifstream fin(fileName);

		TABLE tabelNou;
		
		fin >> tabelNou.tableName;

		fin >> tabelNou.nrofCollumns;

		for (int i = 0; i < tabelNou.nrofCollumns; i++)
		{
			fin >> tabelNou.coloana[i].type;
		}

		for (int i = 0; i < tabelNou.nrofCollumns; i++)
		{
			fin >> tabelNou.coloana[i].size;
		}

		for (int i = 0; i < tabelNou.nrofCollumns; i++)
		{
			fin >> tabelNou.coloana[i].colName;
		}

		fin >> tabelNou.coloana[0].nr_elemente;
		int nr_nou = tabelNou.coloana[0].nr_elemente;
		for (int i = 0; i < tabelNou.nrofCollumns; i++)
		{
			tabelNou.coloana[i].nr_elemente = nr_nou;
		}
		if (nr_nou != 0)
		{
			for (int z = 0; z < tabelNou.coloana[0].nr_elemente; z++)
			{

				for (int n = 0; n < tabelNou.nrofCollumns; n++)
				{

					fin >> tabelNou.coloana[n].elemente[z].value ;

				}
				
			}
		}

		for (int i = 0; i < tabelNou.nrofCollumns; i++)
		{
			fin >> tabelNou.coloana[i].defaultValue;
		
		}
		tabele[numberOfTabel] = tabelNou;
		fin.close();
	}

	void readDataBase()
	{
		ifstream fRead("listOfTables.txt");

		if (!fRead)
		{
			return;
		}
		//table name
		string s;

		//nr of tables is set to 0
		this->nrOfTables = 0;
		
		while (fRead >> s)
		{
			copyExistingTable(s,this->nrOfTables);
			this->nrOfTables++;
		}

		fRead.close();

	}

	void deleteDataBase()
	{
		ifstream iread("listOfTables.txt");

		string s;

		while (iread >> s)
		{
			if (remove(s.c_str()))
				cout << "file " << s << " has been deleted"<<endl;
		}

		iread.close();

		if (remove("listOfTables.txt"))
		{
			cout << "listOfTables.txt has been deleted"<<endl;
		}
	}
	
		
	~ALLTables() {
		delete[] tabele;
	}



};

bool verifParantezeCreateIndexSauInsertInto(string command) {
	int ok;
	if (command.front() == '(' && command.back() == ')') {
		ok = true;
	}
	else
		ok = false;
	return ok;
}



//structura ((x,y,z,c),...,(a,b,c,d))
//verif prima data daca parantezele mici contin 3 virgule structura (x,y,z,c)
bool verifParantezeMiciCreateTable(string command) {
	int ok = false;
	int l = command.length();
	if (command.front() == '(' && command.back() == ')') {
		int count = 0;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == ',') {
				count++;
			}
		}
		if (count == 3) {
			ok = true;
		}
	}
	return ok;
}

//verif paranteze comanda create table structura ((x,y,z,c),...,(a,b,c,d))
bool verifParantezeCreateTable(string command) {
	int ok = false;
	string commandCopy = command;
	if (command.front() == '(' && command.back() == ')') {
		if (command.at(1) == '(') {
			int pos = 3;
			pos = command.find('(', pos);
			if (pos == -1) {
				int pos1 = command.find(')');
				string str = command.substr(1, pos1);
				ok = verifParantezeMiciCreateTable(str);
			}
			else {
				pos = 0;
				while (pos >= 0) {
					pos = command.find(')');
					string str = command.substr(1, pos);
					command = command.substr(pos + 1);
					ok = verifParantezeMiciCreateTable(str);
					pos = command.find(',');
				}
			}

		}


	}
	commandCopy.pop_back();
	if (commandCopy.back() != ')') {
		ok = false;
	}

	return ok;
}



char* lower(char comanda[])
{
	for (int i = 0; comanda[i] != NULL; i++)
	{
		comanda[i] = tolower(comanda[i]);
	}

	return comanda;
}



//function for validating and using the commands
void findMyCommand(char* command, ALLTables& database)
{
	string s;
	char* next_token;
	char* secCommand = strtok_s(command, " ", &next_token);
	//Create - command
	if (secCommand != NULL && strcmp(lower(secCommand), "create") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);

		if (secCommand != NULL && strcmp(lower(secCommand), "table") == 0)
		{
			//the table's name
			secCommand = strtok_s(NULL, " ", &next_token);
			//verify if the table's name is not null
			if (secCommand != NULL)
			{
				//transform the char into a string
				s = lower(secCommand);
				//verify if the table's name is not already in the database
				if (database.tableVerification(secCommand))
				{
					string paranthesis = next_token;
					if (verifParantezeCreateTable(paranthesis))
					{ //we make a local object of TABLE class
						TABLE tabel1;
						tabel1.setTabelName(s);
						secCommand = strtok_s(NULL, " ,()", &next_token);

						while (secCommand)
						{
							//we create a local object of COLLUMN class
							COLLUMN coloana1;
							//here we must introuce at least 1 collumn to the table


							//column name

							s = lower(secCommand);

							coloana1.setColName(s);//setter for collumn name

							//type of collumn
							secCommand = strtok_s(NULL, " ,()", &next_token);

							s = lower(secCommand);
							coloana1.setType(s);//setter for type

							//size
							secCommand = strtok_s(NULL, " ,()", &next_token);
							int x = atoi(secCommand);

							coloana1.setSize(x);//setter for size

							//default value
							secCommand = strtok_s(NULL, " ,()", &next_token);
							s = lower(secCommand);
							coloana1.addDefault(s);
							ELEMENTE element1;
							element1.addElemente(s);
							for (int i = 0; i < 10; i++)
							{
								coloana1.addELEMENTE(element1, i);
							}

							//here we copy the collumn into the table
							tabel1.addCOLLUMNS(coloana1, tabel1.nrofCollumns);
							tabel1.addColoane();

							secCommand = strtok_s(NULL, " ,()", &next_token);
						}
						//here we copy the table into the database
						database.addNewTable(tabel1, database.nrOfTables);
						database.addTables();
						cout << "Table " << tabel1.tableName << " has been created" << endl;
					}
					else
					{
						cout << "The values are not inserted correctly" << endl;
					}
				}
				else
				{
					cout << "The table's name is already in the database" << endl;

					//the table's name is already in the database
				}



			}
			else {
				cout << "there is no input"<<endl;
			}
		}
		else if (secCommand != NULL && strcmp(lower(secCommand), "index") == 0)
		{
			//index name

			secCommand = strtok_s(NULL, " ", &next_token);
			string indexName = lower(secCommand);
			int ok = 0;
			for (int i = 0; i < database.nrOfTables; i++)
			{
				for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
				{
					if (database.tabele[i].coloana[j].index == indexName)
					{
						ok++;
					}

				}
			}
			if (ok == 0)
			{
				secCommand = strtok_s(NULL, " ", &next_token);
				if (secCommand != NULL && strcmp(lower(secCommand), "on") == 0)
				{
					//tablename
					secCommand = strtok_s(NULL, " ", &next_token);
					s = lower(secCommand);

					for (int z = 0; z < database.nrOfTables; z++)
					{
						if (s == database.tabele[z].tableName)
						{
							string paranthesis = next_token;
							if (verifParantezeCreateIndexSauInsertInto(paranthesis))
							{
								secCommand = strtok_s(NULL, " ()", &next_token);
								s = lower(secCommand);
								for (int n = 0; n < database.tabele[z].nrofCollumns; n++)
								{
									if (s == database.tabele[z].coloana[n].colName)
									{
										database.tabele[z].coloana[n].index = indexName;
										cout << "inedx created for column: " << database.tabele[z].coloana[n].colName << endl;
									}
								}
							}
							else
							{
								cout << "missing paranthesis" << endl;
							}
						}
						else
						{
							cout << "table name not found" << endl;
						}
					}

				}
				else
				{
					cout << "there is no on" << endl;
				}

			}
			else
			{
				cout << " the collumn has an index already" << endl;
			}


		}
		//wrong input case
		else
		{
		cout << " create command wrong format" << endl;

		}
	}//drop - command
	else if (secCommand != NULL && strcmp(lower(secCommand), "drop") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);

		if (secCommand != NULL && strcmp(lower(secCommand), "table") == 0)
		{
			secCommand = strtok_s(NULL, " ", &next_token);//table name
			s = lower(secCommand);
			int ok = 0;
			int found = 0;
			TABLE tabel2;
			for (int i = 0; i < database.nrOfTables; i++)
			{
				if (database.tabele[i].tableName == s)
				{
					if (i == database.nrOfTables - 1)
					{
						database.tabele[i] = tabel2;
						database.delNrofTables();
						i--;
						found++;
					}
					else
					{
						for (int j = i; j < database.nrOfTables - 1; j++)
						{
							database.tabele[j] = database.tabele[j + 1];
						}
						database.delNrofTables();
						i--;
						found++;
					}
					database.tabele[database.nrOfTables + 1] = tabel2;
				}
			}

			if (found)
			{
				cout << "Element has been deleted" << endl;
			}
			else
			{
				cout << "Element not found";
			}

		}
		else if (secCommand != NULL && strcmp(lower(secCommand), "index") == 0)
		{
			//index name
			secCommand = strtok_s(NULL, " ", &next_token);
			s = lower(secCommand);

			for (int i = 0; i < database.nrOfTables; i++)
			{
				for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
				{
					if (database.tabele[i].coloana[j].index == s)
					{
						database.tabele[i].coloana[j].index = "";
						cout << "index deleted" << endl;
					}

				}
			}


		}
		//wrong input case
		else {

		}

	}

	//display - command
	else if (secCommand != NULL && strcmp(lower(secCommand), "display") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);
		if (secCommand != NULL && strcmp(lower(secCommand), "table") == 0)
		{
			//table name
			secCommand = strtok_s(NULL, " ", &next_token);
			s = lower(secCommand);
			for (int i = 0; i < database.nrOfTables; i++)
			{
				if (s == database.tabele[i].tableName)
				{
					cout << " id ";
					for (int m = 0; m < 6; m++)
					{
						cout << " ";
					}
					for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
					{
						cout << database.tabele[i].coloana[j].colName;
						int l = database.tabele[i].coloana[j].colName.length();
						for (int m = 0; m < 25 - l; m++)
						{
							cout << " ";
						}

					}
					cout <<"\n\n";
					for (int z = 0; z < database.tabele[i].coloana[0].nr_elemente; z++)
					{
						cout << " " << z+1 << " ";
						for (int m = 0; m < 7; m++)
						{
							cout << " ";
						}
						for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
						{
							
							cout << database.tabele[i].coloana[j].elemente[z].value;
							int l = database.tabele[i].coloana[j].elemente[z].value.length();
							for (int m = 0; m < 25 - l; m++)
							{
								cout << " ";
							}
						}
						cout << endl;
					}
				}
			}

		}
		//wrong input case
		else
		{

		}

	}
	else if (secCommand != NULL && strcmp(lower(secCommand), "delete") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);

		if (secCommand != NULL && strcmp(lower(secCommand), "from") == 0)
		{
			//table name
			secCommand = strtok_s(NULL, " ", &next_token);
			s = lower(secCommand);
			for (int i = 0; i < database.nrOfTables; i++)
			{
				if (database.tabele[i].tableName == s)
				{
					secCommand = strtok_s(NULL, " ", &next_token);
					if (secCommand != NULL && strcmp(lower(secCommand), "where") == 0)
					{
						secCommand = strtok_s(NULL, " ", &next_token);
						if (secCommand != NULL && strcmp(lower(secCommand), "column_name") == 0)
						{
							secCommand = strtok_s(NULL, " ", &next_token);
							if (secCommand != NULL && strcmp(lower(secCommand), "=") == 0)
							{
								secCommand = strtok_s(NULL, " ", &next_token);
								s = lower(secCommand);
								COLLUMN coloana2;
								int found = 0;
								for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
								{
									if (s == database.tabele[i].coloana[j].colName)
									{
										if (j == database.tabele[i].nrofCollumns - 1)
										{
											database.tabele[i].coloana[j] = coloana2;
											database.tabele[i].delNrOfCollumns();
											i--;
											found++;
										}
										else
										{
											for (int k = j; k < database.tabele[i].nrofCollumns - 1; k++)
											{
												database.tabele[i].coloana[k] = database.tabele[i].coloana[k + 1];
											}
											database.tabele[i].delNrOfCollumns();
											j--;
											found++;
										}

										database.tabele[i].coloana[database.tabele[i].nrofCollumns] = coloana2;
									}
								}
								if (found)
								{
									cout << "Element has been deleted" << endl;
								}
								else
								{
									cout << "Element not found" << endl;
								}
							}
							else
							{
								cout << "wrong sign" << endl;
							}
						}
						else
						{
							cout << "wrong collumn name" << endl;
						}
					}
					else
					{
						cout << "wrong where clause" << endl;
					}

				}
			}
		}

		else
		{
			cout << "there is no from" << endl;
		}
	}

	else if (secCommand != NULL && strcmp(lower(secCommand), "insert") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);
		if (secCommand != NULL && strcmp(lower(secCommand), "into") == 0)
		{
			secCommand = strtok_s(NULL, " ", &next_token);
			s = lower(secCommand);
			string paranthesis = next_token;
			if (verifParantezeCreateIndexSauInsertInto(paranthesis))
			{
				for (int i = 0; i < database.nrOfTables; i++)
				{
					if (s == database.tabele[i].tableName)
					{
						for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
						{
							secCommand = strtok_s(NULL, " ,()", &next_token);
							s = lower(secCommand);

							database.tabele[i].coloana[j].elemente[database.tabele[i].coloana[j].nr_elemente].value = s;
							database.tabele[i].coloana[j].addNrElemente();
						}
					}
				}
			}
			else
			{
				cout << "missing paranthesis" << endl;
			}
		}



	}
	else if (secCommand != NULL && strcmp(lower(secCommand), "update") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);
		s = lower(secCommand);
		for (int i = 0; i < database.nrOfTables; i++)
		{
			if (s == database.tabele[i].tableName)
			{
				secCommand = strtok_s(NULL, " ", &next_token);
				s = lower(secCommand);
				if (secCommand != NULL && strcmp(lower(secCommand), "set") == 0)
				{
					secCommand = strtok_s(NULL, " ", &next_token);
					s = lower(secCommand);
					if (secCommand != NULL && strcmp(lower(secCommand), "column_name") == 0)
					{
						secCommand = strtok_s(NULL, " ", &next_token);
						s = lower(secCommand);
						if (secCommand != NULL && strcmp(lower(secCommand), "=") == 0)
						{
							secCommand = strtok_s(NULL, " ", &next_token);
							s = lower(secCommand);
							//new collum name
							string newName = s;
							//where clause
							secCommand = strtok_s(NULL, " ", &next_token);
							s = lower(secCommand);
							if (secCommand != NULL && strcmp(lower(secCommand), "where") == 0)
							{
								secCommand = strtok_s(NULL, " ", &next_token);
								s = lower(secCommand);
								if (secCommand != NULL && strcmp(lower(secCommand), "column_name") == 0)
								{
									secCommand = strtok_s(NULL, " ", &next_token);
									s = lower(secCommand);
									if (secCommand != NULL && strcmp(lower(secCommand), "=") == 0)
									{
										//collumn name that must be changed
										secCommand = strtok_s(NULL, " ", &next_token);
										s = lower(secCommand);
										for (int i = 0; i < database.nrOfTables; i++)
										{
											for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
											{
												if (s == database.tabele[i].coloana[j].colName)
												{
													database.tabele[i].coloana[j].colName = newName;
												}

											}
										}


									}
									else
									{
										cout << "there is no = sign" << endl;
									}
								}
								else
								{
									cout << "there is no column_name" << endl;
								}

							}
							else
							{
								cout << "there is no where clause" << endl;
							}


						}
						else
							cout << "there is no = sign" << endl;
					}
					else
					{
						cout << "column_name is not writen correctly" << endl;
					}
				}
				else
				{
					cout << "there is no set clause" << endl;
				}

			}
			else
			{
				cout << "table name not found";
			}
		}


	}
	else if (secCommand != NULL && strcmp(lower(secCommand), "select") == 0)
	{
	
	secCommand = strtok_s(NULL, " ,()", &next_token);
	if (secCommand != NULL && strcmp(lower(secCommand), "all") != 0)
	{
		int nr_col = 0;
		int cols[10];
		for (int i = 0; i < 10; i++)
			cols[i] = 0;
		while (secCommand != NULL && strcmp(lower(secCommand), "from") != 0)
		{
			//collumn name
			
			s = lower(secCommand);
			for (int i = 0; i < database.nrOfTables; i++)
			{
				for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
				{
					if (database.tabele[i].coloana[j].colName == s)
					{
                     cols[j]++;
					}
				}
			}
			secCommand = strtok_s(NULL, " ,()", &next_token);
		}

		if (secCommand != NULL && strcmp(lower(secCommand), "from") == 0)
		{
			//table name
			secCommand = strtok_s(NULL, " ,()", &next_token);
			s = lower(secCommand);
			for (int i = 0; i < database.nrOfTables; i++)
			{
				if (database.tabele[i].tableName == s)
				{
					secCommand = strtok_s(NULL, " ", &next_token);
					if (secCommand!=NULL && strcmp(lower(secCommand), "where") == 0)
					{
						secCommand = strtok_s(NULL, " ", &next_token);
						if (secCommand != NULL && strcmp(lower(secCommand), "id") == 0)
						{
							secCommand = strtok_s(NULL, " ", &next_token);
							if (secCommand != NULL && strcmp(lower(secCommand), "=") == 0)
							{
								//id value
								secCommand = strtok_s(NULL, " ", &next_token);
								int id = atoi(secCommand);

								cout << " id ";
								for (int m = 0; m < 6; m++)
								{
									cout << " ";
								}
								for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
								{
									if (cols[j] == 1)
									{
										cout << database.tabele[i].coloana[j].colName;
										int l = database.tabele[i].coloana[j].colName.length();
										for (int m = 0; m < 25 - l; m++)
										{
											cout << " ";
										}
									}

								}
								cout << "\n\n";
								
								
									cout << " " << id << " ";
									for (int m = 0; m < 7; m++)
									{
										cout << " ";
									}
									for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
									{
										if (cols[j] == 1)
										{
											cout << database.tabele[i].coloana[j].elemente[id-1].value;
											int l = database.tabele[i].coloana[j].elemente[id-1].value.length();
											for (int m = 0; m < 25 - l; m++)
											{
												cout << " ";
											}
										}
									}
									cout << endl;
								


							}
							else
							{
								cout << "there is no = sign" << endl;
							}
						}
						else
						{
							cout << "there is no id" << endl;
						}
					}
					else 
					{

						cout << " id ";
						for (int m = 0; m < 6; m++)
						{
							cout << " ";
						}
						for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
						{
							if (cols[j] == 1)
							{
								cout << database.tabele[i].coloana[j].colName;
								int l = database.tabele[i].coloana[j].colName.length();
								for (int m = 0; m < 25 - l; m++)
								{
									cout << " ";
								}
							}
							
						}
						cout << "\n\n";
						for (int z = 0; z < database.tabele[i].coloana[0].nr_elemente; z++)
						{
							cout << " " << z+1 << " ";
							for (int m = 0; m < 7; m++)
							{
								cout << " ";
							}
							for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
							{
								if (cols[j] == 1)
								{
									cout << database.tabele[i].coloana[j].elemente[z].value;
									int l = database.tabele[i].coloana[j].elemente[z].value.length();
									for (int m = 0; m < 25 - l; m++)
									{
										cout << " ";
									}
								}
							}
							cout << endl;
						}
					}
				}
				else
				{
				cout << "there is no such table" << endl;
 }

			}
		}




	}
	else if (secCommand != NULL && strcmp(lower(secCommand), "all") == 0)
	{
	secCommand = strtok_s(NULL, " ,()", &next_token);
	if (secCommand != NULL && strcmp(lower(secCommand), "from") == 0)
	{
		secCommand = strtok_s(NULL, " ,()", &next_token);
		s = lower(secCommand);
		for (int i = 0; i < database.nrOfTables; i++)
		{
			if (database.tabele[i].tableName == s)
			{
				secCommand = strtok_s(NULL, " ", &next_token);
				if (secCommand != NULL && strcmp(lower(secCommand), "where") == 0)
				{
					secCommand = strtok_s(NULL, " ", &next_token);
					if (secCommand != NULL && strcmp(lower(secCommand), "id") == 0)
					{
						secCommand = strtok_s(NULL, " ", &next_token);
						if (secCommand != NULL && strcmp(lower(secCommand), "=") == 0)
						{
							//id value
							secCommand = strtok_s(NULL, " ", &next_token);
							int id = atoi(secCommand);

							cout << " id ";
							for (int m = 0; m < 6; m++)
							{
								cout << " ";
							}
							for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
							{
								
								
									cout << database.tabele[i].coloana[j].colName;
									int l = database.tabele[i].coloana[j].colName.length();
									for (int m = 0; m < 25 - l; m++)
									{
										cout << " ";
									}
								

							}
							cout << "\n\n";


							cout << " " << id << " ";
							for (int m = 0; m < 7; m++)
							{
								cout << " ";
							}
							for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
							{
								
								
									cout << database.tabele[i].coloana[j].elemente[id - 1].value;
									int l = database.tabele[i].coloana[j].elemente[id - 1].value.length();
									for (int m = 0; m < 25 - l; m++)
									{
										cout << " ";
									}
								
							}
							cout << endl;



						}
						else
						{
							cout << "there is no = sign" << endl;
						}
					}
					else
					{
						cout << "there is no id" << endl;
					}
				}
				else
				{

					cout << " id ";
					for (int m = 0; m < 6; m++)
					{
						cout << " ";
					}
					for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
					{
						
						
							cout << database.tabele[i].coloana[j].colName;
							int l = database.tabele[i].coloana[j].colName.length();
							for (int m = 0; m < 25 - l; m++)
							{
								cout << " ";
							}
						

					}
					cout << "\n\n";
					for (int z = 0; z < database.tabele[i].coloana[0].nr_elemente; z++)
					{
						cout << " " << z + 1 << " ";
						for (int m = 0; m < 7; m++)
						{
							cout << " ";
						}
						for (int j = 0; j < database.tabele[i].nrofCollumns; j++)
						{
							
							
								cout << database.tabele[i].coloana[j].elemente[z].value;
								int l = database.tabele[i].coloana[j].elemente[z].value.length();
								for (int m = 0; m < 25 - l; m++)
								{
									cout << " ";
								}
							
						}
						cout << endl;
					}
				}
			}
			else
			{
				cout << "there is no such table" << endl;
			}

		}


	}
	else
	{
		cout << "there is no from"<<endl;
	}

 }

 }
	else
	cout << "Wrong input" << endl;
 }

	

