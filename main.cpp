/**
 * Cashion Penha
 * Lab 7
 * Coordinate Conversion
 * 16/10/2017
 */

/**< preprocessor directives / header files*/
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <math.h>

using namespace std;/** Includes commonly used tools, such as cout, cin, To prevent typing "std" */

/**< Cartesian to Polar function, separate function to convert from Rectangular form to polar form*/
void cart_2_polar(double x, double y, double *r, double*t)
{
    *r = sqrt(pow(x,2)+pow(y,2));
    *t = atan2(y,x);/**< atan2 is used to determine the appropriate quadrant */
    cout.precision(4);
}

/**< Polar to Cartesian function, separate function to convert from Polar to rectangular form*/
void polar_2_cart(double radius, double theta, double *xval, double *yval)
{
    *xval= radius*cos(theta);
    *yval= radius*sin(theta);
     cout.precision(4);
}

/**< Separate function to display the menu when called in the main function*/
void menu(void)
{
	/**< clear screen - not good programming practice! - system specific */
	system("cls");

	cout <<"Cashion Penha - C00218875";

	/**< print menu */
	cout << "\n_______________________________________________" <<
            "\nExercise 7 - Coordinate Conversion" <<
			"\n\nChoose from one of the following:" <<
			"\np - Cartesian to Polar conversion" <<
			"\nc - Polar to Cartesian"
			"\nq - quit" <<
			"\n_______________________________________________" <<endl;

	return;
}


/**< main function */
int main(void)
{
	/**< variable declarations */
	char input;

	/**< continue running program until q is pressed */
	do
	{
		/**< display menu and get user input */
		menu();
		fflush(stdin);
		cin >> input;
		fflush(stdin);

		/**< switch case statement to implement user's decision */
		switch (input)
		{
		    /**< When p is entered by user, get values from user, and call the cartesian to polar function*/
			case 'p':   cout << "_______________________________________________";
                        cout << "\nCartesian to Polar coordinates conversion...\n" << endl;
                        double x,y,r,t;
                        char s1,s2,s3;/**< Simply using string to display brackets and comma within user input*/

                        cout << "Please enter the cartesian coordinate in form (x,y): ";
                        cin >> s1 >> x >> s2 >> y >> s3;/**< Determining the position of strings with respect to the answer*/

                        cart_2_polar(x,y,&r,&t);

                        cout << "\nThe magnitude is: " << r;
                        cout << "\nThe angle ø theta is: " << t*(180/M_PI) << " degrees";

                        fflush(stdin);
						getchar();
						break;

			/**< When c is entered by user, get values from user, and call the polar to cartesian function*/
			case 'c':   cout << "_______________________________________________";
                        cout << "\nPolar to Cartesian conversion...\n" << endl;
                        double radius,theta,xval,yval;

                        cout << "Enter value for radius r: ";
                        cin >> radius;

                        cout << "Enter value for angle theta in radians: ";
                        cin >> theta;

                        polar_2_cart(radius,theta,&xval,&yval);

                        cout << "\nThe Cartesian coordinates are (x,y): " << "("<< xval << ","<< yval << ")";
                        cout << "\nWhere the x value is: "<< xval << " and the y value is: "<< yval << endl;

                        fflush(stdin);
						getchar();
						break;

			/**< When q is entered by user, provide salutation and end the program*/
			case 'q':   cout << "_______________________________________________";
                        cout << "\nThanks for using the program, Goodbye...\n" << endl;
                        cout << "Press any key to close window"<< endl;
                        fflush(stdin);
                        break;

            /**< When unknown value is entered by user, display the error and display menu again after a key is pressed */
			default:	cout << "\nInvalid input, try again...\n" << endl;
						/**< wait for key to be pressed */
						cout << "Press any key to continue..." << endl;
						fflush(stdin);
						getchar();
						break;
		}
	}
	while (input != 'q');/**< Keep looping until q is not entered by the user, the menu will simply be displayed unless terminated */

	return 0;
}
