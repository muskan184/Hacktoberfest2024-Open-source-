bool checkCows(vector<int>&stalls,int mid,int Givencows){
	int cows=1;//first number cow 
	int lastPos=stalls[0];//because we sort the array and first cows is 
	//placed at first postion
	for(int i=1;i<stalls.size();i++){//because we already placed first cow
		if(stalls[i]-lastPos>=mid){
			cows++;
			lastPos=stalls[i];
			
		}
		
	}
	if(cows>=Givencows){
				return true;
			}
	return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
   int n=stalls.size();
	sort(stalls.begin(),stalls.end());// first we sort the array
	int l=0;
	int h=stalls[n-1]-stalls[0];// maximum element - minimum element this is max smallest distace we can take
	int res=-1;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(checkCows(stalls,mid,k)){// if we are able to place k cows in mid distance
			res=mid;// store the answer
			l=mid+1;// check for max distance in the right 
		}
		else{
			h=mid-1;
		}
	}
	return res;
}
