#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include "Player.h"
// added player already in players vector, returned error, added new player, quit program and it all worked well.
// added player to lineup not in players vector, repromted, added player from players vector, added another from players vector, returned draw and added to the thing.
// showed empty lineup, tried to fight with no players, reprompted.
 
using namespace std;

void addplayer(vector<Player*> & allplayers)
{
	string name_in; 
	cout << endl << "What's the name of the person you want to add? " ;
	getline (cin, name_in);
	Player* my_player = new Player(name_in);
	bool found = false;
	for(int i = 0; i < allplayers.size(); i++) // if we already have this car in our list don't allow the user to buy it
	{ 
		if (allplayers[i]->getname()==name_in) // should this be within the for loop above? Can I combine these into an else if and take out the for loop?
		{
			found = true;
			cout << endl << "You already have a player by that name. Please try again. \n\n";
		}
	}
	if(!found)	
	{
		allplayers.push_back(my_player);
		cout << endl << "Ok, the player \"" << name_in << "\" was added. \n" << endl;
	}

}

void addtolineup(vector<Player*> & allplayers, vector<Player*> & lineup)
{
	string name_in; 
	cout << endl << "What's the name of the player you want to add to the lineup? " ;
	getline (cin, name_in);
	bool found = false;
	for(int i = 0; i < allplayers.size(); i++) // if we already have this player in our list, add them to the lineup.
	{ 
		if (allplayers[i]->getname()==name_in)
		{
			found = true;
			lineup.push_back(allplayers[i]);
			cout << endl << "Ok, the player \"" << name_in << "\" was put into Lineup from Players. \n" << endl;
			// code for adding that pointer to the lineup vector
		}
	}
	if(!found)	
	{
		cout << "\nThat player was not in the list, please select someone from the list. \n\n";
	}

}

//void fight();
 
int main()

{
	srand (time(NULL));
	vector<Player*> allplayers;
	vector<Player*> lineup;
	string ans;

	Player* my_player = new Player("Michelle"); // creates new player object and pointer that points to it
	allplayers.push_back(my_player);
	my_player = new Player("Brianne");
	allplayers.push_back(my_player);
	my_player = new Player("Christina");
	allplayers.push_back(my_player);
	
	cout << "\"A\" -- Show Players.\n"; // How do I change this to int instead of strings? 
	cout << "\"B\" -- Add a Player.\n";
	cout << "\"C\" -- Add to Line-Up.\n";
	cout << "\"D\" -- Show Line-Up.\n";
	cout << "\"E\" -- Fight.\n";
	cout << "\"F\" -- Exit the program.\n";

	cout << "What would you like to do? ";
	getline(cin, ans);

	while ((ans != "F") && (ans != "f"))

	{

		if ((ans == "A") || (ans == "a"))
		{ 
			cout << "\nPlayers: \n\n";
			for (int i=0; i<allplayers.size(); i++)
			{
				cout << allplayers[i]->tostring();
				cout << endl;
			}
		}
		else if ((ans == "B") || (ans == "b"))
		{ 
			addplayer(allplayers);
		}
		else if ((ans == "C") || (ans == "c"))
		{ 
			addtolineup(allplayers,lineup); //idk if this is the correct vector to use but oh well for now! 
		}
		else if ((ans == "D") || (ans == "d"))	
		{ 
			cout << "\nLine Up: \n\n";
			for (int i=0; i<lineup.size(); i++)
			{
				cout << lineup[i]->tostring();
				cout << endl;

			}
		}
		else if ((ans == "E") || (ans == "e"))
		{ 
			if (lineup.size()>1)
			{
			string ans1=lineup[0]->getThrow();
			string ans2=lineup[1]->getThrow();
			cout << endl << lineup[0]->getname() << " threw " << ans1 << endl << endl;
			cout << endl << lineup[1]->getname() << " threw " << ans2 << endl;
				if (lineup[0]->getname()==lineup[1]->getname())
				{
					cout << "\nDraw\n" << endl; 
					lineup[0]->adddraw();
				}
				else if (ans1==ans2)
				{
					cout << "\nDraw\n" << endl; 
					lineup[0]->adddraw();
					lineup[1]->adddraw();
				}
				else if(ans1 == "Paper"  &&  ans2 =="Rock")
				{
				   cout << "\nPaper covers rock, " << lineup[0]->getname() << " wins.\n";
				   lineup[0]->addwins();
				   lineup[1]->addlosses();
				}
				else if(ans1== "Rock" && ans2=="Scissors")
				{
					cout<<"\nRock beats scissors, " << lineup[0]->getname() << " wins.\n";
					lineup[1]->addlosses();
					lineup[0]->addwins();
				}
				else if(ans1== "Scissors" && ans2=="Paper")
				{
				   cout<<"\nScissors cut paper, " << lineup[0]->getname() << " wins.\n";
				   lineup[0]->addwins();
				   lineup[1]->addlosses();
				}
				else if(ans1== "Scissors" && ans2=="Rock")
				{
					cout<<"\nRock beats scissors, "<<lineup[1]->getname() << " wins.\n";
					lineup[0]->addlosses();
					lineup[1]->addwins();
				}
				else if(ans1== "Rock" && ans2=="Paper")
				{
					cout<<"\nPaper covers rock, " << lineup[1]->getname() << " wins.\n";
					lineup[1]->addwins();
					lineup[0]->addlosses();
				}
				else if(ans1== "Paper" && ans2=="Scissors")
				{
				   cout<<"\nScissors cuts paper, " << lineup[1]->getname() << " wins.\n";
				   lineup[1]->addwins();
				   lineup[0]->addlosses();
				}
				for (int i = 0 + 1; i<lineup.size(); i++)
				{
					lineup[i-1] = lineup[i];
				}
				lineup.pop_back();
				for (int i = 0 + 1; i<lineup.size(); i++)
				{
					lineup[i-1] = lineup[i];
				}
				lineup.pop_back();
			}
			else
			{
			cout <<"\nThere must be at least two players.\n\n"; // Return user to the menu.
			}
		}
		else
		{
			cout <<"\nInvalid input, please try again.\n\n"; // Return user to the menu.
		}
		cout << "\"A\" -- Show Players.\n";
		cout << "\"B\" -- Add a Player.\n";
		cout << "\"C\" -- Add to Line-Up.\n";
		cout << "\"D\" -- Show Line-Up.\n";
		cout << "\"E\" -- Fight.\n";
		cout << "\"F\" -- Exit the program.\n";
		cout << "What would you like to do? ";
		getline(cin,ans);
	}
	system("pause");
	return 0; 
}
