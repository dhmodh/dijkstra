#include<iostream>
using namespace std;

class disktra
{
	int ver;
	int **ad_mat;
	public:
		void initialize_mat(int);
		void insert_weight();
		void print_mat();
		void shortest_path();
};

void disktra::initialize_mat(int v)
{
	ver=v;
	ad_mat=new int *[v];
	for(int i=0;i<v;i++)
		ad_mat[i]=new int[v]();
}

void disktra::insert_weight()
{
	for(int i=0;i<ver;i++)
	{
		for(int j=0;j<ver;j++)
		{
			cout<<"Enter weightage of egde from vertex "<< i <<" to vertex "<< j << " : ";
			cin>>ad_mat[i][j];
		}
	}
	cout<<"\nA-1=";
	print_mat();
}

void disktra::print_mat()
{
	for(int i=0;i<ver;i++)
	{
		for(int j=0;j<ver;j++)
			cout<<"\t"<<ad_mat[i][j];
		cout<<endl;
	}
}

void disktra::shortest_path()
{
	int t;
	for(int k=0;k<ver;k++)
	{
		for(int i=0;i<ver;i++)
		{
			for(int j=0;j<ver;j++)
			{
				t=ad_mat[i][k]+ad_mat[k][j];
				if(t<ad_mat[i][j])
					ad_mat[i][j]=t;
			}
		}
		cout<<"\nA"<<k<<"=";
		print_mat();
	}	
}

int main()
{
	disktra d;
	int v;
	cout<<"Enter No, of Vertex:- ";
	cin>>v;
	d.initialize_mat(v);
	cout<<"\nIf Edge not exist the Enter highest value\n";
	d.insert_weight();
	d.shortest_path();
	return 0;
}
