#include <iostream>
#include <cstring>
#include <string>
#include<fstream>


class document
{
public:

std::string doc_name, doc_reps[10];
int no_doc_reps,elligible,assigned;
std::ifstream rfile;
std::ofstream wfile;
//document() {}
//document(std::string name)
void initialize_doc(std::string name)
{
this->doc_name=name;
std::string word;

int i,flag=0;
rfile.open(name.c_str());
if(rfile.is_open())
	{
	while(!rfile.eof())  // Reads from file and stores the document representatives in an array for future processing
		{
		rfile>>word;
		for(i=0;strcmp(doc_reps[i].c_str(),"\0")!=0;i++)
			{
			if(strcmp(word.c_str(),this->doc_reps[i].c_str())==0)
				{
					flag=1;   // To avoid duplication in array
					break;
				}
			}

		if(flag==0)
			{
				for(i=0;strcmp(doc_reps[i].c_str(),"\0")!=0;i++);			
				this->doc_reps[i]=word;
			}
		flag=0;
		}

	rfile.close();
	}
doc_reps[++i]="\0";
this->no_doc_reps=0;
//this->no_doc_reps=get_total_elements(this->doc_reps);

for(i=0;strcmp(doc_reps[i].c_str(),"\0")!=0;i++)
this->no_doc_reps++;	

std::cout<<"\nno_of_doc_reps"<<this->no_doc_reps<<"\n";

this->elligible=0;
this->assigned=100;

}

int get_no_of_reps()     // Counts number of document represnetatives
{
int i;
this->no_doc_reps++;
for(i=0;strcmp(doc_reps[i].c_str(),"\0")!=0;i++)
this->no_doc_reps++;	
return no_doc_reps;
}

void show_drs()
{
int i;
for(i=0;strcmp(doc_reps[i].c_str(),"\0")!=0;i++)	
std::cout<<"\t"<<this->doc_reps[i];

}


double compute_dice_coefficient(std::string doc)
{

//document d2(doc);
document d2;
d2.initialize_doc(doc);
int i,j,k=0;
std::string intersection[10];

for(i=0;strcmp(this->doc_reps[i].c_str(),"\0")!=0;i++)   // d1 intersection d2
{
	for(j=0;strcmp(d2.doc_reps[j].c_str(),"\0")!=0;j++)
	{	
		if(strcmp(this->doc_reps[i].c_str(),d2.doc_reps[j].c_str())==0)
			{		
			intersection[k++]= this->doc_reps[i].c_str();
			break;
			}			
	
	}
}
intersection[k]="\0";

std::cout<<"\n Intersection =";
for(i=0;strcmp(intersection[i].c_str(),"\0")!=0;i++)   // Prints d1 intersection d2
std::cout<<"\t"<<intersection[i];

double d1_inter_d2 = get_total_elements(intersection);
if(intersection[0]!="\0")
{
std::cout<<"\n"<<"|intersection| = "<<d1_inter_d2<<"\n";
//std::cout<<"\n"<<d2.no_doc_reps<<"\n";

double dice_coeff = 2*((d1_inter_d2) / (this->no_doc_reps + d2.no_doc_reps));
std::cout<<"\n Dice coeff = "<<dice_coeff<<"\n";

return dice_coeff;
}
else return 0;


}



int get_total_elements(std::string s[10])
{
int i,n;
for(i=0;strcmp(s[i].c_str(),"\0")!=0;i++)
n++;
return n;
}



};


/*

class model: public document{

int threshold=85;

public:

model(std::string name) : document(std::string name){} 


//void compute_dice_coefficient(std::string n1,std::string n2)
void compute_dice_coefficient(document d1,document d2)
{

//document d1("1.txt"),d2("2.txt");
int i,j,k=0;
std::string intersection[10];

for(i=0;strcmp(d1.doc_reps[i].c_str(),"\0")!=0;i++)
{
	for(j=0;strcmp(d2.doc_reps[j].c_str(),"\0")!=0;j++)
	{	
		if(strcmp(d1.doc_reps[i].c_str(),d2.doc_reps[j].c_str())==0)
			{		
			intersection[k++]= d1.doc_reps[i].c_str();
			break;
			}			
	
	}
}


for(i=0;strcmp(intersection[i].c_str(),"\0")!=0;i++)
std::cout<<"\t"<<intersection[i];

}




};


*/


class cluster 
{
public:
//std::string doc_names[5],dr;
document d[5];
std::string cr;
int total;


cluster()
{
cr="\0";
total=-1;
}


void put_in_cluster(std::string name)
{

int i,flag=0;



for(i=0;strcmp(this->d[i].doc_name.c_str(),"\0")!=0;i++)
			{
			if(strcmp(name.c_str(),this->d[i].doc_name.c_str())==0)
				{
					flag=1;   // To avoid duplication in array
					break;
				}
			}

		if(flag==0)
			{
				for(i=0;strcmp(this->d[i].doc_name.c_str(),"\0")!=0;i++);			
				this->d[i].initialize_doc(name);
			}
flag=0;
total=i+1;


update_cr();
}

void update_cr()
{
int i,x=0;
//for(i=0;strcmp(d[i].doc_name.c_str(),"\0")!=0;i++)
for(i=0;i<=total;i++)
{
	if(this->d[i].no_doc_reps>=x)
		{
			this->cr=this->d[i].doc_name;
			x=d[i].no_doc_reps;
		}
}
std::cout<<"\ncr = "<<cr<<"\n";
}

void show_cluster()
{
int i;
for(i=0;i<=total;i++)
std::cout<<"\t"<<d[i].doc_name;
}

};





int main()
{
double threshold=0.80;
 
cluster c[3];
int no_of_clusters=3,no_of_docs=5,i,j;

//document c1[5],c2[5];

//document d1("1.txt"),d2("2.txt"),d3("3.txt"),d4("4.txt");
//document d1,d2,d3,d4;
document org_docs[10];

org_docs[0].initialize_doc("1.txt");
org_docs[1].initialize_doc("2.txt");
org_docs[2].initialize_doc("3.txt");
org_docs[3].initialize_doc("4.txt");
org_docs[4].initialize_doc("5.txt");

//d2.initialize_doc("2.txt");
//d3.initialize_doc("3.txt");
//d4.initialize_doc("4.txt");

std::cout<<std::endl<<"Doc 1";
org_docs[0].show_drs();
std::cout<<std::endl<<"Doc 2";
org_docs[1].show_drs();
std::cout<<std::endl<<"Doc 3";
org_docs[2].show_drs();
std::cout<<std::endl<<"Doc 4";
org_docs[3].show_drs();
std::cout<<std::endl<<"Doc 4";
org_docs[4].show_drs();
std::cout<<std::endl;

c[0].put_in_cluster(org_docs[0].doc_name);  //Put first document in cluster
std::cout<<"\n cluster 1";
c[0].show_cluster();

//if(org_docs[2].compute_dice_coefficient(c[0].cr.c_str())>=threshold)
//c[0].put_in_cluster(org_docs[2].doc_name);
//std::cout<<"\n\n dc for i ="<<i<<"\tj="<<j<<"\t="<<org_docs[j].compute_dice_coefficient(c[0].cr.c_str())<<"\n\n\n\n";

for(i=0;i<no_of_clusters;i++)
{

	std::cout<<"\n FOR CLUSTER"<<i<<"\n";
	
	for(j=0;j<no_of_docs;j++)
	{
		std::cout<<"\n Compairing cluster "<<i<<"with "<<j<<"\n";		
		if(org_docs[j].compute_dice_coefficient(c[i].cr.c_str())>=threshold)
		{
			c[i].put_in_cluster(org_docs[j].doc_name);
			org_docs[j].assigned=i;
			//std::cout<<"\n\n dc for i ="<<i<<"\tj="<<j<<"\t="<<org_docs[j].compute_dice_coefficient(c[i].cr.c_str())<<"\n\n\n\n";
		}
	else if(i<(no_of_clusters-1) && org_docs[j].assigned==100)
		if(c[i+1].cr=="\0")
		{
			c[i+1].put_in_cluster(org_docs[j].doc_name); 
		}
	}
}
std::cout<<"\n cluster 1";
c[0].show_cluster();
std::cout<<"\t and Cluster Representative is "<<c[0].cr;
std::cout<<"\n cluster 2";
c[1].show_cluster();
std::cout<<"\t and Cluster Representative is "<<c[1].cr;
std::cout<<"\n cluster 3";
c[2].show_cluster();
std::cout<<"\t and Cluster Representative is "<<c[2].cr;



//std::cout<<std::endl<<"Intersection of d1 and d4";





/*

if(d1.compute_dice_coefficient("4.txt")>=threshold)
	c1.put_in_cluster(d4.doc_name);

*/



return 0;
}



