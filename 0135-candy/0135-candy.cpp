class Solution {
public:
    void goleft(vector<int>& ratings,vector<int>&sol,int temp){
        int value=2;
        while(temp>0&&ratings[temp-1]>ratings[temp]){

                sol[temp-1]=max(value,sol[temp-1]);
                value++;
            temp--;
        }
    }
    void goright(vector<int>& ratings,vector<int>&sol,int temp){
        int value=2;

        while(temp+1<ratings.size() && ratings[temp+1]>ratings[temp]){
                    
                 sol[temp+1]=max(value,sol[temp+1]);
                value++;
            temp++;
        }
    }
    int candy(vector<int>& ratings) {
        queue<int>q;
        int n=ratings.size();
        q.push(0);
        q.push(n-1);
        for(int i=1;i<n-1;i++){
           if(ratings[i]<=ratings[i-1]&&ratings[i]<=ratings[i+1]){
               q.push(i);
           }
        }
       
        vector<int>sol(n,1);
        vector<int>allocate(n,1);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
           
            goleft(ratings,sol,temp);
            goright(ratings,sol,temp);
        }

        int ans=0;

        for(int i=0;i<n;i++){cout<<sol[i]<<" ";ans+=sol[i];}
        return ans;
    }
};