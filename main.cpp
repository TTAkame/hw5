#include<iostream>
#include<fstream>

#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string.h>

#include "Parameter.h"
#include "Person.h"
#include "Time.h"
#include "Thing.h"
#include "Location.h"
#include "Record.h"
#include "hw3json.h"

using namespace std;

int main(){

    string f1("output");
    
    Time one;
    one.name = "8:00";
    
    Time two;
    two.name = "9:00";
    Time three;
    three.name = "10:00";
    Time four;
    four.name = "11:00";
    
    Person red;
    red.name="Little Red";
    Person mom;
    mom.name="Mom";
    Person grandma;
    grandma.name="Grandma";
    Person wolf;
    wolf.name="wolf";
    
    Thing cap;
    cap.name="cap";
    Thing wine;
    wine.name="wine";
    Thing cake;
    cake.name="cake";
    Thing oak;
    oak.name = "oak";

    Location iw;
    iw.name = "a spot in the wood";
    Location ow;
    ow.name = "outside of the wood";
    Location ot;
    ot.name = "nearby three large oak trees";
    
    Location hm;
    hm.name = "home";
    
    //Little Red Ridding Hood wore the Cap
    Record s1;
    s1.setPerson(red);
    s1.setThing(cap);
    s1.setLocation(hm);
    s1.setTime(one);
    
    //Her mom gave her the cake and wine
    Record s2;
    s2.setPerson(red,mom);
    s2.setThing(cake,wine);
    s2.setLocation(hm);
    s2.setTime(two);
    
    //Little Red met the wolf at a particular spot in the wood
    Record s3;
    s3.setPerson(red,wolf);
    s3.setLocation(iw);
    s3.setTime(three);
      
    //Grandma was at her own home right outside of the wood and there were three large oak trees nearby
    Record s4;
    s4.setPerson(grandma);
    s4.setLocation(ot);
    s4.setTime(four);

    ofstream output("output.json");

    Json::Value arr;
    arr[0]=s1.dump2json();
    arr[1]=s2.dump2json();
    arr[2]=s3.dump2json();
    arr[3]=s4.dump2json();
    output << arr.toStyledString();
    output.close();
        
	
	ifstream input("output.json");
	Json::Value obj;
	input >> obj;
	input.close();


	Json::StreamWriterBuilder builder;
	const std::string outstring = Json::writeString(builder, obj); 


	//new record
	Json::Value obj1 = obj[0];
	Json::Value obj2 = obj[1];
	Json::Value obj3 = obj[2];
	Json::Value obj4 = obj[3];

	Record ss1;
	Record ss2;
	Record ss3;
	Record ss4;



	ss1.JSON2Object(obj[0]);
	ss2.JSON2Object(obj[1]);
	ss3.JSON2Object(obj[2]);
	ss4.JSON2Object(obj[3]);


	Json::Value arr2;
	arr2[0]=ss1.dump2json();
	arr2[1]=ss2.dump2json();
	arr2[2]=ss3.dump2json();
	arr2[3]=ss4.dump2json();

	ofstream out2("out2.json");
	out2<<arr2.toStyledString();
	out2.close();

    cout<<"\noutput.json out2.json complete\n\n";


    return 0;
}

