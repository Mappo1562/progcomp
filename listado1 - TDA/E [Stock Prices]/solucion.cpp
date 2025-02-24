// A ask price :  el precio mas bajo que alguien esta dispuesto a VENDER
// B bird price:  el precio mas alto que alguien esta dispuesto a PAGAR
// S stock price: el precio de la ultima operacion

// B >= A -> hay trato, se vende al valor de A
#include <bits/stdc++.h>
using namespace std;




int main(){
    string trash, order_type;
    long long n,x,y,aux,trato;
    cin>>aux;
    while (aux--){
        map<int,int> a;
        map<int,int,greater<int>> b;
        cin>>n;
        cin.ignore();
        trato = -1;
        while (n--){
            

            cin >> order_type >> x >> trash >> trash >> y;


            // cout<<order_type<<" "<<x<<" "<<y<<"\n";
            
            // cout<<"order type = ["<<order_type<<"]\n";
            if (order_type[0] == 'b'){
                b[y]+=x;
            } 
            else{
                a[y]+=x; 
            }

            while (a.size() && b.size() && a.begin()->first <= b.begin()->first){
                auto it = a.begin(), it2 = b.begin();
                trato = it->first;
                long long cantidad = min(it->second,it2->second);
                it->second -= cantidad;
                it2->second -= cantidad;
                if (it->second == 0)
                    a.erase(a.begin());
                if (it2->second == 0)
                    b.erase(b.begin());
            }

            if (a.size()){
                cout<<a.begin()->first<<" ";
            }
            else{
                cout<<"- ";
            }
            if (b.size()){
                cout<<b.begin()->first<<" ";
            }
            else{
                cout<<"- ";
            }
            if (trato==-1){
                cout<<"-\n";
            }
            else{
                cout<<trato<<"\n";
            }
            
        }
    }
}


//                         a   b   s
// buy 10 shares at 100   -   100 -
// sell 1 shares at 120   120 100 -
// sell 20 shares at 110  110 100 -
// buy 30 shares at 110   120 110 110
// sell 10 shares at 99   120 100 99  
// buy 1 shares at 120    -   100 120

// 100 - -
// 100 80 -
// 100 90 -
// 90 80 90  me tira 100 90 90
// 100 80 90
// 100 - 80