#include<bits/stdc++.h>
using namespace std;

class product{

 private:
   string product_id,quantity,price, product_type;
 public :
     string _product_id,_quantity,_price,_product_type;
    product(string id,string t,string q,string p ){
         _product_id=id;
         _quantity=q;
         _price=p;
         _product_type=t;
         set_value();
     }
     void set_value(){
         product_id=_product_id;
         quantity=_quantity;
         price=_price;
         product_type=_product_type;

     }

     void print(){
         cout<<"Product Id: "<<product_id<<endl;
         cout<<"Quantity: "<<quantity<<endl;;
         cout<<"Price: "<<price<<endl;
         cout<<"Product Type: "<<product_type<<endl;
     }
     void update_inventory(int sold){

          int temp=stoi(quantity)-sold;
          quantity=to_string(temp);
          cout<<endl;
          cout<<endl;
          cout<<"Updated Inventory-"<<endl;
          print();
     }

};

/* Invoice function */
int invoice(product **a,int i){

    ofstream out("Invoice_2.txt");
    string pid,ptype,name,phone;
    int pquantity=0,tprice=0,pprice;

    out<<"******This is receipt for bill******"<<"\n";

    pid=a[i]->_product_id;
    ptype=a[i]->_product_type;
    pprice=stoi( a[i]->_price); //per product price
    cout<<endl;
    //customer details
    cin.ignore();
    cout<<"Enter customer's name:";
    getline(cin,name);
    cout<<"Enter customer's mobile no: ";
    cin>>phone;
    cout<<"No. of quantity Customer want to buy :";
    cin>>pquantity;
    cout<<endl;

    if(pquantity>stoi(a[i]->_quantity)){
    cout<<"Sorry, we've only left"<<" "<<a[i]->_quantity<<" "<<"products";
    return 0;
    }
    else
    {   tprice=pprice*pquantity;
   //for invoice file
    out<<" Name of customer    :"<<name<<"\n";
    out<<" Customer's Mobile No:"<<phone<<"\n";
    out<<" Product ID          :"<<pid<<"\n";
    out<<" Product Type        :"<<ptype<<"\n";
    out<<" Quantity            :"<<pquantity<<"\n";
    out<<" Price               :"<<tprice<<"\n";
    cout<<"Bill is ready to collect!"<<endl;
    return pquantity;
    }
}



int main()
{
  product *pp[20];//dynamic
  ifstream in("Inventory.txt");
  string line,type,id,quantity,price;

  int i,j=0;

  while(getline(in,line)){
        i=0;
        stringstream ss(line);
        while(getline(ss,line,',')){
            i++;
            if(i==1)  id=line;
            if(i==2)  type=line;
            if(i==3)  quantity=line;
            if(i==4)  price=line;

            }
            pp[j]=new product(id,type,quantity,price);
            j++;
    }
      // pp[3]->print();
      //invoice calling
      int _id;
      cout<<"Enter product ID for billing :";
      cin>>_id;
      cout<<"Details of product-"<<endl;
      pp[_id]->print();
      int sold=invoice(pp,_id);

      /* Inventory update */
      pp[_id]->update_inventory(sold);



}

