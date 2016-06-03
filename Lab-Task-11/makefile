#	Makefile for CSC 322 Homework 11

NameAge:		NameAge.o Person.o mystrings.o
		gcc -o NameAge NameAge.o Person.o mystrings.o

mystrings.o:	mystrings.c mystrings.h boolean.h
		gcc -c mystrings.c

Person.o:		Person.c Person.h
		gcc -c Person.c

NameAge.o:		NameAge.c Person.h
		gcc -c NameAge.c