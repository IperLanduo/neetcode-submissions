class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        int first_number;
        int second_number;

        for(const string& s:tokens){
            if(s=="+"){
                first_number = number.top();
                number.pop();
                second_number = number.top();
                number.pop();
                number.push(first_number+second_number);
            }   
            else if(s=="-"){
                first_number = number.top();
                number.pop();
                second_number = number.top();
                number.pop();
                number.push(second_number-first_number);
            }
            else if(s=="*"){
                first_number = number.top();
                number.pop();
                second_number = number.top();
                number.pop();
                number.push(first_number*second_number);
            }
            else if(s=="/"){
                first_number = number.top();
                number.pop();
                second_number = number.top();
                number.pop();
                number.push(second_number/first_number);
            }
            else{
                int temp = stoi(s);
                number.push(temp);
            }
        }
        return number.top();
    }
};
