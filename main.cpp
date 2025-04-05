#include <iostream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX_COLUMNS 1000

using namespace std;

//This method counts how many '1's are on the signal and returns 1 or 0 in any case
int even(int signal[],int bits)
{
    int i,counter=0,parity;
    i=0;
    while (i<bits)
    {
        if (signal[i]==1)
        {
            counter++;
        }
        i++;
    }
    if (counter%2!=0)
    {
        parity=1;
    }
    else
    {
        parity=0;
    }
    return parity;
}

//checks if the signal carry out even parity
bool parity_checker(int signal[],int bits)
{
    bits+=1; //because we added parity bit
    int i=0,counter=0;
    while (i<bits+1)
    {
        if (signal[i]==1)
        {
            counter++;
        }
        i++;
    }
    if (counter%2!=0) //if counter mod 2 is different than 0 then the signal has wrong parity check
    {
        return false;
    }
    else
    {
        return true;
    }
}

//changes bit value at given position
void switch_bit(int signal[],int position)
{
    if (signal[position]==0)
    {
        signal[position]=1;
    }
    else
    {
        signal[position]=0;
    }
}

//changes bit value at given position (in the two dimensional array)
void array_error(int arr[][1000],int m,int n)
{
    if (arr[m][n]==1)
    {
        arr[m][n]=0;
    }
    else
    {
        arr[m][n]=1;
    }
    cout<<"Created error at row:"<<m+1<<" and column:"<<n+1<<endl;
}

//prints the two dimensional array
void print(int arr[][1000],int m,int n)
{
    int i=0,j;
    while (i<m)
    {
        j=0;
        while (j<n)
        {
            cout<<arr[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

//checks for errors in the array (with the parity bits)
void error_checker(int arr[][1000],int m,int n)
{
    int i=0;
    while (i<m) //checks each row
    {
        int counter=0,j=0;
        while (j<n)
        {
            if (arr[i][j]==1) //counts '1's in each row
            {
                counter++;
            }
            j++;
        }
        if(counter%2==0)
        {
            cout<<"No error(s) found at row:"<<i+1<<endl;
        }
        if(counter%2!=0)
        {
            cout<<"Error(s) found at row:"<<i+1<<endl;
        }
        i++;
    }
    i=0;
    while (i<n) //checks each column
    {
        int counter=0,j=0;
        while (j<m)
        {
            if(arr[j][i]==1) //counts '1's in each column
            {
                counter++;
            }
            j++;
        }
        if(counter%2==0)
        {
            cout<<"No error(s) found at column:"<<i+1<<endl;
        }
        if(counter%2!=0)
        {
            cout<<"Error(s) found at column:"<<i+1<<endl;
        }
        i++;
    }
}

int main()
{
//1st Exercise
    cout<<"1st Exercise:"<<endl;
    cout<<"Give number of bits(tip:Give 14 bits for the exercise):";
    int bits,i,numoferrors=0,firstpos,secondpos,j;
    cin>>bits;
    int a[bits+1];
    cout<<"Give a binary sequence(tip:Give 1 0 0 0 1 1 0 1 0 1 1 0 0 0 for the exercise):";
    i=0;
    while (i<bits)
    {
        cin>>a[i];
        i++;
    }
    int par=even(a,bits-1);
    a[bits]=par;  //Add parity bit to the signal.
    cout<<"The signal with the parity bit is:";
    i=0;
    while (i<bits+1)
    {
        cout<<a[i]<<" ";
        i++;
    }
    cout<<endl<<endl;
//2nd Exercise [a)0,b)1 and c)2 errors]
    cout<<"2nd Exercise:"<<endl;
    //a)0 errors
    cout<<"a)Send signal with 0 errors:"<<endl;
    if (parity_checker(a,bits))
    {
        cout<<"No error(s) found"<<endl;
    }
    //b)1 error
    cout<<"b)Send signal with 1 error:"<<endl;
    cout<<"Give number of errors(tip:Give 1 for the exercise):";
    cin>>numoferrors;
    cout<<"Give error(s) position(tip:Give 6 for the exercise):";
    cin>>firstpos;
    switch_bit(a,firstpos-1);
    cout<<"Sequence with error:";
    i=0;
    while (i<bits+1)
    {
         cout<<a[i]<<" ";
         i++;
    }
    cout<<endl;
    if (parity_checker(a,bits))
    {
        cout<<"No error(s) found"<<endl;
    }
    else
    {
        cout<<"Error found"<<endl;
    }
    //c)2 errors
    cout<<"c)Send signal with 2 errors:"<<endl;
    cout<<"Give second error(s) position(tip:Give 12 for the exercise,the 6 is from before):";
    cin>>secondpos;
    switch_bit(a,secondpos-1);
    cout<<"Sequence with error:";
    i=0;
    while (i<bits+1)
    {
        cout<<a[i]<<" ";
        i++;
    }
    cout<<endl;
    if (parity_checker(a,bits))
    {
        cout<<"No error(s) found"<<endl;
    }
    else
    {
        cout<<"Error found"<<endl;
    }
    cout<<endl;
//3rd Exercise [28 bits signal]
    cout<<"3rd Exercise:"<<endl;
    int rows,columns;
    cout<<"Give number of rows(Tip:Give 4 for the exercise):";
    cin>>rows;
    cout<<"Give number of columns(Tip:Give 7 for the exercise):";
    cin>>columns;
    int arr[rows+1][MAX_COLUMNS];
    cout<<"Give 28 bits signal(tip:Give 1 1 0 0 1 1 1 1 0 1 1 1 0 1 0 1 1 1 0 0 1 0 1 0 1 0 0 1 for the exercise):"<<endl;
    i=0;
    while (i<rows)
    {
        j=0;
        while (j<columns)
        {
            cin>>arr[i][j];
            j++;
        }
        i++;
    }
    cout<<"Matrix (without the parity bits) is:"<<endl;
    i=0;
    while (i<rows)
    {
        j=0;
        while (j<columns)
        {
            cout<<arr[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    i=0;
    while (i<rows)
    {
        int counter=0;
        j=0;
        while (j<columns)
        {
            if (arr[i][j]==1) //counts '1's in each row
            {
                counter++;
            }
            j++;
        }
        if (counter%2!=0) //puts the correct parity bit
        {
            arr[i][columns]=1;
        }
        else
        {
            arr[i][columns]=0;
        }
        i++;
    }
    i=0;
    while (i<columns+1)
    {
        int counter=0;
        j=0;
        while (j<rows)
        {
            if (arr[j][i]==1) //counts '1's in each column
            {
                counter++;
            }
            j++;
        }
        if (counter%2!=0) //puts the correct parity bit
        {
            arr[rows][i]=1;
        }
        else
        {
            arr[rows][i]=0;
        }
        i++;
    }
    cout<<"Matrix (within the parity bits) is:"<<endl;
    i=0;
    while (i<rows+1)
    {
        j=0;
        while (j<columns+1)
        {
            cout<<arr[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;
//4th Exercise
    cout<<"4th Exercise:"<<endl;
    int errors;
    int r,c;
    cout<<"Give number of error(s)(Tip:Give i)0,ii)1 or iii)2 for every case,one number every case!):";
    cin>>errors;
    if (errors!=0)
    {
        cout<<"Give error(s) positions(Tip:Give ii)2 3 or ii)2 3 2 5 for every case!):";
    }
    if (errors==0)
    {
        cout<<"No error(s) found"<<endl;
    }
    i=0;
    while (i<errors)
    {
        cin>>r>>c;
        array_error(arr,r-1,c-1);
        i++;
    }
    if (errors!=0)
    {
        cout<<"Matrix with error(s):"<<endl;;
        print(arr,rows+1,columns+1);
        error_checker(arr,rows+1,columns+1);
    }
    return 0;
}
