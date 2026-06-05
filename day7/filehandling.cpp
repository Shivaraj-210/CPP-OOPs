#include <iostream>
#include <string>
using namespace std;
class PlayerScore
{
private:
    int ballsFaced;
    int score;
    double sr=0.0;

public:
    // constructor
    PlayerScore()
    {
        ballsFaced = 0;
        score = 0;
    }
    // parameterizaed constructor
    PlayerScore(int balls, int runs)
    {
        ballsFaced = balls;
        score = runs;
    }

    // friend function
    friend void showScore(PlayerScore);
    // exapmle 2
    friend void calculateStrikeRate(PlayerScore);
};
// friend function is special function used to access the class function out of the class and can also access private data members
void showScore(PlayerScore player)
{
    cout << "the player has scored " << player.score << " runs in " << player.ballsFaced << " balls.\n";
}
void calculateStrikeRate(PlayerScore p)
{
    p.sr = (static_cast<double>(p.score) / p.ballsFaced) * 100;
    cout << "The player has scored " << p.score << " runs at the strike rate of " << p.sr << endl;

}
int main(){
    PlayerScore player1(20,70);
    PlayerScore player2(33,83);

    showScore(player1);
    calculateStrikeRate(player1);
    showScore(player2);
    calculateStrikeRate(player2);
}                                                                                                                                   // friend function