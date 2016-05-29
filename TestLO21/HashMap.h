#pragma once
#include "Litterale.h"
#include"ComputerException.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

const int TABLE_SIZE = 128;

class HashEntry {
private:
	string key;
	Litterale* value;
public:
	HashEntry(string key, Litterale* value) : key(key), value(value) {};

	string getKey() {
		return key;
	}

	Litterale* getValue() {
		return value;
	}
};

class HashMap {
private:
	HashEntry **table;
public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	Litterale* get(string key) {
		int hash = 0;
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1);
		if (table[hash] == NULL)
			throw ComputerException("Aucune valeur trouvé pour cet identifiant\n");
		else
			return table[hash]->getValue();
	}

	void put(string key, Litterale* value) {
		int hash = 0;
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1);
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
};