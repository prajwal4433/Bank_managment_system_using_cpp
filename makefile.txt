out: main.o accounts.o transactions.o file_operations.o search.o
	g++ main.o accounts.o transactions.o file_operations.o search.o -o out

main.o: main.cpp
	g++ -c main.cpp

accounts.o: accounts.cpp
	g++ -c accounts.cpp

transactions.o: transactions.cpp
	g++ -c transactions.cpp

file_operations.o: file_operations.cpp
	g++ -c file_operations.cpp

search.o: search.cpp
	g++ -c search.cpp

clean:
	rm -f *.o out

