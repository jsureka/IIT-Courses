#include<bits/stdc++.h>
using namespace std;
string hextoBin(string str)
{   string converted="";
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
            converted+="0000";
            else if(str[i]=='1')
            converted+="0001";
            else if(str[i]=='2')
            converted+="0010";
            else if(str[i]=='3')
            converted+="0011";
            else if(str[i]=='4')
            converted+="0100";
            else if(str[i]=='5')
            converted+="0101";
            else if(str[i]=='6')
            converted+="0110";
            else if(str[i]=='7')
            converted+="0111";
            else if(str[i]=='8')
            converted+="1000";
            else if(str[i]=='9')
            converted+="1001";
            else if(str[i]=='A')
            converted+="1010";
            else if(str[i]=='B')
            converted+="1011";
            else if(str[i]=='C')
            converted+="1100";
            else if(str[i]=='D')
            converted+="1101";
            else if(str[i]=='E')
            converted+="1110";
            else if(str[i]=='F')
            converted+="1111";

    }
    return converted;
}
string cleftShift(string s)
{
    string temp = s.substr(0,7);
    s.erase(0,7);
    s = s + temp;
}
int main (){

    string plaintext;
    string key;
    plaintext = hextoBin( plaintext );
    key = hextoBin( key );
    string w[4];
    w[0] = key.substr (0,31);
    w[1] = key.substr (31, 63);
    w[2] =  key.substr (64 , 95);
    w[3] = key.substr (96, 127);
    string gw3 = w [3];



}
