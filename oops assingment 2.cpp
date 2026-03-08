#include <iostream>
using namespace std;

class smartdeliveryservice
{
	protected:
		int id;
		double cost;
		string name;
		
		void displayinfo(int id,double cost,string name)
		{
			cout<<"Delivery Information"<<endl;
			cout<<"ID : "<<id<<endl;
			cout<<"Cost : "<<cost<<endl;
			cout<<"customer : "<<name<<endl;
			
		}
};

class expressdelivery : public smartdeliveryservice{
	public:
		string priority_level;
		using smartdeliveryservice::displayinfo;
		
	void displayinfo(int id,double cost,string name,string priority){
	
		
		cout<<"Express Delivery Information"<<endl;
		cout<<"ID : "<<id<<endl;
		cout<<"cost : "<<cost<<endl;
		cout<<"Customer : "<<name<<endl;
		cout<<"Priority Level : "<<priority_level<<endl;
		
	}
			
};

int main()
{
	expressdelivery e1;
	e1.displayinfo(101,850.5,"ALI");
	e1.displayinfo(202,1500.75,"SANA","HIGH");

}
