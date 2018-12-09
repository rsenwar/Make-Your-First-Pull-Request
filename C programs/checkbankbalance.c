#include <stdio.h>


// Structure Declaration for account
struct account
{
	int accNumber;                          // Account number
	double balance;                         // Balance of the account
};

/*  Function to add an amount if positive-valued */
//
double balanceUp( double amount,double balance)
{
	if (amount >=0)
	{
	   balance = balance+amount;
	   return balance;}
	else
	{
		return balance;
	}
}
double balanceDown(double amount,double balance)
{

	   balance = balance-amount;
	   return balance;
}
int inputaccNumber(){
	int inputaccNumberF;
	printf("Enter account number: ");
	scanf("%d",&inputaccNumberF);
	return inputaccNumberF;
}


/* Function to calculate the interest rate*/
//
double interestCalc(double balance,double rate)
{
	double interest=0;
  interest= balance * (rate/100);
  return interest;
}

/* main program */
int main()
{
	const int nosClients = 5;                                                       // Number of accounts
	int option;
	int match=0;
	int i=0;
	double calcInterest=0;
	double rateInput=0,rate=0;
	int accNumberInput=0;
	double  amountInput=0 ,amount=0;


	// Hold the selection
	// Initialize the struct account array with opening balance
	struct account acct[] = { { 11111111, 123.45 },{ 22222222, 12365.50 },{ 33333333,0 },{ 44444444,1475 },{ 55555555,25000.65 } };

	printf("***** Welcome to Savings Account Banking *****\n\n");

	do
	{
		// Print the option list
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Account Summary\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		// Waiting for the input
		scanf("%d",&option);

		switch (option)
		{
		case 0:
		       // loopEnd = 0 ; // Exit the program
			break;

		case 1: // Deposit
		       //printf("Enter account number: ");
		       printf("\n");//@IN-LAB
		       printf("-- Make a deposit --\n");
		       printf("\n");
		       accNumberInput = inputaccNumber();
		       //scanf("%d",&accNumberInput);
		       for(i=0;i<5;i++)
		       {
			      // printf("%d",accNumberInput);

			       //printf("%d",acct[i].accNumber);
			if(accNumberInput == acct[i].accNumber){
			      match =1;
				     printf("Enter amount to deposit (CAD): ");
				     scanf("%lf",&amountInput);
				     acct[i].balance = balanceUp(acct[i].balance,amountInput);


				     printf("Current balance is : %.2lf\n",acct[i].balance);
				     printf("\n");
				 break;

			       }

			    }


		       if(match == 0)

		       {
			printf("ERROR: Account number does not exit.\n\n");
		       }

		       match=0;


			break;
		//      amount=amountInput;

		case 2: // Withdraw funds
		       printf("\n");//@IN-LAB
		       printf("-- Withdram funds --\n");
		       printf("\n");

		       accNumberInput = inputaccNumber();
				//@HOME
		       for(i=0;i<5;i++)
		       {
			      // printf("%d",accNumberInput);

			       //printf("%d",acct[i].accNumber);
			if(accNumberInput == acct[i].accNumber){
				      match=1;
				     //printf("%lf\n",acct[i].balance);
				     printf("Enter amount to withdraw (CAD): ");
				     scanf("%lf",&amountInput);

			       if( acct[i].balance > amountInput)
			       {
				     //acct[i].balance = acct[i].balance-amountInput;
				     acct[i].balance= balanceUp(amountInput,acct[i].balance);

				      printf("Current balance is : %.2lf\n",acct[i].balance);
				      printf("\n");
			       }
				     else

				     {

			printf("Withdramal failed. You only have : 0.00 in your account\n");
			printf("\n");
				     }


			  break;
			}

			//break;
			}


		       if(match == 0)

		       {
			printf("ERROR: Account number does not exit.\n");

		       }
		       match =0;
		       break;

		case 3:
		       printf("\n");
		       printf("-- Add monthly interest earnings to all accounts --\n");
		       printf("\n");           // Apply interest earnings to all accounts
		       printf("Account# New Balance Interest Earnings (M)\n");  //@IN-LAB
		       printf("-------- ----------- ---------------------\n");
		       for(i=0;i<5;i++){
			       match=0;
			       if (acct[i].balance <= 500){
				       rateInput=0.99;
			      calcInterest=interestCalc(acct[i].balance,rateInput);

			      acct[i].balance=balanceUp(acct[i].balance,calcInterest);


			       }

			       else if(acct[i].balance>500 && acct[i].balance <= 1500){
				     // change=1;
				       rateInput=1.66;
			      //rate= acct[i].balance*(rateInput/100);
			      calcInterest=(acct[i].balance,rateInput);

			      acct[i].balance=balanceUp(acct[i].balance,calcInterest);
			       }
				if (acct[i].balance >1500 ){
				       //change=1;
				       rateInput=2.49;

			      calcInterest=(acct[i].balance,rateInput);
			      acct[i].balance=balanceUp(acct[i].balance,calcInterest);
			       }


		       printf("%8d %11.2lf %21.2lf\n",acct[i].accNumber,acct[i].balance,calcInterest);

		       }
			      printf("\n");
			       break;



		case 4: // Display Account Information
			printf("\n");
			printf("-- Account information --\n");
			printf("\n");
			printf("Account# Balance\n");
			printf("-------- ----------\n");
		       for(i=0;i<5;i++){

			       acct[i].balance = acct[i].balance+amount;
			       balanceUp(amountInput,acct[i].balance);
			       //balanceUp(amountInput,acct[i].balance);
				//@IN-LAB
			       interestCalc(acct[i].balance,rateInput);
		       printf("%8d %10.2lf \n",acct[i].accNumber,acct[i].balance);

		       }
			printf("\n");
			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}
