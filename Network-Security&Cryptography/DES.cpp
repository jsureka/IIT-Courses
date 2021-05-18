
#include<bits/stdc++.h>
using namespace std;

string dectoBin(int val){
    string converted="";
        if(val==0)
            converted+="0000";
            else if(val==1)
            converted+="0001";
            else if(val==2)
            converted+="0010";
            else if(val==3)
            converted+="0011";
            else if(val==4)
            converted+="0100";
            else if(val==5)
            converted+="0101";
            else if(val==6)
            converted+="0110";
            else if(val==7)
            converted+="0111";
            else if(val==8)
            converted+="1000";
            else if(val==9)
            converted+="1001";
            else if(val==10)
            converted+="1010";
            else if(val==11)
            converted+="1011";
            else if(val==12)
            converted+="1100";
            else if(val==13)
            converted+="1101";
            else if(val==14)
            converted+="1110";
            else if(val==15)
            converted+="1111";
    return converted;
}

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
int bintodec(string binary)
{
	int decimal = 0;
	for (int counter = binary.size()-1, i=0; counter >= 0, i<binary.size() ; counter--,i++)
	{
		if (binary[i] == '1')
			{
			    decimal = (decimal + pow(2,counter));

			}
	}
	return decimal;
}

string permute(string str, int* table, int n){
    string permuted="";
    for(int i=0;i<n;i++)
    {
        permuted+=str[table[i]-1];
    }
    return permuted;
}

string shiftLeft(string left, int shift){

    string k="";
    for(int i=0;i<shift;i++ ){
        for(int j=1;j<28;j++)
        {
            k+=left[j];
        }
        k+=left[0];
        left=k;
        k="";

    }
    return left;
}
string exor(string a, string b)
{
    string ans = "";
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans += "0";
        }
        else {
            ans += "1";
        }
    }
    return ans;
}
string encryption(string pt, string keys[])
{
    int initial_perm[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };
    // Initial Permutation
    pt = permute(pt, initial_perm, 64);
    string left = pt.substr(0, 32);
    string right = pt.substr(32, 32);

     // Expansion D-box Table
    int exp_d[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };
     // S-box Table
    int s[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

    // Straight Permutation Table
    int per[32] = { 16, 7, 20, 21,
                    29, 12, 28, 17,
                    1, 15, 23, 26,
                    5, 18, 31, 10,
                    2, 8, 24, 14,
                    32, 27, 3, 9,
                    19, 13, 30, 6,
                    22, 11, 4, 25 };
    for(int i=0;i<16;i++)
    {


    string x = permute(right, exp_d,48);
    string right1= exor(x, keys[i]);

    // Straight Permutation Table
    string temp="";
  for(int j=0;j<8;j++)
  {

      string row=right1.substr(j*6,1)+right1.substr(j*6+5,1);

      string col=right1.substr(j*6+1,4);
      int rowD= bintodec(row);

      int colD= bintodec(col);

      int val=s[j][rowD][colD];
      string conv=dectoBin(val);

      temp+=conv;

  }

  temp=permute(temp,per,32);

  right1=exor(temp,left);
  left=right1;
  if(i!=15)
    swap(left,right);
    }
  string combine= left+right;

   int final_perm[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25 };

    // Final Permutation
    string cipher = permute(combine, final_perm, 64);

    return cipher;
}

int main(){
    string plaintext="123456ABCD132536";
    string hexkey="AABB09182736CCDD";
    string key=hextoBin(hexkey);
     plaintext= hextoBin(plaintext);
    // Parity bit drop table
    int keyp[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };

    // getting 56 bit key from 64 bit using the parity bits
    key = permute(key, keyp, 56); // key without parity
       int shift_table[16] = { 1, 1, 2, 2,
                            2, 2, 2, 2,
                            1, 2, 2, 2,
                            2, 2, 2, 1 };

    // Key- Compression Table
    int key_comp[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };
  string roundkeys[16]="";
  string left= key.substr(0,28);
      string right= key.substr(28,28);
  for(int i=0;i<16;i++)
  {



      left = shiftLeft(left, shift_table[i]);
      right = shiftLeft(right, shift_table[i]);

      roundkeys[i] = left + right;

      roundkeys[i] = permute(roundkeys[i], key_comp,48);

  }
  string ciphertext= encryption(plaintext, roundkeys);
  cout<<"Plain Text : "<<plaintext<<endl;
    cout<<"Cipher Text : "<<ciphertext;
}
