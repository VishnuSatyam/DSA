class Solution {
public:

    void solve(int index , string num , int target , string curr , vector<string> &ans , long prev , long res){

        // base case
        if(index == num.length()){

            if(res == target){
                ans.push_back(curr);
            }

            return;
        }

        string st = "";
        long currRes = 0;

        for(int i = index; i < num.length(); i++){

            // avoid numbers like 05 , 00 , 012
            if(i > index && num[index] == '0'){
                break;
            }

            st += num[i];

            // converting string into number
            currRes = currRes * 10 + (num[i] - '0');

            // first number
            if(index == 0){

                solve(i + 1 , num , target , st , ans , currRes , currRes);
            }

            else{

                // +
                solve(i + 1 , num , target , curr + "+" + st , ans , currRes , res + currRes);

                // -
                solve(i + 1 , num , target , curr + "-" + st , ans , -currRes , res - currRes);

                // *
                solve(i + 1 , num , target , curr + "*" + st , ans , prev * currRes , res - prev + (prev * currRes));
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0 , num , target , "" , ans , 0 , 0);

        return ans;
    }
};