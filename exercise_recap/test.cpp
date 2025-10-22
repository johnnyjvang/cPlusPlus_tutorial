# include <iostream>
// you can add these so you can avoid typing std in front of the commands
// cout = command prompt out i think
// endl = end line or you can do /n
using std::cout;
using std::endl;
using std::cin;

int main(){
    int x, y;
    std::cout << "hello world" << std::endl;
    cout << "hello world version 2" << endl;
    cout << "please input for x and y:";
    // honestly this is not a good method, its not user friendly to have them both be targeted
    cin >> x >> y; 
    cout << x + y << endl;
    return 0;
}