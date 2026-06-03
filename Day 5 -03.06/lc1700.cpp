class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countzero=0;
        int countone=0;
        for (int x:students){
            if(x==1){
                countone++;
            }
            else{
                countzero++;
            }
        }
        for(int x:sandwiches){
            if (x==1){
                countone--;
                if(countone<0){
                    countone=0;
                    break;
                }
            }
            else{
                countzero--;
                if(countzero<0){
                    countzero=0;
                    break;
                }
            }
        }
        return countone+countzero;
    }
};