all: main.out

main.out: LesTestsDoubleLinkedList.o DoubleLinkedList.o
	g++ LesTestsDoubleLinkedList.o DoubleLinkedList.o -o main.out

LesTestsDoubleLinkedList.o: DoubleLinkedList.h LesTestsDoubleLinkedList.C
	g++ -c LesTestsDoubleLinkedList.C

DoubleLinkedList.o: DoubleLinkedList.h DoubleLinkedList.C
	g++ -c DoubleLinkedList.C
