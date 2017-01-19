#include "function.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <chrono>

//bool squares3(int a, int b, int c, int d, int e, int f, int g, int h, int i)
//{
//	for (int aa = a; aa < a + 10; ++aa)
//	{
//		for (int bb = b; bb <= b + 10; ++bb)
//		{
//			for (int cc = c; cc <= c + 10; ++cc)
//			{
//				for (int dd = d; dd <= d + 10; ++dd)
//				{
//					for (int ee = e; ee <= e + 10; ++ee)
//					{
//						for (int ff = f; ff <= f + 10; ++ff)
//						{
//							for (int gg = g; gg <= g + 10; ++gg)
//							{
//								for (int hh = h; hh <= h + 10; ++hh)
//								{
//									for (int ii = i; ii <= i + 10; ++ii)
//									{
//										if (aa == bb || aa == cc || aa == dd || aa == ee || aa == ff || aa == gg || aa == hh || aa == ii ||
//											aa == bb || bb == cc || bb == dd || bb == ee || bb == ff || bb == gg || bb == hh || bb == ii ||
//											cc == bb || aa == cc || cc == dd || cc == ee || cc == ff || cc == gg || cc == hh || cc == ii ||
//											dd == bb || dd == cc || aa == dd || dd == ee || dd == ff || dd == gg || dd == hh || dd == ii ||
//											ee == bb || ee == cc || ee == dd || aa == ee || ee == ff || ee == gg || ee == hh || ee == ii ||
//											ff == bb || ff == cc || ff == dd || ff == ee || aa == ff || ff == gg || ff == hh || ff == ii ||
//											gg == bb || gg == cc || gg == dd || gg == ee || gg == ff || aa == gg || gg == hh || gg == ii ||
//											hh == bb || hh == cc || hh == dd || hh == ee || hh == ff || hh == gg || aa == hh || hh == ii ||
//											ii == bb || ii == cc || ii == dd || ii == ee || ii == ff || ii == gg || ii == hh || aa == ii)
//										{
//											continue;
//										}
//
//										if (
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) + 
//											(aa + ee + ii) + (cc + ee + gg))/8 == (aa + bb + cc)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//											(aa + ee + ii) + (cc + ee + gg)) / 8 == (dd + ee + ff)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) + 
//											(aa + ee + ii) + (cc + ee + gg))/8 == (gg + hh + ii)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//												(aa + ee + ii) + (cc + ee + gg)) / 8 == (aa + dd + gg)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//												(aa + ee + ii) + (cc + ee + gg)) / 8 == (bb + ee + hh)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//												(aa + ee + ii) + (cc + ee + gg)) / 8 == (cc + ff + ii)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//												(aa + ee + ii) + (cc + ee + gg)) / 8 == (aa + ee + ii)
//											&&
//											((aa + bb + cc) + (dd + ee + ff) + (gg + hh + ii) +
//											(aa + dd + gg) + (bb + ee + hh) + (cc + ff + ii) +
//												(aa + ee + ii) + (cc + ee + gg)) / 8 == (cc + ee + gg)
//											&&
//
//											(aa != bb != cc != dd != ee != ff != gg != hh != ii))
//										{
//											std::cout << "Success!" << std::endl;
//											std::cout << aa << ", " << bb << ", " << cc << std::endl;
//											std::cout << dd << ", " << ee << ", " << ff << std::endl;
//											std::cout << gg << ", " << hh << ", " << ii << std::endl;
//											return 1;
//										}
//										else
//										{
//											std::cout << "Fail :(  on iteration " << aa << "." << bb <<
//												"." << cc << "." << dd << "." << ee << "." << ff <<
//												"." << gg << "." << hh << "." << ii << std::endl;
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}

void magicsquare(std::ofstream &outputFile, double E, double n, double m)
{
	/*Function for finding all magic squares of the form:
	 
	 E+n   E-n-m    E+m
	E-n+m    E     E+n-m
	 E-m   E+n+m    E-n
	 
	 For integers E, n, m, where each integer value cycles between 1 and user-inputted function arguments*/


	// initialise timer
	typedef std::chrono::high_resolution_clock Clock;
	auto time1 = Clock::now();
	int timeprint = 1;
	int successcount = 0;

	for (int EE = 1; EE < E; ++EE)
	{
		for (int nn = 1; nn < n; ++nn)
		{
			for (int mm = 1; mm < m; ++mm)
			{
				//TIMER - updates and displays message in console every ~5 seconds
				auto time2 = Clock::now();
				if (std::chrono::duration_cast<std::chrono::seconds>(time2 - time1).count() > 5)
				{
					std::cout << 5 * timeprint << " seconds elapsed at iteration " << EE << "." << nn << "." << mm << "; Successful results: " << successcount << std::endl;
					++timeprint;
					time1 = time2;
				}

				// Squares not possible if the below are true since they would result in some squares having same value
				if (mm == nn || mm == 2*nn || nn == 2*mm)
					continue;
				if (EE - nn - mm <= 0)
					continue;

				
				// Check that no square value is the same.
				else if((EE+nn) != (EE-nn-mm) != (EE+mm) != (EE-nn+mm) !=
					(EE) != (EE+nn-mm) != (EE-mm) != (EE+nn+mm) != (EE-nn))
				{
					outputFile << "Success!" << std::endl;
					outputFile << (EE+nn) << ", " << (EE-nn-mm) << ", " << (EE+mm) << std::endl;
					outputFile << (EE-nn+mm) << ", " << (EE) << ", " << (EE+nn-mm) << " Magic sum = " << 3*EE << std::endl;
					outputFile << (EE-mm) << ", " << (EE+nn+mm) << ", " << (EE-nn) << std::endl;
					++successcount;
				}
				
			}
		}
	}
}

void squareofsquares(std::ofstream &outputFile, double e, double h, double i)
{
	/*
	Function for finding the as yet undiscovered 'magic square of squares'
	Code is a work in progress. Has a logic error somewhere - currently lets squares through with some digits the same.
	*/

	// initialise timer
	typedef std::chrono::high_resolution_clock Clock;
	auto time1 = Clock::now();
	int timeprint = 1;
	int successcount = 0;

	double d_sqrt;
	int i_sqrt;

	for (int EE = 1; EE < e; ++EE)
	{
		for (int HH = 1; HH < h; ++HH)
		{
			for (int II = 1; II < i; ++II)
			{

				//TIMER - updates and displays message in console every ~5 seconds
				auto time2 = Clock::now();
				if (std::chrono::duration_cast<std::chrono::seconds>(time2 - time1).count() > 5)
				{
					std::cout << 5 * timeprint << " seconds elapsed at iteration " << EE << "." << HH << "." << II << "; Successful results: " << successcount << std::endl;
					++timeprint;
					time1 = time2;
				}

				if (EE == II || EE == HH || II == HH || e*EE*EE < II*II ||
					(2 * EE*EE) < HH*HH || EE*EE > (HH*HH + II*II) ||
					(2 * EE*EE) >(HH*HH + 2 * II*II) || (4 * EE*EE) < (HH*HH + 2 * II*II) ||
					(3 * EE*EE) < (II*II + HH*HH))
					continue;

				d_sqrt = sqrt(2 * EE*EE - II*II);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				d_sqrt = sqrt(2 * EE*EE - HH*HH);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				d_sqrt = sqrt(-(EE*EE) + HH*HH + II*II);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				d_sqrt = sqrt(-(2*EE*EE) + HH*HH + 2*II*II);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				d_sqrt = sqrt(4 * EE*EE - HH*HH - 2*II*II);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				d_sqrt = sqrt(3 * EE*EE - II*II - HH*HH);
				i_sqrt = d_sqrt;
				if (d_sqrt != i_sqrt)
					continue;

				else
				{
					outputFile << "Success!" << std::endl;
					outputFile << sqrt(2 * EE*EE - II*II) << ", " << sqrt(2 * EE*EE - HH*HH) << ", " << sqrt(-(EE*EE) + HH*HH + II*II) << std::endl;
					outputFile << sqrt(-(2 * EE*EE) + HH*HH + 2 * II*II) << ", " << EE << ", " << sqrt(4 * EE*EE - HH*HH - 2 * II*II) << " Magic sum = " << 3 * EE*EE << std::endl;
					outputFile << sqrt(3 * EE*EE - II*II - HH*HH) << ", " << HH << ", " << II << std::endl;
					++successcount;
				}
			}
		}
	}
}