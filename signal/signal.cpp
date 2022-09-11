#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int find_value(int data[][3], int index, int len) {
    if(index > data[len][0])
        return -1;
    int sum, k;
    sum = 0;
    for(k=0; k<=len; k++) {
        if(index >= data[k][0])
            sum += data[k][1];
    }
    return sum;
}

int find_index(int data[][3],int index, int len) {
    if(index > data[len][0])
        return 0;
    int k;
    for(k=0; k<=len; k++) {
        if(index < data[k+1][0])
            break;
    }
    return k;
}


void find_min_max(int start, int fin, int data[][3],int len,int first_value) {
    int local_max=0,local_min=0,temp=0;

    for(int i = start; i < fin ; i++) {
        temp +=data[i+1][1];
        if(temp > local_max)
            local_max = temp;
        else if(temp < local_min)
            local_min = temp;
    }
    cout << first_value + local_min << ' ' << first_value + local_max << '\n';
}

int main () {
    int number [20000][3];
    int i = 0,j=0 ;
    ifstream myfile ("zsignal.txt");
    if (myfile.is_open()) {
        while ( myfile>>number[i][1]) {
            number[i][0] = j;
            i++;
            if(number [i-1][1] == 0 ) {
                myfile>> number[i-1][2];
                j += number[i-1][2];
                continue;
            }
            j++;
            if(myfile.eof())
                break;
        }
        myfile.close() ;
    } else cout << "zsignal.txt을 열 수 없네요.";

    char query_type;
    int n,u,v,result,len=i-1,temp;

    while(cin>>query_type) {

        if(query_type=='T') {
            cin>>n;
            result = find_value(number,n,len);
            cout <<  result<< '\n';

        } else if(query_type=='M'){
            cin>>u>>v;
            if(find_index(number,u,len) && find_index(number,v,len) )
                find_min_max(find_index(number,u,len),find_index(number,v,len),number,len,find_value(number,u,len));

            else cout << -1<<'\n';
        }
    if(cin.eof()){
        break;
    }
    }
}


