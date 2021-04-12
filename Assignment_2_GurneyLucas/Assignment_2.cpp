#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class character
{
private:
	int health = 20;
	int damage = 2;
	string weapon = "Wooden Sword";
public:
	void damageTaken(int enemieDamage)
	{
		health -= enemieDamage;
	}
	void newWeapon(string weaponFound, int weaponDamage)
	{
		weapon = weaponFound;
		damage = weaponDamage;
		cout << "You got " << weapon << " and you deal" << damage << endl;
	}

	int damageGiven()
	{
		return damage;
	}

	int checkHealth()
	{
		return health;
	}
};

class enemieKnight 
{
private:
	int health = 10;
	int damage = 4;
	string weapon = "Gaint iron sword";
public:
	void damageTaken(int enemieDamage)
	{
		damage -= enemieDamage;
	}

	int damageGiven()
	{
		return damage;
	}

	int checkHealth()
	{
		return health;
	}
};

class enemieBoss
{
private:
	int health = 1;
	int damage = 1;
	string weapon = "Gaint iron sword";
public:
	void damageTaken(int enemieDamage)
	{
		damage -= enemieDamage;
	}

	int damageGiven()
	{
		return damage;
	}

	int checkHealth()
	{
		return health;
	}
};

class DynIntStack
{
private:
	class StackNode
	{
		friend class DynIntStack;
		int value;
		StackNode* next;
		// Constructor
		StackNode(int value1, StackNode* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode* top;
public:
	DynIntStack() { top = NULL; }
	void push(int num)
	{
		top = new StackNode(num, top);
	}

	void pop(int& num)
	{
		StackNode* temp;

		if (isEmpty())
		{
			cout << "The stack is empty.\n";
			exit(1);
		}
		else   // Pop value off top of stack
		{
			num = top->value;
			temp = top;
			top = top->next;
			delete temp;
			temp = nullptr;
		}
	}

	bool isEmpty() const
	{
		if (!top)
			return true;
		else
			return false;
	}
};

int main()
{
	character player;
	enemieKnight NPC;
	enemieBoss finaleBoss;
	DynIntStack stack;

	fstream storyFile;
	fstream dungeonFile;

	string story;
	string answer;

	int catchNumber;
	int choice = 0;
	int titlesNumber1 = 44, titlesNumber2 = 83, titlesNumber3 = 139;

	storyFile.open("Story.txt", ios::in);
	if (storyFile.fail())
	{
		cout << "File open error!" << endl;
		return 1;
	}

	getline(storyFile, story);
	while (!storyFile.fail())
	{
		cout << story << endl;
		getline(storyFile, story);
	}

	storyFile.close();

	cout << endl;

	cout << "Welcome players to my mysterious dungeon. \n what do you want to do?: " << endl;
	cout << "1. go into the dungeon.\n2. don't go into the dungeon. -->";

	cin >> choice;

	if (choice == 1)
	{
		dungeonFile.open("dungeon.txt", ios::in);
		if (dungeonFile.fail())
		{
			cout << "File open error!" << endl;
			return 1;
		}

		getline(dungeonFile, story);
		while (!dungeonFile.fail())
		{
			cout << story << endl;
			getline(dungeonFile, story);
		}

		dungeonFile.close();
		// 1 dungeon
		while (true)
		{
			cout << "What do you do?\n1. inspect area \n2. leave room \n3. attack pieces----> ";

			getline(cin, answer);

			if (answer == "1" || answer == "inspect area" || answer == "Inspect area")
			{
				cout << "\nAs you look around in the room, you notice that there is a sign that is replica of the game in the room but one of the pieces are missing."
					<< " you notice that there is a picture of the queen piece pionting towards the hat part of the piece." << endl << "\nwhat should you do?"
					<< "\n1.inspect pieces. \n2.forget it.---->";
				getline(cin, answer);

				if (answer == "1" || answer == "inspect pieces" || answer == "Inspect pieces")
				{
					cout << "\nAs you inspect the top part of the piece, you then begin to unscrew the hat, which then reveles one of the pieces for the wall."
						<< " you inspected earlier. You would then put the piece from the queens hat and place it in the missing space.";
					break;
				}

				else if (answer == "2" || answer == "forget it" || answer == "Forget it")
				{
					cout << "forget about it" << endl;
				}
			}

			else if (answer == "2" || answer == "leave room" || answer == "Leave room")
			{
				cout << "You can't get out of the dungeon" << endl;
			}

			else if (answer == "3" || answer == "attack pieces" || answer == "Attack pieces")
			{
				cout << "you go a take a swing at the piece and your sword bonses off the piece." << endl;
			}
		}

		cout << endl;
		dungeonFile.open("dungeon2.txt", ios::in);
		if (dungeonFile.fail())
		{
			cout << "\nFile open error!" << endl;
			return 1;
		}

		getline(dungeonFile, story);
		while (!dungeonFile.fail())
		{
			cout << story << endl;
			getline(dungeonFile, story);
		}

		dungeonFile.close();
		// 2 dungeon
		while (true)
		{
			cout << "What do you do?\n1. inspect area \n2. leave room \n3. attack knight----> ";
			getline(cin, answer);

			if (answer == "1" || answer == "inspect area" || answer == "Inspect area")
			{
				cout << "You manage to notice that the sword is surperiorly better than your current sword." << endl;
				player.newWeapon("Iron sword", 5);
				cout << "\nYou then realize that there are words on the floor saying achilles.";
			}

			else if (answer == "2" || answer == "leave room" || answer == "Leave room")
			{
				cout << "You tried to leave the room and the door closes on you." << endl;
			}

			else if (answer == "3" || answer == "attack knight" || answer == "Attack knight")
			{
				cout << "As you go in for the attack, the knight comes to life and prepares to fight you." << endl;

				while (true)
				{
					cout << "What do you do?\n1. block attack \n2. dodge attack \n3. attack knight----> ";
					getline(cin, answer);

					if (answer == "1" || answer == "block attack" || answer == "Block attack")
					{
						cout << "When you successfully block the attack, you notice that the knight has a delay to it when it finishes it's attack." << endl;
					}

					else if (answer == "2" || answer == "dodge attack" || answer == "Dodge attack")
					{
						cout << "As you dodge the attack, you are given a moment to attack the knight\nWhat do you want to do?\n1. Attack high\n2. Attack low----> ";
						getline(cin, answer);
						if (answer == "1" || answer == "attack high" || answer == "Attack high")
						{
							NPC.damageTaken(player.damageGiven());
						}

						if (answer == "2" || answer == "attack low" || answer == "Attack low")
						{
							break;
						}
					}

					else if (answer == "3" || answer == "attack knight" || answer == "Attack knight")
					{
						cout << "You have attacked the knight, but he also hits you back." << endl;
						player.damageTaken(NPC.damageGiven());
						NPC.damageTaken(player.damageGiven());

					}
				}
				break;
			}
		}

		cout << endl;
		dungeonFile.open("dungeon3.txt", ios::in);
		if (dungeonFile.fail())
		{
			cout << "\nFile open error!" << endl;
			return 1;
		}

		getline(dungeonFile, story);
		while (!dungeonFile.fail())
		{
			cout << story << endl;
			getline(dungeonFile, story);
		}

		dungeonFile.close();

		// 3 dungeon
		while (true)
		{
			cout << "What do you do?\n1. inspect tiles \n2. inspect area \n3. attack tiles----> ";
			getline(cin, answer);
			if (answer == "1" || answer == "inspect tiles" || answer == "Inspect tiles")
			{
				cout << "You go and inspect the tiles and the numbers are " << titlesNumber3 << ", " << titlesNumber1 << ", and" << titlesNumber2
					<< ".\nwhat order do you want?\n1. ascending order\n2. descending order----> ";
				stack.push(titlesNumber1);
				stack.push(titlesNumber2);
				stack.push(titlesNumber3);
				getline(cin, answer);

				if (answer == "1" || answer == "ascending order" || answer == "Ascending order")
				{
					cout << titlesNumber1 << " " << titlesNumber2 << " " << titlesNumber3 << " noting seems to happen.";
				}
				else if (answer == "2" || answer == "descending order" || answer == "Descending order")
				{
					for (int i = 1; i <= 3; i++)
					{
						stack.pop(catchNumber);
						cout << catchNumber << " ";
					}
					break;
				}
			}
			else if (answer == "2" || answer == "inspect area" || answer == "Inspect area")
			{
				cout << "While you look around in the area, you manage to find a note saying \"One hit\" and that's it." << endl;
			}
			else if (answer == "3" || answer == "attack tiles" || answer == "Attack tiles")
			{
				cout << "you attempt to break it but, you sword tinks off" << endl;
			}
		}

		cout << endl;
		dungeonFile.open("dungeon4.txt", ios::in);
		if (dungeonFile.fail())
		{
			cout << "\nFile open error!" << endl;
			return 1;
		}

		getline(dungeonFile, story);
		while (!dungeonFile.fail())
		{
			cout << story << endl;
			getline(dungeonFile, story);
		}

		dungeonFile.close();

		// 4 dungeon
		while (true)
		{
			cout << "What do you do?\n1. block attack \n2. dodge attack \n3. attack Boss----> ";
			getline(cin, answer);

			if (answer == "1" || answer == "block attack" || answer == "Block attack")
			{
				cout << "When you successfully block the attack, the sword seems to go through yours and somehow hits you" << endl;
				player.damageTaken(finaleBoss.damageGiven());
			}

			else if (answer == "2" || answer == "dodge attack" || answer == "Dodge attack")
			{
				cout << "As you dodge the attack, you are given a moment to attack the knight\nWhat do you want to do?\n1. Attack high\n2. Attack low----> ";
				getline(cin, answer);
				if (answer == "1" || answer == "attack high" || answer == "Attack high")
				{
					player.damageTaken(finaleBoss.damageGiven());
					cout << "As you go in for a counter attack, he immediately backs up and counter attacks you.";
				}

				if (answer == "2" || answer == "attack low" || answer == "Attack low")
				{
					player.damageTaken(finaleBoss.damageGiven());
					cout << "As you go in for a counter attack, he immediately backs up and counter attacks you.";
				}
			}

			else if (answer == "3" || answer == "attack boss" || answer == "Attack boss")
			{
				break;
			}
		}

		if (player.checkHealth() < 1)
		{
			cout << endl;
			dungeonFile.open("Bad Ending.txt", ios::in);
			if (dungeonFile.fail())
			{
				cout << "\nFile open error!" << endl;
				return 1;
			}

			getline(dungeonFile, story);
			while (!dungeonFile.fail())
			{
				cout << story << endl;
				getline(dungeonFile, story);
			}

			dungeonFile.close();
		}
		
		else if (player.checkHealth() > 1)
		{
			cout << endl;
			dungeonFile.open("Good Ending.txt", ios::in);
			if (dungeonFile.fail())
			{
				cout << "\nFile open error!" << endl;
				return 1;
			}

			getline(dungeonFile, story);
			while (!dungeonFile.fail())
			{
				cout << story << endl;
				getline(dungeonFile, story);
			}

			dungeonFile.close();
		}
	}

	else if (choice == 2)
	{
		cout << "\nWell have a good day then.";

		cout << endl;
		dungeonFile.open("Gone Home Ending.txt", ios::in);
		if (dungeonFile.fail())
		{
			cout << "\nFile open error!" << endl;
			return 1;
		}

		getline(dungeonFile, story);
		while (!dungeonFile.fail())
		{
			cout << story << endl;
			getline(dungeonFile, story);
		}

		dungeonFile.close();
	}

	

	return 0;
}