#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;

class Player
{

	private:

		string name;
		int wins;
		int losses;
		int draws;

	public:

		Player(string name);
		string getname();
		string getThrow();
		double getRecord();
		int getwins();
		int getlosses();
		int getdraws();
		void youwon();
		string tostring();
		void addwins();
		void addlosses();
		void adddraw();
};
