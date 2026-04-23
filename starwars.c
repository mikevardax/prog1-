// Barkonikos Grigoris
// AM: 2022202200136
// dit22136@go.uop.gr

// Bardajopoulos Mixalis
// AM: 2022202100021
// dit21021@go.uop.gr

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define MIN 10
#define MAX 26

void moveset_Leia (char** a, int N, int M, int s);
void free2DArray(char** array, int N);
char** array_creator ( int N , int M );
void random_placement(char** a, int N, int M, int s, int ob);
void print_table(char **a, int N , int M);
void stormtrooper_movement (char** a, int t, int N, int M, int s);
void Vader_movement(char** a, int N, int M);
int main (void)
{
    int N, M, c, i, j;
    
    printf("Welcome young padawan, my name is Yoda and your guide I will be!\n");
    printf("Choose the length of the space ship.[min 10],[max 26]\n");
    scanf("%d", &N);
    while (N < MIN || N > MAX){
        printf("Wrong you are , choose again!\n");
        printf("Choose the length of the space ship.[min 10],[max 26]\n");
        scanf("%d", &N);
    }
    printf("Choose the height of the space ship.[min 10],[max 26]\n");
    scanf("%d", &M);
    while (M < MIN || M > MAX){ 
        printf("Wrong you are , choose again!\n");
        printf("Choose the height of the space ship.[min 10],[max 26]\n");
        scanf("%d", &M);
    }
    printf("Choose dificulty you must.\n");
    printf("press '1' for youngling dificulty(easy)\n");
    printf("press '2' for padawan dificulty(medium)\n");
    printf("press '3' for jedi knight dificulty(hard)\n");
    printf("press '4' for grandmaster dificulty(imposible)\n");
     scanf("%d", &c);
     while (c < 1 || c > 4){ 
        printf("Wrong you are.\n");
        printf("Choose dificulty again you must!\n");
        scanf("%d", &c);
    }
    int SIZE = N * M;
    int s,ob; // s = stormtroopers , ob = obsticles // 
    if(c == 1)
    {   
        s = (SIZE) * 2 / 100 ;
        ob = (SIZE) * 13 / 100 ;
    }
    else if(c == 2)
    {
        s = (SIZE) * 5 / 100 ;
        ob = (SIZE) * 10 / 100 ;
    }
    else if(c == 3)
    {
        s = (SIZE) * 10 / 100 ;
        ob = (SIZE) * 5 / 100 ;
    }
    else
    {
        s = (SIZE) * 15 / 100 ;
        ob = 0 ;
    }
    char** a = array_creator(N,M);
    random_placement(a,N,M,s,ob);
    printf("\n");
    print_table(a,N,M);
    moveset_Leia (a,N,M,s);

    return 0;
}

char** array_creator ( int N , int M ){
    // Function to create a 2D char array dynamically
    char** a = (char**)malloc(N * sizeof(char*));
    if (a == NULL) {
        printf("Memory allocation failed\n");
    }
    for (int i = 0; i < N; i++) {
        a[i] = (char*)malloc(M * sizeof(char));
        if (a[i] == NULL) {
            printf("Memory allocation failed\n");
        }
    }
    // Initialize the 2D array with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = '.';
        }
    }
    return a;
}

// Function to free memory allocated for the 2D char array
void free2DArray(char** a, int N) {
    for (int i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);
}
    
//placement of stormtroopers, obsticles, Darth Vader, R2D2, princess Leia//
void random_placement(char** a, int N, int M, int s, int ob){
    srand(time(NULL));
    int darth = rand()%(4);
    if (darth == 1){
        a[0][0] = 'D';
    }
    else if (darth == 2){
         a[0][M-1] = 'D';
    }
    else if (darth == 3){
         a[N-1][0] = 'D';
    }
    else {
         a[N-1][M-1] = 'D';
         
    }
    int w = 0; // w = number of stormtroopers placed on the array
    while(w < s){
        int x = rand()%(N);
        int y = rand()%(M);
        if (a[x][y]=='@'){
            continue;
        }
        else if (a[x][y]!='.'){
            continue;
        }
        w++;
        a[x][y] = '@';
    }
    int z = 0; // z = number of obsticles placed on the array
    while(z < ob){
        int x = rand()%(N);
        int y = rand()%(M);
        if (a[x][y]=='X'){
            continue;
        }
        else if (a[x][y]!='.'){
            continue;
        }
        z++;
        a[x][y] = 'X';
    }
    
    bool mpike= false ;
    while (mpike == false){
      int x = rand()%(N);
      int y = rand()%(M);
      if (a[x][y]!='.'){
          continue;
      }
      else{
          a[x][y] = 'R';
          mpike = true;
      }
    }
    mpike= false ;
    while (mpike == false){
      int x = rand()%(N);
      int y = rand()%(M);
      if (a[x][y]!='.'){
          continue;
      }
      else{
          a[x][y] = 'L';
          mpike = true;
      }
    }
}

void print_table(char **a, int N , int M){
    int row, col ;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 'L') {
                row = i;
                col = j;
            }
        }
    }
    printf("  ");
    for (int j = 0; j < M; j++){
        printf(" %c", 'A'+j);
    }
     printf("\n");
    for (int i = 0; i < N; i++){
        if (i<9){
        printf(" %d",i+1);}
        else{
            printf("%d",i+1);
        }
        for (int j = 0; j < M; j++){
            if (i == row ){
                printf(" %c", a[i][j]);
                continue;
            }
             if (j == col){
                printf(" %c", a[i][j]);
                continue;
            }
            else{
                printf(" #");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
void moveset_Leia (char** a, int N, int M, int s){
    char b;
    int i = 0, j = 0;
    int ra = rand()%(4);
    int t = ra;
    printf("Choose your move.\n");
    printf("Write:\nU/u to move up.\nD/d to move down.\nL/l to move left.\nR/r to move right.\n");
    printf("Press (>) to write the number of a tile on the space ship that has an obsticle on it,\n");
    printf("to use the Force(>) and move it to an other tile (example c3>g3).\n");
    printf("By pressing H/h you can call upon master Yoda to reveal everything on the space ship.\n");
    printf("Also if you press the letter X/x the game will end.\n");
    scanf("%c", &b);
    do {
        scanf("%c", &b);
        int row, col;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 'L') {
                    row = i;
                    col = j;
                }
            }
        }
        if (b == 'U' || b == 'u')
        {
            if (row == 0 || a[row-1][col] == 'X')
            {
                printf("Invalid input!\nPlease enter a new input.\n");
            }
            else if (a[row-1][col] == 'D')
            {
                printf("You hear the sound of someone breathing.\n");
                printf("And sudenly you feel something that you can not see grabing you!\n");
                printf("You will come with me princess.\n");
                printf("And you will tell me everything about the rebel aliance!\n");
                printf("You lost, and with you died the hope for the rebelion\n");
                break;
            }
            else if (a[row-1][col] == '@')
            {
                printf("\"blaster shots\", intense battle!\n");
                if (j < 1)
                {
                    printf("You came out victorious, but sevearly wounded!\n");
                    printf("I do not think you will be this lucky the next time.\n");
                    j++;
                    a[row][col] = '.';
                    a[row-1][col] = 'L';
                    print_table(a,N,M);
                }
                else
                {
                    printf("You are coming with me rebel scum!!!\n");
                    printf("Lord Vader would like to have a word with you.\n");
                    printf("You lost, and with you died the hope for the rebelion\n");    
                    break;
                }
            }
            else if (a[row-1][col] == 'R')
            {
                printf("You hear the beeps of a Droid!\n");
                printf("You can now pass down the information to the rebel alliance!\n");
                break;
            }
            else
            {
                a[row][col] = '.';
                a[row-1][col] = 'L';
                stormtrooper_movement(a,t,N,M,s);
                Vader_movement(a,N,M);
                print_table(a,N,M);
            }
        }
        else if (b == 'D' || b == 'd')
        {
            if (row == (N - 1) || a[row+1][col] == 'X')
            {
                printf("Invalid input!\nPlease enter a new input.\n");
            }
            else if (a[row+1][col] == 'D')
            {
                printf("You hear the sound of someone breathing.\n");
                printf("And sudenly you feel something that you can not see grabing you!\n");
                printf("You will come with me princess.\n");
                printf("And you will tell me everything about the rebel aliance!\n");
                printf("You lost, and with you died the hope for the rebelion\n");
                break;
            }
            else if (a[row+1][col] == '@')
            {
                printf("\"blaster shots\", intense battle!\n");
                if (j < 1)
                {
                    printf("You came out victorious, but sevearly wounded!\n");
                    printf("I do not think you will be this lucky the next time.\n");
                    j++;
                    a[row][col] = '.';
                    a[row+1][col] = 'L';
                    print_table(a,N,M);
                }
                else
                {
                    printf("You are coming with me rebel scum!!!\n");
                    printf("Lord Vader would like to have a word with you.\n");
                    printf("You lost, and with you died the hope for the rebelion\n");    
                    break;
                }
            }
            else if (a[row+1][col] == 'R')
            {
                printf("You hear the beeps of a Droid!\n");
                printf("You can now pass down the information to the rebel alliance!\n");
                free2DArray(a,N);
                break;
            }
            else
            {
                a[row][col] = '.';
                a[row+1][col] = 'L';
                stormtrooper_movement(a,t,N,M,s);
                Vader_movement(a,N,M);
                print_table(a,N,M);
            }
        }
        else if (b == 'L' || b == 'l')
        {
            if (col == 0 || a[row][col-1] == 'X')
            {
                printf("Invalid input!\nPlease enter a new input.\n");
            }
            else if (a[row][col-1] == 'D')
            {
                printf("You hear the sound of someone breathing.\n");
                printf("And sudenly you feel something that you can not see grabing you!\n");
                printf("You will come with me princess.\n");
                printf("And you will tell me everything about the rebel aliance!\n");
                printf("You lost, and with you died the hope for the rebelion\n");
                break;
            }
            else if (a[row][col-1] == '@')
            {
                printf("\"blaster shots\", intense battle!\n");
                if (j < 1)
                {
                    printf("You came out victorious, but sevearly wounded!\n");
                    printf("I do not think you will be this lucky the next time.\n");
                    j++;
                    a[row][col] = '.';
                    a[row][col-1] = 'L';
                    print_table(a,N,M);
                }
                else
                {
                    printf("You are coming with me rebel scum!!!\n");
                    printf("Lord Vader would like to have a word with you.\n");
                    printf("You lost, and with you died the hope for the rebelion\n");    
                    break;
                }
            }
            else if (a[row][col-1] == 'R')
            {
                printf("You hear the beeps of a Droid!\n");
                printf("You can now pass down the information to the rebel alliance!\n");
                break;
            }
            else
            {
                a[row][col] = '.';
                a[row][col-1] = 'L';
                stormtrooper_movement(a,t,N,M,s);
                Vader_movement(a,N,M);
                print_table(a,N,M);
            }
        }
        else if (b == 'R' || b == 'r')
        {
            if (col == (M - 1) || a[row][col+1] == 'X')
            {
                printf("Invalid input!\nPlease enter a new input.\n");
            }
            else if (a[row][col+1] == 'D')
            {
                printf("You hear the sound of someone breathing.\n");
                printf("And sudenly you feel something that you can not see grabing you!\n");
                printf("You will come with me princess.\n");
                printf("And you will tell me everything about the rebel aliance!\n");
                printf("You lost, and with you died the hope for the rebelion\n");
                break;
            }
            else if (a[row][col+1] == '@')
            {
                printf("\"blaster shots\", intense battle!\n");
                if (j < 1)
                {
                    printf("You came out victorious, but sevearly wounded!\n");
                    printf("I do not think you will be this lucky the next time.\n");
                    j++;
                    a[row][col] = '.';
                    a[row][col+1] = 'L';
                    print_table(a,N,M);
                }
                else
                {
                    printf("You are coming with me rebel scum!!!\n");
                    printf("Lord Vader would like to have a word with you.\n");
                    printf("You lost, and with you died the hope for the rebelion\n");    
                    break;
                }
            }
            else if (a[row][col+1] == 'R')
            {
                printf("You hear the beeps of a Droid!\n");
                printf("You can now pass down the information to the rebel alliance!\n");
                break;
            }
            else
            {   
                a[row][col] = '.';
                a[row][col+1] = 'L';
                stormtrooper_movement(a,t,N,M,s);
                Vader_movement(a,N,M);
                print_table(a,N,M);
            }
        }
        else if (b == 'H' || b == 'h')
        {
            printf("As your guide let me help you by giving light to everything that can not be seen.\n");
            // Print the 2D array with everything visible
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    printf("%c ", a[i][j]);
                }
                printf("\n");
            }
        }
        else if (b == 'X' || b == 'x')
        {
            printf("Already gave up, you did!\nMore from you, I expected.\n");
            break;
        }
    } while (i == 0);
}

void stormtrooper_movement (char** a, int t, int N, int M, int s){
    if (t == 1)
    {
        int row, col ;
        int v = s;
        while (v > 0)
        {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == '@') {
                        row = i;
                        col = j;
                    }
                }
            }
            if(row == 0 || a[row-1][col] == 'X' || a[row-1][col] == '@' || a[row-1][col] == 'D' || a[row-1][col] == 'R')
            {
                t = 3;
            }
            else
            {
                a[row][col] = '.';
                a[row-1][col] = '@';
            }
            v--;
        }
    }
    else if (t == 2)
    {
        int v = s;
        while (v > 0)
        {
            int row, col ;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == '@') {
                        row = i;
                        col = j;
                    }
                }
            }
            if(col == 0 || a[row][col-1] == 'X' || a[row][col-1] == '@' || a[row][col-1] == 'D' || a[row][col-1] == 'R')
            {
                t = 4;
            }
            else
            {
                a[row][col] = '.';
                a[row][col-1] = '@';
            }
            v--;
        }
    }
    else if (t == 3)
    {
        int v = s;
        while (v > 0)
        {
            int row, col ;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == '@') {
                        row = i;
                        col = j;
                    }
                }
            }
            if(row == (N-1) || a[row+1][col] == 'X' || a[row+1][col] == '@' || a[row+1][col] == 'D' || a[row+1][col] == 'R')
            {
                t = 1;
            }
            else
            {
                a[row][col] = '.';
                a[row+1][col] = '@';
            }
            v--;
        }
    }
    else if (t == 4)
    {
        int v = s;
        while (v > 0)
        {
            int row, col ;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (a[i][j] == '@') {
                        row = i;
                        col = j;
                    }
                }
            }
            if(row == (M-1) || a[row][col+1] == 'X' || a[row][col+1] == '@' || a[row][col+1] == 'D' || a[row][col+1] == 'R')
            {
                t = 2;
            }
            else
            {
                a[row][col] = '.';
                a[row][col+1] = '@';
            }
            v--;
        }
    }
}

void Vader_movement(char** a, int N, int M){
        int s1, s2 ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 'L') {
                    s1 = i;
                    s2 = j;
                }
            }
        }
        int row, col ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] == 'D') {
                    row = i;
                    col = j;
                }
            }
        }
        if(row == (M-1) || a[row][col+1] == 'X' || a[row][col+1] == '@' || a[row][col+1] == 'R' || 
           row == (N-1) || a[row+1][col] == 'X' || a[row+1][col] == '@' || a[row+1][col] == 'R' ||
           col == 0 || a[row][col-1] == 'X' || a[row][col-1] == '@' || a[row][col-1] == 'R' ||
           row == 0 || a[row-1][col] == 'X' || a[row-1][col] == '@' || a[row-1][col] == 'R' ||
           a[row-1][col-1] == 'X' || a[row-1][col-1] == '@' || a[row-1][col-1] == 'R' ||
           a[row-1][col+1] == 'X' || a[row-1][col+1] == '@' || a[row-1][col+1] == 'R' ||
           a[row+1][col-1] == 'X' || a[row+1][col-1] == '@' || a[row+1][col-1] == 'R' ||
           a[row+1][col+1] == 'X' || a[row+1][col+1] == '@' || a[row+1][col+1] == 'R')
        {
            printf("I see you");
        }
        else if(s1 == row && s2 > col)
        {
            a[row][col] = '.';
            a[row][col+1] = 'D';
        }
        else if(s1 == row && s2 < col)
        {
            a[row][col] = '.';
            a[row][col-1] = 'D';
        }
        else if(s2 == col && s1 > row)
        {
            a[row][col] = '.';
            a[row+1][col] = 'D';
        }
        else if(s2 == col && s2 < row)
        {
            a[row][col] = '.';
            a[row-1][col] = 'D';
        }
}

void new_game(char** a, int N, int M, int s, int ob){
    if(s > 2)
    {
        //Free memory allocated for the 2D array
        free2DArray(a, N);
        char** a = array_creator(N,M);
        random_placement(a,N,M,s,ob);
        printf("\n");
        print_table(a,N,M);
        moveset_Leia (a,N,M,s);
        s--;
    }
    else 
    {
        printf("Concratulations");
        printf("You WON!");
    }
}
