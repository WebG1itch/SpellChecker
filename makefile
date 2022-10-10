run: spellChecker
	./spellChecker

spellChecker: main.o SpellChecker.o HashTable.o
	g++ main.o SpellChecker.o HashTable.o -o spellChecker

main.o: main.cpp SpellChecker.h
	g++ -c main.cpp

SpellChecker.o: SpellChecker.cpp SpellChecker.h
	g++ -c SpellChecker.cpp

HashTable.o: HashTable.cpp HashTable.h TimeInterval.h
	g++ -c HashTable.cpp

clean:
	rm -f *.o
	rm spellChecker
