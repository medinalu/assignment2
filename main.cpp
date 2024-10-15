#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


/*
* Function: user_input_check_mnybll
* Description: Prints "Hello, World!" to the terminal.
* Side effects: "Hello, World!" printed to the terminal
*/
int user_input_check_mnybll(){

  int mnyballrackpos;

  do {
    cout << "Please provide the location for the money ball rack as a number between 1 and 5 inclusive: "<< endl;
    cin >> mnyballrackpos;
  }
  while ((mnyballrackpos<1) || (mnyballrackpos>5)); {
  }
  return mnyballrackpos;
}

int user_input_check_userability(){

  int userability;

  do {
    cout << "Please provide your shooting ability as a number between 1 and 99 inclusive: "<< endl;
    cin >> userability;
  }
  while ((userability<0) || (userability>99)); {
  }
  return userability;
}

int user_input_check_numofplayers(){

  int num_of_players;

  do {
    cout << "Please provide the number of people playing as an integer: "<< endl;
    cin >> num_of_players;
  }
  while ((num_of_players<0) || (num_of_players>50)); {
  }
  return num_of_players;
}


int player_probability(int random_values_array[],int b) {
  int something = b;
  int x[100];
  for (int i=0; i<=99;i++){
    if (i<something) {
      x[i]=1;
      }
    else {
      x[i]=0;
      }
  for (int j=0; j<27; j++){
    int babe = rand()%100;
    int kaney = x[babe];
    random_values_array[j]=kaney;
    }
  }
  return random_values_array[0];

}

int mnyballfunction(int mnyball){
    int n;
    if (mnyball == 1) {
        n = 0;}
    if (mnyball == 2) {
        n = 5;}
    if (mnyball == 3) {
        n = 11;}
    if (mnyball == 4) {
        n = 17;}
    if (mnyball == 5){
        n = 23;}
    return n;
}

int convert_rand_to_made_missed(char random_array[], int random_values_array[],int mnyball){
    int m=mnyballfunction(mnyball);
    for (int i=0; i<27; i++)
    {
        if (i>=m && i<=(m+4)) 
        {
            if (random_values_array[i]==1) 
            {
                random_array[i]='M';
            }
            else
            {
                random_array[i]='_'; 

            }
        }
        else if (i==10 || i==16) 
        {
            if (random_values_array[i]==1)
            {
                random_array[i]='S';
            }
            else
            {
                random_array[i]='_';
            }
        }
        else
        {
            if (random_values_array[i]==1)
            {
                if (i==4 || i==9 || i==15 || i==21 || i==26){
                    random_array[i]='M';
                }
                else{
                    random_array[i]='X';

                }
            }
            else
            {
                random_array[i]='_';
            }
         }
      }

        return 0;  
}

int random_array_char_to_points_array(int points_set[], char random_array[]){
    for (int i = 0; i<27; i++){
        if (random_array[i]=='X'){
            points_set[i]=1;
        }
        else if (random_array[i]=='_'){
            points_set[i]=0;
        }
        else if (random_array[i]=='M'){
            points_set[i]=2;
        }
        else{ 
            points_set[i]=3;
        }
    }
    return 0;
}


int function_row_sum(int sum_row_array[],int points_set[]){
    int sum=0;
    int b=0;

    for (int i = 0; i<27; i++){
            sum = sum+points_set[i];
            if (i==4 || i==9 || i == 15 || i==21 || i==26){
                sum_row_array[b]=sum;
                b++;
                sum=0;
            }
            else if (i==10 || i==16){
                sum_row_array[b]=sum;
                b++;
                sum=0;
            }

    }
    return 0;
}

int function_player_points_sum(int sum_row_array[]){
    int sum=0;
    for (int i = 0; i<7; i++){
        sum=sum+sum_row_array[i];
    }
    return sum;
}

int winner_loser_function(int winner_loser_array[]){
  int a = winner_loser_array[0];
  int b = winner_loser_array[1];
  if (a>b){
      cout << "Player 1 is the winner!"<< endl;
  }
  else if (a<b){
      cout << "Player 2 is the winner!"<< endl;
  }
  else{
      cout << "It's a tie!"<< endl;
  }

  return 0;}

void results_output_function(int b, char random_array[],int sum_row_array[],int nina){
    cout<<"Player "<< b <<endl;
    cout << "Rack 1: "<<random_array[0]<< random_array[1]<< random_array[2]<< random_array[3]<< random_array[4]<<" | "<<sum_row_array[0]<<" pts"<<endl;
    cout << "Rack 2: "<<random_array[5]<< random_array[6]<< random_array[7]<< random_array[8]<< random_array[9]<<" | "<< sum_row_array[1]<<" pts"<<endl;
    cout << "Starry: "<< random_array[10] <<" | "<<sum_row_array[2]<<" pts"<<endl;
    cout << "Rack 3:"<<random_array[11]<< random_array[12]<< random_array[13]<< random_array[14]<< random_array[15]<<" | "<<sum_row_array[3]<<" pts"<<endl;
    cout<<"Starry: "<< random_array[16] <<" | "<< sum_row_array[4]<<" pts"<<endl;
    cout << "Rack 4: "<<random_array[17]<< random_array[18]<< random_array[19]<< random_array[20]<< random_array[21]<<" | "<< sum_row_array[5]<<" pts"<<endl;
    cout << "Rack 5: "<<random_array[22]<< random_array[23]<< random_array[24]<< random_array[25]<< random_array[26]<<" | "<< sum_row_array[6]<<" pts"<<endl;
    cout <<"Total Points: " << nina<< " pts"<<endl;
}

int main(){
  int answer=20;
  int x = time(0);
  srand(x);
  int numofplayers = user_input_check_numofplayers();
  int i=1;
  int winner_loser_array[2]={0,0};


    
do{

  int random_values_array[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  char random_array[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  int points_set[27]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  int sum_row_array[7]={0,0,0,0,0,0,0};

  int mnyball =  user_input_check_mnybll();

  int userability = user_input_check_userability();


  player_probability(random_values_array,userability);

  convert_rand_to_made_missed(random_array, random_values_array, mnyball);

  random_array_char_to_points_array(points_set, random_array);

  function_row_sum(sum_row_array, points_set);

  int nina = function_player_points_sum(sum_row_array);

  if (i==1){
    winner_loser_array[0]=nina;
  }
  else{
      winner_loser_array[1]=nina;
  }

  results_output_function(i,random_array, sum_row_array,nina);

  if (i==2){
    winner_loser_function(winner_loser_array);
  }

  if (i==numofplayers){
      cout << "Would you like to play again? (1-yes, 0-no)" << endl;
      cin >> answer;
    if (answer==1){
        i=1;
        continue;
      }
    else{
        break;
      }
  }

    i++; 

}

  while (answer!=0);
    cout<< "Ok, Goodbye!" << endl;

  return 0;
}
