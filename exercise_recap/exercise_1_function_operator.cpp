// Ask for two numbers and an operation (+, -, *, /), then print the result.

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int operation_function(int x, int y, char input_operator){
    int answer;
    switch (input_operator){
        case '+':
            answer = x + y;
            break;
        case '-':
            answer = x - y;
            break;
        case '*':
            answer = x * y;
            break;
        case '/':
            answer = x / y;
            break;
    }
    return answer;
}

bool isInteger(const string& s) {
    if (s.empty()) return false;
    int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (start == 1 && s.size() == 1) return false; // just "-" is invalid
    for (int i = start; i < s.size(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}


int main(){
    int x,y;
    char input_operator;
    cout << "Please enter for x: ";
    cin >> x;
    cout << endl << "Please enter for y: ";
    cin >> y;
    cout << endl << "Please enter an operator (+, -, *, /) :";
    cin >> input_operator; 
    if (input_operator == '+' || input_operator == '-' || input_operator == '/' || input_operator == '*'){
        cout << "Output " << x << input_operator << y << "=" << operation_function(x,y,input_operator) << endl;
    }else if(cin.fail()){
        cout << endl <<"X or Y integer was invalide, Please enter integers only" << endl;
    }else{
        cout << "Invalid operator, try again" << endl;
    }
}