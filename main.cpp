using namespace std;

// -----------HEADER FILES STATED----------
#include<iostream>
#include<conio.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

// Definition of function prototype for respective app.
int welcomeUser();
int displayPlayers(string [],string []);
int selectBatsmanAndBowler(string [],string []);
int startInning(int, string, string);
int playinn();
int display_score(string,int);
int decide_winner(int , int);

// Declaration of Global Variable (items)

string current_batm;
string current_bowl;

//MAIN FUNCTION CALL

int main()
{
    // Declaration of Class 
    class Team 
    {
        public:
        int run_scored;
        string team_name;
        string players[3];
    };
    //Declaration of object
    Team A,B;
    // Defining of elements for object A (means for Team A).

    A.team_name="Team A";
    for(int i=0;i<3;i++)
    {
            cout<<"Enter Team A members name  "<<i<<":"<<endl;
            getline(cin,A.players[i]);    
    }
    

    // Defining of data for object B (means for Team B)

    B.team_name="Team B";
    for(int i=0;i<3;i++)
    {
            cout<<"Enter Team B members name  "<<i<<":"<<endl;
            getline(cin,B.players[i]);    
    }

    welcomeUser();
    sleep(4);
    displayPlayers(A.players,B.players);

    cout<<"\n--------------------------------------------------------\n"<<endl;
    cout<<"Match Starting\n"<<"******Please Wait*******"<<endl;
    cout<<"\n--------------------------------------------------------\n"<<endl;

    sleep(6);

    //First Inning

    selectBatsmanAndBowler(A.players,B.players);
    startInning(1,A.team_name,B.team_name);

    sleep(4);

    A.run_scored=playinn();

    cout<<"\n--------------------------------------------------------\n"<<endl;
    cout<<"First Inning Ended\n"<<"******Please Wait*******"<<endl;
    cout<<"\n--------------------------------------------------------\n"<<endl;

    display_score(A.team_name,A.run_scored);

    sleep(6);

    //Second Inning
    selectBatsmanAndBowler(B.players,B.players);
    startInning(2,B.team_name,A.team_name);

    sleep(5);

    B.run_scored=playinn();
    display_score(B.team_name,B.run_scored);
    
    sleep(6);
    cout<<"\n--------------------------------------------------------\n"<<endl;
    cout<<"Second Inning Ended\n"<<"******Please Wait*******"<<endl;
    cout<<"\n--------------------------------------------------------\n"<<endl;

    //Deciding the result

    decide_winner(A.run_scored,B.run_scored);
    

    return 0;
}

//Defining Welcome Statement or Screen 

int welcomeUser(){
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\t\t"<<"Welcome to Gully Cricket 2023"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;

    sleep(3);

    cout<<"\t\t"<<"Creating Teams..."<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    
}

// Details Display Function

int displayPlayers(string team1[],string team2[])
{
    cout<<"Players of Team A"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"Player_"<<i+1<<":"<<team1[i]<<endl;
    }
    cout<<"Players of Team B"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"Player_"<<i+1<<":"<<team2[i]<<endl;
    }
}

// Player Selection 

int selectBatsmanAndBowler(string team1[],string team2[])
{
    srand(time(NULL));
    int i=rand()%3;
    current_batm=team1[i];
    i=rand()%3;
    current_bowl=team2[i];
}

// Inning Statements which player will play first.

int startInning(int inn_no, string bat_team, string bowl_team){
    cout<<"\t\t"<<"Inning "<<inn_no<<" Started"<<endl;
    cout<<"\t\t"<<"Batsman Team : "<<bat_team<<endl;
    cout<<"\t\t"<<"Bowling Team : "<<bowl_team<<endl;
    cout<<"\t\t"<<"Batsman Player (Current) : "<<current_batm<<endl;
    cout<<"\t\t"<<"Bowling Player (Current) : "<<current_bowl<<endl;
    
}

// Total Runs Scored in the innings 

int playinn()
{
    int total_runs=0;
    srand(time(NULL));
    cout<<"Ball \t\t"<<"Runs"<<endl;
    for(int i=0;i<6;i++)
    {
        int run=rand()%7;
        cout<<i+1<<"\t\t"<<run<<endl;
        total_runs+=run;
        sleep(5);
    }

    return total_runs;

}

//Display Score Scored by the team.

int display_score(string team,int total_runs)
{
    cout<<"TOTAL RUNS SCORED BY"<<team<<":\t\t"<<total_runs<<endl;

}

//Winner Decision Block.


int decide_winner(int team1_score, int team2_score)
{
    if(team1_score>team2_score)
    {
        cout<<"Team 1 WINS"<<endl;

    }
    else if(team1_score<team2_score)
    {
        cout<<"Team 2 WINS"<<endl;
    }
    else
    {
        cout<<"DRAW"<<endl;
    }
}