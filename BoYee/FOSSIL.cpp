#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct point{
	   double x,y;
};

vector<point> hull1, hull2;
vector<pair<point, point> > upper, lower;

void decompose(const vector<point>& hull) {
	 // traverse all points in the hull.
	 int n = hull.size();
	 for(int i=0;i<n;i++)
	 {
	  		 if(hull[i].x < hull[(i+1)%n].x)
	  		 			  lower.push_back(make_pair(hull[i], hull[(i+1)%n]));
           else
           	   			  upper.push_back(make_pair(hull[i], hull[(i+1)%n]));       	   			  
	 }	 
}

bool between(const point& a, const point& b, double x)
{
 	 // cosnt reference 사용.
	  // experiment
	 // a = 1;
	 // a.x = 1;
	   
 	 return ( (a.x <= x && b.x >=x) || (b.x <= x && a.x >= x) );
}

double at(const point& a, const point &b, double x)
{
 	   double dx = b.x - a.x;
 	   double dy = b.y - a.y;
		double my = ( dy * x ) /dx + ( a.y * dx ) / (a.x * dy );
 	   double yongman = a.y + (dy / dx) * (x - a.x);
 	   printf (" my : %f ,youngman : %f\n",my,yongman);
 	   return my;   
}

double vertical(double x)
// vertical 계산을 왜 이렇게 복잡하게 하는거지?, x 위치에서 계산할 부분은 하나 아닌가? 
{
 	   double minUp =1e20;
 	   double maxLow = -1e20;
 	   
 	   for(int i=0;i<upper.size();i++)
 	   {
	   		   if( between(upper[i].first, upper[i].second, x) )
	   		   	   minUp = min ( minUp, at(upper[i].first, upper[i].second, x));
	   }
	   
	   for (int i=0;i<lower.size();i++)
	   {
	   	   if( between(lower[i].first, lower[i].second, x) )
	   	   	   maxLow = max( maxLow, at(lower[i].first, lower[i].second, x));
	   }
	   
	   return minUp - maxLow;
}

double minX(const vector<point>& hull)
{
 	   double mini = hull[0].x;
 	   for(int i=1;i<hull.size();i++)
 	   {
	   		   mini = min( mini, hull[i].x );
	   }
	   return mini;
}

double maxX(const vector<point>& hull)
{
 	   double maxx = hull[0].x;
 	   for(int i=1;i<hull.size();i++)
 	   {
	   		   maxx = max( maxx, hull[i].x );
	   }
	   return maxx;
}

double solve()
{
 	   // 두 hull이 겹칠 가능성이 높은 부분을 찾는다. 
 	   double lo = max(minX(hull1), minX(hull2)); 
 	   double hi = min(maxX(hull1), maxX(hull2));
		
		if( lo > hi )	return 0; // hull1 <---> hull2 좌우로 떨어져 있을 경우.
		
		for(int iter=0;iter<100;iter++)
		{
		 		double aab = (lo*2 + hi)/ 3.0;
		 		double abb = (lo + hi*2)/ 3.0;
		
				if(vertical(aab) < vertical(abb))
				 				 lo = aab;
			    else
			 	 				 hi = abb;
		}
		return max(0.0, vertical(hi)); 
		// hull1과 hull2가 수직으로 떨어져 있을 경우, vertical이 음수를 반환한다. 
}

int main(int argc, char *argv[])
{
 	int n,m;
 	scanf("%d %d\n",&n,&m);
 	printf("%d %d\n",n,m);
 	for(int i=0;i<n;i++)
 	{
	 		struct point *p = (struct point *)malloc(sizeof(struct point));
			scanf("%lf %lf ",&((*p).x),&((*p).y));
   			hull1.push_back(*p);
   			printf("%f %f\n",hull1[i].x, hull1[i].y);
	}		
 	
 	
    system("PAUSE");
    return EXIT_SUCCESS;
}
