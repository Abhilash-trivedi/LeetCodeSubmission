class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0;
        for(int i=1;i+1<(int)colors.length();i++){
            if(colors[i-1]==colors[i+1]&&colors[i]==colors[i+1]){
                if(colors[i]=='A'){
                    alice++;
                }else{
                    bob++;
                }
            }
        }
        return (alice>bob);
    }
};