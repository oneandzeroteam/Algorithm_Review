#include <cstdlib>
#include <iostream>
# define L 2000000000
using namespace std;

int ratio(double a, double b)
{
 	// a/b
 	return ( (100 * a ) / b );
}
double ration(double a, double b)
{
 	// a/b
 	return  ( (100 * a ) / b );
}
int neededGame(double G, double W)
{
 	if(ratio(W,G) == ratio(W+L, G+W))
 				  return -1;
   
   double low= 0, high= L;
   int count = 0;
   printf("curr ratio : %d\n",ratio(W,G)); //??
   double aim = ration(W,G) +1 ;
   while(low +1 < high)
   {
   			   double mid = (low + high)/2;
   			  // printf("call : %f, %f ----- %f ----- %f\n",ration(W+mid, G+mid),low,mid,high);
   			   
   			   if( aim > ration(W + mid, G+mid))
   			   				 low = mid;
		       else
		       	   			 high = mid;
		       	    printf("call : %f, %f ----- %f ----- %f\n",ration(W+mid, G+mid),low,mid,high);			 
		 			
	 }
		 return high +1;
  
}

int main(int argc, char *argv[])
{
 	double G,W;
 	scanf("%lf %lf",&G,&W);
 	printf ("result : %d",neededGame(G,W));
    system("PAUSE");
    return EXIT_SUCCESS;
}
