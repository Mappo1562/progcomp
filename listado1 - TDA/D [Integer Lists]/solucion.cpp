#include <iostream>
#include <string>
using namespace std;

int main(){
    int p,m,numero[3],i,digito,direccion,head,tail,pos;
    string instrucciones,entrada;

    cin>>p;
    cin.ignore();
    for(int n=0;n<p;n++){
        getline(cin, instrucciones);
        cin>>m;
        cin.ignore();
        getline(cin, entrada);
        i=0;
        pos=0;
        int lista[m];
        for (char c:entrada){
            if (isdigit(c)){
                numero[i]=c-'0';
                i++;
            }
            else if(c==','||c==']'){
                if (i>0){
                    digito=0;
                    for (int j=0;j<i;j++)
                        digito=digito*10+numero[j];
                    lista[pos]=digito;
                    i=0;
                    pos++;
                }
            }
        }
        direccion=1;
        int flag=1;
        head=0;
        tail=m-1;
        for (char c:instrucciones){
            if (c=='R'){
                direccion=!direccion;
            }
            else{
                if (direccion){
                    head++;
                    m--;
                }
                else{
                    tail--;
                    m--;
                }
            }
        }
        if (m<0){
            cout<<"error\n";
            flag=0;
        }
        else if(m==0){
            cout<<"[]\n";
            flag=0;
        }
        if (flag){
            if(direccion){
                cout<<"[";
                for (i=head;i<tail;i++)
                    cout<<lista[i]<<",";
                cout<<lista[tail]<<"]\n";
            }
            else{
                cout<<"[";
                for (i=tail;i>head;i--)
                    cout<<lista[i]<<",";
                cout<<lista[head]<<"]\n";
            }
        }

    }
}