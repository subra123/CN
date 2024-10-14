#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int checksum(string & data){
    int sum=0;
    for(int i=0;i<data.length();i+=2){
        int word=(data[i]<<8);
        if(i+1<data.length()){
            word |= data[i+1];
        }
        sum+=word;
    }
    while(sum>>16){
        sum= (sum & 0xFFFF)+ (sum>>16);
    }
    return static_cast<int>(~sum);

}

int main(){
    string data="Hello, World";
    uint16_t check=checksum(data);
    cout<<"checksum: "<<hex<<check<<endl;
    return 0;
}
