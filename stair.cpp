#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int x_compare (int cnt, int* stco){
    int res = 0 ;
    for(int i = 0 ; i<cnt;i++)
        res += stco[i*2];
    return res;
}


int y_compare (int cnt, int len, int* stco){
    int sum = 0;
    for(int i =(len/2);i>=cnt;i--){
        sum += stco[i*2-1];
    }
    return sum;
}
int main (){

    int stair_coord [41],i=0,len=0;
    while(cin>>stair_coord[i])
    {
        if(stair_coord[i]==0) break;
        i++;
    }
    len = i ;
    int xco=0,yco=0,cnt=0,x_ref,y_ref1,y_ref2;

    while(cin>>xco>>yco){

    cnt =1;

    while(cnt <(len/2)){
        if(xco>x_compare(cnt,stair_coord))
        cnt ++;
    else break;
    }

    x_ref = x_compare(cnt,stair_coord);
    y_ref1 = y_compare(cnt,len,stair_coord);
    y_ref2 = y_compare(cnt+1,len,stair_coord);

    string st;
    if(xco>x_ref)
        st = "out";
    else if(xco == x_ref){
    if(yco >=y_ref2 && yco<=y_ref1)
            st = "on";
        else if (yco < y_ref1)
            st = "in";
        else
            st = "out";
    }
    else{
        if(yco >y_ref1)
            st = "out";
        else if(yco == y_ref1)
            st = "on";
        else
            st = "in";
    }
    cout << st<<'\n';
    if(cin.eof()){
        break;
    }
    }

    return 0 ;
}




