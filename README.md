# MAZEBOARD

#include<iostream>
#include<fstream>
#include<conio.h> 


using namespace std;


int main()

{
	
	
	
	ofstream file_;
	
	
    
	file_.open("mazeboard mania!\n");
	file_<<"Welcome to DBMS Mazeboard Mania!!! By Group 1\n "  <<endl;
	
	file_<<"Names: Joddian Allen, Bryanna Chang, Schana Beckford,\n";
	file_<<" Gerard Francis, Mark Dennis, Garson Anglin,\n"; 
	file_<< "Christopher Howe, Shanika Ferguson,  \n" <<endl;	

	file_<<"About our game: Our Mazeboard mania program is a simple interactive game that test the player memory when played with the intention for the user to navigate from one room at a time to find the exit point. This program was created using the C++ object-oriented programing language to establish the necessary functions that is needed to create the maze effect and its functions.  \n";
	file_<<"Instructions: The objective of DBMS Mazeboard Mania! is to navigate from one room,(R1-R8) in order o find the exit of the maze\n ";
	file_.close();
	std::cin.get();
	return(0);
}
