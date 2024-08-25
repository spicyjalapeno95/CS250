using namespace std;

class InvestmentAccount {
public:
	InvestmentAccount();
	InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_numYears, double annualInterest);

	double getInitialInvestment();
	double getMonthlyDeposit();
	double getNumYears();
	double getAnnualInterest();


	void printUserInput();
	void printReports();

private:
	double initialInvestment;
	double monthlyDeposit;
	double numYears;
	double annualInterest;
};
