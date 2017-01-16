#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
string obj[100];
int n;
int maxVol;
int vol[100];
int need[100];
int dp[1001][101];
int backtrack[1001][101];
vector<int> ans;


int solve(int nowVol, int objNum)
{
    printf("nowVol : %d objNum : %d\n",nowVol, objNum);
    if(objNum == n)
    return 0;
    
    if(dp[nowVol][objNum] != -1)
    return dp[nowVol][objNum];
    // caching 정보 
    
    
    int ret = 0, maxObjNum = -1, tempRet;
    if (nowVol - vol[objNum] >= 0)
    {
               printf("i pickup %d\n",objNum);
               tempRet = solve(nowVol - vol[objNum], objNum+1) + need[objNum];
               if(ret < tempRet){
               ret = tempRet;
               maxObjNum = objNum;
               }
    }
    // 집는 것 한번 
    
    printf("i skip %d\n",objNum);
    tempRet = solve(nowVol, objNum+1);
    if(ret < tempRet)
    {
           ret = tempRet;
           maxObjNum = -1;
           // 이 object는 없는게 더 좋다. 
           
    }
    // 놓고 가는것 한번 
    
    
    dp[nowVol][objNum] = ret;
    
    // 해당 object 집었을 때만 back track = 1 아니면  0 
    if(maxObjNum != -1)
                 backtrack[nowVol][objNum] =1;
    else 
                 backtrack[nowVol][objNum] =0;
                 
    return ret; 
                       
    
}

void setAns()
{
     int nowVol = maxVol;
     int objNum = 0;
     while(true)
     {
                // 이거 집었던 거야? 
                if(backtrack[nowVol][objNum])
                {
                 ans.push_back(objNum);
                 nowVol -= vol[objNum];
                }
                objNum++;
                if( objNum == n)
                    break;
     }
}

int main(int argc, char *argv[])
{
 
    int t;
    cin >> t;
    while (t--)
    {
          cin >> n >> maxVol;
          for(int i =0; i<n;i++)
          {
                  cin >> obj[i] >> vol[i] >> need[i];
          }
          // input 받기 object 크기 필요성
          
          memset(dp, -1, sizeof(dp));
          ans.clear(); 
          cout << solve(maxVol, 0) << " ";
          setAns();
          cout << " " << ans.size() << endl;
    }
        
    system("PAUSE");
    
    return EXIT_SUCCESS;
}
