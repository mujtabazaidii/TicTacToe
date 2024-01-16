#include<iostream>
#include<time.h>
using namespace std;
int main() {
    int draw = 0;
    char c;
    char multi[100];
    do {
        //menu for the 3 nums 

        cout << "a: multiplayer" << endl;

        cout << "b: computer player" << endl;
        cin >> multi;
        char ans[3];
        int temp;
        temp = 0;
        for (int i = 0; multi[i] != '\0'; i++) {
            temp++;
        }
        if (temp > 1) {
            cout << "\n Please enter valid option \n";
            continue;
        }



        //multiplayer
        if (multi[0] == 'a') {
            int a[9] = { 0,1,2,3,4,5,6,7,8 };
            int o = 0;
            cout << "please use these ref points to play game \n";


            for (int i = 1; i <= 3; i++) {//controling rows
                cout << endl;
                for (int z = 1; z <= 3; z++) {//controlling colum 
                    if (z == 3) {//to skip last colum
                        cout << a[o];
                        o++;
                    }
                    else {
                        cout << a[o] << "|";
                        o++;
                    }
                }
                cout << endl;
                if (i == 3) {//to skip last  
                    cout << " | |";
                }
                else {
                    cout << "_|_|_";
                }
            }



            cout << endl;
            cout << "use x and o formate" << endl;
            char plc;
            char b[9]{ 0,0,0,0,0,0,0,0,0 };
            o = 0;


            //defining ka kis ka turn ha 
            for (int game = 0; game < 9; game++) {//main outer loop 

                if (game % 2 == 0) {
                    cout << "Player 1 turn" << endl;
                }
                else if (game % 2 != 0) {

                    cout << "Player 2 turn" << endl;

                }






                //inputs 
                cout << "please enter your positon:";
                cin >> ans;//taking input for place 
                temp = 0;
                for (int i = 0; ans[i] != '\0'; i++) {//checking ka aik sa zayada input to nahi de diya like 40-50 
                    temp++;
                }
                if (temp > 1) {
                    cout << "invalid" << endl;
                    game--;
                    continue;
                }
                plc = ans[0];

                if (plc >= '0' && plc <= '8') {//check ka place ka input 0-8 ki range main ha ya nahi 

                }
                else {
                    cout << "invalid" << endl;
                    game--;
                    continue;
                }
                plc = plc - 48; //subtracting q ke plc ko agar as a index use krain to 0 ana chahiye 
                if (b[plc] == 'x' || b[plc] == 'o') {//check ka yahan already kuch ha ka nahi 
                    cout << "\n this place is already used please use another place" << endl;
                    game = game - 1;
                    continue;

                }



                //entering o or x 
                if (game % 2 == 0) {
                    b[plc] = 'x';
                }
                else if (game % 2 != 0) {
                    b[plc] = 'o';
                }



                //dubara sa print 
                o = 0;

                for (int i = 1; i <= 3; i++) {//printing rows 

                    cout << endl;
                    for (int z = 1; z <= 3; z++) {//printing colums
                        if (b[o] == 'x' || b[o] == 'o') {//check ke agar kisi position pa x ya o to nahi a gaya 
                            if (z == 3) {//agar vo position end ki ha to formate ka liya | skip
                                cout << b[o];//printing out b 
                                o++;

                            }
                            else {//agar ending position nahi to | a jaye gi 
                                cout << b[o] << "|";
                                o++;
                            }
                        }
                        else {
                            if (z == 3) {//check ke agar x ya o nahi to kiya ho ga 
                                cout << a[o];//x ya o nahi to simple counting a jaye gi 
                                o++;
                            }
                            else {
                                cout << a[o] << "|";//uppar vala for formate 
                                o++;
                            }

                        }
                    }
                    if (i == 3) {
                        cout << endl;
                        cout << " | | ";//last line cute rakhnay ke liya 

                    }
                    else {
                        cout << endl;//baki lines ke liye 
                        cout << "_|_|_";
                    }
                }



                cout << endl;



                //conditions 



                if (b[0] == 'x' && b[3] == 'x' && b[6] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else  if (b[1] == 'x' && b[4] == 'x' && b[7] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[2] == 'x' && b[5] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[0] == 'x' && b[4] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[2] == 'x' && b[4] == 'x' && b[6] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[0] == 'x' && b[1] == 'x' && b[2] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[3] == 'x' && b[4] == 'x' && b[5] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[6] == 'x' && b[7] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }

                else  if (b[0] == 'o' && b[3] == 'o' && b[6] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else  if (b[1] == 'o' && b[4] == 'o' && b[7] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[2] == 'o' && b[5] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[o] == 'o' && b[4] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[2] == 'o' && b[4] == 'o' && b[6] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[0] == 'o' && b[1] == 'o' && b[2] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[3] == 'o' && b[4] == 'o' && b[5] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[6] == 'o' && b[7] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }


                //draw condition 
                else {
                    draw = 0;
                    for (int i = 0; i < 9; i++) {
                        if (b[i] == 'x' || b[i] == 'o') {
                            draw = 1;//so its checking ka poray map main agar kahi bhi jaha nahi bachi to draw ho jaye ga 
                        }
                        else {
                            draw = 0;
                            break;
                        }
                    }
                }
                if (draw == 1) {
                    cout << "Match is draw ";
                    break;
                }



            }
        }








        //difficult mode





        else if (multi[0] == 'b') {
            srand(time(0));
            int a[9] = { 0,1,2,3,4,5,6,7,8 };
            int o = 0;
            cout << "please use these ref points to play game \n";
            //for orignal map 

            for (int i = 1; i <= 3; i++) {//controling rows
                cout << endl;
                for (int z = 1; z <= 3; z++) {//controlling rows 
                    if (z == 3) {//to skip last colum
                        cout << a[o];
                        o++;
                    }
                    else {
                        cout << a[o] << "|";
                        o++;
                    }
                }
                cout << endl;
                if (i == 3) {//to skip last   
                    cout << " | |";
                }
                else {
                    cout << "_|_|_";
                }
            }



            cout << endl;
            cout << "use x and o formate" << endl;
            char plc;
            char b[9]{ 0,0,0,0,0,0,0,0,0 };



            for (int game = 0; game < 9; game++) {

                if (game % 2 == 0) {
                    cout << "please enter position" << endl;
                }
                else if (game % 2 != 0) {

                    cout << "computer playing  " << endl;

                }

                //inputs 



                 //first player
                if (game % 2 == 0) {
                    cin >> ans;//taking input for place 
                    temp = 0;
                    for (int i = 0; ans[i] != '\0'; i++) {
                        temp++;
                    }
                    if (temp > 1) {
                        cout << "invalid" << endl;
                        game--;
                        continue;
                    }
                    plc = ans[0];

                    if (plc >= '0' && plc <= '8') {

                    }
                    else {
                        cout << "invalid" << endl;
                        game--;
                        continue;
                    }
                    plc = plc - 48;
                    if (b[plc] == 'o' || b[plc] == 'x') {
                        game = game - 1;
                        cout << "chose another position";
                        continue;
                    }
                    b[plc] = 'x';

                }



                //computer
                else if (game % 2 != 0) {


                    //making computer smart 


                    if (b[1] == 'o' && b[2] == 'o') {
                        if (b[0] == 'o' || b[0] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 0;
                            goto q;
                        }
                    }
                    else if (b[0] == 'o' && b[2] == 'o') {
                        if (b[1] == 'o' || b[1] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 1; goto q;
                        }


                    }
                    else  if (b[0] == 'o' && b[1] == 'o') {
                        if (b[2] == 'o' || b[2] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 2; goto q;
                        }

                    }
                    else  if (b[3] == 'o' && b[4] == 'o') {
                        if (b[5] == 'o' || b[5] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 5; goto q;
                        }

                    }
                    else if (b[5] == 'o' && b[3] == 'o') {
                        if (b[4] == 'o' || b[4] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 4; goto q;
                        }

                    }
                    else  if (b[4] == 'o' && b[5] == 'o') {
                        if (b[3] == 'o' || b[3] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 3; goto q;
                        }

                    }
                    else  if (b[6] == 'o' && b[7] == 'o') {
                        if (b[8] == 'o' || b[8] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 8; goto q;
                        }

                    }
                    else  if (b[6] == 'o' && b[8] == 'o') {
                        if (b[7] == 'o' || b[7] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 7; goto q;
                        }

                    }
                    else  if (b[7] == 'o' && b[8] == 'o') {
                        if (b[6] == 'o' || b[6] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 6; goto q;
                        }

                    }
                    else  if (b[0] == 'o' && b[3] == 'o') {
                        if (b[6] == 'o' || b[6] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 6; goto q;
                        }

                    }
                    else  if (b[0] == 'o' && b[6] == 'o') {
                        if (b[3] == 'o' || b[3] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 3; goto q;
                        }

                    }
                    else if (b[3] == 'o' && b[6] == 'o') {
                        if (b[0] == 'o' || b[0] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 0; goto q;
                        }

                    }
                    else  if (b[1] == 'o' && b[4] == 'o') {
                        if (b[7] == 'o' || b[7] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 7; goto q;
                        }

                    }
                    else  if (b[1] == 'o' && b[7] == 'o') {
                        if (b[4] == 'o' || b[4] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 4; goto q;
                        }

                    }
                    else if (b[4] == 'o' && b[7] == 'o') {
                        if (b[1] == 'o' || b[1] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 1; goto q;
                        }

                    }
                    else  if (b[2] == 'o' && b[5] == 'o') {
                        if (b[0] == 'o' || b[0] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 0; goto q;
                        }
                    }
                    else if (b[2] == 'o' && b[8] == 'o') {
                        if (b[5] == 'o' || b[5] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 5; goto q;
                        }
                    }
                    else if (b[8] == 'o' && b[5] == 'o') {
                        if (b[2] == 'o' || b[2] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 2; goto q;
                        }
                    }
                    else if (b[0] == 'o' && b[4] == 'o') {
                        if (b[8] == 'o' || b[8] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 8; goto q;
                        }
                    }
                    else if (b[8] == 'o' && b[0] == 'o') {
                        if (b[4] == 'o' || b[4] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 4; goto q;
                        }
                    }
                    else if (b[4] == 'o' && b[8] == 'o') {
                        if (b[0] == 'o' || b[0] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 0; goto q;
                        }
                    }
                    else if (b[2] == 'o' && b[4] == 'o') {
                        if (b[6] == 'o' || b[6] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 6; goto q;
                        }
                    }
                    else if (b[2] == 'o' && b[6] == 'o') {
                        if (b[4] == 'o' || b[4] == 'x') {
                            goto p;
                        }
                        else {
                            plc = 4; goto q;
                        }
                    }
                    else if (b[6] == 'o' && b[4] == 'o') {
                        if (b[2] == 'o' || b[2] == 'x') {

                            goto p;
                        }
                        else {
                            plc = 2; goto q;
                        }
                    }

                p:
                    if (b[1] == 'x' && b[2] == 'x') {

                        if (b[0] == 'x' || b[0] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 0;
                        }
                    }
                    else if (b[0] == 'x' && b[2] == 'x') {
                        if (b[1] == 'x' || b[1] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 1;
                        }
                    }
                    else  if (b[0] == 'x' && b[1] == 'x') {
                        if (b[2] == 'x' || b[2] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 2;
                        }
                    }
                    else  if (b[3] == 'x' && b[4] == 'x') {
                        if (b[5] == 'x' || b[5] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 5;
                        }
                    }
                    else if (b[5] == 'x' && b[3] == 'x') {
                        if (b[4] == 'x' || b[4] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 4;
                        }
                    }
                    else  if (b[4] == 'x' && b[5] == 'x') {
                        if (b[3] == 'x' || b[3] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 3;
                        }
                    }
                    else  if (b[6] == 'x' && b[7] == 'x') {
                        if (b[8] == 'x' || b[8] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 8;
                        }
                    }
                    else  if (b[6] == 'x' && b[8] == 'x') {
                        if (b[7] == 'x' || b[7] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 7;
                        }
                    }
                    else  if (b[7] == 'x' && b[8] == 'x') {
                        if (b[6] == 'x' || b[6] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 6;
                        }
                    }
                    else  if (b[0] == 'x' && b[3] == 'x') {
                        if (b[6] == 'x' || b[6] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 6;
                        }
                    }
                    else  if (b[0] == 'x' && b[6] == 'x') {
                        if (b[3] == 'x' || b[3] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 3;
                        }
                    }
                    else if (b[3] == 'x' && b[6] == 'x') {
                        if (b[0] == 'x' || b[0] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 0;
                        }
                    }
                    else  if (b[1] == 'x' && b[4] == 'x') {
                        if (b[7] == 'x' || b[7] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 7;
                        }
                    }
                    else  if (b[1] == 'x' && b[7] == 'x') {
                        if (b[4] == 'x' || b[4] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 4;
                        }
                    }
                    else if (b[4] == 'x' && b[7] == 'x') {
                        if (b[1] == 'x' || b[1] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 1;
                        }
                    }
                    else  if (b[2] == 'x' && b[5] == 'x') {
                        if (b[8] == 'x' || b[8] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 8;
                        }
                    }
                    else if (b[2] == 'x' && b[8] == 'x') {
                        if (b[5] == 'x' || b[5] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 5;
                        }
                    }
                    else if (b[8] == 'x' && b[5] == 'x') {
                        if (b[2] == 'x' || b[2] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 2;
                        }
                    }
                    else if (b[0] == 'x' && b[4] == 'x') {
                        if (b[8] == 'x' || b[8] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 8;
                        }
                    }
                    else if (b[8] == 'x' && b[0] == 'x') {
                        if (b[4] == 'x' || b[4] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 4;
                        }
                    }
                    else if (b[4] == 'x' && b[8] == 'x') {
                        if (b[0] == 'x' || b[0] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 0;
                        }
                    }
                    else if (b[2] == 'x' && b[4] == 'x') {
                        if (b[6] == 'x' || b[6] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 6;
                        }
                    }
                    else if (b[2] == 'x' && b[6] == 'x') {
                        if (b[4] == 'x' || b[4] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 4;
                        }
                    }
                    else if (b[6] == 'x' && b[4] == 'x') {
                        if (b[2] == 'x' || b[2] == 'o') {
                            plc = rand() % 9;
                        }
                        else {
                            plc = 2;
                        }
                    }

                    else {
                        plc = rand() % 9;
                    }

                    //check agar pehlay sa hi idhar num ha ya nahi 

                q:
                    if (b[plc] == 'x' || b[plc] == 'o') {
                        game = game - 1;

                        continue;
                    }
                    b[plc] = 'o';

                }


                //dubara sa print 



                o = 0;

                for (int i = 1; i <= 3; i++) {//printing rows 

                    cout << endl;
                    for (int z = 1; z <= 3; z++) {//printing colums
                        if (b[o] == 'x' || b[o] == 'o') {//check ke agar kisi position pa x ya o to nahi a gaya 
                            if (z == 3) {//agar vo position end ki ha to formate ka liya | skip
                                cout << b[o];//printing out b 
                                o++;

                            }
                            else {//agar ending position nahi to | a jaye gi 
                                cout << b[o] << "|";
                                o++;
                            }
                        }
                        else {
                            if (z == 3) {//check ke agar x ya o nahi to kiya ho ga 
                                cout << a[o];//x ya o nahi to simple counting a jaye gi 
                                o++;
                            }
                            else {
                                cout << a[o] << "|";//uppar vala for formate 
                                o++;
                            }

                        }
                    }
                    if (i == 3) {
                        cout << endl;
                        cout << " | | ";//last line cute rakhnay ke liya 

                    }
                    else {
                        cout << endl;//baki lines ke liye 
                        cout << "_|_|_";
                    }
                }
                cout << endl;


                //conditions 




                if (b[0] == 'x' && b[3] == 'x' && b[6] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else  if (b[1] == 'x' && b[4] == 'x' && b[7] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[2] == 'x' && b[5] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[0] == 'x' && b[4] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[2] == 'x' && b[4] == 'x' && b[6] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[0] == 'x' && b[1] == 'x' && b[2] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[3] == 'x' && b[4] == 'x' && b[5] == 'x') {
                    cout << "player 1 wins";
                    break;
                }
                else if (b[6] == 'x' && b[7] == 'x' && b[8] == 'x') {
                    cout << "player 1 wins";
                    break;
                }

                else  if (b[0] == 'o' && b[3] == 'o' && b[6] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else  if (b[1] == 'o' && b[4] == 'o' && b[7] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[2] == 'o' && b[5] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[o] == 'o' && b[4] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[2] == 'o' && b[4] == 'o' && b[6] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[0] == 'o' && b[1] == 'o' && b[2] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[3] == 'o' && b[4] == 'o' && b[5] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else if (b[6] == 'o' && b[7] == 'o' && b[8] == 'o') {
                    cout << "player 2 wins";
                    break;
                }
                else {
                    draw = 0;
                    for (int i = 0; i < 9; i++) {
                        if (b[i] == 'x' || b[i] == 'o') {
                            draw = 1;
                        }
                        else {
                            draw = 0;
                            break;

                        }
                    }
                }
                if (draw == 1) {
                    cout << "Match is draw ";
                    break;
                }


            }
        }
        else {
            cout << "\n Please enter valid option \n";
            continue;
        }
        //exit 
        cout << "\n please enter x to exit game";
        cout << "\n press any other key to play again";
        cin >> c;
    } while (c != 'x');
    return 0;
}
