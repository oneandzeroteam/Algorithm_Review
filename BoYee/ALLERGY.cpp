#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n,m;
int best =100000;

void fastsearch(int edible[], vector<int> *eaters, vector<int> *canEat, int& chosen)
{
 	 
 	 int first = 0;
 	 
	  // 아직도 먹을것이 없는 친구를 찾자. 
	  while ( first < n && edible[first] != 0) first++;
	  
	  // 다들 먹을것이 있다. 
	  if(first == n) 
	  {
				for(int i=0; i<n; i++)
				{
				 		printf("edible[%d] : %d ", i,edible[i]);
				}
				cout << "chosen : "<< chosen << "\n";	   		 
				  	  
	   		   // 지금 고른 음식의 개수가 이전보다 적다. 
	   		   if (chosen < best) 
	   		   	  { best = chosen; return; }
	  }
	  
	  // 아직 먹지 못한 친구의 id는 first, first가 먹을 수 있는 음식을 한개씩 만들어 보자.
	  for(int i=0; i<canEat[first].size(); i++)
	  {
	   		  int which = canEat[first][i];
				 
				 // 먹어보자. 
		 		 for(int j=0; j<eaters[which].size(); j++)
				 		 edible[eaters[which][j]]++;
	 		    
		 		chosen++;
				fastsearch(edible, eaters, canEat, chosen); 
	  			chosen--;
	  			
	  			for(int j=0; j<eaters[which].size(); j++)
				 		 edible[eaters[which][j]]--;
	  }
	  
}

void slowsearch(int& food, int edible[], vector<int> *eaters, int& chosen)
{
 		 
 	 if(food == m){
	 		 	
     // debug, print edible array.
	for(int i=0; i<n; i++)
	{
	 		printf("edible[%d] : %d ", i,edible[i]);
	}
	cout << "chosen : "<< chosen << "\n";
	
	 			int check =1;
				for(int i=0; i<n; i++)
				{
				 		if(edible[i] ==0)
			 			{ check = 0; break;}	 
				}
				
				if(check == 1)
  				{ best = chosen; return; }
  				else
  					return;
  				
	  }
	  
	  food++;
	  slowsearch(food, edible, eaters, chosen);
	  food--;
	  			
	  // Let's eat!!
	  for(int j=0; j<eaters[food].size();j++)
	  		  edible[eaters[food][j]]++;
	  
	  food++; chosen++;
	  slowsearch(food, edible, eaters, chosen);
	  food--; chosen--;
	  //rollback
	  for(int j=0; j<eaters[food].size(); j++)
	  		  edible[eaters[food][j]]--;
}

int main(int argc, char *argv[])
{
	cin >> n >> m;
 	printf("n: %d m: %d\n ",n,m); // n is # of friends and m is # of food types.
 	vector<string> friends; 	
 	vector<int> eaters[m]; // eaters[i] contains the 'id's of friends who could eat food i.
 	vector<int> canEat[n]; // canEat[i] contains the 'id's of foods friend i could eat. 
 	int edible[n]; // edible[j] indicates the number of foods that friends j could eat.
 	memset(edible, 0, n*sizeof(int));
 	
	 // get friend's names. 	
 	for(int i=0; i<n; i++)
 	{
	 		string input;
	  		cin >> input;
 	 		friends.push_back(input);		
	 }
	 
	 // debug, print friends vector.
	 for(int i=0; i<n; i++)
	 {
	  		 cout << friends[i] << " ";
	 }
    cout << "\n";
 	
 	// who could eat eaters[i], insert the id of friends.
 	for(int i =0; i< m; i++)
 	{
	 	 int count;
		 cin >> count; // how many friends want to eat food i?
	 	 for(int j=0; j<count; j++)
	 	 {
		  		 string name;
	 			 cin >> name ;
		  		 int k;
		  		 for(k =0; k<n; k++)
		  		 {
				  	  if(name == friends[k])
				  	  {
					   		  cout << "catch "<< name << "\n";
					   		  break;
					  }
				 }
				 // homonym.
		  		 canEat[k].push_back(i); // friend k could eat food i.
		  		 eaters[i].push_back(k); // food i could be eaten by friend k.
		 }
	}
	
	//debug, print the eaters vecotr.
	for(int i=0; i<m; i++)
	{
	 		for(int j=0; j<eaters[i].size();j++)
	 				cout << eaters[i][j] << " ";
				
	cout << "\n";
	}
	
	int chosen = 0;
	int food = 0;
	int& chosen_ref = chosen;
	int& food_ref = food;
	
	// start putting contents of edible array from food id 0.
	//slowsearch(food_ref, edible, eaters, chosen_ref);
	fastsearch(edible, eaters, canEat, chosen_ref);
	
	// debug, print edible array.
	for(int i=0; i<n; i++)
	{
	 		printf("edible[%d] : %d ", i,edible[i]);
	}
	cout << "\n";
 	
    system("PAUSE");
    return EXIT_SUCCESS;
}


//void gogo(int& chosen, int& food)
//{
// 	 chosen++;
// 	 	cout << chosen << " " << food << "\n";
//}
//int main(int argc, char *argv[])
//{
//
//	int chosen = 1;
//	int food = 2;
//	int& chosen_ref = chosen;
//	int& food_ref = food;
//	
//	cout << chosen << " " << food << "\n";
//	cout << chosen_ref << " " << food_ref << "\n";
//	
//	gogo(chosen_ref, food_ref);
// 		cout << chosen_ref << " " << food_ref << "\n";
//    system("PAUSE");
//    return EXIT_SUCCESS;
//}

