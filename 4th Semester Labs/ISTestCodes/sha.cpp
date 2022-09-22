#include<bits/stdc++.h>
using namespace std;

#define SHR(x, n)    (x >> n)
#define ROTR(x, n)   ((x >> n) ^ (x << (64 - n)))
#define CH(x, y, z)  ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define sum512_zero(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define sum512_one(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define sigma512_zero(x) (ROTR(x,  1) ^ ROTR(x,  8) ^ SHR(x,  7))
#define sigma512_one(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x,  6))

uint64_t key[80],HASH[8];

void initializeHASH()
{
    ifstream ifile;
    ifile.open("initialHASH.txt");
    if(!ifile)
    {
        cout<<"unable to open initialHASH.txt";
        exit(0);
    }
    for(int i=0;i<8;i++) ifile>>hex>>HASH[i];
    ifile.close();
}

void initializeKey()
{
    ifstream ifile;
    ifile.open("SHAkey.txt");
    if(!ifile)
    {
        cout<<"unable to open SHAkey.txt"<<endl;
        exit(1);
    }
    for(int i=0;i<80; i++) ifile>>hex>>key[i];
    ifile.close();
}
void printHASH()
{
    cout<<hex<<(uint64_t)HASH[0]<<(uint64_t)HASH[1]
            <<(uint64_t)HASH[2]<<(uint64_t)HASH[3]
            <<(uint64_t)HASH[4]<<(uint64_t)HASH[5]
            <<(uint64_t)HASH[6]<<(uint64_t)HASH[7]<<endl;
}

int main(void)
{
    string s,temp;
    ifstream ifile;
    ifile.open("input.txt");
    getline(ifile,s);
    while(getline(ifile,temp)) s+="\n" + temp;
    uint64_t numberOfBlock,mLength,pos = 0;
    mLength = s.length();
    if(mLength==0) exit(0);
    numberOfBlock = ceil((mLength+17+0.0)/128);
    initializeKey();
    initializeHASH();
    unsigned char *totalCH = new unsigned char[numberOfBlock*128];
    for(uint64_t i=0; i<mLength; i++) totalCH[i] = s[i];
    totalCH[mLength] = 1<<7;
    for(uint64_t i=mLength+1; i<numberOfBlock*128; i++) totalCH[i] = 0;
    uint64_t totalBINs = mLength*8;
    for(uint64_t i=(numberOfBlock*128-1); i>(numberOfBlock*128-17); i--)
    {
        totalCH[i] = totalBINs;
        totalBINs = totalBINs>>8;
    }

    for(int i=0; i<numberOfBlock*128;i++){
        cout << totalCH[i] << " ";
    }

    for(uint64_t k=1; k<=numberOfBlock; k++)
    {
        uint64_t W[80],t1,t2,a,b,c,d,e,f,g,h;
        for(int j=0;j<16;j++)
        {
            W[j] = totalCH[pos];
            for(int i=1; i<8; i++) W[j] = W[j]<<8 | totalCH[pos+i];
            pos+=8;
        }
        for(int j=16;j<80;j++) W[j] = (sigma512_one(W[j-2])+W[j-7]+sigma512_zero(W[j-15])+W[j-16]);

        a = HASH[0];   e = HASH[4];
        b = HASH[1];   f = HASH[5];
        c = HASH[2];   g = HASH[6];
        d = HASH[3];   h = HASH[7];

        for(int i=0;i<80;i++)
        {
            t1 = (h + CH(e,f,g) + sum512_one(e) + W[i] + key[i]);
            t2 = (sum512_zero(a) + MAJ(a,b,c));
            h = g;   g = f;
            f = e;   e = (d+ t1);
            d = c;   c = b;
            b = a;   a = (t1+ t2);
        }

       HASH[0] = (a+HASH[0]);
       HASH[1] = (b+HASH[1]);
       HASH[2] = (c+HASH[2]);
       HASH[3] = (d+HASH[3]);
       HASH[4] = (e+HASH[4]);
       HASH[5] = (f+HASH[5]);
       HASH[6] = (g+HASH[6]);
       HASH[7] = (h+HASH[7]);

    }
    printHASH();

}
//improvement:
//              1) it takes only string as input but previous one takes a file as input;
//              2) easier to understand
//              3) more applicable in GUI development
