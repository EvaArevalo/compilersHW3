#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOL_TABLE_SIZE 400

class SymbolTableEntry {
public:
	std::string id;
	int scope;
	int offset;
};

class SymbolTable {

public:

	SymbolTableEntry table[SYMBOL_TABLE_SIZE];
	int cur_counter=0;
	int cur_scope=0;

	SymbolTable() {
		cur_counter = 0;
		cur_scope = 0;
	}

	void installSymbol(char* a, int offset) 
	{
		if (cur_counter >= SYMBOL_TABLE_SIZE) {
			err("Symbol Table Full");
		}
		else {
			table[cur_counter].scope = cur_scope;
			table[cur_counter].id = a;
			table[cur_counter].offset = offset;
			cur_counter++;
		}
	}

	int lookupSymbol(char a[])
	{
		if (cur_counter == 0) {
			return -1;
		} 
		for (int i = cur_counter - 1; i >= 0; i--) {
			if (a == table[i].id)
				return i;
		}
		return -1;
	}

	int popSymbol() 
	{
		int i;
		int pop_count = 0;
		if (cur_counter == 0) 
			return 0;
		for (i = cur_counter - 1; i >= 0; i--) {
			if (table[i].scope != cur_scope) 
				break;
			pop_count ++;
		}
		cur_counter = i + 1;
		return pop_count;
	}

	void updateScope(int scope) 
	{
		cur_scope = scope;
	}

};