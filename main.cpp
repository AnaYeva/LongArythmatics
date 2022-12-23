#include <iostream>
#include <string>
using namespace std;

int sumOfTwoDigits(char a,char b){
    return a+b-96;
}
int multOfTwoDigits(char a,char b){
    return (a-48)*(b-48);
}

void zeroClean(string &str){
    while(str[0]=='0' and str.length()>1){
        str.erase(0, 1);
    }
}

string sum (string &first,string &second){
    string result,big,small;
    short int overten=0;
    char k;
    int c;
    if (first.length()>second.length()){
        big=first;
        small=second;
    }
    else {
        big=second;
        small=first;
    }
    for (int i= big.length()-1;i>=0;i--){
        if (i < big.length() - small.length()){
            k='0';
        }
        else{k = small[i - big.length() + small.length()];}

        c = sumOfTwoDigits(big[i],k)+overten;

        if(c>9){
            overten=1;
            c-=10;}
        else {overten=0;}
        result.insert(0,to_string(c));
    }
    if (overten==1)result="1"+result;
    zeroClean(result);
    return result;
}

string multiplyOneDigit(string bignum,char digitnum){
    string result;
    int overten=0;
    int c;
    for(int i=bignum.length()-1;i>=0;i--){
        c = multOfTwoDigits(bignum[i],digitnum)+overten;
        overten=c/10;
        result.insert(0,(to_string(c%10)));
    }
    if (overten>0)result=(to_string(overten))+result;
    return result;
}

string multiply (string &first,string &second){
    string temp,result;
    result = multiplyOneDigit(first,second[0]);
    for (int i=1;i<=second.length()-1;i++){
        temp = multiplyOneDigit(first,second[i]);
        result+='0';
        result = sum(temp,result);
    }
    zeroClean(result);
    return result;
}

string userNumber(){
  string str;
  bool good=false;
    std::cin>>str;
    while(!good){
        good=true;
        for (int i=0;i<str.length();i++){
            if ((int)str[i]>57 or (int)str[i]<46){
                std::cout << "That's not a number. Try again: " << std::endl;
                std::cin>>str;
                good=false;
                break;
            }
        }
    }
    return str;
}

int main() {
    string first,second;
    std::cout << "Enter the first NUMBER:" << std::endl;
    first = userNumber();
    std::cout << "Enter the second NUMBER:" << std::endl;
    second= userNumber();
    std::cout << "Sum of first and second number is:  " << (sum(first,second)) << std::endl;
    std::cout << "Multiplication of first and second number is:  " << multiply(first,second) << std::endl;
    return 0;
}
