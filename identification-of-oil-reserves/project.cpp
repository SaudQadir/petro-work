#include <stdio.h>
#include <conio.h> 
#include <iostream>
#include <string>
using namespace std;

struct res
{
	string height_str;							//This is Height of Core Sample
	int height;

	string depth_str;
	int depth;									//This is Depth of Well

	string radius_str;							//This is Radius of Core Sample
	int radius;

	string gvolume_str;							//This is Grain Volume Obtained From Core Sample
	int gvolume;

	string fvfactor_str;						//This is Formation Volume Factor
	int fvfactor;

	string swater_str;							//This is Water Saturation
	int swater;

	string area_str;							//This is Area of Reservoir
	int area;

	string c7_str;								//This is C7+ Molecules percentage
	int c7;

	string scf_str;								//This is Standard Cubic Feet of Gass dissolved in oil
	int scf;

	float gravity;								//This is specific gravity of fluid
	float api;									//This is API Gravity
	float bvolume;								//This is Bulk Volume 
	float pvolume;								//This is Pore Volume
	float porosity;								//This is Porosity of Rock
	float No;									//This is Estimated Number of Barrels of Oil in Initial Place	
	float Ng;									//This is Estimated Number of Barrels of Gas in Initial Place
	float stb;									//This is Stock Tank Barrel of Oil
	float goratio;								//This is Initial Gas Oil Ratio
	string rtype;

};
// Source: http://www.dreamincode.net/forums/topic/83273-numbers-only-no-letters-validation/
bool ifNumber(string input)
{
	bool ifnum = true;
	if (input.length() == 0)
	{
		ifnum = false;
	}
	else
	{
		for(int i=0; i<input.length(); i++ )
		if( input[i] < '0' || input[i] > '9')
		{
			ifnum = false;
			break;
		}
	}
	return ifnum;
}
// main function
int main()
{
	int x = 0, y = 0;									//For Switch cases
	res res1;
	res res2;
	cout << "************************************************Please Enter the Data of Reservoir************************************************" << endl;
	while(!ifNumber(res1.height_str))
	{
		cout << "\nEnter Height of Core Sample (in ft): ";
		cin >> res1.height_str;
	}
	res1.height= atoi(res1.height_str.c_str());

	while (!ifNumber(res1.depth_str))
	{
		cout << "\nEnter Depth of Well (in ft): ";
		cin >> res1.depth_str;
	}
	res1.depth = atoi(res1.depth_str.c_str());

	while(!ifNumber(res1.radius_str))
	{
		cout << "\nEnter Radius of Core Sample (in ft) : ";
		cin >> res1.radius_str;
	}
	res1.radius = atoi(res1.radius_str.c_str());

	while (!ifNumber(res1.swater_str))
	{
		cout << "\nEnter Water Saturation in Core Sample (in %) : ";
		cin >> res1.swater_str;
	}
	res1.swater = atoi(res1.swater_str.c_str());

	while (!ifNumber(res1.gvolume_str)) 
	{
		cout << "\nEnter Volume of Grain Size (cubic ft) : ";
		cin >> res1.gvolume_str;
	}
	res1.gvolume = atoi(res1.gvolume_str.c_str());
	
	while (!ifNumber(res1.fvfactor_str))
	{
		cout << "\nEnter Formation Volume Factor (res/stb): ";
		cin >> res1.fvfactor_str;
	}
	res1.fvfactor = atoi(res1.fvfactor_str.c_str());

		cout << "\nEnter Specific Gravity of Fluid : ";
		cin >> res1.gravity;

	while (!ifNumber(res1.scf_str))
	{
		cout << "\nEnter Standard Cubic Feet of Gass Dissolved in Fluid (in SCF) : ";
		cin >> res1.scf_str;
	}
	res1.scf = atoi(res1.scf_str.c_str());

	while(!ifNumber(res1.c7_str))
	{
		cout << "\nEnter percentage of C7+ molecules : ";
		cin >> res1.c7_str;
	}
	res1.c7 = atoi(res1.c7_str.c_str());
	
	while (!ifNumber(res1.area_str))
	{
		cout << "\nEnter Estimate Area Covered by Reservoir(in Acre) : ";
		cin >> res1.area_str;
	}
	res1.area = atoi(res1.area_str.c_str());

	//Formulae Applied
	
	res1.api = (141.5 / res1.gravity) - 131.5;
	res1.bvolume = 3.1416*res1.radius*res1.radius*res1.height;
	res1.pvolume = res1.bvolume - res1.gvolume;
	res1.porosity = res1.pvolume / res1.bvolume;
	res1.No = 7758 * res1.porosity*res1.area*res1.height*(1 - res1.swater/100);
	res1.Ng = 43560 * res1.area*res1.height*res1.porosity*(1-res1.swater/100)*res1.depth*43/1500;
	res1.stb = res1.No / res1.fvfactor;
	res1.goratio = res1.scf/1;											//as it is scf per stb

	if ( res1.goratio <= 2000 && res1.api < 45 && res1.fvfactor==2 && res1.c7>30)
		{ 
			res1.rtype = "Black Oil"; 
		}
	else if ( (res1.goratio >= 2000 && res1.goratio <= 3300) && res1.api >= 45 && res1.fvfactor>2 && (res1.c7>12.5 && res1.c7<30))
		{ 
			res1.rtype = "Volatile Oil"; 
		}
	else if ( (res1.goratio >= 3300 && res1.goratio <= 5000) && (res1.api >= 45 && res1.api <= 60) && res1.c7<12.5)
		{
			res1.rtype = "Retrograde Gasses"; 
		}
	else
	{
			res1.rtype = "Unknown Type";
	}
	system("CLS");
	cout << "************************************************Please Select the Desired Operation************************************************" <<endl;
	cout << "1: Identification of Reservoir \n\n2: Number of bbl of Oil Reserves \n\n3: Number of bbl of Gas Reserves \n\n4: Number of bbl of Stock Tank Oil \n\n5: Enter the data of 2nd Reservoir"<<endl;
	cin >> x;
	system("CLS");
	switch (x)
	{
	case 1:
		cout << "The Reservoir is of " << res1.rtype << endl;
		break;
	case 2:
		cout << "Oil Reserves Present in Reservoir are " << res1.No << " bbl " << endl;
		break;
	case 3:
		cout << "Gas Reserves Present in Reservoir are " << res1.Ng << " cubic ft " << endl;
		break;
	case 4:
		cout << "Oil Present on Surface will be " << res1.stb << " bbl " << endl;
		break;
	case 5:	
		cout << "************************************************Please Enter the Data of 2nd Reservoir************************************************" << endl;
		while (!ifNumber(res2.height_str))
		{
			cout << "\nEnter Height of Core Sample (in ft): ";
			cin >> res2.height_str;
		}
		res2.height = atoi(res2.height_str.c_str());

		while (!ifNumber(res2.depth_str))
		{
			cout << "\nEnter Depth of Well (in ft): ";
			cin >> res2.depth_str;
		}

		res2.depth = atoi(res2.depth_str.c_str());

		while (!ifNumber(res2.radius_str))
		{
			cout << "\nEnter Radius of Core Sample (in ft) : ";
			cin >> res2.radius_str;
		}

		res2.radius = atoi(res2.radius_str.c_str());

		while (!ifNumber(res2.swater_str))
		{
			cout << "\nEnter Water Saturation in Core Sample (in %) : ";
			cin >> res2.swater_str;
		}
		res2.swater = atoi(res2.swater_str.c_str());

		while (!ifNumber(res2.gvolume_str))
		{
			cout << "\nEnter Volume of Grain Size (cubic ft) : ";
			cin >> res2.gvolume_str;
		}
		res2.gvolume = atoi(res2.gvolume_str.c_str());

		while (!ifNumber(res2.fvfactor_str))
		{
			cout << "\nEnter Formation Volume Factor (res/stb): ";
			cin >> res2.fvfactor_str;
		}
		res2.fvfactor = atoi(res2.fvfactor_str.c_str());

		cout << "\nEnter Specific Gravity of Fluid : ";
		cin >> res2.gravity;

		while (!ifNumber(res2.scf_str))
		{
			cout << "\nEnter Standard Cubic Feet of Gass Dissolved in Fluid (in SCF) : ";
			cin >> res2.scf_str;
		}
		res2.scf = atoi(res2.scf_str.c_str());

		while (!ifNumber(res2.c7_str))
		{
			cout << "\nEnter percentage of C7+ molecules : ";
			cin >> res2.c7_str;
		}
		res2.c7 = atoi(res2.c7_str.c_str());

		while (!ifNumber(res2.area_str))
		{
			cout << "\nEnter Estimate Area Covered by Reservoir(in Acre) : ";
			cin >> res2.area_str;
		}
		res2.area = atoi(res2.area_str.c_str());

		//Formulae Applied

		res2.api = (141.5 / res2.gravity) - 131.5;
		res2.bvolume = 3.1416*res2.radius*res2.radius*res2.height;
		res2.pvolume = res2.bvolume - res2.gvolume;
		res2.porosity = res2.pvolume / res2.bvolume;
		res2.No = 7758 * res2.porosity*res2.area*res2.height*(1 - res2.swater / 100);
		res2.Ng = 43560 * res2.area*res2.height*res2.porosity*(1 - res2.swater / 100)*res2.depth*43 / 1500;
		res2.stb = res2.No / res2.fvfactor;
		res2.goratio = res2.scf / 1;											//as it is scf per stb

		if (res2.goratio <= 2000 && res2.api < 45 && res2.fvfactor == 2 && res2.c7>30)
		{
			res2.rtype = "Black Oil";
		}
		else if ((res2.goratio >= 2000 && res2.goratio <= 3300) && res2.api >= 45 && res2.fvfactor > 2 && (res2.c7 > 12.5 && res2.c7 < 30))
		{
			res2.rtype = "Volatile Oil";
		}
		else if ((res2.goratio >= 3300 && res2.goratio <= 5000) && (res2.api >= 45 && res2.api <= 60) && res2.c7 < 12.5)
		{
			res2.rtype = "Retrograde Gas";
		}
		else
		{
			res2.rtype = "Unknown Type";
		}
		system("CLS");
		cout << "************************************************Please Select the Desired Operation************************************************" << endl;
		cout << "\n1: Identification of 2nd Reservoir \n\n2: Number of bbl of Oil Reserves of 2nd Reservoir \n\n3: Number of bbl of Gas Reserves in 2nd Reservoir \n\n4: Number of bbl of Stock Tank Oil of 2nd Reservoir \n\n5: Compare Both Reservoir " << endl;
		cin >> y;
		system("CLS");
		switch (y)
			{
			case 1:
				cout << "The Second Reservoir is of " << res2.rtype << endl;
				break;
			case 2:
				cout << "Oil Reserves Present in Seconf Reservoir are " << res2.No << " bbl " << endl;
				break;
			case 3:
				cout << "Gas Reserves Present in Second Reservoir are " << res2.Ng << " cubic ft " << endl;
				break;
			case 4:
				cout << "Oil Present on Surface will be " << res2.stb << " bbl " << endl;
				break;
			case 5:
				if (res1.No > res2.No || res1.Ng < res2.Ng)
				{
					cout << "First Reservoir is more Economical and it is of " << res1.rtype << ". And Total Number of oil reserves" << res1.No << "bbl" << endl;
				}
				else if (res1.No < res2.No || res1.Ng>res2.Ng)
				{
					cout << "Second Reservoir is More Economical and it is of " << res2.rtype << "\nTotal Number of oil reserves are" << res2.No << " bbl" << endl;
				}
				else
				{
					cout << "Both Reservoir have Their Own Characteristics"<<endl;
				}
				break;
			default:
				cout << "Your Choice is incorrect"<<endl;
				break;
		}
	}
	getch();
	return 0;
}