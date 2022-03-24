class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0;
      
        int n=people.size();
          int j=n-1;
        int count=0;
        
       while(i<=j)
       {
               if(people[i]+people[j]<=limit)
               {
                       i+=1;
                       j-=1;
                       count+=1;
               }
               else
               {
                       j-=1;
                       count+=1;
               }
       }
            return count;
        
    }
};