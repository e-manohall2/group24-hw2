#include <iostream>

using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];

	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const std::invalid_argument&)
			{
				if(i==1)
					cout << "(Invalid loan amount): " << argv[i] << endl;
				else if (i==2)
					cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
				else
					cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;
				return -2;
			}
			i++;
		}
	}
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double intrest_sum=0;
	int month=0;
	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	if(monthly_payment<(yearly_interest_rate/1200*loan_amount)){ //if intrest is greater than payment 
		cout << "(Insufficient payment): " << arguments[0] << ", " << arguments[1] << ", " << arguments[2] << endl;
		return -1;

	}
	else if (yearly_interest_rate<0)
	{
		cout<<"(Invalid Intrest Rate): "<< arguments[0] << ", " << arguments[1] << ", " << arguments[2] << endl;
		return -1;

	}
	else if (monthly_payment<0)
	{
		cout<<"(Invalid Monthly Payment): "<< arguments[0] << ", " << arguments[1] << ", " << arguments[2] << endl;
		return -1;

	}
	


	double instantaneous_intrest;
	cout<<"******************************************************"<<endl;
	cout<<"\tAmortized Table"<<endl;
	cout<<"******************************************************"<<endl;

	cout<<"Month\tBalance\tPayment\tRate\tIntrest\tPrinciple"<<endl;

	while(loan_amount>0.00){
		if(month==0){
			cout<<month<<"\t"<<loan_amount<<"\tN/A\tN/A\tN/A\tN/A"<<endl;
		}
		else{
			instantaneous_intrest = loan_amount * yearly_interest_rate /1200;
			if(monthly_payment<(loan_amount+instantaneous_intrest)){
				loan_amount+=instantaneous_intrest;
				loan_amount-=monthly_payment;
				intrest_sum += instantaneous_intrest;
				cout<<month<<"\t$"<<loan_amount<<"\t$"<<monthly_payment<<"\t"<<yearly_interest_rate/(12.0)<<"\t$"<<instantaneous_intrest<<"\t$"<<monthly_payment-instantaneous_intrest<<endl;
			}
			else{

				loan_amount+=instantaneous_intrest;
				cout<<month<<"\t$"<<0.00<<"\t$"<<loan_amount<<"\t"<<yearly_interest_rate/(12.0)<<"\t$"<<instantaneous_intrest<<"\t$"<<loan_amount-instantaneous_intrest<<endl;
				intrest_sum+=instantaneous_intrest;
				loan_amount-=monthly_payment;
				loan_amount = (loan_amount<0)?0:loan_amount;
				
			}

		}
		month++;
	}
	cout<<"******************************************************\n"<<endl;
	cout<<"It takes "<<month<<" to pay off the loan."<<endl;
	cout<<"Total intrest paid is: $"<<intrest_sum<<endl;



	return 0;
}
