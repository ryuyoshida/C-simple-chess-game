//library that have been used in this program
#include <iostream>
#include <cstdlib>
#include <time.h>
#include<limits>
using namespace std;

// set up my variables value for the battle chess pieces
int queen,knight,bishop,rook,pawn;
int queen_mark=9;
int rook_mark=6;
int bishop_mark=4;
int knight_mark=4;
int pawn_mark=1;
int player_choose;

// Function
void playerchoose (){
       cout << "Choose your piece to fight with computer (enter 1,2,3,4 or 5) ===> " ;
        cin >> player_choose ;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// starting main function
int main()
{
	// Battle chess game banner
    cout << "=================================" << endl;
    cout << "======= The Chess Battle ========" << endl;
    cout << "=================================" << endl;
	// set up my variables for chess pieces , your mark and computer mark
	double sum_mark = 0;
	double sumcom_mark = 0;
    double your_mark ;
	double com_mark ;
    int queen_piece;
	int rook_piece;
	int bishop_piece;
    int knight_piece;
    int pawn_piece;
	// ask the player to enter the number of their chess pieces
    cout << "Please enter the number of your queen (1 or 2 pieces), then press enter ==> ";
    cin >> queen_piece;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(queen_piece != 1 && queen_piece != 2)
    {
        // ask the player to choose their number of pieces if their not enter the correct value
        cout << "INVALID . Please enter the number of your queen (1 or 2 pieces), then press enter ==> ";
        cin >> queen_piece;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Please enter the number of your rook (1 or 2 pieces), then press enter ==> ";
    cin >> rook_piece;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(rook_piece != 1 && rook_piece != 2)
    {

        cout << "INVALID . Please enter the number of your rook (1 or 2 pieces), then press enter ==> ";
        cin >> rook_piece;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Please enter the number of your bishop (1 or 2 pieces), then press enter ==> ";
    cin >> bishop_piece;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(bishop_piece != 1 && bishop_piece != 2)
    {

        cout << "INVALID . Please enter the number of your bishop (1 or 2 pieces), then press enter ==> ";
        cin >> bishop_piece;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cout << "Please enter the number of your knight (1 or 2 pieces), then press enter ==> ";
    cin >> knight_piece;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(knight_piece != 1 && knight_piece != 2)
    {

        cout << "INVALID . Please enter the number of your knight (1 or 2 pieces), then press enter ==> ";
        cin >> knight_piece;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cout << "Please enter the number of your pawn (1 or 2 pieces), then press enter ==> ";
    cin >> pawn_piece;
	cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(pawn_piece != 1 && pawn_piece != 2)
    {

        cout << "INVALID . Please enter the number of your pawn (1 or 2 pieces), then press enter ==> ";
        cin >> pawn_piece;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

	    // the status of the player pieces after they had enter all the pieces that they want
        cout <<"" << endl;
        cout << "=================================" << endl;
        cout << "=========  YOUR STATUS  =========" << endl;
        cout << "=================================" << endl;
        cout << "1. QUEEN = "  << queen_piece << endl;
        cout << "2. ROOK = "  << rook_piece << endl;
        cout << "3. BISHOP = " << bishop_piece << endl;
		cout << "4. KNIGHT = "  << knight_piece << endl;
        cout << "5. PAWN = " << pawn_piece << endl;
        cout <<"" << endl;


        cout << "YOUR MARK = 0" << endl;
        cout << "COMPUTER MARK = 0" << endl;
        cout <<"" << endl;
// total piece of all their pieces after sum
int total_piece = queen_piece + rook_piece + bishop_piece + knight_piece + pawn_piece  ;
// function void appear after user had enter all their pieces
while (total_piece > 0)
{
        playerchoose() ;
        
		// this one for the loop when user run out of chess pieces
        while (player_choose == 1 && queen_piece== 0){cout << "Please try again .";  playerchoose() ;}
        while (player_choose == 2 && rook_piece== 0) {cout << "Please try again .";  playerchoose() ;}
        while (player_choose == 3 && bishop_piece== 0)  {cout << "Please try again .";  playerchoose() ;}
		while (player_choose == 4 && knight_piece== 0) {cout << "Please try again .";  playerchoose() ;}
        while (player_choose == 5 && pawn_piece== 0)  {cout << "Please try again .";  playerchoose() ;}


       srand(time(NULL));
            // gets a random number between 1 and 5 and tell the player what was chosen
            int computer_mark= rand()%5+1;

            cout<< "" <<endl;

            if(player_choose == 1)
            cout << "You select QUEEN\n" ;
            if(player_choose == 2)
            cout << "You select ROOK\n" ;
            if(player_choose == 3)
            cout << "You select BISHOP\n" ;
		    if(player_choose == 4)
            cout << "You select KNIGHT\n" ;
            if(player_choose == 5)
            cout << "You select PAWN\n" ;



            if(computer_mark== 1)
            cout << "Computer select QUEEN\n" ;
            if(computer_mark == 2)
            cout << "Computer select ROOK\n" ;
            if(computer_mark == 3)
            cout << "Computer select BISHOP\n" ;
		    if(computer_mark == 4)
            cout << "Computer select KNIGHT\n" ;
            if(computer_mark == 5)
            cout << "Computer select PAWN\n" ;


            if (computer_mark == 1)
                computer_mark = queen_mark;
            else if (computer_mark == 2)
                computer_mark = rook_mark;
			else if (computer_mark == 3)
                computer_mark = bishop_mark;
			else if (computer_mark == 4)
                computer_mark = knight_mark;
            else
                computer_mark = pawn_mark;

			// switch statement appear after the user enter the pieces that they want to battle with computer
            switch(player_choose)
            {
                case 1:{

                    if(queen_mark==computer_mark)
                        {cout << "RESULT : TIE"<< endl;
                         your_mark = 0.5;
						 // result for user if they tie with computer
						 sum_mark = your_mark + sum_mark;
						 // this one result for computer 
                         double com_mark = 0.5;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    else if (queen_mark>computer_mark)
                        {cout << "RESULT : YOU WIN ! "<< endl;
                         your_mark = 1;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0;
                        }
                    else
                        {cout << "RESULT : YOU LOSE ! "<< endl;
                         your_mark = 0;
                         double com_mark = 1;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    queen_piece = queen_piece-1;
                    break ;}

               case 2:{

                    if(rook_mark==computer_mark)
                        {cout << "RESULT : TIE"<< endl;
                         your_mark = 0.5;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0.5;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    else if (rook_mark>computer_mark)
                        {cout << "RESULT : YOU WIN ! "<< endl;
                         your_mark = 1;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0;
                        }
                    else
                        {cout << "RESULT : YOU LOSE ! "<< endl;
                         your_mark = 0;
                         double com_mark = 1;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    rook_piece = rook_piece-1;
                    break ;}

            case 3:{

                    if(bishop_mark==computer_mark)
                        {cout << "RESULT : TIE"<< endl;
                         your_mark = 0.5;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0.5;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    else if (bishop_mark>computer_mark)
                        {cout << "RESULT : YOU WIN ! "<< endl;
                         your_mark = 1;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0;
                        }
                    else
                        {cout << "RESULT : YOU LOSE ! "<< endl;
                         your_mark = 0;
                         double com_mark = 1;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    bishop_piece = bishop_piece-1;
                    break ;}
			case 4:{

                    if(knight_mark==computer_mark)
                        {cout << "RESULT : TIE"<< endl;
                         your_mark = 0.5;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0.5;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    else if (knight_mark>computer_mark)
                        {cout << "RESULT : YOU WIN ! "<< endl;
                         your_mark = 1;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0;
                        }
                    else
                        {cout << "RESULT : YOU LOSE ! "<< endl;
                         your_mark = 0;
                         double com_mark = 1;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    knight_piece = knight_piece-1;
                    break ;}
			case 5:{

                    if(pawn_mark==computer_mark)
                        {cout << "RESULT : TIE"<< endl;
                         your_mark = 0.5;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0.5;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    else if (pawn_mark>computer_mark)
                        {cout << "RESULT : YOU WIN ! "<< endl;
                         your_mark = 1;
						 sum_mark = your_mark + sum_mark;
                         double com_mark = 0;
                        }
                    else
                        {cout << "RESULT : YOU LOSE ! "<< endl;
                         your_mark = 0;
                         double com_mark = 1;
						 sumcom_mark = com_mark + sumcom_mark;
                        }
                    pawn_piece = pawn_piece-1;
                    break ;}

					// user must re-enter the correct value . if not, then they will be warned
             default : cout <<" INVALID INPUT . PLEASE TRY AGAIN " << endl ;


             }

  total_piece = queen_piece + rook_piece + bishop_piece + knight_piece + pawn_piece ;
// status after user had battle their pieces with computer and status will show how much pieces left for the user to play
  cout << "================================" << "\n"
       << "=========  YOUR STATUS =========" << "\n"
       << "================================" << "\n"
       << "1. QUEEN = "  << queen_piece << " piece \n"
       << "2. ROOK = "  << rook_piece << " piece \n"
       << "3. BISHOP = " << bishop_piece << " piece \n"
       << "4. KNIGHT = "  << knight_piece << " piece \n"
       << "5. PAWN = " << pawn_piece << " piece \n"
	   << "--------------------------------" << "-\n";
       // user will be show their mark and computer mark to know who have the highest mark
  cout <<"YOUR MARK = " <<sum_mark<< "\n" ;
  cout <<"COMPUTER MARK = "<<sumcom_mark<< "\n" ;
  cout << "" << endl;

}
   // This one to determine who win and who lose at the end of the game
   if ( sum_mark > sumcom_mark )
      cout << " == CONGRATULATIONS YOU WIN == "	<< endl;
  else 
	  cout << " == SORRY YOU LOSE == " << endl;
return 0;
}




