#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task1();
void task2();
void task3();
void task4();
bool nums(char a);

int main(){

    int a;

    cout<<"task? ";
    cin>>a;

    switch(a){
        case (1):{task1(); break;}
        case (2):{task2(); break;}
        case (3):{task3(); break;}
        case (4):{task4(); break;}
        default:{cout<<"err num task\n";}
    }

    return 0;

}

void task1(){

    string txt;
    int maxlength, j=0;

    cin.ignore();
    getline(cin, txt);
    txt+=' ';

    vector <int> posofsp;
    posofsp.resize(txt.length());
    posofsp[-1]=-1;
    vector <int> resofpos;
    resofpos.resize(txt.length());

    for (int i=0; i<txt.length(); i++){
        if (txt[i]==' '){
            posofsp[j]=i;
            j++;
        }
    }

    posofsp.resize(j);

    resofpos[0]=posofsp[0];
    maxlength=resofpos[0];

    for (j=0; j<posofsp.size(); j++){
        resofpos[j+1]=posofsp[j+1]-posofsp[j]-1;
        if (resofpos[j]>maxlength){
            maxlength=resofpos[j];
        }
    }

    for (int i=0; i<posofsp.size(); i++)
        if (resofpos[i]==maxlength) {
            cout<<"longest word ";
            for (int k=1; k<resofpos[i]+1; k++){
                cout<<txt[posofsp[i-1]+k];
            }
        }

    cout<<endl;

}

void task2(){

    string txt;

    cin.ignore();
    getline(cin, txt);
    txt+=' ';

    vector <string> words;

    for (int i=0, j=0; i<txt.length(); i++){
        while (txt[j]!=' ') {words[i]+=txt[i]; j++;}
        cout<<words[i]<<endl;
    }

}

void task3(){

    string txt1="", txt2="";

    cin.ignore();
    getline(cin, txt1);

    for (int i=0; i<txt1.length(); i++){
        if (txt1[i]==' '||txt1[i+1]==' ') txt2+=txt1[i];
        else {
            txt2+=txt1[i];
            txt2+=' ';
        }
    }

    cout<<txt2<<endl;

}

void task4(){

    string txt="";
    int count=0;

    cin.ignore();
    getline(cin, txt);

    for (int i=0; i<txt.length(); i++){
        if (nums(txt[i])) count++;
    }

    cout<<"amount of numbers: "<<count<<endl;

}

bool nums(char a){
    return (
    (a=='0')||
    (a=='1')||
    (a=='2')||
    (a=='3')||
    (a=='4')||
    (a=='5')||
    (a=='6')||
    (a=='7')||
    (a=='8')||
    (a=='9')
    );
}
