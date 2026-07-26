#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <iomanip>


using namespace std;

int main()
{
    string total[10][4];
    string fname, lname, stop = "stop";
    bool check1 = false;
 cout << "\t\t---------------------------------------\n";
   cout << "\t\t|  Welcome to ABC's Table-Estimation  |\n";
    cout << "\t\t---------------------------------------\n\n";
    while(check1 == false)
{
 cout << "Please enter your Fullname \n";
         cin>>fname; cin>> lname;

       if( fname.length() > 2 && lname.length() > 2)
        {
             check1 = true;
        }
        else{
            check1 = false;
        }

       for (int i = 0; i < fname.length(); i++)
             {
               if (!isalpha(fname[i]))
                check1 = false;
             }

            for (int i = 0; i < lname.length(); i++)
             {
               if (!isalpha(lname[i]))
                check1 = false;
             }


          if(check1 == false)
          {
             cout <<"\nName must contain only letters and must have at least three characters\n";
          }
}

    for(int i=0; i<sizeof total / sizeof total[0];i++)
    {
         static string tabel[4];
    int selectedShape, selectedMaterial;
    float diameter, height, width, longbase, shortbase, theight, materialcostcost[2] = {12.5, 22.5};
    bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false, check6 = false;;
    string shapes[4] = {"Rectangular", "Circular", "Trapezoid"}, material[2] = {"Laminate", "Oak"}, endprogram="End Program", stop = "stop";
    double area; //


    cout << "\nWhat shape of table do you wish to build?\n";

    while(check2 == false)
    {
        bool checkdatatype = true;
       for(int i=0; i<(sizeof(shapes)/sizeof(string)); i++)// To iterate through the array
       {
        int no = i +1;
        if(no == (sizeof(shapes)/sizeof(string)))// this if statement output the result beside the array
        {

            cout << no << ". " << endprogram << endl;
            cout << "Enter menu entry: ";
            cin >> selectedShape;
             if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               checkdatatype = false;
             }
             cout <<"\n";
         if(selectedShape > 0 && selectedShape <= sizeof(shapes)/sizeof(string) ) //validate if the number is greater than 0 and less the array size
          {
          check2 = true;
          check2 = checkdatatype;
          }

            if(check2 == false)
            {
                cout <<"Invalid number please try again \n";
            }
        }
        else{
           cout << no << ". " << shapes[i] << endl;
        }
      }
    }

    int arrayindex = selectedShape-1;//subtract 1 from the selected shape to file the array index


    switch(arrayindex)
    {
     case 0:
         while(check3 == false)
         {
             bool heightisnumber = true;
             bool widthisnumber = true;

          cout << "Enter the width of the table: ";
          cin >> width;
          if (cin.fail()) { //validate if the user input other data type other than the defined(int)
               cin.clear();
               cin.ignore(256,'\n');
               widthisnumber = false;
           }
          cout << "Enter the Height of the table: ";
          cin >> height;
            if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               heightisnumber = false;
           }
            if(width > 0)//validate if the number is positive
            {
              check3 = true;
            }
             if(check3 == false || widthisnumber == false)
             {
                 cout << "\nPlease Enter a valid width (in inches)\n" << endl;
            if(height > 0)
            {
              check3 = true;
            }
             }
              else if(check3 == false || heightisnumber == false)
             {
                    cout << "Please Enter a valid height (in inches)\n" << endl;
             }
             else
             {
                 check3 = true;
             }
             }
         area = width * height; //calculate the area
         tabel[0] = shapes[arrayindex];
         tabel[1] = to_string(area);
     break;
     case 1:
          while(check4 == false)
          {
              bool diameterisnumber = true;
             cout << "Enter the diameter of the table: ";
             cin >> diameter;
             if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               diameterisnumber = false;
             }
             if(diameter > 0)
             {
              check4 = true;
             }
                 if(check4 == false || diameterisnumber == false)
                  {
                    cout << "\nPlease Enter a valid diameter\n"<<endl;
                  }
                  else
                  {
                    check4 = true;
                  }

          }
          area = M_PI * (diameter/2) * (diameter/2);
        tabel[0] = shapes[arrayindex];
         tabel[1] = to_string(area);
     break;
     case 2:
    while(check5 == false)
          {
        bool islongbasenumber = true;
        bool isshortbasenumber = true;
        bool isheightnumber = true;
             cout << "Enter the short base of the table: ";
             cin >> shortbase;
                  if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               isshortbasenumber = false;
             }
              cout << "Enter the long base of the table: ";
             cin >> longbase;
                  if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               islongbasenumber = false;
             }
             cout << "Enter the height of the table: ";
             cin >> theight;
                  if (cin.fail()) {
               cin.clear();
               cin.ignore(256,'\n');
               isheightnumber = false;
             }
            if(shortbase > 0)
            {
              check5 = true;
            }
             if(check5 == false || isshortbasenumber == false)
             {
                 cout << "\nPlease Enter a valid short base\n"<<endl;
          if(longbase > 0)
            {
              check5 = true;
            }
             }
             else if(check5 == false || islongbasenumber==false)
             {
                    cout << "\nPlease Enter a valid long base\n"<<endl;
            if(theight > 0)
            {
              check5 = true;
            }
             }
              else if(check5 == false || isheightnumber==false)
             {
                    cout << "\nPlease Enter a valid height\n"<<endl;
             }
             else
             {
                 check5 = true;
             }
          }
          area = (shortbase + longbase)/ 2 * theight;
         tabel[0] = shapes[arrayindex];
         tabel[1] = to_string(area);
     break;
     default:
     tabel[0] = stop;
     break;
    }
          if(tabel[0] == stop)
             {
                 break;
             }
 cout <<""<< endl;

 //material and material cost
 while(check6 == false)
    {
       for(int i=0; i<(sizeof(material)/sizeof(string)); i++)
       {
        int no = i +1;
        cout << no << ". " << material[i] <<" ("<<materialcostcost[i]<<" Birr per square inches)\n";
        }
            cout << "Enter menu entry: ";
            cin >> selectedMaterial; cout <<"\n";

              if(selectedMaterial > 0 && selectedMaterial <= sizeof(material)/sizeof(string ))// validate the entered material if its greater than 0 and less than material array size which is 2
               {
                 check6 = true;
               }
            if(check6 == false)
            {
                cout <<"Invalid number please try again\n";
            }
       }
     cout <<"\n";


     tabel[2] = material[(selectedMaterial-1)];
     tabel[3] = to_string(area * materialcostcost[selectedMaterial-1]); //calculate and store the cost of the table

         for(int j=0; j<4; j++)// to store the table array in to multi dimetional array that have size of 10
         {
            total[i][j] = tabel[j];
         }
    }




    cout << "\t ABC company Table Estimation Report \n" ;
     cout << "\t  --------------------------------- \n\n" ;

    for(int i=0; i<=(sizeof total / sizeof total[0]); i++)
    {
        float discount, tabelcost, totalcost;
        tabelcost = std::atof(total[i][3].c_str());
         totalcost += tabelcost;

         if(total[0][0].empty())//if the user doesn't select any shape
         {
             cout << "Ooops! you did not request any estimates\nGoodbye!!\n\n";
             break;
         }
        if(total[i][0].empty() || i == (sizeof total / sizeof total[0]))
          {
              if(total[1][0].empty())//if the table contain one 1 table
              {
               cout <<"The cost of a table you estimated is "<< totalcost <<" Birr \n";
              }
              else
              {
               cout <<"The total cost of the "<< i <<" tables you estimated is "<< totalcost <<" Birr \n";
              }

         float fivePercentDiscountMin = 8000;
         float tenPercentDiscountMin = 24000;

         if(totalcost > fivePercentDiscountMin && totalcost < tenPercentDiscountMin)
         {
             discount = totalcost/20;
         }
         else if(totalcost > tenPercentDiscountMin)
         {
             discount = totalcost/10;
         }
         else{
            discount = 0;
         }

         if(discount > 0)
         {
             cout <<"Your discount is " << discount << " Birr \n";
             cout <<"Your final total is "<< totalcost-discount << " Birr \n";
         }
         cout << "Thank you for using the table cost estimation program!\nGoodbye!!\n\n";
         break;
     }


              if(total[1][0].empty())
              {
               cout<<"Table "<<endl; //if the user is only asked for one table
              }
              else
              {
               cout<<"Table "<<(i+1)<<endl;
              } //if the user is asked for multiple tables, the output will display the number of tables

	cout<<"\tThe area of the " <<total[i][0]<<" table is " <<(std::stof(total[i][1]))<<" square inches\n";
	cout<<"\tThe table will be made of " <<total[i][2]<<"\n";
    cout<<"\tThe cost of this table is " <<tabelcost<<" Birr\n\n";
    }

    return 0;
}



