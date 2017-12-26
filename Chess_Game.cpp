/**********|**********|**********|
Program: TT01_A2_NABIL_FARHAN.cpp
Course: TCP1101 Programming Fundamentals
Year: 2016/17 Trimester 2
Name: NABIL FARHAN BIN MAHMAD ZULHASNAN	
ID: 1141128645
Email: nnabilfarhan@gmail.com
Phone: 017-6730017
**********|**********|**********/

#include <iostream>
#include <vector>   // Vectors are sequence containers representing arrays that can change in size
#include <cstdlib>	// srand()
#include <ctime>	// time()
using namespace std;

// Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.
// This is where contains all the details about the charater of the piece such as queen , rook etc.
class piece{
	char name;
	int owner, points, x, y, start, end, range;
public:
	piece(char n = ' ', int o = -1, int p = 0): name(n), owner(o), points(p), range(1), start(0), end(8){ // range 1 to 8 because piece contain 8 char which is Q,q,B,b,K,k,R,r
		if(name == 'B' || name == 'b'){
			start = 4;
		} else if (name == 'R' || name == 'r' || name == 'K' || name == 'k'){
			start = 0;
			end = 4;
			if(name == 'K' || name == 'k'){
				range = 2;
			}
		} 
	}
	void setx(int px) {x = px;}
	void sety(int py) {y = py;}
	void setp(int p) {points = p;}
	int getx() {return x;}
	int gety() {return y;}
	int getp() {return points;}
	int geto() {return owner;}
	int gets() {return start;}
	int gete() {return end;}
	int getr() {return range;}
	char getn() {return name;}
};
// This is where the character of the piece will be randomly put in the board
int nabil_shuffle(const int& SIZE, vector<piece>& a, char board[][3]){
	for (int i = 0; i < a.size(); ++i){
		int j = rand() % a.size();
		
		// swap a[i] and a[j]
		piece temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	
	int count = 0;
	int r = rand()%SIZE;
	int c = rand()%SIZE;
	board[r][c] = ' ';
	//A for loop is a repetition control structure that allows you to efficiently write a loop that needs to execute a specific number of times.
	for (int y = 0; y < SIZE; ++y){
		for (int x = 0; x < SIZE; ++x){
			if (!(x == r && y == c)){
				board[x][y] = a[count].getn();
				a[count].setx(x);
				a[count++].sety(y);
			}
		}
	}
	
	return (c * SIZE + r);
}

// This display function to show the template of the board in this game
void display_board(const int& SIZE, char board[][3]){
	cout << "\n=============\n";
	for (int y = 0; y < SIZE; ++y){
		for (int x = 0; x < SIZE; ++x){
			cout << "| " << board[x][y] << " ";
		}
		cout << "|\n";
	}
	cout << "=============\n";
}

// Function for chess piece to attack their enemy
void destroy(char board[][3], vector<piece>& set, const int& t){
	board[set[t].getx()][set[t].gety()] = ' ';
	set[t].setp(0);
}
// The Boolean data type is used to declare a variable whose value will be set as true (1) or false (0)
// This boolean datatype is to find the chess piece that player choose to attack their enemy
// After player had choose their piece , then this bool will find their enemy to attack
bool seek(char board[][3], vector<piece>& set, int& s, int& skip){
	int x = 0, y = 0, target = 0, addxy[2][8] = {{0,-1,0,1,-1,-1,1,1},{-1,0,1,0,-1,1,1,-1}}; 
	for(int i = set[s].gets(); i < set[s].gete(); ++i){
		x = set[s].getx() + (addxy[0][i]*set[s].getr());
		y = set[s].gety() + (addxy[1][i]*set[s].getr());
		if(x >= 0 && x <= 2 && y >= 0 && y <= 2){
			target = y*3 + x;
			if(target != skip){ // chess piece will not attack if the target not its enemy
				if(target >= skip){
					target--;
				}
				if(set[target].geto() != set[s].geto() && set[target].getp() != 0){
					destroy(board, set, target); //if multiple target, choose first encounter
					return true;
				}
			}
		}
	}
	cout << "No target\n"; // Output if theres no target for the chess piece to attack
	return false;
}
// Chess pieces to make an attack or shoot the other piece , chess piece will find their enemy
bool attack(char board[][3], vector<piece>& a, char piece[], const char& in, const int& turn, int& skip){
	bool error = true;
	int select;
	for(int i = 0; i < 8; ++i){
		if(in == piece[i] && ( in != piece[0+turn] && in != piece[2+turn] && in != piece[4+turn] && in != piece[6+turn] )){
			error = false;
			break;
		}
	}
	
	if(error){
		// Output if user enter other than Q,R,K and B
		cout << "Invalid piece\n";
		return error;
	}
	
	error = true;
	// This one for player to enter the input from the board , and if player enter other input then the program will show "Piece not found"
	for(int y = 0; y < 3; ++y){
		for(int x = 0; x < 3; ++x){
			if(board[x][y] != ' ' && in == board[x][y]){
				select = y*3 + x;
				if (select >= skip){
					select--;
				}
				error = false;
				break;
			}
		}
	}
	
	if(error){
		// Output to show that piece not found because player choose other input from the board
		cout << "Piece not found\n";
		return error;
	}

	return !(seek(board, a, select, skip));
}
// If the chess pieces already attack their enemy , so the pieces of enemy will erase from the board
void trim(string& in){
	for(int i =  in.size(); i >= 0; --i){
		if(in[i] == ' ' || in[i] == '\t')
			in.erase(i,	1);
	}
	if(in.size() > 1 || in.size() < 1){
		in = "X";
	}
}

int main()
{   // Battle Chess Game banner
	cout << "=========================" << endl;
    cout << " WELCOME TO CHESS BATTLE " << endl;
    cout << "=========================" << endl;
	
	int skip = 0, turn = 1;
	string input;
	int score[2] = {0,0},  strength[] = {9,9,6,6,4,4,4,4}; // Strength of the character or score of each chess pieces , score [2] because there is 2 player
	char pieces[] = {'Q','q','R','r','K','k','B','b'};
	
	vector<piece> set;
	// A for loop is a repetition control structure that allows you to efficiently write a loop that needs to execute a specific number of times.
	for(int i = 0; i < 8; ++i){
		set.push_back( piece(pieces[i], i%2, strength[i]) );
	}
	
	srand(time(NULL));
	const int SIZE = 3;
	char board[SIZE][SIZE];
	skip = nabil_shuffle(SIZE, set, board);
	
	// Player turn to make a move whether to choose Queen , Rook , Bishop or Knight
	while(turn <= 4){
		display_board(SIZE, board);
		cout << "Player " << turn%2+1 << "\nChoose your piece <" << "Select piece <" << pieces[1-turn%2] << ", " << pieces[3-turn%2] <<
		", " << pieces[5-turn%2] << ", " << pieces[7-turn%2] << "> or type z to exit ==> ";
		getline(cin, input);
		trim(input);
		// input for player if player enter z and the output will be game over
		if(input == "z" || input == "Z" ){
			cout << "\nGame Over";
			break;
		} else {
			if( attack(board, set, pieces, input[0], turn%2, skip) ){
				turn--;
			}
		}
		turn++;
	}
	 // This for loop is to calculate the score for each player 1 and player 2 , it will find their remaining pieces from the board
	for(int i = 0; i < set.size(); ++i){
		score[set[i].geto()] += set[i].getp();
	}
	
	display_board(SIZE, board);
	// Display Player score at the end of the game
	cout << "\nPlayer 1 : " << score[0] << " Points\nPlayer 2 : " << score[1] << " Points\n";
	
	if(score[0] > score[1]){
		cout << "Player 1 wins\n";
	} else if (score[0] < score[1]){
		cout << "Player 2 wins\n";
	} else {
		cout << "Draw game\n";
	}
	return 0;
}